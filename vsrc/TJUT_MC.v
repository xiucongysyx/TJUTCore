`include "define.v"
module TJUT_MC(
  input clk_div4,
  input  [`MCCTRL_WIDTH-1:0]  mc_ctrl_sig,
  input  [`DATA_WIDTH-1:0]    ex_out_data,
  input  [`DATA_WIDTH-1:0]    src2,
  input  [`DATA_WIDTH-1:0]    instpc,
  output [`DATA_WIDTH-1:0]    memregdata,
  output [`DATA_WIDTH-1:0]    inst_seg_data
);

/*****************ex_out_sig解码*****************/
wire                      memren      = mc_ctrl_sig[0];
wire                      memwen      = mc_ctrl_sig[1];
assign memregdata = rdata;

TJUT_MEM u_TJUT_MEM(
    .clk_div4 (clk_div4),
    .instpc   (instpc),
    .inst_seg_data(inst_seg_data),
    .addr     (ex_out_data),
    .wdata    (src2      ),
    .rdata    (memregdata     ),
    .memren   (memren    ),
    .memwen   (memwen    )
);

endmodule
