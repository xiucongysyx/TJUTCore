#ifndef __ISA_H__
#define __ISA_H__

#include <common.h>

// cpu_state
typedef struct {
  data_t *gpr;
  data_t *pc;
  data_t snpc;
  data_t *dnpc;
  inst_t *inst_act;
  inst_t inst_ref;
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

