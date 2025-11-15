`include "define.v"
module TJUT_GPIO(
input               clk,
input               rstn,

input  [`DATA_WIDTH-1:0] ex_out_data,

input  [`DATA_WIDTH-1:0] src2,
output reg [`DATA_WIDTH-1:0] gpiodata,

output gpio_sel,

input [`MCCTRL_WIDTH-1:0] mc_ctrl_sig,

inout [`DATA_WIDTH-1:0] gpio_io1,
inout [`DATA_WIDTH-1:0] gpio_io2
);

reg [`DATA_WIDTH-1:0] gpio1_data;
reg [`DATA_WIDTH-1:0] gpio1_dir;

reg [`DATA_WIDTH-1:0] gpio2_data;
reg [`DATA_WIDTH-1:0] gpio2_dir;

reg [`DATA_WIDTH-1:0] gpio1_input;
reg [`DATA_WIDTH-1:0] gpio2_input;

genvar i;
generate
    for (i=0; i<8; i=i+1) begin : gpio_tristate
        assign gpio_io1[i] = gpio1_dir[i] ? gpio1_data[i] : 1'bz;
        assign gpio_io2[i] = gpio2_dir[i] ? gpio2_data[i] : 1'bz;
    end
endgenerate

wire gpio_we = mc_ctrl_sig[1];
wire gpio_re = mc_ctrl_sig[0];

wire gpio_sel_d1 = (ex_out_data == 8'hf6 || ex_out_data == 8'hf7 || ex_out_data == 8'hf8 || ex_out_data == 8'hf9 || ex_out_data == 8'hfa || ex_out_data == 8'hfb || ex_out_data == 8'hfc || ex_out_data == 8'hfd) ;
assign gpio_sel = mc_ctrl_sig[1] != mc_ctrl_sig[0] ? (gpio_sel_d1 == 1'b1 ? 1'b1 : 1'b0) : 1'b0;

always @(posedge clk) begin
    if(!rstn) begin
        gpio1_input <= 8'b0;
        gpio2_input <= 8'b0;
    end else begin
        gpio1_input <= gpio_io1;
        gpio2_input <= gpio_io2;
    end
end

always @(posedge clk) begin
    if(!rstn) begin
        gpio1_data <= 8'b0;
        gpio1_dir <= 8'b0;
        gpio1_data <= 8'b0;
        gpio1_dir <= 8'b0;
    end else if(gpio_we) begin
        case (ex_out_data)
            8'hfd: gpio1_data <= src2;
            8'hfc: gpio1_dir <= src2;
            
            8'hfa: gpio2_data <= src2;
            8'hf9: gpio2_dir <= src2;
            default: ;
        endcase
    end
end

always  @(*) begin
    if(!rstn) begin
        gpiodata = 8'b0;
    end else if(gpio_re) begin
        case (ex_out_data)
            8'hfd:gpiodata = gpio1_input;  
            8'hfc:gpiodata = gpio1_dir; 
            8'hfb:gpiodata = gpio1_data; 

            8'hfa:gpiodata = gpio2_input; 
            8'hf9:gpiodata = gpio2_dir; 
            8'hf8:gpiodata = gpio2_data; 
            default:;
        endcase
    end
end

endmodule
