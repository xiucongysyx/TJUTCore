#include <common.h>
#include <cpu/cpu.h>
#include <locale.h>
#include <isa/isa.h>
#include <isa/reg.h>

#define MAX_INST_TO_PRINT 10
#define FTRACE_BUF_SIZE 2048
#define NUMBERIC_FMT "%'" PRIu64

CPU_state cpu = {};

uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0;
static bool g_print_step = false;

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
bool ftrace_judge(uint32_t pc, uint32_t dnpc, char *ftrace_buf, int iscall);
bool wp_watch();

static void trace_and_difftest() {
  if(g_print_step) {IFDEF(CONFIG_ITRACE, printf("npc: ");puts(cpu.logbuf));}

  // 判断是否执行完或者遇到无效指令
  if(*cpu.breakpoint) {set_npc_state(NPC_END, cpu.pc, gpr(10));}
  else if(*cpu.invalid) {invalid_inst(cpu.pc);}

  IFDEF(CONFIG_ITRACE,
    IFDEF(CONFIG_ITRACE_COND, log_write(log_fp, "%s\n", cpu.logbuf));
  )

  #ifdef CONFIG_FTRACE
    char ftrace_buf[FTRACE_BUF_SIZE];
    if(ftrace_judge(cpu.pc, *cpu.dnpc, ftrace_buf, (BITS(cpu.inst, 6, 0) == 0x6f || BITS(cpu.inst, 6, 0) == 0x67) && BITS(cpu.inst, 11, 7) == 0x1) == true) {
      log_write(ftrace_fp, "%s\n", ftrace_buf);
    } 
  #endif
  
  #ifdef CONFIG_WATCHPOINT
    if(wp_watch() == true) {npc_state.state = NPC_STOP;}
  #endif
}

static void exec_once() {
  isa_exec_once();
#ifdef CONFIG_ITRACE
  char *p = cpu.logbuf;
  p += snprintf(p, sizeof(cpu.logbuf), FMT_WORD ":", cpu.pc);
  int ilen = cpu.snpc - cpu.pc;
  int i;
  uint8_t *inst = (uint8_t*)cpu.inst_act;
  for(i = ilen - 1; i >= 0; i--) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  memset(p, ' ', 1);
  p++;

  disassemble(p, cpu.logbuf + sizeof(cpu.logbuf) - p, cpu.pc, (uint8_t *)cpu.inst_act, ilen);
#endif
}

static void execute(uint64_t n) {
  for (;n > 0; n--) {
    exec_once();
    g_nr_guest_inst ++;
    trace_and_difftest();
    if (npc_state.state != NPC_RUNNING) break;
  }
}

static void statistic() {
  extern char *img_file;
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
  Log("The %s done!", SLASH(img_file, 4));
}

void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("npc: %s at pc = " FMT_WORD, 
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) : 
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) : 
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))), 
          npc_state.halt_pc);
      break;
    
    case NPC_QUIT: statistic();break;
  }
}

void inst_display() {
int i,j;
int ilen = 4;
data_t pc = 0x00;
char disinst[1023];
for (i=0; i<cpu.instlong; i=i+4) {
  printf("0x%02x:  ", pc);
  pc=pc+4;
  for(j=ilen-1; j>=0; j--) {
    printf("%02x ", *(cpu.mem+i+j));
  }
  disassemble(disinst, sizeof(disinst), pc, (uint8_t *)(cpu.mem+i), ilen);
  printf("\t%s", disinst);
  printf("\n");
}

}