`include "define.v"
module TJUT_COMPARE(
	input   [`DATA_WIDTH-1:0]      com_data1,
	input   [`DATA_WIDTH-1:0]      com_data2,
	input 												 is_signed,
	output  [`COM_RESULT-1:0]      com_results 
);

/*****************adder_data2补码********************/
wire [`DATA_WIDTH-1:0] adder_data1 = com_data1;
wire [`DATA_WIDTH-1:0] adder_data2 = (8'hff ^ com_data2);


/****************定义gp信号***************************/
wire [`DATA_WIDTH-2:0] level1G; //等级1的g、p
wire [`DATA_WIDTH-2:0] level1P;

/*******************生成GP的函数******************/
function  Gij;
	input Gik;
	input Pik;
	input Gk_1j;
	begin
		Gij = Gik | (Pik & Gk_1j);
	end
endfunction

function  Pij;
	input Pik;
	input Pk_1j;
	begin
		Pij = Pik & Pk_1j;
	end
endfunction

function  Sum;
	input Ai;
  input Bi;
	input G0j;
	input P0j;
	input Cin;
	begin
		Sum = (G0j | (P0j & Cin)) ^ Ai ^ Bi;
	end
endfunction

function  Carry;
	input G_i_to_0;
	input P_i_to_0;
	input Cin;
	begin
		Carry = (P_i_to_0 & Cin) | G_i_to_0;
	end
endfunction


//生成g、p信号 保存在level1中
genvar i;
generate
	for(i=0;i<7;i=i+1) begin
		assign level1G[i] = adder_data1[i] & adder_data2[i]; //g[i,i] = adder_data1iadder_data2i
		assign level1P[i] = adder_data1[i] ^ adder_data2[i]; //p[i,i] = adder_data1i ? adder_data2i
	end
endgenerate

//第一次合并
wire level2G_1  = Gij(level1G[1 ], level1P[1 ], level1G[0 ]);
wire level2P_1  = Pij(level1P[1 ], level1P[0 ]);
wire level2G_3  = Gij(level1G[3 ], level1P[3 ], level1G[2 ]);
wire level2P_3  = Pij(level1P[3 ], level1P[2 ]);
wire level2G_4  = Gij(level1G[4 ], level1P[4 ], level1G[3 ]);
wire level2P_4  = Pij(level1P[4 ], level1P[3 ]);
wire level2G_6  = Gij(level1G[6 ], level1P[6 ], level1G[5 ]);
wire level2P_6  = Pij(level1P[6 ], level1P[5 ]);

//第二次合并
wire level3G_3 = Gij(level2G_3, level2P_3, level2G_1);
wire level3P_3 = Pij(level2P_3, level2P_1);
wire level3G_6 = Gij(level2G_6, level2P_6, level2G_4);
wire level3P_6 = Pij(level2P_6, level2P_4);

//第三次合并
wire level4G_6 = Gij(level3G_6, level3P_6, level3G_3);
wire level4P_6 = Pij(level3P_6, level3P_3);

wire adder_out_7 = Sum(adder_data1[7],adder_data2[7],level4G_6,level4P_6,1'b1);


/********************获得比较结果**********************/
// 判断两个输入符号是否一致
wire ne_signed 	= com_data1[7] ^ com_data2[7];
// 有符号数
wire com_lt_s 	= ne_signed ? (com_data1[7] & ~com_data2[7]) : adder_out_7;
// 无符号数
wire com_lt_u 	= ne_signed ? (~com_data1[7] & com_data2[7]) : adder_out_7;
// 等于
wire com_eq = com_data1 == com_data2;
// 有符号还是无符号
wire com_lt = is_signed ? com_lt_s : com_lt_u;

assign com_results = {com_eq, com_lt};

endmodule

