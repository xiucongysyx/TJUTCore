// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_TOP__Syms.h"


VL_ATTR_COLD void VTJUT_TOP___024root__trace_init_sub__TOP__0(VTJUT_TOP___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+170,"clk", false,-1);
    tracep->declBit(c+171,"rst", false,-1);
    tracep->declBit(c+172,"breakpoint", false,-1);
    tracep->declBit(c+173,"invalid", false,-1);
    tracep->declBus(c+174,"pc", false,-1, 31,0);
    tracep->pushNamePrefix("TJUT_TOP ");
    tracep->declBit(c+170,"clk", false,-1);
    tracep->declBit(c+171,"rst", false,-1);
    tracep->declBit(c+172,"breakpoint", false,-1);
    tracep->declBit(c+173,"invalid", false,-1);
    tracep->declBus(c+174,"pc", false,-1, 31,0);
    tracep->declBus(c+105,"inst", false,-1, 31,0);
    tracep->declBus(c+183,"src1", false,-1, 31,0);
    tracep->declBus(c+183,"src2", false,-1, 31,0);
    tracep->declBus(c+183,"imm", false,-1, 31,0);
    tracep->declBus(c+175,"snpc", false,-1, 31,0);
    tracep->declBus(c+106,"ex_out_data", false,-1, 31,0);
    tracep->declBus(c+1,"memregdata", false,-1, 31,0);
    tracep->declBus(c+107,"adder_rd", false,-1, 4,0);
    tracep->declBus(c+108,"adder_src1", false,-1, 4,0);
    tracep->declBus(c+109,"adder_src2", false,-1, 4,0);
    tracep->declBus(c+184,"ex_ctrl_sig", false,-1, 18,0);
    tracep->declBus(c+185,"wb_ctrl_sig", false,-1, 4,0);
    tracep->declBus(c+186,"if_ctrl_sig", false,-1, 0,0);
    tracep->declBus(c+187,"mc_ctrl_sig", false,-1, 8,0);
    tracep->pushNamePrefix("u_TJUT_EX ");
    tracep->declBus(c+174,"pc", false,-1, 31,0);
    tracep->declBus(c+175,"snpc", false,-1, 31,0);
    tracep->declBus(c+183,"src1", false,-1, 31,0);
    tracep->declBus(c+183,"src2", false,-1, 31,0);
    tracep->declBus(c+183,"imm", false,-1, 31,0);
    tracep->declBus(c+184,"ex_ctrl_sig", false,-1, 18,0);
    tracep->declBus(c+106,"ex_out_data", false,-1, 31,0);
    tracep->declBit(c+186,"selalu1", false,-1);
    tracep->declBit(c+186,"selalu2", false,-1);
    tracep->declBit(c+186,"clrlsb", false,-1);
    tracep->declBit(c+186,"is_signed", false,-1);
    tracep->declBit(c+186,"sft_dir", false,-1);
    tracep->declBit(c+186,"ADD", false,-1);
    tracep->declBit(c+186,"SUB", false,-1);
    tracep->declBit(c+186,"LOGIC", false,-1);
    tracep->declBit(c+186,"SHIFT", false,-1);
    tracep->declBit(c+186,"COMPARE", false,-1);
    tracep->declBit(c+186,"BRANCH", false,-1);
    tracep->declBit(c+186,"add", false,-1);
    tracep->declBit(c+186,"sub", false,-1);
    tracep->declBit(c+186,"compare", false,-1);
    tracep->declBit(c+186,"shift", false,-1);
    tracep->declBit(c+2,"com_lt", false,-1);
    tracep->declBit(c+188,"com_eq", false,-1);
    tracep->declBit(c+186,"log_xor", false,-1);
    tracep->declBit(c+186,"log_or", false,-1);
    tracep->declBit(c+186,"log_and", false,-1);
    tracep->declBus(c+189,"alu_op", false,-1, 6,0);
    tracep->declBus(c+190,"bra_op", false,-1, 3,0);
    tracep->declBus(c+191,"log_op", false,-1, 2,0);
    tracep->declBus(c+174,"alu_data1", false,-1, 31,0);
    tracep->declBus(c+183,"alu_data2", false,-1, 31,0);
    tracep->declBus(c+183,"add_data1", false,-1, 31,0);
    tracep->declBus(c+183,"add_data2", false,-1, 31,0);
    tracep->declBus(c+3,"add_result", false,-1, 31,0);
    tracep->declBus(c+183,"sub_result", false,-1, 31,0);
    tracep->declBus(c+183,"logic_data1", false,-1, 31,0);
    tracep->declBus(c+183,"logic_data2", false,-1, 31,0);
    tracep->declBus(c+183,"and_result", false,-1, 31,0);
    tracep->declBus(c+183,"or_result", false,-1, 31,0);
    tracep->declBus(c+183,"xor_result", false,-1, 31,0);
    tracep->declBus(c+4,"log_result", false,-1, 31,0);
    tracep->declBus(c+183,"sft_data", false,-1, 31,0);
    tracep->declBus(c+192,"sft_num1", false,-1, 5,0);
    tracep->declBus(c+192,"sft_num", false,-1, 5,0);
    tracep->declBus(c+183,"sft_result", false,-1, 31,0);
    tracep->declBus(c+183,"com_data1", false,-1, 31,0);
    tracep->declBus(c+183,"com_data3", false,-1, 31,0);
    tracep->declBus(c+183,"com_data2", false,-1, 31,0);
    tracep->declBus(c+5,"com_results", false,-1, 1,0);
    tracep->declBus(c+6,"com_result", false,-1, 31,0);
    tracep->declBus(c+110,"bra_result", false,-1, 31,0);
    tracep->declBus(c+3,"eq_result", false,-1, 31,0);
    tracep->declBus(c+175,"ne_result", false,-1, 31,0);
    tracep->declBus(c+176,"gt_result", false,-1, 31,0);
    tracep->declBus(c+177,"lt_result", false,-1, 31,0);
    tracep->declBus(c+183,"imm_result", false,-1, 31,0);
    tracep->declBus(c+106,"ex_result", false,-1, 31,0);
    tracep->pushNamePrefix("u0_MuxKeyWithDefault ");
    tracep->declBus(c+193,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+193,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+106,"out", false,-1, 31,0);
    tracep->declBus(c+189,"key", false,-1, 6,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+111,"lut", false,-1, 272,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+193,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+193,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+195,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+106,"out", false,-1, 31,0);
    tracep->declBus(c+189,"key", false,-1, 6,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+111,"lut", false,-1, 272,0);
    tracep->declBus(c+196,"PAIR_LEN", false,-1, 5,0);
    for (int i = 0; i < 7; ++i) {
        tracep->declQuad(c+120+i*2,"pair_list", true,(i+0), 38,0);
    }
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+7+i*1,"key_list", true,(i+0), 6,0);
    }
    for (int i = 0; i < 7; ++i) {
        tracep->declBus(c+134+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+141,"lut_out", false,-1, 31,0);
    tracep->declBit(c+142,"hit", false,-1);
    tracep->declBus(c+197,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u1_MuxKeyWithDefault ");
    tracep->declBus(c+198,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+198,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+110,"out", false,-1, 31,0);
    tracep->declBus(c+190,"key", false,-1, 3,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+178,"lut", false,-1, 143,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+198,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+198,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+195,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+110,"out", false,-1, 31,0);
    tracep->declBus(c+190,"key", false,-1, 3,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+178,"lut", false,-1, 143,0);
    tracep->declBus(c+199,"PAIR_LEN", false,-1, 5,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+143+i*2,"pair_list", true,(i+0), 35,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+14+i*1,"key_list", true,(i+0), 3,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+151+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+155,"lut_out", false,-1, 31,0);
    tracep->declBit(c+156,"hit", false,-1);
    tracep->declBus(c+200,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u2_MuxKeyWithDefault ");
    tracep->declBus(c+201,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+201,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+4,"out", false,-1, 31,0);
    tracep->declBus(c+191,"key", false,-1, 2,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+202,"lut", false,-1, 104,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+201,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+201,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+195,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+4,"out", false,-1, 31,0);
    tracep->declBus(c+191,"key", false,-1, 2,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+202,"lut", false,-1, 104,0);
    tracep->declBus(c+206,"PAIR_LEN", false,-1, 5,0);
    for (int i = 0; i < 3; ++i) {
        tracep->declQuad(c+18+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+24+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+27+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+30,"lut_out", false,-1, 31,0);
    tracep->declBit(c+31,"hit", false,-1);
    tracep->declBus(c+207,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u_TJUT_ADDER ");
    tracep->declBus(c+183,"add_data1", false,-1, 31,0);
    tracep->declBus(c+183,"add_data2", false,-1, 31,0);
    tracep->declBit(c+186,"adder_sub", false,-1);
    tracep->declBus(c+3,"adder_out", false,-1, 31,0);
    tracep->declBus(c+183,"adder_data1", false,-1, 31,0);
    tracep->declBus(c+183,"adder_data2", false,-1, 31,0);
    tracep->declBus(c+208,"level1G", false,-1, 30,0);
    tracep->declBus(c+208,"level1P", false,-1, 30,0);
    tracep->declBus(c+32,"level2G", false,-1, 30,0);
    tracep->declBus(c+33,"level2P", false,-1, 30,0);
    tracep->declBus(c+34,"level3G", false,-1, 30,0);
    tracep->declBus(c+35,"level3P", false,-1, 30,0);
    tracep->declBus(c+36,"level4G", false,-1, 30,0);
    tracep->declBus(c+37,"level4P", false,-1, 30,0);
    tracep->declBus(c+38,"level5G", false,-1, 30,0);
    tracep->declBus(c+39,"level5P", false,-1, 30,0);
    tracep->declBus(c+40,"level6G", false,-1, 30,0);
    tracep->declBus(c+41,"level6P", false,-1, 30,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_TJUT_COMPARE ");
    tracep->declBus(c+183,"com_data1", false,-1, 31,0);
    tracep->declBus(c+183,"com_data2", false,-1, 31,0);
    tracep->declBit(c+186,"is_signed", false,-1);
    tracep->declBus(c+5,"com_results", false,-1, 1,0);
    tracep->declBus(c+183,"adder_data1", false,-1, 31,0);
    tracep->declBus(c+209,"adder_data2", false,-1, 31,0);
    tracep->declBus(c+208,"level1G", false,-1, 30,0);
    tracep->declBus(c+210,"level1P", false,-1, 30,0);
    tracep->declBit(c+188,"level2P_0", false,-1);
    tracep->declBit(c+186,"level2G_0", false,-1);
    tracep->declBit(c+186,"level2G_30", false,-1);
    tracep->declBit(c+42,"level2P_30", false,-1);
    tracep->declBit(c+186,"level2G_28", false,-1);
    tracep->declBit(c+43,"level2P_28", false,-1);
    tracep->declBit(c+186,"level2G_26", false,-1);
    tracep->declBit(c+44,"level2P_26", false,-1);
    tracep->declBit(c+186,"level2G_24", false,-1);
    tracep->declBit(c+45,"level2P_24", false,-1);
    tracep->declBit(c+186,"level2G_22", false,-1);
    tracep->declBit(c+46,"level2P_22", false,-1);
    tracep->declBit(c+186,"level2G_20", false,-1);
    tracep->declBit(c+47,"level2P_20", false,-1);
    tracep->declBit(c+186,"level2G_18", false,-1);
    tracep->declBit(c+48,"level2P_18", false,-1);
    tracep->declBit(c+186,"level2G_16", false,-1);
    tracep->declBit(c+49,"level2P_16", false,-1);
    tracep->declBit(c+186,"level2G_14", false,-1);
    tracep->declBit(c+50,"level2P_14", false,-1);
    tracep->declBit(c+186,"level2G_12", false,-1);
    tracep->declBit(c+51,"level2P_12", false,-1);
    tracep->declBit(c+186,"level2G_10", false,-1);
    tracep->declBit(c+52,"level2P_10", false,-1);
    tracep->declBit(c+186,"level2G_8", false,-1);
    tracep->declBit(c+53,"level2P_8", false,-1);
    tracep->declBit(c+186,"level2G_6", false,-1);
    tracep->declBit(c+54,"level2P_6", false,-1);
    tracep->declBit(c+186,"level2G_4", false,-1);
    tracep->declBit(c+55,"level2P_4", false,-1);
    tracep->declBit(c+186,"level2G_2", false,-1);
    tracep->declBit(c+56,"level2P_2", false,-1);
    tracep->declBit(c+57,"level3G_30", false,-1);
    tracep->declBit(c+58,"level3P_30", false,-1);
    tracep->declBit(c+59,"level3G_26", false,-1);
    tracep->declBit(c+60,"level3P_26", false,-1);
    tracep->declBit(c+61,"level3G_22", false,-1);
    tracep->declBit(c+62,"level3P_22", false,-1);
    tracep->declBit(c+63,"level3G_18", false,-1);
    tracep->declBit(c+64,"level3P_18", false,-1);
    tracep->declBit(c+65,"level3G_14", false,-1);
    tracep->declBit(c+66,"level3P_14", false,-1);
    tracep->declBit(c+67,"level3G_10", false,-1);
    tracep->declBit(c+68,"level3P_10", false,-1);
    tracep->declBit(c+69,"level3G_6", false,-1);
    tracep->declBit(c+70,"level3P_6", false,-1);
    tracep->declBit(c+71,"level3G_2", false,-1);
    tracep->declBit(c+72,"level3P_2", false,-1);
    tracep->declBit(c+73,"level4G_30", false,-1);
    tracep->declBit(c+74,"level4P_30", false,-1);
    tracep->declBit(c+75,"level4G_22", false,-1);
    tracep->declBit(c+76,"level4P_22", false,-1);
    tracep->declBit(c+77,"level4G_14", false,-1);
    tracep->declBit(c+78,"level4P_14", false,-1);
    tracep->declBit(c+79,"level4G_6", false,-1);
    tracep->declBit(c+80,"level4P_6", false,-1);
    tracep->declBit(c+81,"level5G_30", false,-1);
    tracep->declBit(c+82,"level5P_30", false,-1);
    tracep->declBit(c+83,"level5G_14", false,-1);
    tracep->declBit(c+84,"level5P_14", false,-1);
    tracep->declBit(c+85,"level6G_30", false,-1);
    tracep->declBit(c+86,"level6P_30", false,-1);
    tracep->declBit(c+2,"adder_out_31", false,-1);
    tracep->declBit(c+186,"ne_signed", false,-1);
    tracep->declBit(c+2,"com_lt_s", false,-1);
    tracep->declBit(c+2,"com_lt_u", false,-1);
    tracep->declBit(c+188,"com_eq", false,-1);
    tracep->declBit(c+2,"com_lt", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_TJUT_SHIFT ");
    tracep->declBus(c+183,"sft_data", false,-1, 31,0);
    tracep->declBus(c+192,"sft_num", false,-1, 5,0);
    tracep->declBit(c+211,"sft_dir", false,-1);
    tracep->declBit(c+188,"is_signed", false,-1);
    tracep->declBus(c+183,"sft_result", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("u_TJUT_ID ");
    tracep->declBus(c+105,"inst", false,-1, 31,0);
    tracep->declBus(c+184,"ex_ctrl_sig", false,-1, 18,0);
    tracep->declBus(c+185,"wb_ctrl_sig", false,-1, 4,0);
    tracep->declBus(c+186,"if_ctrl_sig", false,-1, 0,0);
    tracep->declBus(c+187,"mc_ctrl_sig", false,-1, 8,0);
    tracep->declBit(c+172,"breakpoint", false,-1);
    tracep->declBit(c+173,"invalid", false,-1);
    tracep->declBus(c+107,"adder_rd", false,-1, 4,0);
    tracep->declBus(c+108,"adder_src1", false,-1, 4,0);
    tracep->declBus(c+109,"adder_src2", false,-1, 4,0);
    tracep->declBus(c+183,"imm", false,-1, 31,0);
    tracep->declBit(c+172,"ebreak", false,-1);
    tracep->declBit(c+186,"valid", false,-1);
    tracep->declBit(c+186,"selpc", false,-1);
    tracep->declBit(c+186,"ADD", false,-1);
    tracep->declBit(c+186,"SUB", false,-1);
    tracep->declBit(c+186,"LOGIC", false,-1);
    tracep->declBit(c+186,"log_xor", false,-1);
    tracep->declBit(c+186,"log_or", false,-1);
    tracep->declBit(c+186,"log_and", false,-1);
    tracep->declBus(c+191,"log_op", false,-1, 2,0);
    tracep->declBit(c+186,"SHIFT", false,-1);
    tracep->declBit(c+186,"COMPARE", false,-1);
    tracep->declBit(c+186,"BRANCH", false,-1);
    tracep->declBit(c+186,"bra_eq", false,-1);
    tracep->declBit(c+186,"bra_ne", false,-1);
    tracep->declBit(c+186,"bra_gt", false,-1);
    tracep->declBit(c+186,"bra_lt", false,-1);
    tracep->declBus(c+190,"bra_op", false,-1, 3,0);
    tracep->declBit(c+186,"IMMLOAD", false,-1);
    tracep->declBus(c+189,"alu_op", false,-1, 6,0);
    tracep->declBit(c+186,"clrlsb", false,-1);
    tracep->declBit(c+186,"is_signed", false,-1);
    tracep->declBit(c+186,"sft_dir", false,-1);
    tracep->declBit(c+186,"selalu1", false,-1);
    tracep->declBit(c+186,"selalu2", false,-1);
    tracep->declBit(c+186,"regpc", false,-1);
    tracep->declBit(c+186,"regwen", false,-1);
    tracep->declBit(c+186,"regrensrc1", false,-1);
    tracep->declBit(c+186,"regrensrc2", false,-1);
    tracep->declBit(c+186,"memregren", false,-1);
    tracep->declBit(c+186,"memwen", false,-1);
    tracep->declBit(c+186,"memren", false,-1);
    tracep->declBit(c+186,"sign_extend", false,-1);
    tracep->declBus(c+212,"wmask", false,-1, 2,0);
    tracep->declBus(c+212,"rmask", false,-1, 2,0);
    tracep->declBit(c+186,"memregsrc2", false,-1);
    tracep->declBit(c+186,"imm_u", false,-1);
    tracep->declBit(c+186,"imm_i", false,-1);
    tracep->declBit(c+186,"imm_j", false,-1);
    tracep->declBit(c+186,"imm_s", false,-1);
    tracep->declBit(c+186,"imm_b", false,-1);
    tracep->declBus(c+157,"imm_i_data", false,-1, 31,0);
    tracep->declBus(c+158,"imm_u_data", false,-1, 31,0);
    tracep->declBus(c+159,"imm_j_data", false,-1, 31,0);
    tracep->declBus(c+160,"imm_s_data", false,-1, 31,0);
    tracep->declBus(c+161,"imm_b_data", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_TJUT_IF ");
    tracep->declBit(c+170,"clk", false,-1);
    tracep->declBit(c+171,"rst", false,-1);
    tracep->declBus(c+186,"if_ctrl_sig", false,-1, 0,0);
    tracep->declBus(c+106,"ex_out_data", false,-1, 31,0);
    tracep->declBus(c+174,"pc", false,-1, 31,0);
    tracep->declBus(c+175,"snpc", false,-1, 31,0);
    tracep->declBus(c+105,"inst", false,-1, 31,0);
    tracep->declBit(c+186,"selpc", false,-1);
    tracep->declBus(c+175,"dnpc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_TJUT_MC ");
    tracep->declBus(c+187,"mc_ctrl_sig", false,-1, 8,0);
    tracep->declBus(c+106,"ex_out_data", false,-1, 31,0);
    tracep->declBus(c+183,"src2", false,-1, 31,0);
    tracep->declBus(c+1,"memregdata", false,-1, 31,0);
    tracep->declBit(c+186,"memren", false,-1);
    tracep->declBit(c+186,"memwen", false,-1);
    tracep->declBit(c+186,"sign_extend", false,-1);
    tracep->declBus(c+212,"rmask", false,-1, 2,0);
    tracep->declBus(c+162,"wmask", false,-1, 7,0);
    tracep->declBus(c+183,"rdata", false,-1, 31,0);
    tracep->declBit(c+163,"addr_byte0", false,-1);
    tracep->declBit(c+164,"addr_byte1", false,-1);
    tracep->declBit(c+165,"addr_byte2", false,-1);
    tracep->declBus(c+183,"rdata_cor", false,-1, 31,0);
    tracep->declBus(c+183,"onebyte_u", false,-1, 31,0);
    tracep->declBus(c+183,"onebyte_s", false,-1, 31,0);
    tracep->declBus(c+183,"onebyte", false,-1, 31,0);
    tracep->declBus(c+183,"twobyte_u", false,-1, 31,0);
    tracep->declBus(c+183,"twobyte_s", false,-1, 31,0);
    tracep->declBus(c+183,"twobyte", false,-1, 31,0);
    tracep->declBus(c+183,"forbyte", false,-1, 31,0);
    tracep->pushNamePrefix("u0_MuxKeyWithDefault ");
    tracep->declBus(c+198,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+201,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+1,"out", false,-1, 31,0);
    tracep->declBus(c+212,"key", false,-1, 2,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+213,"lut", false,-1, 139,0);
    tracep->pushNamePrefix("i0 ");
    tracep->declBus(c+198,"NR_KEY", false,-1, 5,0);
    tracep->declBus(c+201,"KEY_LEN", false,-1, 5,0);
    tracep->declBus(c+194,"DATA_LEN", false,-1, 5,0);
    tracep->declBus(c+195,"HAS_DEFAULT", false,-1, 31,0);
    tracep->declBus(c+1,"out", false,-1, 31,0);
    tracep->declBus(c+212,"key", false,-1, 2,0);
    tracep->declBus(c+183,"default_out", false,-1, 31,0);
    tracep->declArray(c+213,"lut", false,-1, 139,0);
    tracep->declBus(c+206,"PAIR_LEN", false,-1, 5,0);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+87+i*2,"pair_list", true,(i+0), 34,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+95+i*1,"key_list", true,(i+0), 2,0);
    }
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+99+i*1,"data_list", true,(i+0), 31,0);
    }
    tracep->declBus(c+103,"lut_out", false,-1, 31,0);
    tracep->declBit(c+104,"hit", false,-1);
    tracep->declBus(c+200,"i", false,-1, 31,0);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("u_TJUT_WB ");
    tracep->declBit(c+170,"clk", false,-1);
    tracep->declBus(c+106,"ex_out_data", false,-1, 31,0);
    tracep->declBus(c+175,"snpc", false,-1, 31,0);
    tracep->declBus(c+1,"memregdata", false,-1, 31,0);
    tracep->declBus(c+107,"adder_rd", false,-1, 4,0);
    tracep->declBus(c+108,"adder_src1", false,-1, 4,0);
    tracep->declBus(c+109,"adder_src2", false,-1, 4,0);
    tracep->declBus(c+185,"wb_ctrl_sig", false,-1, 4,0);
    tracep->declBus(c+183,"src1", false,-1, 31,0);
    tracep->declBus(c+183,"src2", false,-1, 31,0);
    tracep->declBit(c+186,"memregren", false,-1);
    tracep->declBit(c+186,"regpc", false,-1);
    tracep->declBit(c+186,"regwen", false,-1);
    tracep->declBit(c+186,"regrensrc1", false,-1);
    tracep->declBit(c+186,"regrensrc2", false,-1);
    tracep->declBus(c+106,"wdata_d1", false,-1, 31,0);
    tracep->declBus(c+106,"wdata", false,-1, 31,0);
    tracep->pushNamePrefix("u_TJUT_REGFILE ");
    tracep->declBit(c+170,"clk", false,-1);
    tracep->declBus(c+106,"wdata", false,-1, 31,0);
    tracep->declBus(c+107,"waddr", false,-1, 4,0);
    tracep->declBit(c+186,"regwen", false,-1);
    tracep->declBus(c+183,"rdatasrc1", false,-1, 31,0);
    tracep->declBus(c+183,"rdatasrc2", false,-1, 31,0);
    tracep->declBus(c+108,"raddrsrc1", false,-1, 4,0);
    tracep->declBus(c+109,"raddrsrc2", false,-1, 4,0);
    tracep->declBit(c+186,"regrensrc1", false,-1);
    tracep->declBit(c+186,"regrensrc2", false,-1);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+218+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->declBus(c+183,"reg_zero", false,-1, 31,0);
    tracep->declBus(c+166,"reg_data_src1", false,-1, 31,0);
    tracep->declBus(c+167,"rdata_pre_src1", false,-1, 31,0);
    tracep->declBus(c+168,"reg_data_src2", false,-1, 31,0);
    tracep->declBus(c+169,"rdata_pre_src2", false,-1, 31,0);
    tracep->popNamePrefix(3);
}

VL_ATTR_COLD void VTJUT_TOP___024root__trace_init_top(VTJUT_TOP___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_init_top\n"); );
    // Body
    VTJUT_TOP___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTJUT_TOP___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_TOP___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_TOP___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTJUT_TOP___024root__trace_register(VTJUT_TOP___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTJUT_TOP___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTJUT_TOP___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTJUT_TOP___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTJUT_TOP___024root__trace_full_sub_0(VTJUT_TOP___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTJUT_TOP___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_full_top_0\n"); );
    // Init
    VTJUT_TOP___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_TOP___024root*>(voidSelf);
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTJUT_TOP___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTJUT_TOP___024root__trace_full_sub_0(VTJUT_TOP___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<9>/*287:0*/ __Vtemp_h5e220dde__0;
    VlWide<5>/*159:0*/ __Vtemp_h39811c99__0;
    VlWide<4>/*127:0*/ __Vtemp_h94c31d06__0;
    VlWide<5>/*159:0*/ __Vtemp_h9fb8a6c1__0;
    // Body
    bufp->fullIData(oldp+1,(vlSelf->TJUT_TOP__DOT__memregdata),32);
    bufp->fullBit(oldp+2,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31));
    bufp->fullIData(oldp+3,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result),32);
    bufp->fullIData(oldp+4,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__log_result),32);
    bufp->fullCData(oldp+5,((2U | (IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31))),2);
    bufp->fullIData(oldp+6,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31),32);
    bufp->fullCData(oldp+7,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),7);
    bufp->fullCData(oldp+8,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),7);
    bufp->fullCData(oldp+9,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),7);
    bufp->fullCData(oldp+10,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[3]),7);
    bufp->fullCData(oldp+11,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[4]),7);
    bufp->fullCData(oldp+12,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[5]),7);
    bufp->fullCData(oldp+13,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[6]),7);
    bufp->fullCData(oldp+14,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),4);
    bufp->fullCData(oldp+15,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),4);
    bufp->fullCData(oldp+16,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),4);
    bufp->fullCData(oldp+17,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[3]),4);
    bufp->fullQData(oldp+18,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+20,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+22,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullCData(oldp+24,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+25,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+26,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),3);
    bufp->fullIData(oldp+27,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+28,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+29,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+30,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+31,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+32,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level2G),31);
    bufp->fullIData(oldp+33,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level2P),31);
    bufp->fullIData(oldp+34,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level3G),31);
    bufp->fullIData(oldp+35,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level3P),31);
    bufp->fullIData(oldp+36,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level4G),31);
    bufp->fullIData(oldp+37,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level4P),31);
    bufp->fullIData(oldp+38,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level5G),31);
    bufp->fullIData(oldp+39,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level5P),31);
    bufp->fullIData(oldp+40,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level6G),31);
    bufp->fullIData(oldp+41,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level6P),31);
    bufp->fullBit(oldp+42,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_30));
    bufp->fullBit(oldp+43,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_28));
    bufp->fullBit(oldp+44,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_26));
    bufp->fullBit(oldp+45,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_24));
    bufp->fullBit(oldp+46,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_22));
    bufp->fullBit(oldp+47,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_20));
    bufp->fullBit(oldp+48,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_18));
    bufp->fullBit(oldp+49,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_16));
    bufp->fullBit(oldp+50,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_14));
    bufp->fullBit(oldp+51,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_12));
    bufp->fullBit(oldp+52,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_10));
    bufp->fullBit(oldp+53,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_8));
    bufp->fullBit(oldp+54,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_6));
    bufp->fullBit(oldp+55,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_4));
    bufp->fullBit(oldp+56,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_2));
    bufp->fullBit(oldp+57,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_30));
    bufp->fullBit(oldp+58,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_30));
    bufp->fullBit(oldp+59,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_26));
    bufp->fullBit(oldp+60,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_26));
    bufp->fullBit(oldp+61,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_22));
    bufp->fullBit(oldp+62,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_22));
    bufp->fullBit(oldp+63,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_18));
    bufp->fullBit(oldp+64,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_18));
    bufp->fullBit(oldp+65,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_14));
    bufp->fullBit(oldp+66,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_14));
    bufp->fullBit(oldp+67,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_10));
    bufp->fullBit(oldp+68,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_10));
    bufp->fullBit(oldp+69,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_6));
    bufp->fullBit(oldp+70,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_6));
    bufp->fullBit(oldp+71,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_2));
    bufp->fullBit(oldp+72,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_2));
    bufp->fullBit(oldp+73,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_30));
    bufp->fullBit(oldp+74,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_30));
    bufp->fullBit(oldp+75,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_22));
    bufp->fullBit(oldp+76,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_22));
    bufp->fullBit(oldp+77,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_14));
    bufp->fullBit(oldp+78,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_14));
    bufp->fullBit(oldp+79,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_6));
    bufp->fullBit(oldp+80,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_6));
    bufp->fullBit(oldp+81,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5G_30));
    bufp->fullBit(oldp+82,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5P_30));
    bufp->fullBit(oldp+83,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5G_14));
    bufp->fullBit(oldp+84,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5P_14));
    bufp->fullBit(oldp+85,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level6G_30));
    bufp->fullBit(oldp+86,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level6P_30));
    bufp->fullQData(oldp+87,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),35);
    bufp->fullQData(oldp+89,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),35);
    bufp->fullQData(oldp+91,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),35);
    bufp->fullQData(oldp+93,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3]),35);
    bufp->fullCData(oldp+95,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),3);
    bufp->fullCData(oldp+96,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),3);
    bufp->fullCData(oldp+97,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),3);
    bufp->fullCData(oldp+98,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[3]),3);
    bufp->fullIData(oldp+99,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+100,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+101,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+102,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+103,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+104,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+105,(vlSelf->TJUT_TOP__DOT__inst),32);
    bufp->fullIData(oldp+106,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result),32);
    bufp->fullCData(oldp+107,((0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                        >> 7U))),5);
    bufp->fullCData(oldp+108,((0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+109,((0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                        >> 0x14U))),5);
    bufp->fullIData(oldp+110,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result),32);
    __Vtemp_h5e220dde__0[0U] = 0U;
    __Vtemp_h5e220dde__0[1U] = 0x40U;
    __Vtemp_h5e220dde__0[2U] = (0x400U | (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__log_result 
                                          << 0xeU));
    __Vtemp_h5e220dde__0[3U] = (0x10000U | ((vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result 
                                             << 0x15U) 
                                            | (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__log_result 
                                               >> 0x12U)));
    __Vtemp_h5e220dde__0[4U] = (0x4000000U | (((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31) 
                                               << 0x1cU) 
                                              | (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result 
                                                 >> 0xbU)));
    __Vtemp_h5e220dde__0[5U] = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31) 
                                >> 4U);
    __Vtemp_h5e220dde__0[6U] = 1U;
    __Vtemp_h5e220dde__0[7U] = (0x10U | (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result 
                                         << 0xaU));
    __Vtemp_h5e220dde__0[8U] = (0x400U | (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result 
                                          >> 0x16U));
    bufp->fullWData(oldp+111,(__Vtemp_h5e220dde__0),273);
    bufp->fullQData(oldp+120,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),39);
    bufp->fullQData(oldp+122,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),39);
    bufp->fullQData(oldp+124,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),39);
    bufp->fullQData(oldp+126,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3]),39);
    bufp->fullQData(oldp+128,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[4]),39);
    bufp->fullQData(oldp+130,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[5]),39);
    bufp->fullQData(oldp+132,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[6]),39);
    bufp->fullIData(oldp+134,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+135,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+136,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+137,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+138,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[4]),32);
    bufp->fullIData(oldp+139,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[5]),32);
    bufp->fullIData(oldp+140,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[6]),32);
    bufp->fullIData(oldp+141,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+142,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit));
    bufp->fullQData(oldp+143,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),36);
    bufp->fullQData(oldp+145,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),36);
    bufp->fullQData(oldp+147,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),36);
    bufp->fullQData(oldp+149,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3]),36);
    bufp->fullIData(oldp+151,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
    bufp->fullIData(oldp+152,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
    bufp->fullIData(oldp+153,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
    bufp->fullIData(oldp+154,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[3]),32);
    bufp->fullIData(oldp+155,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
    bufp->fullBit(oldp+156,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit));
    bufp->fullIData(oldp+157,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | (vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0x14U))),32);
    bufp->fullIData(oldp+158,((0xfffff000U & vlSelf->TJUT_TOP__DOT__inst)),32);
    bufp->fullIData(oldp+159,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0x1fU))) 
                                << 0x14U) | ((0xff000U 
                                              & vlSelf->TJUT_TOP__DOT__inst) 
                                             | ((0x800U 
                                                 & (vlSelf->TJUT_TOP__DOT__inst 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlSelf->TJUT_TOP__DOT__inst 
                                                      >> 0x14U)))))),32);
    bufp->fullIData(oldp+160,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0xfe0U 
                                             & (vlSelf->TJUT_TOP__DOT__inst 
                                                >> 0x14U)) 
                                            | (0x1fU 
                                               & (vlSelf->TJUT_TOP__DOT__inst 
                                                  >> 7U))))),32);
    bufp->fullIData(oldp+161,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0x1fU))) 
                                << 0xcU) | ((0x800U 
                                             & (vlSelf->TJUT_TOP__DOT__inst 
                                                << 4U)) 
                                            | ((0x7e0U 
                                                & (vlSelf->TJUT_TOP__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1eU 
                                                  & (vlSelf->TJUT_TOP__DOT__inst 
                                                     >> 7U)))))),32);
    bufp->fullCData(oldp+162,((7U | (((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte2) 
                                      << 5U) | (((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte1) 
                                                 << 4U) 
                                                | ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte0) 
                                                   << 3U))))),8);
    bufp->fullBit(oldp+163,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte0));
    bufp->fullBit(oldp+164,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte1));
    bufp->fullBit(oldp+165,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte2));
    bufp->fullIData(oldp+166,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                              [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                         >> 0xfU))]),32);
    bufp->fullIData(oldp+167,(((0U == (0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                                >> 0xfU)))
                                ? 0U : vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                               [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                          >> 0xfU))])),32);
    bufp->fullIData(oldp+168,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                              [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                         >> 0x14U))]),32);
    bufp->fullIData(oldp+169,(((0U == (0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                                >> 0x14U)))
                                ? 0U : vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                               [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                          >> 0x14U))])),32);
    bufp->fullBit(oldp+170,(vlSelf->clk));
    bufp->fullBit(oldp+171,(vlSelf->rst));
    bufp->fullBit(oldp+172,(vlSelf->breakpoint));
    bufp->fullBit(oldp+173,(vlSelf->invalid));
    bufp->fullIData(oldp+174,(vlSelf->pc),32);
    bufp->fullIData(oldp+175,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullIData(oldp+176,(((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                ? ((IData)(4U) + vlSelf->pc)
                                : vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result)),32);
    bufp->fullIData(oldp+177,(((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                ? vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result
                                : ((IData)(4U) + vlSelf->pc))),32);
    __Vtemp_h39811c99__0[0U] = (IData)((0x800000000ULL 
                                        | (QData)((IData)(
                                                          ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                                            ? vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result
                                                            : 
                                                           ((IData)(4U) 
                                                            + vlSelf->pc))))));
    __Vtemp_h39811c99__0[1U] = ((((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                   ? ((IData)(4U) + vlSelf->pc)
                                   : vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result) 
                                 << 4U) | (IData)((
                                                   (0x800000000ULL 
                                                    | (QData)((IData)(
                                                                      ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                                                        ? vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result
                                                                        : 
                                                                       ((IData)(4U) 
                                                                        + vlSelf->pc))))) 
                                                   >> 0x20U)));
    __Vtemp_h39811c99__0[2U] = (0x40U | ((((IData)(4U) 
                                           + vlSelf->pc) 
                                          << 8U) | 
                                         (((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                            ? ((IData)(4U) 
                                               + vlSelf->pc)
                                            : vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result) 
                                          >> 0x1cU)));
    __Vtemp_h39811c99__0[3U] = (0x200U | ((vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result 
                                           << 0xcU) 
                                          | (((IData)(4U) 
                                              + vlSelf->pc) 
                                             >> 0x18U)));
    __Vtemp_h39811c99__0[4U] = (0x1000U | (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result 
                                           >> 0x14U));
    bufp->fullWData(oldp+178,(__Vtemp_h39811c99__0),144);
    bufp->fullIData(oldp+183,(0U),32);
    bufp->fullIData(oldp+184,(0U),19);
    bufp->fullCData(oldp+185,(0U),5);
    bufp->fullBit(oldp+186,(0U));
    bufp->fullSData(oldp+187,(0x1f8U),9);
    bufp->fullBit(oldp+188,(1U));
    bufp->fullCData(oldp+189,(0U),7);
    bufp->fullCData(oldp+190,(0U),4);
    bufp->fullCData(oldp+191,(0U),3);
    bufp->fullCData(oldp+192,(0U),6);
    bufp->fullCData(oldp+193,(7U),6);
    bufp->fullCData(oldp+194,(0x20U),6);
    bufp->fullIData(oldp+195,(1U),32);
    bufp->fullCData(oldp+196,(0x27U),6);
    bufp->fullIData(oldp+197,(7U),32);
    bufp->fullCData(oldp+198,(4U),6);
    bufp->fullCData(oldp+199,(0x24U),6);
    bufp->fullIData(oldp+200,(4U),32);
    bufp->fullCData(oldp+201,(3U),6);
    __Vtemp_h94c31d06__0[0U] = 0U;
    __Vtemp_h94c31d06__0[1U] = 4U;
    __Vtemp_h94c31d06__0[2U] = 0x10U;
    __Vtemp_h94c31d06__0[3U] = 0x40U;
    bufp->fullWData(oldp+202,(__Vtemp_h94c31d06__0),105);
    bufp->fullCData(oldp+206,(0x23U),6);
    bufp->fullIData(oldp+207,(3U),32);
    bufp->fullIData(oldp+208,(0U),31);
    bufp->fullIData(oldp+209,(0xffffffffU),32);
    bufp->fullIData(oldp+210,(0x7fffffffU),31);
    bufp->fullBit(oldp+211,(1U));
    bufp->fullCData(oldp+212,(7U),3);
    __Vtemp_h9fb8a6c1__0[0U] = 0U;
    __Vtemp_h9fb8a6c1__0[1U] = 4U;
    __Vtemp_h9fb8a6c1__0[2U] = 0x10U;
    __Vtemp_h9fb8a6c1__0[3U] = 0x40U;
    __Vtemp_h9fb8a6c1__0[4U] = 0U;
    bufp->fullWData(oldp+213,(__Vtemp_h9fb8a6c1__0),140);
    bufp->fullIData(oldp+218,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[0]),32);
    bufp->fullIData(oldp+219,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[1]),32);
    bufp->fullIData(oldp+220,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[2]),32);
    bufp->fullIData(oldp+221,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[3]),32);
    bufp->fullIData(oldp+222,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[4]),32);
    bufp->fullIData(oldp+223,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[5]),32);
    bufp->fullIData(oldp+224,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[6]),32);
    bufp->fullIData(oldp+225,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[7]),32);
    bufp->fullIData(oldp+226,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[8]),32);
    bufp->fullIData(oldp+227,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[9]),32);
    bufp->fullIData(oldp+228,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[10]),32);
    bufp->fullIData(oldp+229,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[11]),32);
    bufp->fullIData(oldp+230,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[12]),32);
    bufp->fullIData(oldp+231,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[13]),32);
    bufp->fullIData(oldp+232,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[14]),32);
    bufp->fullIData(oldp+233,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[15]),32);
    bufp->fullIData(oldp+234,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[16]),32);
    bufp->fullIData(oldp+235,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[17]),32);
    bufp->fullIData(oldp+236,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[18]),32);
    bufp->fullIData(oldp+237,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[19]),32);
    bufp->fullIData(oldp+238,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[20]),32);
    bufp->fullIData(oldp+239,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[21]),32);
    bufp->fullIData(oldp+240,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[22]),32);
    bufp->fullIData(oldp+241,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[23]),32);
    bufp->fullIData(oldp+242,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[24]),32);
    bufp->fullIData(oldp+243,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[25]),32);
    bufp->fullIData(oldp+244,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[26]),32);
    bufp->fullIData(oldp+245,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[27]),32);
    bufp->fullIData(oldp+246,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[28]),32);
    bufp->fullIData(oldp+247,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[29]),32);
    bufp->fullIData(oldp+248,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[30]),32);
    bufp->fullIData(oldp+249,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf[31]),32);
}
