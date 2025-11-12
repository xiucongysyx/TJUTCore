#include <common.h>
#include <memory/paddr.h>
#include <getopt.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_imem();
void init_sdb();
void init_isa();
void init_disasm(const char *triple);
void init_first_pc();

static void welcome() {
  printf("Welcome to riscv32-npc!\n");
}

void sdb_set_batch_mode();
char *img_file = NULL;
char *log_file = NULL;
static char *elf_file = NULL;

static long load_img() {
  if(img_file == NULL) {
    Log("img_file open error!\n");
    return 4096;
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", SLASH(img_file, 4), size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host_imem(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"  , no_argument      , NULL, 'b'},
    {"log"    , required_argument, NULL, 'l'},
    {"elf"    , required_argument, NULL, 'e'},
    {"help"   , no_argument      , NULL, 'h'},
    {0        , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:e:d:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'l': log_file = optarg; break;
      case 'e': elf_file = optarg; break;
      case  1 : img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-e,--elf=FILE           input elf for progrom\n");
        printf("\n");
        exit(0); 
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {

  init_isa();
  // 识别参数，并通过参数初始化一些东西
  parse_args(argc, argv);

  // 随机数生成模式选择
  init_rand();

// 初始化log文件
  init_log(log_file);

  // 初始化mem
  init_mem();
  init_imem();

  long img_size = load_img();

  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm("riscv32-pc-linux-gun"));

  welcome();

  init_first_pc();
}