#ifndef __CPU_CPU_H__
#define __CPU_CPU_H__

#include <common.h>

typedef struct Trace {
  vaddr_t pc;
  vaddr_t snpc;
  vaddr_t dnpc;
  IFDEF(CONFIG_ITRACE, char logbuf[128]);
} Trace;

void cpu_exec(uint64_t n);

void set_npc_state(int state, vaddr_t pc, int halt_ret);

void invalid_inst(vaddr_t thispc);

#endif

