`include "define.v"
module TJUT_REGFILE (
  input                       clk,
  input   [`DATA_WIDTH-1:0]   wdata,
  input   [`ADDER_WIDTH-1:0]  waddr,
  input                       regwen,
  output  [`DATA_WIDTH-1:0]   rdatasrc1,
  output  [`DATA_WIDTH-1:0]   rdatasrc2,
  input   [`ADDER_WIDTH-1:0]  raddrsrc1,
  input   [`ADDER_WIDTH-1:0]  raddrsrc2,
  input                       regrensrc1,
  input                       regrensrc2
);
  reg     [`DATA_WIDTH-1:0] rf [31:0];
  wire    [`DATA_WIDTH-1:0] reg_zero = 8'b0;


  wire    [`DATA_WIDTH-1:0] reg_data_src1 = rf[raddrsrc1];
  wire    [`DATA_WIDTH-1:0] rdata_pre_src1 = (raddrsrc1 == 5'h0 ? reg_zero : reg_data_src1);
  assign  rdatasrc1 = (regrensrc1 == 1'b1 ? rdata_pre_src1 : 8'b0);
  
  wire    [`DATA_WIDTH-1:0] reg_data_src2 = rf[raddrsrc2];
  wire    [`DATA_WIDTH-1:0] rdata_pre_src2 = (raddrsrc2 == 5'h0 ? reg_zero : reg_data_src2);
  assign  rdatasrc2 = (regrensrc2 == 1'b1 ? rdata_pre_src2 : 8'b0);
  
  always @(posedge clk) begin
    if(regwen) begin 
       rf[waddr] <= wdata;
       rf[0] <= 8'h0;
    end
  end
endmodule
