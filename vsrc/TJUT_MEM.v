`include "define.v"
module TJUT_MEM(
    input wire clk_div4,
    input wire [`DATA_WIDTH-1:0] instpc,
    output reg [`DATA_WIDTH-1:0] inst_seg_data,
   
    input wire [`DATA_WIDTH-1:0] addr,
    input wire [`DATA_WIDTH-1:0] wdata,
   output wire [`DATA_WIDTH-1:0] rdata,

   input wire memren,
   input wire memwen
);

reg [`DATA_WIDTH-1:0] mem [255:0];

assign inst_seg_data = mem[instpc];
assign rdata = memren ? mem[addr] : 8'b0;

always @(posedge clk_div4) begin
    if(memwen) begin
       mem[waddr]  <= wdata;
    end
end

endmodule