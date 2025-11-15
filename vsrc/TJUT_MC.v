`include "define.v"
module TJUT_MC(
  input clk_div4,
  input rstn,

  input  [`MCCTRL_WIDTH-1:0]  mc_ctrl_sig,
  input  [`DATA_WIDTH-1:0]    ex_out_data,
  input  [`DATA_WIDTH-1:0]    src2,
  input  [`DATA_WIDTH-1:0]    instpc,
  output [`DATA_WIDTH-1:0]    memregdata,
  output [`DATA_WIDTH-1:0]    inst_seg_data,

  //load inst io
  input instload,
  input [`DATA_WIDTH-1:0]  memuartdata,
  input rx_done
);

reg [`PC_WIDTH-1:0] instaddr;

reg rx_done_d0;
reg rx_done_d1;
wire rx_done_rise = rx_done_d0 & ~rx_done_d1; 
/*****************ex_out_sig解码*****************/
wire                      memren      = mc_ctrl_sig[0];
wire                      memwen      = instload ? rx_done_rise : mc_ctrl_sig[1];
wire        [`DATA_WIDTH-1:0]              wdata =  instload ? memuartdata : src2;
wire  [`DATA_WIDTH-1:0] addr = instload ? instaddr : ex_out_data;

always @(posedge clk_div4) begin
  if(!rstn) begin
    rx_done_d0 <= 1'b0;
    rx_done_d1 <= 1'b0;
  end else begin
    rx_done_d0 <= rx_done;
    rx_done_d1 <= rx_done_d0;
  end
end

always @(posedge clk_div4) begin
  if(!rstn) begin
    instaddr <= 8'h00;
  end else if(rx_done_rise) begin
    instaddr <= instaddr + 1'b1;
  end else begin
    instaddr <= instaddr;
  end
end



TJUT_MEM u_TJUT_MEM(
    .clk_div4 (clk_div4),
    .instpc   (instpc),
    .inst_seg_data(inst_seg_data),
    .addr     (addr),
    .wdata    (wdata      ),
    .rdata    (memregdata     ),
    .memren   (memren    ),
    .memwen   (memwen    )
);

endmodule
