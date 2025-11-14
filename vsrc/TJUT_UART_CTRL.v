`include "define.v"
module TJUT_UART_CTRL(
    input                clk,
    input               rstn,
    input               instload,

    input [`MCCTRL_WIDTH-1:0]   mc_ctrl_sig,

    input              uart_rxd,
    output           uart_txd,
    output           rx_done,

    input     [`DATA_WIDTH-1:0]          ex_out_data, //addr
    input    [`DATA_WIDTH-1:0]            src2, //uart_din
    output  reg [`DATA_WIDTH-1:0]           memuartdata 
);

//cache/fifo 相关信号
reg [`DATA_WIDTH-1:0] uart_din_cache [15:0];
reg [3:0] cache_wcnt;
reg [3:0] cache_rcnt;
wire cache_not_empty;

reg [1:0] cache_w_cnt;
reg         cache_w_en;

wire uart_txd_done;
wire [`DATA_WIDTH-1:0] uart_din;
wire [`DATA_WIDTH-1:0] uart_data;
reg tx_en;

//发送控制状态机
parameter IDLE = 3'b001;
parameter GENTXEN = 3'b010;
parameter WAITTXEND = 3'b100;

reg [2:0] cs, ns;

always @(posedge clk) begin
    if(!rstn) begin
        cache_w_cnt <= 2'b0;
    end else begin
        cache_w_cnt <= cache_w_cnt + 1'b1;
    end
end

assign cache_w_en = (cache_w_cnt == 2'b11);

always @(posedge clk) begin
    if(!rstn) begin
        cache_wcnt <= 4'd0;
    end else if(cache_w_en && ex_out_data == 8'hFE && mc_ctrl_sig[1]) begin
        uart_din_cache[cache_wcnt] <= src2;
        cache_wcnt <= cache_wcnt + 4'd1;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        memuartdata <= 8'b0;
    end else if((ex_out_data == 8'hFE && mc_ctrl_sig[0]) || instload) begin
        memuartdata <= uart_data;
    end else begin
        memuartdata <= 8'b0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        cache_rcnt <= 4'd0;
    end else if(uart_txd_done) begin
        cache_rcnt <= cache_rcnt + 4'd1;
    end
end

assign cache_not_empty = (cache_wcnt != cache_rcnt);
assign uart_din = uart_din_cache[cache_rcnt];

always @(posedge clk) begin
    if(!rstn) begin
        cs <= IDLE;
    end else begin
        cs <= ns;
    end
end

always @(*) begin
    ns = cs;
    case (cs)
        IDLE: begin
            if(cache_not_empty) begin
                ns = GENTXEN;
            end
        end
        GENTXEN: begin
            ns = WAITTXEND;
        end
        WAITTXEND: begin
            if(uart_txd_done) begin
                ns = IDLE;
            end
        end
        default: ns = IDLE;
    endcase
end

always @(*) begin
    tx_en = 1'b0;
    if(cs == GENTXEN) begin
        tx_en = 1'b1;
    end
end

integer i;
always @(posedge clk) begin
    if(!rstn) begin
        for (i = 0; i < 16; i = i+1) begin
            uart_din_cache[i] <= 8'h0;
        end
    end
end

TJUT_UART_RECV u_TJUT_UART_RECV(
    .clk      (clk      ),
    .rstn     (rstn     ),
    .uart_rxd (uart_rxd ),
    .uart_data (uart_data ),
    .rx_done (rx_done)
);

TJUT_UART_SEND u_TJUT_UART_SEND(
    .clk      (clk      ),
    .rstn     (rstn     ),
    .uart_din (uart_din ),
    .tx_en    (tx_en    ),
    .uart_txd_done (uart_txd_done),
    .uart_txd (uart_txd )
);

endmodule
