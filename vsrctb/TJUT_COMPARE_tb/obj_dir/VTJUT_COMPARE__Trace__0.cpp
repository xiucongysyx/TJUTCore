// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_COMPARE__Syms.h"


void VTJUT_COMPARE___024root__trace_chg_sub_0(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTJUT_COMPARE___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_chg_top_0\n"); );
    // Init
    VTJUT_COMPARE___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_COMPARE___024root*>(voidSelf);
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTJUT_COMPARE___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTJUT_COMPARE___024root__trace_chg_sub_0(VTJUT_COMPARE___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->TJUT_COMPARE__DOT__level1G),7);
        bufp->chgCData(oldp+1,(vlSelf->TJUT_COMPARE__DOT__level1P),7);
        bufp->chgBit(oldp+2,(vlSelf->TJUT_COMPARE__DOT__level2G_1));
        bufp->chgBit(oldp+3,(vlSelf->TJUT_COMPARE__DOT__level2P_1));
        bufp->chgBit(oldp+4,(vlSelf->TJUT_COMPARE__DOT__level2G_3));
        bufp->chgBit(oldp+5,(vlSelf->TJUT_COMPARE__DOT__level2P_3));
        bufp->chgBit(oldp+6,(vlSelf->TJUT_COMPARE__DOT__level2G_4));
        bufp->chgBit(oldp+7,(vlSelf->TJUT_COMPARE__DOT__level2P_4));
        bufp->chgBit(oldp+8,(vlSelf->TJUT_COMPARE__DOT__level2G_6));
        bufp->chgBit(oldp+9,(vlSelf->TJUT_COMPARE__DOT__level2P_6));
        bufp->chgBit(oldp+10,(vlSelf->TJUT_COMPARE__DOT__level3G_3));
        bufp->chgBit(oldp+11,(vlSelf->TJUT_COMPARE__DOT__level3P_3));
        bufp->chgBit(oldp+12,(vlSelf->TJUT_COMPARE__DOT__level3G_6));
        bufp->chgBit(oldp+13,(vlSelf->TJUT_COMPARE__DOT__level3P_6));
        bufp->chgBit(oldp+14,(vlSelf->TJUT_COMPARE__DOT__level4G_6));
        bufp->chgBit(oldp+15,(vlSelf->TJUT_COMPARE__DOT__level4P_6));
        bufp->chgBit(oldp+16,(vlSelf->TJUT_COMPARE__DOT__adder_out_7));
        bufp->chgBit(oldp+17,(vlSelf->TJUT_COMPARE__DOT__ne_signed));
    }
    bufp->chgCData(oldp+18,(vlSelf->com_data1),8);
    bufp->chgCData(oldp+19,(vlSelf->com_data2),8);
    bufp->chgBit(oldp+20,(vlSelf->is_signed));
    bufp->chgCData(oldp+21,(vlSelf->com_results),2);
    bufp->chgCData(oldp+22,((0xffU & (~ (IData)(vlSelf->com_data2)))),8);
    bufp->chgBit(oldp+23,((1U & ((IData)(vlSelf->TJUT_COMPARE__DOT__ne_signed)
                                  ? ((~ ((IData)(vlSelf->com_data2) 
                                         >> 7U)) & 
                                     ((IData)(vlSelf->com_data1) 
                                      >> 7U)) : (IData)(vlSelf->TJUT_COMPARE__DOT__adder_out_7)))));
    bufp->chgBit(oldp+24,((1U & ((IData)(vlSelf->TJUT_COMPARE__DOT__ne_signed)
                                  ? ((~ ((IData)(vlSelf->com_data1) 
                                         >> 7U)) & 
                                     ((IData)(vlSelf->com_data2) 
                                      >> 7U)) : (IData)(vlSelf->TJUT_COMPARE__DOT__adder_out_7)))));
    bufp->chgBit(oldp+25,(((IData)(vlSelf->com_data1) 
                           == (IData)(vlSelf->com_data2))));
    bufp->chgBit(oldp+26,((1U & ((IData)(vlSelf->is_signed)
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

void VTJUT_COMPARE___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_COMPARE___024root__trace_cleanup\n"); );
    // Init
    VTJUT_COMPARE___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_COMPARE___024root*>(voidSelf);
    VTJUT_COMPARE__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
