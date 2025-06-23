`include "define.v"
module TJUT_SHIFT(
  input       [`DATA_WIDTH-1:0]  sft_data,
  input       [`SHIFT_WIDTH-1:0] sft_num,
  input                          sft_dir,
  input                          is_signed,
  output      [`DATA_WIDTH-1:0]  sft_result
);


assign sft_result = sft_dir == 1'b1 ? is_signed == 1'b1 ? sft_num == 6'd1 ? sft_data : 32'd0 : 32'd0 : 32'd0;

endmodule
