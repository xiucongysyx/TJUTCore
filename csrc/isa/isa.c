#include <common.h>
#include <isa/isa.h>
#include <isa/reg.h>
#include <cpu/ifetch.h>
#include <cpu/cpu.h>
#include <memory/paddr.h>

VTJUT_TOP* top = NULL;
static VerilatedContext* context = NULL;
IFDEF(CONFIG_VCD, static VerilatedVcdC* tfp = NULL);

void uart_recv();


typedef struct {
  data_t *pc;
  data_t *snpc;
  data_t *dnpc;
  char udata;
  int bpscnt;
  int udatacnt;
  int udataflag;
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

void setp_and_dump_wave() {
  setp_and_dump_wave_half_clk();
  setp_and_dump_wave_half_clk();
}

void isa_exec_once() {
  // 现在是运行4个clk周期完成一次指令的取指
  //one clk
  if(top->instload == 0) {top->uart_rxd = top->uart_txd;};
  setp_and_dump_wave_half_clk();
  cpu.pc = *tpu.pc;
  cpu.dnpc = *tpu.dnpc;
  cpu.snpc = *tpu.snpc;
  cpu.inst_ref = inst_fetch(cpu.pc, 4);
//  cpu.inst_ref = *cpu.inst_act;
  setp_and_dump_wave_half_clk();
 uart_recv();


  //second clk
  setp_and_dump_wave_half_clk();
  setp_and_dump_wave_half_clk();
 uart_recv();

  //third clk
  setp_and_dump_wave_half_clk();
  setp_and_dump_wave_half_clk();
 uart_recv();

  //fourth clk
  setp_and_dump_wave_half_clk();
  setp_and_dump_wave_half_clk();
 uart_recv();


  IFDEF(CONFIG_MTRACE, cpu.memflag = false);
}

static void restart() {
  int i;
  cpu.gpr = (data_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf;
  tpu.pc = (data_t*)&top->rootp->TJUT_TOP__DOT__pc;
  tpu.dnpc = (data_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc;
  tpu.snpc = (data_t*)&top->rootp->TJUT_TOP__DOT__snpc;
  cpu.breakpoint = (bool*)&top->breakpoint;
  cpu.invalid = (bool*)&top->invalid;
  cpu.inst_act = (inst_t*)&top->rootp->TJUT_TOP__DOT__inst;
  cpu.mem = (data_t*)&top->rootp->TJUT_TOP__DOT__u_TJUT_MC__DOT__u_TJUT_MEM__DOT__dmem;
  top->rstn = 0;
  top->clk = 0;
  top->instload = 0;
  top->uart_rxd = 1;
  tpu.bpscnt = 0;
  tpu.udata = 0;
  tpu.udataflag = 0;
  tpu.udatacnt = 0;
  for(i = 6; i > 0; i--) {
    setp_and_dump_wave_half_clk();
  }
  top->rstn = 1;

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

void uart_send(char udata){
  int i;
  int j;

 for(i=0; i<10; i++) {
  switch (i) {
    case 0: top->uart_rxd = 0;break;
    case 1: top->uart_rxd = (udata & 0x01) == 0x01;break;
    case 2: top->uart_rxd = (udata & 0x02) == 0x02;break;
    case 3: top->uart_rxd = (udata & 0x04) == 0x04;break;
    case 4: top->uart_rxd = (udata & 0x08) == 0x08;break;
    case 5: top->uart_rxd = (udata & 0x10) == 0x10;break;
    case 6: top->uart_rxd = (udata & 0x20) == 0x20;break;
    case 7: top->uart_rxd = (udata & 0x40) == 0x40;break;
    case 8: top->uart_rxd = (udata & 0x80) == 0x80;break;
    case 9: top->uart_rxd = 1;break;
  }
  for(j=434; j>0; j--) {
    setp_and_dump_wave();
  }
 } 
}

void uart_recv(){
  if(top->uart_txd == 0 && tpu.udataflag == 0) {
    tpu.udataflag = 1;
  }
  if(tpu.udataflag == 1) {
    tpu.bpscnt = tpu.bpscnt + 1;
    if(tpu.bpscnt == 220) {
      switch (tpu.udatacnt) { 
        case 1: if(top->uart_txd) {tpu.udata =tpu.udata | 0x01;} break;
        case 2: if(top->uart_txd) {tpu.udata =tpu.udata | 0x02;} break;
        case 3: if(top->uart_txd) {tpu.udata =tpu.udata | 0x04;} break;
        case 4: if(top->uart_txd) {tpu.udata =tpu.udata | 0x08;} break;
        case 5: if(top->uart_txd) {tpu.udata =tpu.udata | 0x10;} break;
        case 6: if(top->uart_txd) {tpu.udata =tpu.udata | 0x20;} break;
        case 7: if(top->uart_txd) {tpu.udata =tpu.udata | 0x40;} break;
        case 8: if(top->uart_txd) {tpu.udata =tpu.udata | 0x80;} break;
        case 9: {
          printf("uart_rec=%c", tpu.udata); 
          if(tpu.bpscnt == 400) {
            tpu.udataflag = 0;
            tpu.udatacnt = 0;
            tpu.udata = 0;
            tpu.bpscnt = 0;
          }
        }
      }
    }
  }
}

void init_inst(){
  top->instload = 1;
  setp_and_dump_wave();
  setp_and_dump_wave();
  setp_and_dump_wave();
  int i;
  data_t pcaddr=0x00;
  for(i=251; i>0; i--) {
    uart_send((char)inst_fetch(pcaddr, 1));
    pcaddr++;
  }
  top->instload = 0;

  top->rstn = 0;
  setp_and_dump_wave();
  setp_and_dump_wave();
  setp_and_dump_wave();
  top->rstn = 1;
  
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
