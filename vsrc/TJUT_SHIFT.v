`include "define.v"
module TJUT_SHIFT(
  input       [`DATA_WIDTH-1:0]  sft_data,
  input       [`SHIFT_WIDTH-1:0] sft_num,
  input                          sft_dir,
  input                          is_signed,
  output      reg [`DATA_WIDTH-1:0]  sft_result
);

always @( * ) begin
  if (sft_dir == 1'b0) begin
    case(sft_num)
      3'b000: sft_result = sft_data;
      3'b001: sft_result = {sft_data[6:0], 1'b0};
      3'b010: sft_result = {sft_data[5:0], 2'b00};
      3'b011: sft_result = {sft_data[4:0], 3'b000};
      3'b100: sft_result = {sft_data[3:0], 4'b0000};
      3'b101: sft_result = {sft_data[2:0], 5'b00000};
      3'b110: sft_result = {sft_data[1:0], 6'b000000};
      3'b111: sft_result = {sft_data[0], 7'b0000000};
    endcase   
  end else begin
    if(is_signed == 1'b1) begin
      case(sft_num)
        3'b000: sft_result = sft_data;
        3'b001: sft_result = {sft_data[7], sft_data[7:1]};
        3'b010: sft_result = {{2{sft_data[7]}}, sft_data[7:2]};
        3'b011: sft_result = {{3{sft_data[7]}}, sft_data[7:3]};
        3'b100: sft_result = {{4{sft_data[7]}}, sft_data[7:4]};
        3'b101: sft_result = {{5{sft_data[7]}}, sft_data[7:5]};
        3'b110: sft_result = {{6{sft_data[7]}}, sft_data[7:6]};
        3'b111: sft_result = {{7{sft_data[7]}}, sft_data[7]};
      endcase
    end else begin
      case(sft_num)
        3'b000: sft_result = sft_data;
        3'b001: sft_result = {1'b0, sft_data[7:1]};
        3'b010: sft_result = {2'b00, sft_data[7:2]};
        3'b011: sft_result = {3'b000, sft_data[7:3]};
        3'b100: sft_result = {4'b0000, sft_data[7:4]};
        3'b101: sft_result = {5'b00000, sft_data[7:5]};
        3'b110: sft_result = {6'b000000, sft_data[7:6]};
        3'b111: sft_result = {7'b0000000, sft_data[7]};
      endcase
    end
  end
end
endmodule
