#include <memory/paddr.h>
#include <memory/host.h>
#include <isa/isa.h>
#include <common.h>

static uint8_t *pmem = NULL;
extern FILE *mtrace_fp;

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }

#ifdef CONFIG_MTRACE
static void paddr_mtrace(vaddr_t addr, paddr_t data, char *status) {
  if (!cpu.memflag && addr != *cpu.ddnpc) {
    log_write(mtrace_fp, "%#x %s: addr = " FMT_PADDR "\tdata = " FMT_WORD "\n", cpu.pc, status, addr, data);
    cpu.memflag = true;
  }
}
#endif

static void out_of_bound(paddr_t addr) {
  printf("npc:address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD "\n", addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
  npc_state.state = NPC_ABORT;
}

extern "C" void cpu_pmem_read(int raddr, int *rdata, char rmask) {
  if(raddr == 0) return;
  paddr_t addr = raddr & ~0x3u;
  int len = rmask & 0x7;
  if (likely(in_pmem(addr))) {
    *rdata = host_read(guest_to_host(addr), 4);
    #ifdef CONFIG_MTRACE
    char is_write[] = "read";
    paddr_mtrace(addr, *rdata, is_write);
    #endif
    return;
  }

  #ifdef CONFIG_MTRACE
  char is_write[] = "read";
  paddr_mtrace(addr, *rdata, is_write);
  #endif

  out_of_bound(addr);
  }


extern "C" void cpu_pmem_write(int waddr, int wdata, char wmask) {
  if(waddr == 0) return;
  paddr_t addr = waddr & ~0x3u;
  int len = wmask & 0x7;
  if (likely(in_pmem(addr))) {
    paddr_t rdata = host_read(guest_to_host(addr), 4);
    paddr_t wdata_cor;
    switch (wmask) {
      case 0b00000001: wdata_cor = (BITS(rdata, 31,  8) << 8 ) | (BITS(wdata,  7, 0)); break;
      case 0b00001001: wdata_cor = (BITS(rdata, 31, 16) << 16) | (BITS(wdata,  7, 0) <<  8) | (BITS(rdata,  7, 0)); break;
      case 0b00010001: wdata_cor = (BITS(rdata, 31, 24) << 24) | (BITS(wdata,  7, 0) << 16) | (BITS(rdata, 15, 0)); break;
      case 0b00100001: wdata_cor = (BITS(wdata,  7,  0) << 24) | (BITS(rdata, 23, 0)); break;
      case 0b00000010: wdata_cor = (BITS(rdata, 31, 16) << 16) | (BITS(wdata, 15, 0)); break;
      case 0b00001010: wdata_cor = (BITS(rdata, 31, 24) << 24) | (BITS(wdata, 15, 0) <<  8) | (BITS(rdata,  7, 0)); break;
      case 0b00010010: wdata_cor = (BITS(wdata, 15,  0) << 16) | (BITS(rdata, 15, 0)); break;
      default: wdata_cor = wdata; break;
    }
    host_write(guest_to_host(addr), 4, wdata_cor);
    #ifdef CONFIG_MTRACE 
    char is_write[] = "write";
    paddr_mtrace(addr, wdata, is_write);
    #endif
    return;
  }

  #ifdef CONFIG_MTRACE 
  char is_write[] = "write";
  paddr_mtrace(addr, wdata, is_write);
  #endif

  out_of_bound(addr);
}

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

void init_mem() {
  pmem = (uint8_t* )(malloc(CONFIG_MSIZE));
  assert(pmem);
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  out_of_bound(addr);
  return 0;
}