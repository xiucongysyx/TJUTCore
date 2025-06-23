`include "define.v"
module TJUT_EX (
    input   [`PC_WIDTH-1:0]         pc,
    input   [`PC_WIDTH-1:0]         snpc,
    input   [`DATA_WIDTH-1:0]       src1,
    input   [`DATA_WIDTH-1:0]       src2,
    input   [`DATA_WIDTH-1:0]       imm,
    input   [`EXCTRL_WIDTH-1:0]     ex_ctrl_sig,

    output  [`DATA_WIDTH-1:0]       ex_out_data 
);

/******************解码ex控制信号**********************/
wire selalu1    = ex_ctrl_sig[0];
wire selalu2    = ex_ctrl_sig[1];
wire clrlsb     = ex_ctrl_sig[2];
wire is_signed  = ex_ctrl_sig[3];
wire sft_dir    = ex_ctrl_sig[4];

wire ADD        = alu_op[0];
wire SUB        = alu_op[1];
wire LOGIC      = alu_op[2];
wire SHIFT      = alu_op[3];
wire COMPARE    = alu_op[4];
wire BRANCH     = alu_op[5];

wire add        = ADD | BRANCH;
wire sub        = SUB;
wire compare    = COMPARE | BRANCH;
wire shift      = SHIFT;

wire com_lt     = com_results[0];
wire com_eq     = com_results[1];

wire log_xor    = log_op[0];
wire log_or     = log_op[1];
wire log_and    = log_op[2];

wire [`ALUOP_WIDTH-1:0] alu_op      = ex_ctrl_sig[`ALUOP_WIDTH-1+`EXCTRL_OTHER:`EXCTRL_OTHER];
wire [`BRAOP_WIDTH-1:0] bra_op      = ex_ctrl_sig[`BRAOP_WIDTH+`ALUOP_WIDTH+`EXCTRL_OTHER-1:`ALUOP_WIDTH+`EXCTRL_OTHER];
wire [`LOGOP_WIDTH-1:0] log_op      = ex_ctrl_sig[`LOGOP_WIDTH+`BRAOP_WIDTH+`ALUOP_WIDTH+`EXCTRL_OTHER-1:`BRAOP_WIDTH+`ALUOP_WIDTH+`EXCTRL_OTHER];


/******************32位加法模块*******************/
TJUT_ADDER u_TJUT_ADDER(
    .add_data1   (add_data1   ),
    .add_data2   (add_data2   ),
    .adder_sub   (sub         ),
    .adder_out   (add_result  )
);

TJUT_COMPARE u_TJUT_COMPARE(
    .com_data1  (com_data1  ),
    .com_data2  (com_data2  ),
    .is_signed  (is_signed  ),
    .com_results(com_results)
);

TJUT_SHIFT u_TJUT_SHIFT(
    .sft_data   (sft_data   ),
    .sft_num    (sft_num    ),
    .sft_dir    (SHIFT ? sft_dir : 1    ),
    .is_signed  (SHIFT ? is_signed : 1  ),
    .sft_result (sft_result )
);




/***************************算术运算*****************/
//确定加法器两位参数
wire [`DATA_WIDTH-1:0] alu_data1    = (selalu1 ? src1 : pc  );
wire [`DATA_WIDTH-1:0] alu_data2    = (selalu2 ? src2 : imm);
wire [`DATA_WIDTH-1:0] add_data1    = (add | sub ? alu_data1 : 32'b0);
wire [`DATA_WIDTH-1:0] add_data2    = (add | sub ? alu_data2 : 32'b0);

wire [`DATA_WIDTH-1:0] add_result;
wire [`DATA_WIDTH-1:0] sub_result   = sub ? add_result : 32'h0;



/********************逻辑运算***********************/
//and
wire [`DATA_WIDTH-1:0] logic_data1  = (LOGIC ? alu_data1 : 32'b0);
wire [`DATA_WIDTH-1:0] logic_data2  = (LOGIC ? alu_data2 : 32'b0);

wire [`DATA_WIDTH-1:0] and_result   = (log_and ? logic_data1 & logic_data2 : 32'h0);
//or
wire [`DATA_WIDTH-1:0] or_result    = (log_or ? logic_data1 | logic_data2 : 32'h0);
//xor
wire [`DATA_WIDTH-1:0] xor_result   = (log_xor ? logic_data1 ^ logic_data2 : 32'h0);

wire [`DATA_WIDTH-1:0] log_result;
`define LOG_XOR 3'b001
`define LOG_OR  3'b010
`define LOG_AND 3'b100
MuxKeyWithDefault #(6'd3, 6'd3, 6'd32) u2_MuxKeyWithDefault(log_result, log_op, 32'b0, {
    `LOG_XOR     , xor_result,
    `LOG_OR      , or_result,
    `LOG_AND     , and_result
});



/*********************移位运算*************************/
wire [`DATA_WIDTH-1:0]  sft_data     = (shift ? alu_data1 : 32'h0);
wire [`SHIFT_WIDTH-1:0] sft_num1     = (selalu2 ? {1'b0, alu_data2[4:0]} : alu_data2[5:0]);
wire [`SHIFT_WIDTH-1:0] sft_num      = (shift ? sft_num1  : 6'b0);
wire [`DATA_WIDTH-1:0]  sft_result;



/*********************比较运算************************/
//确定比较器两位参数
wire [`DATA_WIDTH-1:0] com_data1    = (compare ? src1 : 32'h0);
wire [`DATA_WIDTH-1:0] com_data3    = (BRANCH | (COMPARE & selalu2) ? src2 : imm);
wire [`DATA_WIDTH-1:0] com_data2    = (compare ? com_data3 : 32'h0);

wire [`COM_RESULT-1:0] com_results;
wire [`DATA_WIDTH-1:0] com_result   = {31'b0, com_lt};



/********************************跳转计算**************************/
wire [`DATA_WIDTH-1:0] bra_result;
wire [`DATA_WIDTH-1:0] eq_result    = (com_eq ? add_result : snpc);
wire [`DATA_WIDTH-1:0] ne_result    = (~com_eq ? add_result : snpc);
wire [`DATA_WIDTH-1:0] gt_result    = (~com_lt ? add_result : snpc);
wire [`DATA_WIDTH-1:0] lt_result    = (com_lt ? add_result : snpc);
`define BRA_EQ  4'b0001
`define BRA_NE  4'b0010
`define BRA_GT  4'b0100
`define BRA_LT  4'b1000
MuxKeyWithDefault #(6'd4, 6'd4, 6'd32) u1_MuxKeyWithDefault(bra_result, bra_op, 32'b0, {
    `BRA_EQ      , eq_result,
    `BRA_NE      , ne_result,
    `BRA_GT      , gt_result,
    `BRA_LT      , lt_result
});



/*******************************加载立即数******************************/
wire [`DATA_WIDTH-1:0] imm_result   = imm;


/*********************************选择结果***************************/
//输出暂存
wire [`DATA_WIDTH-1:0] ex_result;
assign ex_out_data  = clrlsb ? (ex_result & 32'hffff_fffe) : ex_result;

`define EX_ADD  7'b000_0001
`define EX_SUB  7'b000_0010
`define EX_COM  7'b001_0000
`define EX_BRA  7'b010_0000
`define EX_LOG  7'b000_0100
`define EX_SFT  7'b000_1000
`define EX_IMM  7'b100_0000


MuxKeyWithDefault #(6'd7, 6'd7, 6'd32) u0_MuxKeyWithDefault(ex_result, alu_op, 32'b0, {
    `EX_ADD      , add_result,
    `EX_SUB      , sub_result,
    `EX_COM      , com_result,
    `EX_BRA      , bra_result,
    `EX_LOG      , log_result,
    `EX_SFT      , sft_result,
    `EX_IMM      , imm_result
});

endmodule
