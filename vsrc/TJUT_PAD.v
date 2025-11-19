`include "define.v"
module TJUT_PAD(
    input   wire				clk_pad,
    input   wire				rstn_pad,
    input  wire				instload_pad,
    output  wire				breakpoint_pad,
    input wire				uart_rxd_pad,
    output wire				uart_txd_pad,
    
    inout wire  [`DATA_WIDTH-1:0]            gpio1_pad,
    inout wire   [`DATA_WIDTH-1:0]           gpio2_pad

);
     wire   [`DATA_WIDTH-1:0]				gpio1_dir_n_core;
     wire   [`DATA_WIDTH-1:0]				gpio2_dir_n_core;

     wire  [`DATA_WIDTH-1:0]				gpio1_out_core;
     wire  [`DATA_WIDTH-1:0]				gpio2_out_core;

     wire [`DATA_WIDTH-1:0]				gpio1_in_core;
     wire [`DATA_WIDTH-1:0]              		gpio2_in_core;

TJUT_TOP u_TJUT_TOP(
    .clk        (clk_core        ),
    .rstn       (rstn_core       ),
    .instload   (instload_core   ),
    .breakpoint (breakpoint_core ),
    .uart_rxd   (uart_rxd_core   ),
    .uart_txd   (uart_txd_core   ),
    .gpio1_dir_n  (gpio1_dir_n_core  ),
    .gpio2_dir_n  (gpio2_dir_n_core  ),
    .gpio1_out  (gpio1_out_core  ),
    .gpio2_out  (gpio2_out_core  ),
    .gpio1_in   (gpio1_in_core   ),
    .gpio2_in   (gpio2_in_core   )
);
endmodule
