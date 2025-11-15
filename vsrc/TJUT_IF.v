`include "define.v"
module TJUT_IF(
    input   wire                        clk,
    input   wire                        rstn,
    input  wire                         instload,
    input   wire    [`IFCTRL_WIDTH-1:0] if_ctrl_sig,
    input   wire    [`DATA_WIDTH-1:0]   ex_out_data,
    input   wire    [`DATA_WIDTH-1:0]  inst_seg_data,
    output  reg     [`PC_WIDTH-1:0]     pc,
    output  reg    [`PC_WIDTH-1:0]    snpc, 
    output wire   [`PC_WIDTH-1:0]    instpc,
    output  reg   [`INST_WIDTH-1:0]   inst
);

// IF 控制信号解码 下一个PC信号
wire                                            selpc = if_ctrl_sig[0];
wire [`PC_WIDTH-1:0]         dnpc = ~instload ? (selpc ? ex_out_data : snpc) : 8'h0;              
reg [`PC_WIDTH-1:0]           instpc_reg;

// 指令读取
parameter INST_SEG_DEFAULT = 4'b0000;
parameter INST_SEG_ONE = 4'b0001;
parameter INST_SEG_TWO = 4'b0010;
parameter INST_SEG_THREE = 4'b0011;
parameter INST_SEG_FOUR = 4'b0100;

reg [`INST_SEG-1:0] inst_seg_state;
reg  [`DATA_WIDTH-1:0]  inst_byte [`INST_SEG-2:0];
assign instpc = ~instload ? inst_seg_state == INST_SEG_ONE ? dnpc : instpc_reg : 8'h0;

always @(posedge clk) begin
    if(!rstn || instload) begin
        inst_seg_state <= INST_SEG_DEFAULT;
        inst_byte[0] <= 8'h00;
        inst_byte[1] <= 8'h00;
        inst_byte[2] <= 8'h00;
        inst <= 32'h00000000;
        pc <= 8'h00;
        snpc <= 8'h00;
    end else begin
        case(inst_seg_state) 
            INST_SEG_DEFAULT: begin
                inst_seg_state <= INST_SEG_ONE;
            end
            INST_SEG_ONE: begin
                inst_byte[0] <= inst_seg_data;
                inst_seg_state <= INST_SEG_TWO;
                instpc_reg <= dnpc + 8'h1;
            end
            INST_SEG_TWO: begin
                inst_byte[1] <= inst_seg_data;
                inst_seg_state <= INST_SEG_THREE;
                instpc_reg <= instpc_reg + 8'h1;
            end
            INST_SEG_THREE: begin
                inst_byte[2] <= inst_seg_data;
                inst_seg_state <= INST_SEG_FOUR;
                pc <=  selpc ? dnpc : snpc;
                instpc_reg <= instpc_reg + 8'h1;
            end
            INST_SEG_FOUR: begin
                inst <= {inst_seg_data, inst_byte[2], inst_byte[1], inst_byte[0]};
                inst_seg_state <= INST_SEG_ONE;
                snpc <= pc + 8'h4;
            end
            default: begin
                inst_seg_state <= INST_SEG_DEFAULT;
            end
        endcase
    end
end

endmodule


