`include "define.v"
module TJUT_COMPARE(
	input   [`DATA_WIDTH-1:0]      com_data1,
	input   [`DATA_WIDTH-1:0]      com_data2,
	input 												 is_signed,
	output  [`COM_RESULT-1:0]      com_results 
);

/*****************adder_data2补码********************/
wire [`DATA_WIDTH-1:0] adder_data1 = com_data1;
wire [`DATA_WIDTH-1:0] adder_data2 = (32'hffff_ffff ^ com_data2);


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
	for(i=0;i<31;i=i+1) begin
		assign level1G[i] = adder_data1[i] & adder_data2[i]; //g[i,i] = adder_data1iadder_data2i
		assign level1P[i] = adder_data1[i] ^ adder_data2[i]; //p[i,i] = adder_data1i ? adder_data2i
	end
endgenerate

//第一次合并
wire level2P_0 = level1P[0];
wire level2G_0 = level1G[0];
wire level2G_30 = Gij(level1G[30], level1P[30], level1G[29]);
wire level2P_30 = Pij(level1P[30], level1P[29]);        
wire level2G_28 = Gij(level1G[28], level1P[28], level1G[27]);
wire level2P_28 = Pij(level1P[28], level1P[27]);        
wire level2G_26 = Gij(level1G[26], level1P[26], level1G[25]);
wire level2P_26 = Pij(level1P[26], level1P[25]);        
wire level2G_24 = Gij(level1G[24], level1P[24], level1G[23]);
wire level2P_24 = Pij(level1P[24], level1P[23]);        
wire level2G_22 = Gij(level1G[22], level1P[22], level1G[21]);
wire level2P_22 = Pij(level1P[22], level1P[21]);        
wire level2G_20 = Gij(level1G[20], level1P[20], level1G[19]);
wire level2P_20 = Pij(level1P[20], level1P[19]);        
wire level2G_18 = Gij(level1G[18], level1P[18], level1G[17]);
wire level2P_18 = Pij(level1P[18], level1P[17]);        
wire level2G_16 = Gij(level1G[16], level1P[16], level1G[15]);
wire level2P_16 = Pij(level1P[16], level1P[15]);        
wire level2G_14 = Gij(level1G[14], level1P[14], level1G[13]);
wire level2P_14 = Pij(level1P[14], level1P[13]);        
wire level2G_12 = Gij(level1G[12], level1P[12], level1G[11]);
wire level2P_12 = Pij(level1P[12], level1P[11]);        
wire level2G_10 = Gij(level1G[10], level1P[10], level1G[9 ]);
wire level2P_10 = Pij(level1P[10], level1P[9 ]);        
wire level2G_8  = Gij(level1G[8 ], level1P[8 ], level1G[7 ]);
wire level2P_8  = Pij(level1P[8 ], level1P[7 ]);        
wire level2G_6  = Gij(level1G[6 ], level1P[6 ], level1G[5 ]);
wire level2P_6  = Pij(level1P[6 ], level1P[5 ]);        
wire level2G_4  = Gij(level1G[4 ], level1P[4 ], level1G[3 ]);
wire level2P_4  = Pij(level1P[4 ], level1P[3 ]);        
wire level2G_2  = Gij(level1G[2 ], level1P[2 ], level1G[1 ]);
wire level2P_2  = Pij(level1P[2 ], level1P[1 ]);

//第二次合并
wire level3G_30 = Gij(level2G_30, level2P_30, level2G_28);
wire level3P_30 = Pij(level2P_30, level2P_28);
wire level3G_26 = Gij(level2G_26, level2P_26, level2G_24);
wire level3P_26 = Pij(level2P_26, level2P_24);
wire level3G_22 = Gij(level2G_22, level2P_22, level2G_20);
wire level3P_22 = Pij(level2P_22, level2P_20);
wire level3G_18 = Gij(level2G_18, level2P_18, level2G_16);
wire level3P_18 = Pij(level2P_18, level2P_16);
wire level3G_14 = Gij(level2G_14, level2P_14, level2G_12);
wire level3P_14 = Pij(level2P_14, level2P_12);
wire level3G_10 = Gij(level2G_10, level2P_10, level2G_8);
wire level3P_10 = Pij(level2P_10, level2P_8);
wire level3G_6 = Gij(level2G_6, level2P_6, level2G_4);
wire level3P_6 = Pij(level2P_6, level2P_4);
wire level3G_2 = Gij(level2G_2, level2P_2, level2G_0);
wire level3P_2 = Pij(level2P_2, level2P_0);

//第三次合并
wire level4G_30 = Gij(level3G_30, level3P_30, level3G_26);
wire level4P_30 = Pij(level3P_30, level3P_26);
wire level4G_22 = Gij(level3G_22, level3P_22, level3G_18);
wire level4P_22 = Pij(level3P_22, level3P_18);
wire level4G_14 = Gij(level3G_14, level3P_14, level3G_10);
wire level4P_14 = Pij(level3P_14, level3P_10);
wire level4G_6 	= Gij(level3G_6, level3P_6, level3G_2);
wire level4P_6 	= Pij(level3P_6, level3P_2);

//第四次合并
wire level5G_30 = Gij(level4G_30, level4P_30, level4G_22);
wire level5P_30 = Pij(level4P_30, level4P_22);
wire level5G_14 = Gij(level4G_14, level4P_14, level4G_6);
wire level5P_14 = Pij(level4P_14, level4P_6);

//第五次合并
wire level6G_30 = Gij(level5G_30, level5P_30, level5G_14);
wire level6P_30 = Pij(level5P_30, level5P_14);

wire adder_out_31 = Sum(adder_data1[31],adder_data2[31],level6G_30,level6P_30,1'b1);


/********************获得比较结果**********************/
// 判断两个输入符号是否一致
wire ne_signed 	= com_data1[31] ^ com_data2[31];
// 有符号数
wire com_lt_s 	= ne_signed ? (com_data1[31] & ~com_data2[31]) : adder_out_31;
// 无符号数
wire com_lt_u 	= ne_signed ? (~com_data1[31] & com_data2[31]) : adder_out_31;
// 等于
wire com_eq = com_data1 == com_data2;
// 有符号还是无符号
wire com_lt = is_signed ? com_lt_s : com_lt_u;

assign com_results = {com_eq, com_lt};

endmodule

