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
    log_write(mtrace_fp, "%#x %s: addr = " FMT_PADDR "\tdata = " FMT_WORD "\n", *cpu.pc, status, addr, data);
    cpu.memflag = true;
  }
}
#endif

static void out_of_bound(paddr_t addr) {
  printf("npc:address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD "\n", addr, PMEM_LEFT, PMEM_RIGHT, *cpu.pc);
  npc_state.state = NPC_ABORT;
}

extern "C" void cpu_pmem_read(paddr_t raddr, char *rdata) {
  if (likely(in_pmem(raddr))) {
    *rdata = host_read(guest_to_host(raddr), 1);
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

  out_of_bound(raddr);
  }


extern "C" void cpu_pmem_write(paddr_t waddr, char wdata) {
    host_write(guest_to_host(waddr), 1, wdata);
    #ifdef CONFIG_MTRACE 
    char is_write[] = "write";
    paddr_mtrace(addr, wdata, is_write);
    #endif
    return;

  #ifdef CONFIG_MTRACE 
  char is_write[] = "write";
  paddr_mtrace(addr, wdata, is_write);
  #endif

  out_of_bound(waddr);
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