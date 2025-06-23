// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_TOP.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTJUT_TOP__Syms.h"
#include "VTJUT_TOP__Syms.h"
#include "VTJUT_TOP___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_TOP___024root___dump_triggers__stl(VTJUT_TOP___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VTJUT_TOP___024root___eval_triggers__stl(VTJUT_TOP___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (0U == vlSelf->__VstlIterCount));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VTJUT_TOP___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
