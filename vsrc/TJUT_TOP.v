`include "define.v"
module TJUT_TOP(
    input   wire                        clk,
    input   wire                        rstn,
    input  wire                         instload,
    output  wire                      breakpoint,
    output wire                       invalid,
    input wire                         uart_rxd,
    output wire                       uart_txd,
    
output wire   [`DATA_WIDTH-1:0]         gpio1_dir,
output wire   [`DATA_WIDTH-1:0]         gpio2_dir,

output wire  [`DATA_WIDTH-1:0]          gpio1_out,
output wire  [`DATA_WIDTH-1:0]          gpio2_out,
input wire [`DATA_WIDTH-1:0]              gpio1_in,
input wire [`DATA_WIDTH-1:0]              gpio2_in
);


wire                                            clk_div4;

wire [`INST_WIDTH-1:0]      inst;
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

wire [`DATA_WIDTH-1:0] memuartdata;
wire rx_done;

wire [`PC_WIDTH-1:0] pc;
wire [`PC_WIDTH-1:0] instpc;
wire [`DATA_WIDTH-1:0] inst_seg_data;

wire [`DATA_WIDTH-1:0] gpiodata;
wire gpio_sel;

TJUT_IF u_TJUT_IF(
    .clk           (clk           ),
    .rstn          (rstn          ),
    .instload (instload),
    .if_ctrl_sig   (if_ctrl_sig   ),
    .ex_out_data   (ex_out_data   ),
    .inst_seg_data (inst_seg_data ),
    .pc            (pc            ),
    .snpc          (snpc          ),
    .instpc        (instpc        ),
    .inst          (inst          )
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
    .clk        (clk_div4        ),
    .ex_out_data(ex_out_data),
    .snpc       (snpc       ),
    .memregdata (memregdata ),
    .memuartdata(memuartdata),
    .gpiodata (gpiodata),
    .gpio_sel (gpio_sel),
    .adder_rd   (adder_rd   ),
    .adder_src1 (adder_src1 ),
    .adder_src2 (adder_src2 ),
    .wb_ctrl_sig(wb_ctrl_sig),
    .src1       (src1       ),
    .src2       (src2       )
);

TJUT_MC u_TJUT_MC(
    .clk_div4      (clk_div4      ),
    .rstn          (rstn          ),
    .mc_ctrl_sig   (mc_ctrl_sig   ),
    .ex_out_data   (ex_out_data   ),
    .src2          (src2          ),
    .instpc        (instpc        ),
    .memregdata    (memregdata    ),
    .inst_seg_data (inst_seg_data ),
    .instload      (instload      ),
    .memuartdata   (memuartdata   ),
    .rx_done       (rx_done       )
);

TJUT_UART_CTRL u_TJUT_UART_CTRL(
    .clk         (clk         ),
    .rstn        (rstn        ),
    .instload (instload),
    .mc_ctrl_sig (mc_ctrl_sig ),
    .uart_rxd    (uart_rxd    ),
    .uart_txd    (uart_txd    ),
    .rx_done     (rx_done     ),
    .ex_out_data (ex_out_data ),
    .src2        (src2        ),
    .memuartdata (memuartdata )
);

TJUT_GPIO u_TJUT_GPIO(
    .clk         (clk         ),
    .rstn        (rstn        ),
    .ex_out_data (ex_out_data ),
    .src2        (src2        ),
    .gpiodata    (gpiodata    ),
    .mc_ctrl_sig (mc_ctrl_sig ),
    .gpio_sel (gpio_sel),
    .gpio1_dir (gpio1_dir),
    .gpio2_dir (gpio2_dir),
    .gpio1_out (gpio1_out),
    .gpio2_out (gpio2_out),
    .gpio1_in (gpio1_in),
    .gpio2_in (gpio2_in)
);


TJUT_DIV4 u_TJUT_DIV4(
    .clk    (clk   ),
    .rstn   (rstn  ),
    .clk_div4(clk_div4)
);


endmodule

