`include "define.v"
module TJUT_ID(
    input   wire    [`INST_WIDTH-1:0]       inst,
    output  wire    [`EXCTRL_WIDTH-1:0]     ex_ctrl_sig,
    output  wire    [`WBCTRL_WIDTH-1:0]     wb_ctrl_sig,
    output  wire    [`IFCTRL_WIDTH-1:0]     if_ctrl_sig,
    output  wire    [`MCCTRL_WIDTH-1:0]     mc_ctrl_sig,
    output  wire                            breakpoint,
    output  wire                            invalid,
    output  wire    [`ADDER_WIDTH-1:0]      adder_rd,       //写回寄存器的地址
    output  wire    [`ADDER_WIDTH-1:0]      adder_src1, 
    output  wire    [`ADDER_WIDTH-1:0]      adder_src2,
    output  wire    [`DATA_WIDTH-1:0]       imm
);

// wire    [6:0]   opcode      = inst[6:0];
// wire    [2:0]   func3       = inst[14:12];
// wire    [6:0]   func7       = inst[31:25];
// wire    [5:0]   func6       = inst[31:26];
assign          adder_src1  = inst[19:15]; //第一个寄存器的地址
assign          adder_src2  = inst[24:20]; //第二个寄存器的地址
assign          adder_rd    = inst[11:7];  
assign          breakpoint  = ebreak; // 抛出断点调试，ebreak。
assign          invalid     = inst == 32'h0 ? 0 : ~valid;



/************************指令解码模块*******************/
// wire op_0010011     = (opcode == 7'b0010011);
// wire op_0010111     = (opcode == 7'b0010111);
// wire op_0110111     = (opcode == 7'b0110111);
// wire op_1101111     = (opcode == 7'b1101111);
// wire op_1100111     = (opcode == 7'b1100111);
// wire op_0100011     = (opcode == 7'b0100011);
// wire op_0000011     = (opcode == 7'b0000011);
// wire op_0110011     = (opcode == 7'b0110011);
// wire op_1100011     = (opcode == 7'b1100011);

// wire func3_000      = (func3 == 3'b000);
// wire func3_010      = (func3 == 3'b010);
// wire func3_011      = (func3 == 3'b011);
// wire func3_001      = (func3 == 3'b001);
// wire func3_100      = (func3 == 3'b100);
// wire func3_110      = (func3 == 3'b110);
// wire func3_101      = (func3 == 3'b101);
// wire func3_111      = (func3 == 3'b111);

// wire func6_010000   = (func6 == 6'b010000);
// wire func6_000000   = (func6 == 6'b000000);

// wire func7_0000000  = (func7 == 7'b0000000);
// wire func7_0100000  = (func7 == 7'b0100000);

// // 移位指令
// wire sll            = (op_0110011 & func3_001 & func7_0000000);
// wire slli           = (op_0010011 & func3_001 & func6_000000);
// wire srl            = (op_0110011 & func3_101 & func7_0000000);
// wire srli           = (op_0010011 & func3_101 & func6_000000);
// wire sra            = (op_0110011 & func3_101 & func7_0100000);
// wire srai           = (op_0010011 & func3_101 & func6_010000);

// // 算数指令
// wire add            = (op_0110011 & func3_000 & func7_0000000);
// wire addi           = (op_0010011 & func3_000);
// wire sub            = (op_0110011 & func3_000 & func7_0100000);
// wire lui            =  op_0110111;
// wire auipc          =  op_0010111;

// // 逻辑指令 为了避免和verilog中的关键字重复，因此在后面添加r表示是寄存器异或
// wire xorr           = (op_0110011 & func3_100 & func7_0000000);
// wire xori           = (op_0010011 & func3_100);
// wire orr            = (op_0110011 & func3_110 & func7_0000000);
// wire ori            = (op_0010011 & func3_110);
// wire andr           = (op_0110011 & func3_111 & func7_0000000);
// wire andi           = (op_0010011 & func3_111);

// // 比较指令
// wire slt            = (op_0110011 & func3_010 & func7_0000000);
// wire slti           = (op_0010011 & func3_010);
// wire sltu           = (op_0110011 & func3_011 & func7_0000000);
// wire sltiu          = (op_0010011 & func3_011);

// // 分支指令
// wire beq            = (op_1100011 & func3_000);
// wire bne            = (op_1100011 & func3_001);
// wire blt            = (op_1100011 & func3_100);
// wire bltu           = (op_1100011 & func3_110);
// wire bge            = (op_1100011 & func3_101);
// wire bgeu           = (op_1100011 & func3_111);

// // 跳转和链接指令
// wire jal            = op_1101111;
// wire jalr           = (op_1100111 & func3_000);

// // 环境指令
wire ebreak         = (inst == 32'b000000000001_00000_000_00000_1110011);

// // 储存指令
// wire lb             = (op_0000011 & func3_000);
// wire lh             = (op_0000011 & func3_001);
// wire lbu            = (op_0000011 & func3_100);
// wire lhu            = (op_0000011 & func3_101);
// wire lw             = (op_0000011 & func3_010);

// // 读取指令
// wire sb             = (op_0100011 & func3_000);
// wire sh             = (op_0100011 & func3_001);
// wire sw             = (op_0100011 & func3_010);

wire valid          = 0;



/*********************IF信号编码******************/
wire selpc          = 0;
assign if_ctrl_sig  = {selpc};



/**********************ex信号编码模块******************/
// ADD生成
wire ADD            = 0;

// SUB生成
wire SUB            = 0;

// LOGIC生成
wire LOGIC          = 0; 
wire log_xor        = 0;
wire log_or         = 0;
wire log_and        = 0;
wire [`LOGOP_WIDTH-1:0] log_op = {log_and, log_or, log_xor};

// SHIFT生成
wire SHIFT          = 0; 

// COMPARE生成
wire COMPARE        = 0; 

// BRANCH生成
wire BRANCH         = 0;
wire bra_eq         = 0;
wire bra_ne         = 0;
wire bra_gt         = 0;
wire bra_lt         = 0;
wire [`BRAOP_WIDTH-1:0] bra_op = {bra_lt, bra_gt, bra_ne, bra_eq};

// LUI指令
wire IMMLOAD        = 0;


// alu_op生成
wire [`ALUOP_WIDTH-1:0] alu_op = {IMMLOAD, BRANCH,COMPARE,SHIFT,LOGIC,SUB,ADD};

// 标志是否要将最低位置0 clear least significant bit
wire clrlsb         = 0;
wire is_signed      = 0; 
wire sft_dir        = 0;

// 选择操作数
// selalu1 默认为pc  ，即0，否则为src1； 
// selalu2 默认为imm，即0，否则为src2；
// 当selalu1/selalu2为1时，代表需要从寄存器中取出对应的值
wire selalu1        = 0;
wire selalu2        = 0;

// ex信号
assign ex_ctrl_sig  = {log_op, bra_op, alu_op, sft_dir, is_signed, clrlsb, selalu2, selalu1};



/**********************wb信号编码*****************/
// 判断是否需要保存snpc
wire regpc          = 0;
// 是否需要写回寄存器rd
wire regwen         = 0;
// 读使能
wire regrensrc1     = selalu1 | BRANCH;
wire regrensrc2     = selalu2 | memregsrc2 | BRANCH;
wire memregren      = 0; 
assign wb_ctrl_sig  = {memregren, regpc, regwen, regrensrc1, regrensrc2};



/*********************mc信号编码************************/
wire memwen         = 0;
wire memren         = 0;

wire sign_extend    = 0;

// wmask是写入数据的字节数。
wire [`WMASK_WIDTH-1:0] wmask = {1'b1,1'b1,1'b1};

// rmask是读取数据的字节数
wire [`RMASK_WIDTH-1:0] rmask = {1'b1,1'b1,1'b1};

// 读寄存器2的值
wire memregsrc2     = 0; 

assign mc_ctrl_sig  = {wmask, rmask, sign_extend, memwen, memren};


/***********************立即数生成模块*******************/
//立即数部分
wire imm_u = 0;
wire imm_i = 0;
wire imm_j = 0;
wire imm_s = 0;
wire imm_b = 0;

wire [`DATA_WIDTH-1:0] imm_i_data = {{20{inst[31]}}, inst[31:20]};
wire [`DATA_WIDTH-1:0] imm_u_data = {inst[31:12],12'b0};
wire [`DATA_WIDTH-1:0] imm_j_data = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
wire [`DATA_WIDTH-1:0] imm_s_data = {{20{inst[31]}}, inst[31:25], inst[11:7]};
wire [`DATA_WIDTH-1:0] imm_b_data = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};

assign imm = (
      ({32{imm_u}} & imm_u_data)
    | ({32{imm_i}} & imm_i_data)
    | ({32{imm_j}} & imm_j_data)
    | ({32{imm_s}} & imm_s_data)
    | ({32{imm_b}} & imm_b_data)
);

endmodule 
