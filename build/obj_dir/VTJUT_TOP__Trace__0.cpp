// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_TOP__Syms.h"


void VTJUT_TOP___024root__trace_chg_sub_0(VTJUT_TOP___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTJUT_TOP___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_chg_top_0\n"); );
    // Init
    VTJUT_TOP___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_TOP___024root*>(voidSelf);
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTJUT_TOP___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTJUT_TOP___024root__trace_chg_sub_0(VTJUT_TOP___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<9>/*287:0*/ __Vtemp_h5e220dde__0;
    VlWide<5>/*159:0*/ __Vtemp_h39811c99__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->TJUT_TOP__DOT__memregdata),32);
        bufp->chgBit(oldp+1,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31));
        bufp->chgIData(oldp+2,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result),32);
        bufp->chgIData(oldp+3,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__log_result),32);
        bufp->chgCData(oldp+4,((2U | (IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31))),2);
        bufp->chgIData(oldp+5,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31),32);
        bufp->chgCData(oldp+6,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),7);
        bufp->chgCData(oldp+7,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),7);
        bufp->chgCData(oldp+8,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),7);
        bufp->chgCData(oldp+9,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[3]),7);
        bufp->chgCData(oldp+10,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[4]),7);
        bufp->chgCData(oldp+11,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[5]),7);
        bufp->chgCData(oldp+12,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[6]),7);
        bufp->chgCData(oldp+13,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),4);
        bufp->chgCData(oldp+14,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),4);
        bufp->chgCData(oldp+15,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),4);
        bufp->chgCData(oldp+16,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list[3]),4);
        bufp->chgQData(oldp+17,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+19,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+21,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgCData(oldp+23,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+24,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+25,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),3);
        bufp->chgIData(oldp+26,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+27,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+28,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+29,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+30,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+31,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level2G),31);
        bufp->chgIData(oldp+32,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level2P),31);
        bufp->chgIData(oldp+33,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level3G),31);
        bufp->chgIData(oldp+34,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level3P),31);
        bufp->chgIData(oldp+35,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level4G),31);
        bufp->chgIData(oldp+36,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level4P),31);
        bufp->chgIData(oldp+37,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level5G),31);
        bufp->chgIData(oldp+38,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level5P),31);
        bufp->chgIData(oldp+39,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level6G),31);
        bufp->chgIData(oldp+40,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level6P),31);
        bufp->chgBit(oldp+41,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_30));
        bufp->chgBit(oldp+42,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_28));
        bufp->chgBit(oldp+43,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_26));
        bufp->chgBit(oldp+44,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_24));
        bufp->chgBit(oldp+45,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_22));
        bufp->chgBit(oldp+46,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_20));
        bufp->chgBit(oldp+47,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_18));
        bufp->chgBit(oldp+48,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_16));
        bufp->chgBit(oldp+49,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_14));
        bufp->chgBit(oldp+50,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_12));
        bufp->chgBit(oldp+51,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_10));
        bufp->chgBit(oldp+52,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_8));
        bufp->chgBit(oldp+53,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_6));
        bufp->chgBit(oldp+54,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_4));
        bufp->chgBit(oldp+55,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_2));
        bufp->chgBit(oldp+56,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_30));
        bufp->chgBit(oldp+57,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_30));
        bufp->chgBit(oldp+58,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_26));
        bufp->chgBit(oldp+59,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_26));
        bufp->chgBit(oldp+60,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_22));
        bufp->chgBit(oldp+61,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_22));
        bufp->chgBit(oldp+62,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_18));
        bufp->chgBit(oldp+63,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_18));
        bufp->chgBit(oldp+64,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_14));
        bufp->chgBit(oldp+65,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_14));
        bufp->chgBit(oldp+66,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_10));
        bufp->chgBit(oldp+67,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_10));
        bufp->chgBit(oldp+68,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_6));
        bufp->chgBit(oldp+69,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_6));
        bufp->chgBit(oldp+70,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_2));
        bufp->chgBit(oldp+71,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_2));
        bufp->chgBit(oldp+72,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_30));
        bufp->chgBit(oldp+73,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_30));
        bufp->chgBit(oldp+74,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_22));
        bufp->chgBit(oldp+75,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_22));
        bufp->chgBit(oldp+76,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_14));
        bufp->chgBit(oldp+77,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_14));
        bufp->chgBit(oldp+78,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_6));
        bufp->chgBit(oldp+79,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_6));
        bufp->chgBit(oldp+80,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5G_30));
        bufp->chgBit(oldp+81,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5P_30));
        bufp->chgBit(oldp+82,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5G_14));
        bufp->chgBit(oldp+83,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5P_14));
        bufp->chgBit(oldp+84,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level6G_30));
        bufp->chgBit(oldp+85,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level6P_30));
        bufp->chgQData(oldp+86,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),35);
        bufp->chgQData(oldp+88,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),35);
        bufp->chgQData(oldp+90,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),35);
        bufp->chgQData(oldp+92,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3]),35);
        bufp->chgCData(oldp+94,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[0]),3);
        bufp->chgCData(oldp+95,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[1]),3);
        bufp->chgCData(oldp+96,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[2]),3);
        bufp->chgCData(oldp+97,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list[3]),3);
        bufp->chgIData(oldp+98,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+99,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+100,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+101,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+102,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+103,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+104,(vlSelf->TJUT_TOP__DOT__inst),32);
        bufp->chgIData(oldp+105,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result),32);
        bufp->chgCData(oldp+106,((0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                           >> 7U))),5);
        bufp->chgCData(oldp+107,((0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+108,((0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                           >> 0x14U))),5);
        bufp->chgIData(oldp+109,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result),32);
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
        bufp->chgWData(oldp+110,(__Vtemp_h5e220dde__0),273);
        bufp->chgQData(oldp+119,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),39);
        bufp->chgQData(oldp+121,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),39);
        bufp->chgQData(oldp+123,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),39);
        bufp->chgQData(oldp+125,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3]),39);
        bufp->chgQData(oldp+127,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[4]),39);
        bufp->chgQData(oldp+129,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[5]),39);
        bufp->chgQData(oldp+131,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[6]),39);
        bufp->chgIData(oldp+133,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+134,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+135,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+136,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+137,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[4]),32);
        bufp->chgIData(oldp+138,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[5]),32);
        bufp->chgIData(oldp+139,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[6]),32);
        bufp->chgIData(oldp+140,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+141,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit));
        bufp->chgQData(oldp+142,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0]),36);
        bufp->chgQData(oldp+144,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1]),36);
        bufp->chgQData(oldp+146,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2]),36);
        bufp->chgQData(oldp+148,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3]),36);
        bufp->chgIData(oldp+150,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[0]),32);
        bufp->chgIData(oldp+151,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[1]),32);
        bufp->chgIData(oldp+152,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[2]),32);
        bufp->chgIData(oldp+153,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[3]),32);
        bufp->chgIData(oldp+154,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out),32);
        bufp->chgBit(oldp+155,(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit));
        bufp->chgIData(oldp+156,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0xcU) | (vlSelf->TJUT_TOP__DOT__inst 
                                               >> 0x14U))),32);
        bufp->chgIData(oldp+157,((0xfffff000U & vlSelf->TJUT_TOP__DOT__inst)),32);
        bufp->chgIData(oldp+158,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0x14U) | ((0xff000U 
                                                 & vlSelf->TJUT_TOP__DOT__inst) 
                                                | ((0x800U 
                                                    & (vlSelf->TJUT_TOP__DOT__inst 
                                                       >> 9U)) 
                                                   | (0x7feU 
                                                      & (vlSelf->TJUT_TOP__DOT__inst 
                                                         >> 0x14U)))))),32);
        bufp->chgIData(oldp+159,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelf->TJUT_TOP__DOT__inst 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->TJUT_TOP__DOT__inst 
                                                     >> 7U))))),32);
        bufp->chgIData(oldp+160,((((- (IData)((vlSelf->TJUT_TOP__DOT__inst 
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
        bufp->chgCData(oldp+161,((7U | (((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte2) 
                                         << 5U) | (
                                                   ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte1) 
                                                    << 4U) 
                                                   | ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte0) 
                                                      << 3U))))),8);
        bufp->chgBit(oldp+162,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte0));
        bufp->chgBit(oldp+163,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte1));
        bufp->chgBit(oldp+164,(vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte2));
        bufp->chgIData(oldp+165,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                                 [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0xfU))]),32);
        bufp->chgIData(oldp+166,(((0U == (0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                                   >> 0xfU)))
                                   ? 0U : vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                                  [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                             >> 0xfU))])),32);
        bufp->chgIData(oldp+167,(vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                                 [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                            >> 0x14U))]),32);
        bufp->chgIData(oldp+168,(((0U == (0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf
                                  [(0x1fU & (vlSelf->TJUT_TOP__DOT__inst 
                                             >> 0x14U))])),32);
    }
    bufp->chgBit(oldp+169,(vlSelf->clk));
    bufp->chgBit(oldp+170,(vlSelf->rst));
    bufp->chgBit(oldp+171,(vlSelf->breakpoint));
    bufp->chgBit(oldp+172,(vlSelf->invalid));
    bufp->chgIData(oldp+173,(vlSelf->pc),32);
    bufp->chgIData(oldp+174,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgIData(oldp+175,(((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                               ? ((IData)(4U) + vlSelf->pc)
                               : vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result)),32);
    bufp->chgIData(oldp+176,(((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
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
    bufp->chgWData(oldp+177,(__Vtemp_h39811c99__0),144);
}

void VTJUT_TOP___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root__trace_cleanup\n"); );
    // Init
    VTJUT_TOP___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_TOP___024root*>(voidSelf);
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
