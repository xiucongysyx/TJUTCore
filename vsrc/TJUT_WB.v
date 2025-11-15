`include "define.v"
module TJUT_WB(
    input                         clk,
    input   [`DATA_WIDTH-1:0]     ex_out_data,
    input   [`PC_WIDTH-1:0]       snpc,
    input   [`DATA_WIDTH-1:0]     memregdata,
    input   [`DATA_WIDTH-1:0]     memuartdata,
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
wire  uart_sel = ex_out_data == 8'hfe ? 1'b1 : 1'b0;
wire [3:0] wdata_sel = {uart_sel,memregren,regpc,regwen};

wire [`DATA_WIDTH-1:0] wdata;

`define WDATA_EX 4'b0001
`define WDATA_PC 4'b0011
`define WDATA_REG 4'b0101
`define WDATA_UART 4'b1001
MuxKeyWithDefault #(4'd4, 4'd4, 4'd8) u4_MuxKeyWithDefault(wdata, wdata_sel, 8'b0, {
    `WDATA_EX       ,ex_out_data,
    `WDATA_PC       ,snpc,
    `WDATA_REG     ,memregdata,
    `WDATA_UART  ,memuartdata
});

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
