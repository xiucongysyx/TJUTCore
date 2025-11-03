// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_ADDER__Syms.h"


void VTJUT_ADDER___024root__trace_chg_sub_0(VTJUT_ADDER___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTJUT_ADDER___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_chg_top_0\n"); );
    // Init
    VTJUT_ADDER___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_ADDER___024root*>(voidSelf);
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTJUT_ADDER___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTJUT_ADDER___024root__trace_chg_sub_0(VTJUT_ADDER___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->TJUT_ADDER__DOT__adder_data2),8);
        bufp->chgCData(oldp+1,(vlSelf->TJUT_ADDER__DOT__level1G),7);
        bufp->chgCData(oldp+2,(vlSelf->TJUT_ADDER__DOT__level1P),7);
        bufp->chgCData(oldp+3,(vlSelf->TJUT_ADDER__DOT__level2G),7);
        bufp->chgCData(oldp+4,(vlSelf->TJUT_ADDER__DOT__level2P),7);
        bufp->chgCData(oldp+5,(vlSelf->TJUT_ADDER__DOT__level3G),7);
        bufp->chgCData(oldp+6,(vlSelf->TJUT_ADDER__DOT__level3P),7);
        bufp->chgCData(oldp+7,(vlSelf->TJUT_ADDER__DOT__level4G),7);
        bufp->chgCData(oldp+8,(vlSelf->TJUT_ADDER__DOT__level4P),7);
    }
    bufp->chgCData(oldp+9,(vlSelf->add_data1),8);
    bufp->chgCData(oldp+10,(vlSelf->add_data2),8);
    bufp->chgBit(oldp+11,(vlSelf->adder_sub));
    bufp->chgCData(oldp+12,(vlSelf->adder_out),8);
}

void VTJUT_ADDER___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_cleanup\n"); );
    // Init
    VTJUT_ADDER___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_ADDER___024root*>(voidSelf);
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
