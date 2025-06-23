#include <common.h>
#include <elf.h>

#define FUNC_INFO_NUM 255

typedef struct {
    uint32_t func_addr; // 这个变量用来记录函数的起始位置
    uint32_t func_end;
    char *func_name;  // 这个变量用来记录函数的名称
} ElfInfo;

typedef struct {
    ElfInfo elf_func[FUNC_INFO_NUM];
    int func_num;
}ElfInfoList;

typedef struct {
    int pc_func;
    int dnpc_func;
    int func_pointer;
}ElfJudge;
 
ElfInfoList func_info;
ElfJudge func_judge;

int func_stack[1024] = {0}; // 存放已经调用的函数

void init_elf(char *elf_file) {
    // 定义func info 列表
    func_info.func_num = 0;
    func_judge.dnpc_func = -1;
    func_judge.pc_func = -1;
    func_judge.func_pointer = -1;

    Assert(elf_file, "Invalid name of elf-type file, %s\n", elf_file);
    FILE *sp = fopen(elf_file, "rb");
    Assert(sp, "Can not open %s\n", elf_file);

    Elf32_Ehdr ehdr;
    Assert(fread(&ehdr, 1, sizeof(Elf32_Ehdr), sp), "Fail to read elf header whose name is %s\n", elf_file);
    
    // 首先我们要解析elfHeader，找到section Header的位置
    Elf32_Shdr *shdr = (Elf32_Shdr *)malloc(ehdr.e_shnum * ehdr.e_shentsize); // 这个变量是section Header的结构体 
    fseek(sp, ehdr.e_shoff, SEEK_SET);
    Assert(fread(shdr, ehdr.e_shnum, ehdr.e_shentsize, sp), "Fail to read section header whose name is %s\n", elf_file);
    Assert(shdr[1].sh_type == SHT_PROGBITS, "Please check the correct of the shdr in the %s\n", elf_file);
    int cnt = 0;
    Elf32_Shdr *shdr_strtab = NULL;
    Elf32_Shdr *shdr_symtab = NULL;

    for (cnt = 0; cnt < ehdr.e_shnum; cnt++) {
        if(shdr[cnt].sh_type == SHT_SYMTAB) {shdr_symtab = &shdr[cnt];}
        else if(shdr[cnt].sh_type == SHT_STRTAB) {shdr_strtab = &shdr[cnt]; break;}
    }
    Assert((shdr_symtab->sh_type == SHT_SYMTAB) && (shdr_strtab->sh_type == SHT_STRTAB), "strtab or symtab is error in the %s\n", elf_file);

    // 取出symtab数据
    Elf32_Sym *esym = (Elf32_Sym *)malloc(shdr_symtab->sh_size);
    fseek(sp, shdr_symtab->sh_offset, SEEK_SET);
    Assert(fread(esym, 1, shdr_symtab->sh_size, sp), "Fail to read symtab in the %s\n", elf_file);

    // 取出strtab数据
    char *strdata = (char *)malloc(shdr_strtab->sh_size);
    fseek(sp, shdr_strtab->sh_offset, SEEK_SET);
    Assert(fread(strdata, 1, shdr_strtab->sh_size, sp), "Fail to read strtab in the %s\n", elf_file);

    // 将函数名和指令范围对应起来
    for (cnt = 0; cnt < shdr_symtab->sh_size/shdr_symtab->sh_entsize; cnt++) {
        if(ELF32_ST_TYPE(esym[cnt].st_info) == STT_FUNC) {
            func_info.elf_func[func_info.func_num].func_addr = esym[cnt].st_value;
            func_info.elf_func[func_info.func_num].func_end = esym[cnt].st_value + esym[cnt].st_size;
            func_info.elf_func[func_info.func_num].func_name = (strdata + esym[cnt].st_name);
            func_info.func_num++;
        }
    }
}

bool ftrace_judge(uint32_t pc, uint32_t dnpc, char *ftrace_buf, int is_call) {
    func_stack[-1] = -1;

    for (int i = 0; i < func_info.func_num; i++) {
        if (func_info.elf_func[i].func_addr <= pc && pc < func_info.elf_func[i].func_end)
            func_judge.pc_func = i;
        if (func_info.elf_func[i].func_addr <= dnpc && dnpc < func_info.elf_func[i].func_end)
            func_judge.dnpc_func = i;
    }

    if (func_judge.pc_func == func_judge.dnpc_func) return false;
    if (dnpc == func_info.elf_func[func_judge.dnpc_func].func_addr) {
        if(is_call) {
            func_judge.func_pointer++;
            sprintf(ftrace_buf, "%3d: 0x%8x:%*scall [%s@0x%8x]", func_judge.func_pointer, pc, func_judge.func_pointer, "\0", func_info.elf_func[func_judge.dnpc_func].func_name, func_info.elf_func[func_judge.dnpc_func].func_addr);
        }
        else return false;
    }
    else {
        sprintf(ftrace_buf, "%3d: 0x%8x:%*sret  [%s@0x%8x]", func_judge.func_pointer, pc, func_judge.func_pointer, "\0 ", func_info.elf_func[func_judge.pc_func].func_name, func_info.elf_func[func_judge.pc_func].func_addr);
        func_judge.func_pointer--;
    }

    return true;
}
