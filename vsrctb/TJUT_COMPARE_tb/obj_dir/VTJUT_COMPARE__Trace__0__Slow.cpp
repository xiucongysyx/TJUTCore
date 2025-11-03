// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_COMPARE__Syms.h"


VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_init_sub__TOP__0(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+19,"com_data1", false,-1, 7,0);
    tracep->declBus(c+20,"com_data2", false,-1, 7,0);
    tracep->declBit(c+21,"is_signed", false,-1);
    tracep->declBus(c+22,"com_results", false,-1, 1,0);
    tracep->pushNamePrefix("TJUT_COMPARE ");
    tracep->declBus(c+19,"com_data1", false,-1, 7,0);
    tracep->declBus(c+20,"com_data2", false,-1, 7,0);
    tracep->declBit(c+21,"is_signed", false,-1);
    tracep->declBus(c+22,"com_results", false,-1, 1,0);
    tracep->declBus(c+19,"adder_data1", false,-1, 7,0);
    tracep->declBus(c+23,"adder_data2", false,-1, 7,0);
    tracep->declBus(c+1,"level1G", false,-1, 6,0);
    tracep->declBus(c+2,"level1P", false,-1, 6,0);
    tracep->declBit(c+3,"level2G_1", false,-1);
    tracep->declBit(c+4,"level2P_1", false,-1);
    tracep->declBit(c+5,"level2G_3", false,-1);
    tracep->declBit(c+6,"level2P_3", false,-1);
    tracep->declBit(c+7,"level2G_4", false,-1);
    tracep->declBit(c+8,"level2P_4", false,-1);
    tracep->declBit(c+9,"level2G_6", false,-1);
    tracep->declBit(c+10,"level2P_6", false,-1);
    tracep->declBit(c+11,"level3G_3", false,-1);
    tracep->declBit(c+12,"level3P_3", false,-1);
    tracep->declBit(c+13,"level3G_6", false,-1);
    tracep->declBit(c+14,"level3P_6", false,-1);
    tracep->declBit(c+15,"level4G_6", false,-1);
    tracep->declBit(c+16,"level4P_6", false,-1);
    tracep->declBit(c+17,"adder_out_7", false,-1);
    tracep->declBit(c+18,"ne_signed", false,-1);
    tracep->declBit(c+24,"com_lt_s", false,-1);
    tracep->declBit(c+25,"com_lt_u", false,-1);
    tracep->declBit(c+26,"com_eq", false,-1);
    tracep->declBit(c+27,"com_lt", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_init_top(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_init_top\n"); );
    // Body
    VTJUT_COMPARE___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_COMPARE___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_COMPARE___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_register(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTJUT_COMPARE___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTJUT_COMPARE___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTJUT_COMPARE___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_full_sub_0(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_full_top_0\n"); );
    // Init
    VTJUT_COMPARE___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_COMPARE___024root*>(voidSelf);
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTJUT_COMPARE___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTJUT_COMPARE___024root__trace_full_sub_0(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->TJUT_COMPARE__DOT__level1G),7);
    bufp->fullCData(oldp+2,(vlSelf->TJUT_COMPARE__DOT__level1P),7);
    bufp->fullBit(oldp+3,(vlSelf->TJUT_COMPARE__DOT__level2G_1));
    bufp->fullBit(oldp+4,(vlSelf->TJUT_COMPARE__DOT__level2P_1));
    bufp->fullBit(oldp+5,(vlSelf->TJUT_COMPARE__DOT__level2G_3));
    bufp->fullBit(oldp+6,(vlSelf->TJUT_COMPARE__DOT__level2P_3));
    bufp->fullBit(oldp+7,(vlSelf->TJUT_COMPARE__DOT__level2G_4));
    bufp->fullBit(oldp+8,(vlSelf->TJUT_COMPARE__DOT__level2P_4));
    bufp->fullBit(oldp+9,(vlSelf->TJUT_COMPARE__DOT__level2G_6));
    bufp->fullBit(oldp+10,(vlSelf->TJUT_COMPARE__DOT__level2P_6));
    bufp->fullBit(oldp+11,(vlSelf->TJUT_COMPARE__DOT__level3G_3));
    bufp->fullBit(oldp+12,(vlSelf->TJUT_COMPARE__DOT__level3P_3));
    bufp->fullBit(oldp+13,(vlSelf->TJUT_COMPARE__DOT__level3G_6));
    bufp->fullBit(oldp+14,(vlSelf->TJUT_COMPARE__DOT__level3P_6));
    bufp->fullBit(oldp+15,(vlSelf->TJUT_COMPARE__DOT__level4G_6));
    bufp->fullBit(oldp+16,(vlSelf->TJUT_COMPARE__DOT__level4P_6));
    bufp->fullBit(oldp+17,(vlSelf->TJUT_COMPARE__DOT__adder_out_7));
    bufp->fullBit(oldp+18,(vlSelf->TJUT_COMPARE__DOT__ne_signed));
    bufp->fullCData(oldp+19,(vlSelf->com_data1),8);
    bufp->fullCData(oldp+20,(vlSelf->com_data2),8);
    bufp->fullBit(oldp+21,(vlSelf->is_signed));
    bufp->fullCData(oldp+22,(vlSelf->com_results),2);
    bufp->fullCData(oldp+23,((0xffU & (~ (IData)(vlSelf->com_data2)))),8);
    bufp->fullBit(oldp+24,((1U & ((IData)(vlSelf->TJUT_COMPARE__DOT__ne_signed)
                                   ? ((~ ((IData)(vlSelf->com_data2) 
                                          >> 7U)) & 
                                      ((IData)(vlSelf->com_data1) 
                                       >> 7U)) : (IData)(vlSelf->TJUT_COMPARE__DOT__adder_out_7)))));
    bufp->fullBit(oldp+25,((1U & ((IData)(vlSelf->TJUT_COMPARE__DOT__ne_signed)
                                   ? ((~ ((IData)(vlSelf->com_data1) 
                                          >> 7U)) & 
                                      ((IData)(vlSelf->com_data2) 
                                       >> 7U)) : (IData)(vlSelf->TJUT_COMPARE__DOT__adder_out_7)))));
    bufp->fullBit(oldp+26,(((IData)(vlSelf->com_data1) 
                            == (IData)(vlSelf->com_data2))));
    bufp->fullBit(oldp+27,((1U & ((IData)(vlSelf->is_signed)
                                   ? ((IData)(vlSelf->TJUT_COMPARE__DOT__ne_signed)
                                       ? ((~ ((IData)(vlSelf->com_data2) 
                                              >> 7U)) 
                                          & ((IData)(vlSelf->com_data1) 
                                             >> 7U))
                                       : (IData)(vlSelf->TJUT_COMPARE__DOT__adder_out_7))
                                   : ((IData)(vlSelf->TJUT_COMPARE__DOT__ne_signed)
                                       ? ((~ ((IData)(vlSelf->com_data1) 
                                              >> 7U)) 
                                          & ((IData)(vlSelf->com_data2) 
                                             >> 7U))
                                       : (IData)(vlSelf->TJUT_COMPARE__DOT__adder_out_7))))));
}
