// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_SHIFT__Syms.h"


void VTJUT_SHIFT___024root__trace_chg_sub_0(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VTJUT_SHIFT___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_chg_top_0\n"); );
    // Init
    VTJUT_SHIFT___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_SHIFT___024root*>(voidSelf);
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VTJUT_SHIFT___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void VTJUT_SHIFT___024root__trace_chg_sub_0(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->sft_data),8);
    bufp->chgCData(oldp+1,(vlSelf->sft_num),3);
    bufp->chgBit(oldp+2,(vlSelf->sft_dir));
    bufp->chgBit(oldp+3,(vlSelf->is_signed));
    bufp->chgCData(oldp+4,(vlSelf->sft_result),8);
}

void VTJUT_SHIFT___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_cleanup\n"); );
    // Init
    VTJUT_SHIFT___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_SHIFT___024root*>(voidSelf);
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
