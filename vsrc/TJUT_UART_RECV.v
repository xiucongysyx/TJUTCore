`include "define.v"
module TJUT_UART_RECV(
    input                   clk,
    input                   rstn,
    input                   uart_rxd,
    output  reg [7:0]      uart_data,
    output  reg              rx_done
);

localparam  BPS_CNT = 434;

wire start_flag;
reg start_flag_valid;

reg uart_rxd_d0;
reg uart_rxd_d1;
reg rx_flag;
reg [3:0] rx_cnt;
reg [8:0] bps_cnt;
reg [7:0] tx_data;

assign start_flag = ~uart_rxd_d0 && uart_rxd_d1;

always @(posedge clk) begin
    if(!rstn) begin
       uart_rxd_d0 <= 1'b0;
        uart_rxd_d1 <= 1'b0;
    end else begin
        uart_rxd_d0 <= uart_rxd;
        uart_rxd_d1 <= uart_rxd_d0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        start_flag_valid <= 1'b0;
    end else if(bps_cnt == BPS_CNT/2 && rx_cnt == 4'd0 && uart_rxd_d1== 1'b1) begin
        start_flag_valid <= 1'b1;
    end else begin
        start_flag_valid <= 1'b0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        rx_flag <= 1'b0;
    end else begin
        if(start_flag) begin
            rx_flag <= 1'b1;
        end else if(start_flag_valid) begin
            rx_flag <= 1'b0;
        end else if((bps_cnt == BPS_CNT/2) && (rx_cnt == 4'd9)) begin
            rx_flag <= 1'b0;
        end else begin
            rx_flag <= rx_flag;
        end
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        bps_cnt <= 9'b0;
        rx_cnt <= 4'b0;
    end else if(rx_flag) begin
        if(bps_cnt < BPS_CNT - 1'b1) begin
            bps_cnt <= bps_cnt + 1'b1;
            rx_cnt <= rx_cnt;
        end else begin
            bps_cnt <= 9'b0;
            rx_cnt <= rx_cnt + 1'b1;
        end
    end else begin
        bps_cnt <= 9'b0;
        rx_cnt <= 4'b0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        tx_data <= 8'd0;
    end else if(rx_flag) begin
        if(bps_cnt == BPS_CNT/2) begin
            case(rx_cnt)
                4'd1: tx_data[0] <= uart_rxd_d1;
                4'd2: tx_data[1] <= uart_rxd_d1;
                4'd3: tx_data[2] <= uart_rxd_d1;
                4'd4: tx_data[3] <= uart_rxd_d1;
                4'd5: tx_data[4] <= uart_rxd_d1;
                4'd6: tx_data[5] <= uart_rxd_d1;
                4'd7: tx_data[6] <= uart_rxd_d1;
                4'd8: tx_data[7] <= uart_rxd_d1;
                default: ;
            endcase
        end else begin
            tx_data <= tx_data;
        end
    end else begin
        tx_data <= 8'd0;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        uart_data <= 8'd0;
        rx_done <= 1'b0;
    end else if(rx_cnt == 4'd9 && bps_cnt == BPS_CNT -1) begin
        uart_data <= tx_data;
        rx_done <= 1'b1;
    end else begin
        uart_data <= uart_data;
        rx_done <= 1'b0;
    end
end

endmodule
