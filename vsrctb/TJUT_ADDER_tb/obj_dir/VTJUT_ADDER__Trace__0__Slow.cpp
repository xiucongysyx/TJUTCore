// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTJUT_ADDER__Syms.h"


VL_ATTR_COLD void VTJUT_ADDER___024root__trace_init_sub__TOP__0(VTJUT_ADDER___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+10,"add_data1", false,-1, 7,0);
    tracep->declBus(c+11,"add_data2", false,-1, 7,0);
    tracep->declBit(c+12,"adder_sub", false,-1);
    tracep->declBus(c+13,"adder_out", false,-1, 7,0);
    tracep->pushNamePrefix("TJUT_ADDER ");
    tracep->declBus(c+10,"add_data1", false,-1, 7,0);
    tracep->declBus(c+11,"add_data2", false,-1, 7,0);
    tracep->declBit(c+12,"adder_sub", false,-1);
    tracep->declBus(c+13,"adder_out", false,-1, 7,0);
    tracep->declBus(c+10,"adder_data1", false,-1, 7,0);
    tracep->declBus(c+1,"adder_data2", false,-1, 7,0);
    tracep->declBus(c+2,"level1G", false,-1, 6,0);
    tracep->declBus(c+3,"level1P", false,-1, 6,0);
    tracep->declBus(c+4,"level2G", false,-1, 6,0);
    tracep->declBus(c+5,"level2P", false,-1, 6,0);
    tracep->declBus(c+6,"level3G", false,-1, 6,0);
    tracep->declBus(c+7,"level3P", false,-1, 6,0);
    tracep->declBus(c+8,"level4G", false,-1, 6,0);
    tracep->declBus(c+9,"level4P", false,-1, 6,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_init_top(VTJUT_ADDER___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_init_top\n"); );
    // Body
    VTJUT_ADDER___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_ADDER___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VTJUT_ADDER___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_register(VTJUT_ADDER___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&VTJUT_ADDER___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&VTJUT_ADDER___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&VTJUT_ADDER___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_full_sub_0(VTJUT_ADDER___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_full_top_0\n"); );
    // Init
    VTJUT_ADDER___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VTJUT_ADDER___024root*>(voidSelf);
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VTJUT_ADDER___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VTJUT_ADDER___024root__trace_full_sub_0(VTJUT_ADDER___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->TJUT_ADDER__DOT__adder_data2),8);
    bufp->fullCData(oldp+2,(vlSelf->TJUT_ADDER__DOT__level1G),7);
    bufp->fullCData(oldp+3,(vlSelf->TJUT_ADDER__DOT__level1P),7);
    bufp->fullCData(oldp+4,(vlSelf->TJUT_ADDER__DOT__level2G),7);
    bufp->fullCData(oldp+5,(vlSelf->TJUT_ADDER__DOT__level2P),7);
    bufp->fullCData(oldp+6,(vlSelf->TJUT_ADDER__DOT__level3G),7);
    bufp->fullCData(oldp+7,(vlSelf->TJUT_ADDER__DOT__level3P),7);
    bufp->fullCData(oldp+8,(vlSelf->TJUT_ADDER__DOT__level4G),7);
    bufp->fullCData(oldp+9,(vlSelf->TJUT_ADDER__DOT__level4P),7);
    bufp->fullCData(oldp+10,(vlSelf->add_data1),8);
    bufp->fullCData(oldp+11,(vlSelf->add_data2),8);
    bufp->fullBit(oldp+12,(vlSelf->adder_sub));
    bufp->fullCData(oldp+13,(vlSelf->adder_out),8);
}
