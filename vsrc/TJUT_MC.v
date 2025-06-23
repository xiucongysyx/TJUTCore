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
wire                      sign_extend = mc_ctrl_sig[2]; 
wire [`RMASK_WIDTH-1:0]   rmask       = mc_ctrl_sig[`MCCTRL_WIDTH-`WMASK_WIDTH-1:`MCCTRL_WIDTH-`WMASK_WIDTH-`RMASK_WIDTH];
wire [7:0]                wmask       = {2'b0 ,addr_byte2, addr_byte1, addr_byte0, mc_ctrl_sig[`MCCTRL_WIDTH-1:`MCCTRL_WIDTH-`WMASK_WIDTH]};
reg  [`DATA_WIDTH-1:0]    rdata;

wire                      addr_byte0  = ex_out_data[0] & ~ex_out_data[1];
wire                      addr_byte1  = ex_out_data[1] & ~ex_out_data[0];
wire                      addr_byte2  = ex_out_data[0] & ex_out_data[1];

wire [`DATA_WIDTH-1:0]    rdata_cor   = addr_byte0 ? {8'b0, rdata[31:8]} : 
                                       (addr_byte1 ? {16'b0, rdata[31:16]} :
                                       (addr_byte2 ? {24'b0, rdata[31:24]} : rdata));

wire [`DATA_WIDTH-1:0]    onebyte_u   = {24'b0, rdata_cor[7:0]};
wire [`DATA_WIDTH-1:0]    onebyte_s   = {{24{rdata_cor[7]}}, rdata_cor[7:0]};
wire [`DATA_WIDTH-1:0]    onebyte     = sign_extend ? onebyte_s : onebyte_u;
wire [`DATA_WIDTH-1:0]    twobyte_u   = {16'b0, rdata_cor[15:0]};
wire [`DATA_WIDTH-1:0]    twobyte_s   = {{16{rdata_cor[15]}}, rdata_cor[15:0]};
wire [`DATA_WIDTH-1:0]    twobyte     = sign_extend ? twobyte_s : twobyte_u;
wire [`DATA_WIDTH-1:0]    forbyte     = rdata_cor;

MuxKeyWithDefault #(6'd4, 6'd3, 6'd32) u0_MuxKeyWithDefault(memregdata, rmask, 32'b0, {
    3'd0     , 32'h0,
    3'd1     , onebyte,
    3'd2     , twobyte,
    3'd4     , forbyte
});

import "DPI-C" function void cpu_pmem_read(
  input int raddr, output int rdata, input byte rmask
);

import "DPI-C" function void cpu_pmem_write(
  input int waddr, input int wdata, input byte wmask
);

always @(*) begin 
  if(memren) begin
    cpu_pmem_read(ex_out_data, rdata, {5'b0, rmask});
  end
  else if(memwen) begin
    cpu_pmem_write(ex_out_data, src2, wmask);
    rdata = 32'b0;
  end
  else begin
    rdata = 32'b0;
  end
end
endmodule 
