#ifndef __ISA_H__
#define __ISA_H__

#include <common.h>

// cpu_state
typedef struct {
  word_t *gpr;
  vaddr_t pc;
  vaddr_t snpc;
  vaddr_t *dnpc;
  vaddr_t *ddnpc;
  vaddr_t inst;
  bool *breakpoint;
  bool *invalid;
  IFDEF(CONFIG_MTRACE, bool memflag);
  IFDEF(CONFIG_ITRACE, char logbuf[2048]);
} CPU_state;

extern CPU_state cpu;

// logo.c
extern unsigned char isa_logo[];
// reg.c
void isa_reg_display();
word_t isa_reg_str2val(const char *s, bool *success);
// watchpoint.c
void wp_display();
//expr.c
word_t expr(char *e, bool *success);
// isa.c
void isa_exec_once(); 

#endif

