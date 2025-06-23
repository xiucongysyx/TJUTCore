`include "define.v"
module TJUT_ADDER(
	input   [`DATA_WIDTH-1:0]      add_data1,
	input   [`DATA_WIDTH-1:0]      add_data2,
	input                          adder_sub,
	output  [`DATA_WIDTH-1:0]      adder_out 
);

/*****************adder_data2补码********************/
wire [`DATA_WIDTH-1:0] adder_data1 = add_data1;
wire [`DATA_WIDTH-1:0] adder_data2 = adder_sub ? {32{adder_sub}} ^ add_data2 : add_data2;


/****************定义gp信号***************************/
wire [`DATA_WIDTH-2:0] level1G; //等级1的g、p
wire [`DATA_WIDTH-2:0] level1P;
wire [`DATA_WIDTH-2:0] level2G; //等级2的g、p
wire [`DATA_WIDTH-2:0] level2P;
wire [`DATA_WIDTH-2:0] level3G; //等级3的g、p
wire [`DATA_WIDTH-2:0] level3P;
wire [`DATA_WIDTH-2:0] level4G; //等级4的g、p
wire [`DATA_WIDTH-2:0] level4P;
wire [`DATA_WIDTH-2:0] level5G; //等级5的g、p
wire [`DATA_WIDTH-2:0] level5P;
wire [`DATA_WIDTH-2:0] level6G; //等级6的g、p  到等级6时，每个g、p都是g[0,i]、p[0,i],可以直接用来生成进位信号和和
wire [`DATA_WIDTH-2:0] level6P;


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
assign level2P[0] = level1P[0];
assign level2G[0] = level1G[0];
generate
	for(i=1;i<31;i=i+1) begin
		assign level2G[i] = Gij(level1G[i], level1P[i], level1G[i-1]);
		assign level2P[i] = Pij(level1P[i], level1P[i-1]);
	end
endgenerate

//第二次合并
generate
	for(i=0;i<2;i=i+1) begin
		assign level3P[i] = level2P[i];
    assign level3G[i] = level2G[i];
	end
endgenerate
generate
	for(i=2;i<31;i=i+1) begin
		assign level3G[i] = Gij(level2G[i], level2P[i], level2G[i-2]);
		assign level3P[i] = Pij(level2P[i], level2P[i-2]);
	end
endgenerate

//第三次合并
generate
	for(i=0;i<4;i=i+1) begin
		assign level4P[i] = level3P[i];
    assign level4G[i] = level3G[i];
	end
endgenerate
generate
	for(i=4;i<31;i=i+1) begin
		assign level4G[i] = Gij(level3G[i], level3P[i], level3G[i-4]);
		assign level4P[i] = Pij(level3P[i], level3P[i-4]);
	end
endgenerate

//第四次合并
generate
	for(i=0;i<8;i=i+1) begin
		assign level5P[i] = level4P[i];
    assign level5G[i] = level4G[i];
	end
endgenerate
generate
	for(i=8;i<31;i=i+1) begin
		assign level5G[i] = Gij(level4G[i], level4P[i], level4G[i-8]);
		assign level5P[i] = Pij(level4P[i], level4P[i-8]);
	end
endgenerate

//第五次合并
generate
	for(i=0;i<16;i=i+1) begin
		assign level6P[i] = level5P[i];
    assign level6G[i] = level5G[i];
	end
endgenerate
generate
	for(i=16;i<31;i=i+1) begin
		assign level6G[i] = Gij(level5G[i], level5P[i], level5G[i-16]);
		assign level6P[i] = Pij(level5P[i], level5P[i-16]);
	end
endgenerate

//通过level6GP求和和进位信号
xor (adder_out[0],adder_data1[0],adder_data2[0],adder_sub);
generate
	for(i=0;i<31;i=i+1) begin
	assign adder_out[i+1] = Sum(adder_data1[i+1],adder_data2[i+1],level6G[i],level6P[i],adder_sub);
	end
endgenerate

endmodule

