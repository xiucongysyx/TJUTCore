`include "define.v"
module TJUT_UART_SEND(
    input                       clk,
    input                       rstn,
    input       [`DATA_WIDTH-1:0]       uart_din,
    input                       tx_en,
    output                    uart_txd_done,
    output  reg            uart_txd
);

localparam BPS_CNT = 434;

wire start_flag;
reg uart_txd_valid;

reg tx_en_d0;
reg tx_en_d1;
reg tx_flag;
reg [8:0] bps_cnt;
reg [3:0] tx_cnt;
reg [7:0] tx_data;

assign start_flag = tx_en_d0 && !tx_en_d1;
assign  uart_txd_done = (tx_cnt == 4'd9) && (bps_cnt == BPS_CNT-1);

always @(posedge clk) begin
    if(!rstn) begin
        tx_en_d0 <= 1'b0;
        tx_en_d1 <= 1'b0;
    end else begin
        tx_en_d0 <= tx_en;
        tx_en_d1 <= tx_en_d0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        uart_txd_valid <= 1'b0;
    end else if(bps_cnt == BPS_CNT-1 && tx_cnt == 9) begin
        uart_txd_valid <= 1'b0;
    end else if(start_flag) begin
        uart_txd_valid <= 1'b1;
    end else begin
        uart_txd_valid <= uart_txd_valid;
    end
end

// 这里bps_cnt 一直计数，功耗会很大
always @(posedge clk) begin
    if(!rstn) begin
        bps_cnt <= 9'b0;
        tx_cnt <= 4'd0;
    end else if(start_flag) begin
        bps_cnt <= 9'd0;
        tx_cnt <= 4'd0;
    end else if(uart_txd_valid) begin
        if(bps_cnt < BPS_CNT - 1'b1) begin
            bps_cnt <= bps_cnt + 1'b1;
            tx_cnt <= tx_cnt;
        end else begin
            bps_cnt <= 9'd0;
            tx_cnt <= tx_cnt + 1'b1;
        end
    end else begin
        bps_cnt <= 9'b0;
        tx_cnt <= 4'd0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        tx_flag <= 1'b0;
        tx_data <= 8'd0;
    end else if(start_flag) begin
        tx_flag <= 1'b1;
        tx_data <= uart_din;
    end else if(tx_cnt == 4'd9 && bps_cnt == BPS_CNT-1) begin
        tx_flag <= 1'b0;
        tx_data <= 8'd0;
    end else begin
        tx_flag <= tx_flag;
        tx_data <= tx_data;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        uart_txd <= 1'b1;
    end else if(tx_flag) begin
        case(tx_cnt)
            4'd0: uart_txd <= 1'b0;
            4'd1: uart_txd <= tx_data[0];
            4'd2: uart_txd <= tx_data[1];
            4'd3: uart_txd <= tx_data[2];
            4'd4: uart_txd <= tx_data[3];
            4'd5: uart_txd <= tx_data[4];
            4'd6: uart_txd <= tx_data[5];
            4'd7: uart_txd <= tx_data[6];
            4'd8: uart_txd <= tx_data[7];
        default: uart_txd <= 1'b1;
    endcase
    end
end

endmodule 
