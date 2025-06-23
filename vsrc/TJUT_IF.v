`include "define.v"
module TJUT_IF(
    input   wire                        clk,
    input   wire                        rst,
    input   wire    [`IFCTRL_WIDTH-1:0] if_ctrl_sig,
    input   wire    [`DATA_WIDTH-1:0]   ex_out_data,
    output  reg     [`PC_WIDTH-1:0]     pc,
    output  wire    [`PC_WIDTH-1:0]     snpc,
    output  reg     [`DATA_WIDTH-1:0]   inst
);

wire    selpc = if_ctrl_sig[0];

assign  snpc  = pc   + 32'h4;
wire [`PC_WIDTH-1:0] dnpc = selpc ? ex_out_data : snpc;

import "DPI-C" function void cpu_pmem_read(
  input int raddr, output int rdata, input byte rmask
);

always @(posedge clk) begin
    if(rst) begin
        pc    <= 32'h80000000;
    end
    else begin
        pc    <= dnpc; 
        cpu_pmem_read(dnpc, inst, 8'b0000_0100);
    end 
end

endmodule


