#include <common.h>
#include <isa/isa.h>
#include <isa/reg.h>
#include <cpu/ifetch.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>

VTJUT_TOP* top = NULL;
static VerilatedContext* context = NULL;
IFDEF(CONFIG_VCD, static VerilatedVcdC* tfp = NULL);

typedef struct {
  data_t *pc;
  data_t *snpc;
  data_t *dnpc;
} TPU_PC;

static TPU_PC tpu = {};

static void halt_step_wave() {
  top->eval();
  context->timeInc(1);
  IFDEF(CONFIG_VCD, tfp->dump(context->time()));
  IFDEF(CONFIG_VCD, tfp->flush();)
}

void setp_and_dump_wave_half_clk() {
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();
}

void isa_exec_once() {
  // 现在是运行4个clk周期完成一次指令的取指
  //one clk
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();
  cpu.pc = *tpu.pc;
  cpu.dnpc = *tpu.dnpc;
  cpu.snpc = *tpu.snpc;
  cpu.inst_ref = inst_fetch(cpu.pc, 4);
//  cpu.inst_ref = *cpu.inst_act;
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();


  //second clk
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();

  //third clk
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();

  //fourth clk
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();
  top->clk = !top->clk;
  halt_step_wave();
  halt_step_wave();

  IFDEF(CONFIG_MTRACE, cpu.memflag = false);
}

static void restart() {
  int i;
  cpu.gpr = (data_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf;
  tpu.pc = (data_t*)&top->pc;
  tpu.dnpc = (data_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc;
  tpu.snpc = (data_t*)&top->rootp->TJUT_TOP__DOT__snpc;
  cpu.breakpoint = (bool*)&top->breakpoint;
  cpu.invalid = (bool*)&top->invalid;
  cpu.inst_act = (inst_t*)&top->rootp->TJUT_TOP__DOT__inst;
  top->rst = 1;
  top->clk = 0;
  for(i = 6; i > 0; i--) {
    setp_and_dump_wave_half_clk();
  }
  top->rst = 0;

}

void init_first_pc() {
  int i;
  for (i = 8; i > 0; i--) {
    setp_and_dump_wave_half_clk();
  }
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