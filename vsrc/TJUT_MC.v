`include "define.v"
module TJUT_MC(
  input  [`MCCTRL_WIDTH-1:0]  mc_ctrl_sig,
  input  [`DATA_WIDTH-1:0]    ex_out_data,
  input  [`DATA_WIDTH-1:0]    src2,
  output [`DATA_WIDTH-1:0]    memregdata
);

/*****************ex_out_sig解码*****************/
wire                      memren      = mc_ctrl_sig[0];
wire                      memwen      = mc_ctrl_sig[1];
reg  [`DATA_WIDTH-1:0]    rdata;

assign memregdata = rdata;

import "DPI-C" function void cpu_pmem_read(
  input byte raddr, output byte rdata
);

import "DPI-C" function void cpu_pmem_write(
  input byte waddr, input byte wdata
);

always @(*) begin 
  if(memren) begin
    cpu_pmem_read(ex_out_data, rdata);
  end
  else if(memwen) begin
    cpu_pmem_write(ex_out_data, src2);
    rdata = 8'b0;
  end
  else begin
    rdata = 8'b0;
  end
end
endmodule
