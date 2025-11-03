// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_SHIFT.h for the primary calling header

#include "verilated.h"

#include "VTJUT_SHIFT__Syms.h"
#include "VTJUT_SHIFT___024root.h"

VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_static(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_initial(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_initial\n"); );
}

VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_final(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_triggers__stl(VTJUT_SHIFT___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__stl(VTJUT_SHIFT___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_stl(VTJUT_SHIFT___024root* vlSelf);

VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_settle(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTJUT_SHIFT___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTJUT_SHIFT___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/TJUT_SHIFT.v", 2, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTJUT_SHIFT___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__stl(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VTJUT_SHIFT___024root___ico_sequent__TOP__0(VTJUT_SHIFT___024root* vlSelf);

VL_ATTR_COLD void VTJUT_SHIFT___024root___eval_stl(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VTJUT_SHIFT___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__ico(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__act(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__nba(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTJUT_SHIFT___024root___ctor_var_reset(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sft_data = VL_RAND_RESET_I(8);
    vlSelf->sft_num = VL_RAND_RESET_I(3);
    vlSelf->sft_dir = VL_RAND_RESET_I(1);
    vlSelf->is_signed = VL_RAND_RESET_I(1);
    vlSelf->sft_result = VL_RAND_RESET_I(8);
}
