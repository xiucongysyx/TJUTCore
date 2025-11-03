// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_ADDER.h for the primary calling header

#include "verilated.h"

#include "VTJUT_ADDER__Syms.h"
#include "VTJUT_ADDER__Syms.h"
#include "VTJUT_ADDER___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_ADDER___024root___dump_triggers__ico(VTJUT_ADDER___024root* vlSelf);
#endif  // VL_DEBUG

void VTJUT_ADDER___024root___eval_triggers__ico(VTJUT_ADDER___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (0U == vlSelf->__VicoIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTJUT_ADDER___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_ADDER___024root___dump_triggers__act(VTJUT_ADDER___024root* vlSelf);
#endif  // VL_DEBUG

void VTJUT_ADDER___024root___eval_triggers__act(VTJUT_ADDER___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_ADDER__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_ADDER___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTJUT_ADDER___024root___dump_triggers__act(vlSelf);
    }
#endif
}
