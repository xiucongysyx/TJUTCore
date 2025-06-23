#include <isa/isa.h>
#include <isa/reg.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

extern int is_batch_mode;

void isa_reg_display() {
  int i;
  char *arg = NULL;
  if(is_batch_mode) arg = NULL;
  else arg = strtok(NULL, " ");
  if(arg == NULL) {
    for(i = 0; i < 32; i++) {
      printf("%-6s0X%-12x%-12u\n", reg_name(i), gpr(i), gpr(i));
    }
  }
  else {
    for(i = 0; i < 32; i++) {
      if(strcmp(arg, reg_name(i)) == 0) {
        printf("%-4s0X%-12x%-12d\n", arg, gpr(i), gpr(i));
        return; 
      }
    }
    if(i == 32) {printf("Name of reg is error!\n");}
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  int n = -1;
  if(strcmp("pc", s) == 0) {
    return cpu.pc;
  }
  else {
    for(int i = 0; i < 32; i++) {
      if(strcmp(reg_name(i), s) == 0) {
        //printf("reg_name = %s, s = %s.\n", reg_name(i), s);
        n = i;
        break;
      }
    }
    if(n == -1) {
      *success = false;
      printf("Name of reg is error.\n");
      return 0;
    }
    else {return gpr(n);}
  }
}