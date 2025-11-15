`include "define.v"
module TJUT_TOP(
    input   wire                        tjut_clk,
    input   wire                        tjut_rstn,
    input  wire                         tjut_instload,
    output  wire                      tjut_breakpoint,
    output  wire                     tjut_invalid,
    input wire                         tjut_uart_rxd,
    output wire                       tjut_uart_txd,
    
    inout wire     [`DATA_WIDTH-1:0] tjut_gpio1,
    inout wire     [`DATA_WIDTH-1:0] tjut_gpio2

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
    .clk           (tjut_clk           ),
    .rstn          (tjut_rstn          ),
    .instload (tjut_instload),
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
    .breakpoint (tjut_breakpoint ),
    .invalid    (tjut_invalid    ),
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
    .rstn          (tjut_rstn          ),
    .mc_ctrl_sig   (mc_ctrl_sig   ),
    .ex_out_data   (ex_out_data   ),
    .src2          (src2          ),
    .instpc        (instpc        ),
    .memregdata    (memregdata    ),
    .inst_seg_data (inst_seg_data ),
    .instload      (tjut_instload      ),
    .memuartdata   (memuartdata   ),
    .rx_done       (rx_done       )
);

TJUT_UART_CTRL u_TJUT_UART_CTRL(
    .clk         (tjut_clk         ),
    .rstn        (tjut_rstn        ),
    .instload (tjut_instload),
    .mc_ctrl_sig (mc_ctrl_sig ),
    .uart_rxd    (tjut_uart_rxd    ),
    .uart_txd    (tjut_uart_txd    ),
    .rx_done     (rx_done     ),
    .ex_out_data (ex_out_data ),
    .src2        (src2        ),
    .memuartdata (memuartdata )
);

TJUT_GPIO u_TJUT_GPIO(
    .clk         (tjut_clk         ),
    .rstn        (tjut_rstn        ),
    .ex_out_data (ex_out_data ),
    .src2        (src2        ),
    .gpiodata    (gpiodata    ),
    .mc_ctrl_sig (mc_ctrl_sig ),
    .gpio_sel (gpio_sel),
    .gpio_io1    (tjut_gpio1    ),
    .gpio_io2    (tjut_gpio2    )
);



TJUT_DIV4 u_TJUT_DIV4(
    .clk    (tjut_clk   ),
    .rstn   (tjut_rstn  ),
    .clk_div4(clk_div4)
);


endmodule

