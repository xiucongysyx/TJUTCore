`include "define.v"
module TJUT_WB(
    input                         clk,
    input   [`DATA_WIDTH-1:0]     ex_out_data,
    input   [`PC_WIDTH-1:0]       snpc,
    input   [`DATA_WIDTH-1:0]     memregdata,
    input   [`ADDER_WIDTH-1:0]    adder_rd,
    input   [`ADDER_WIDTH-1:0]    adder_src1,
    input   [`ADDER_WIDTH-1:0]    adder_src2,
    input   [`ADDER_WIDTH-1:0]    wb_ctrl_sig,

    output  [`DATA_WIDTH-1:0]     src1,
    output  [`DATA_WIDTH-1:0]     src2
);

wire memregren  =   wb_ctrl_sig[4];
wire regpc      =   wb_ctrl_sig[3];
wire regwen     =   wb_ctrl_sig[2];
wire regrensrc1 =   wb_ctrl_sig[1];
wire regrensrc2 =   wb_ctrl_sig[0];

wire [`DATA_WIDTH-1:0]  wdata_d1    = (regpc == 1'b1) ? snpc : ex_out_data;
wire [`DATA_WIDTH-1:0]  wdata       = (memregren == 1'b1) ? memregdata : wdata_d1;


TJUT_REGFILE u_TJUT_REGFILE(
    .clk        (clk        ),
    .wdata      (wdata      ),
    .waddr      (adder_rd   ),
    .regwen     (regwen     ),
    .rdatasrc1  (src1       ),
    .rdatasrc2  (src2       ),
    .raddrsrc1  (adder_src1 ),
    .raddrsrc2  (adder_src2 ),
    .regrensrc1 (regrensrc1 ),
    .regrensrc2 (regrensrc2 )
);

endmodule
