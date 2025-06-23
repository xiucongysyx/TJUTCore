`include "define.v"
module TJUT_TOP(
    input   wire                        clk,
    input   wire                        rst,
    output  wire                        breakpoint,
    output  wire                        invalid,
    output  wire    [`PC_WIDTH-1:0]     pc  
);

wire [`DATA_WIDTH-1:0]      inst;
wire [`DATA_WIDTH-1:0]      src1;
wire [`DATA_WIDTH-1:0]      src2;
wire [`DATA_WIDTH-1:0]      imm;
wire [`DATA_WIDTH-1:0]      snpc;
wire [`DATA_WIDTH-1:0]      ex_out_data;
wire [`DATA_WIDTH-1:0]      memregdata;
wire [`ADDER_WIDTH-1:0]     adder_rd;
wire [`ADDER_WIDTH-1:0]     adder_src1;
wire [`ADDER_WIDTH-1:0]     adder_src2;

wire [`EXCTRL_WIDTH-1:0]    ex_ctrl_sig;
wire [`WBCTRL_WIDTH-1:0]    wb_ctrl_sig;
wire [`IFCTRL_WIDTH-1:0]    if_ctrl_sig;
wire [`MCCTRL_WIDTH-1:0]    mc_ctrl_sig;


TJUT_IF u_TJUT_IF(
    .clk        (clk         ),
    .rst        (rst         ),
    .if_ctrl_sig(if_ctrl_sig ),
    .ex_out_data(ex_out_data ),
    .pc         (pc          ),
    .snpc       (snpc        ),
    .inst       (inst        )
);

TJUT_ID u_TJUT_ID(
    .inst       (inst       ),
    .ex_ctrl_sig(ex_ctrl_sig),
    .wb_ctrl_sig(wb_ctrl_sig),
    .if_ctrl_sig(if_ctrl_sig),
    .mc_ctrl_sig(mc_ctrl_sig),
    .breakpoint (breakpoint ),
    .invalid    (invalid    ),
    .adder_rd   (adder_rd   ),
    .adder_src1 (adder_src1 ),
    .adder_src2 (adder_src2 ),
    .imm        (imm        )
);

TJUT_EX u_TJUT_EX(
    .pc         (pc         ),
    .snpc       (snpc       ),
    .src1       (src1       ),
    .src2       (src2       ),
    .imm        (imm        ),
    .ex_ctrl_sig(ex_ctrl_sig),
    .ex_out_data(ex_out_data)
);

TJUT_WB u_TJUT_WB(
    .clk        (clk        ),
    .ex_out_data(ex_out_data),
    .snpc       (snpc       ),
    .memregdata (memregdata ),
    .adder_rd   (adder_rd   ),
    .adder_src1 (adder_src1 ),
    .adder_src2 (adder_src2 ),
    .wb_ctrl_sig(wb_ctrl_sig),
    .src1       (src1       ),
    .src2       (src2       )
);

TJUT_MC u_TJUT_MC(
    .mc_ctrl_sig (mc_ctrl_sig ),
    .ex_out_data (ex_out_data ),
    .src2        (src2        ),
    .memregdata  (memregdata  )
);


endmodule

