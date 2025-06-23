#include <common.h>
#include <isa/isa.h>
#include <isa/reg.h>
#include <cpu/ifetch.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>

VTJUT_TOP* top = NULL;
static VerilatedContext* context = NULL;
IFDEF(CONFIG_VCD, static VerilatedVcdC* tfp = NULL);

static void halt_step_wave() {
  top->eval();
  context->timeInc(1);
  IFDEF(CONFIG_VCD, tfp->dump(context->time()));
  IFDEF(CONFIG_VCD, tfp->flush();)
}

void step_and_dump_wave() {
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();
}

void isa_exec_once() {
  top->clk = !top->clk;
  halt_step_wave();
  cpu.pc = *cpu.dnpc;
  cpu.inst = inst_fetch(cpu.pc, 4);
  halt_step_wave();
  step_and_dump_wave();
  IFDEF(CONFIG_MTRACE, cpu.memflag = false);
  cpu.snpc = cpu.pc + 4;
}

static void restart() {
  cpu.gpr = (word_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf;
  cpu.pc = 0x80000000;
  cpu.dnpc = (word_t*)&top->pc;
  cpu.ddnpc = (word_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc;
  cpu.breakpoint = (bool*)&top->breakpoint;
  cpu.invalid = (bool*)&top->invalid;
  top->rst = 1;
  top->clk = 0;
  for(int i = 5; i > 0; i--) {
    step_and_dump_wave();
    step_and_dump_wave();
  }
  step_and_dump_wave();
  top->rst = 0;
}

void isa_exit() {
  IFDEF(CONFIG_VCD, tfp->close());
}

void init_isa() {
  context = new VerilatedContext; 
  IFDEF(CONFIG_VCD, tfp = new VerilatedVcdC);
  top = new VTJUT_TOP;
#ifdef CONFIG_VCD
  context->traceEverOn(true);
  top->trace(tfp, 10);
  tfp->open("build/npc_wave.vcd");
#endif 
  restart();
}