module TJUT_DIV4(
    input             clk,
    input             rst,
    output          clk_div4
);

reg [1:0] cnt;

always @(posedge clk) begin
    if(rst) begin
        cnt <= 2'b00;
    end else begin
        cnt <= cnt + 2'b01;
    end
end

assign clk_div4 = cnt[0] != cnt[1] ? 1'b1 : 1'b0;

endmodule 
