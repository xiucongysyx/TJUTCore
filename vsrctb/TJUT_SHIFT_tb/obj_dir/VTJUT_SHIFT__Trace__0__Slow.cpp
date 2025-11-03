// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_SHIFT__Syms.h"


VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_init_sub__TOP__0(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"sft_data", false,-1, 7,0);
    tracep->declBus(c+2,"sft_num", false,-1, 2,0);
    tracep->declBit(c+3,"sft_dir", false,-1);
    tracep->declBit(c+4,"is_signed", false,-1);
    tracep->declBus(c+5,"sft_result", false,-1, 7,0);
    tracep->pushNamePrefix("TJUT_SHIFT ");
    tracep->declBus(c+1,"sft_data", false,-1, 7,0);
    tracep->declBus(c+2,"sft_num", false,-1, 2,0);
    tracep->declBit(c+3,"sft_dir", false,-1);
    tracep->declBit(c+4,"is_signed", false,-1);
    tracep->declBus(c+5,"sft_result", false,-1, 7,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_init_top(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_init_top\n"); );
    // Body
    VTJUT_SHIFT___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_SHIFT___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_SHIFT___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_register(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTJUT_SHIFT___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTJUT_SHIFT___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTJUT_SHIFT___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_full_sub_0(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_full_top_0\n"); );
    // Init
    VTJUT_SHIFT___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_SHIFT___024root*>(voidSelf);
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTJUT_SHIFT___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTJUT_SHIFT___024root__trace_full_sub_0(VTJUT_SHIFT___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->sft_data),8);
    bufp->fullCData(oldp+2,(vlSelf->sft_num),3);
    bufp->fullBit(oldp+3,(vlSelf->sft_dir));
    bufp->fullBit(oldp+4,(vlSelf->is_signed));
    bufp->fullCData(oldp+5,(vlSelf->sft_result),8);
}
