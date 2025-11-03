// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_SHIFT.h for the primary calling header

#include "verilated.h"

#include "VTJUT_SHIFT__Syms.h"
#include "VTJUT_SHIFT___024root.h"

extern const VlUnpacked<CData/*7:0*/, 8192> VTJUT_SHIFT__ConstPool__TABLE_hf9d0dfec_0;

VL_INLINE_OPT void VTJUT_SHIFT___024root___ico_sequent__TOP__0(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___ico_sequent__TOP__0\n"); );
    // Init
    SData/*12:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->sft_data) << 5U) 
                    | (((IData)(vlSelf->sft_num) << 2U) 
                       | (((IData)(vlSelf->is_signed) 
                           << 1U) | (IData)(vlSelf->sft_dir))));
    vlSelf->sft_result = VTJUT_SHIFT__ConstPool__TABLE_hf9d0dfec_0
        [__Vtableidx1];
}

void VTJUT_SHIFT___024root___eval_ico(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VTJUT_SHIFT___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VTJUT_SHIFT___024root___eval_act(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_act\n"); );
}

void VTJUT_SHIFT___024root___eval_nba(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_nba\n"); );
}

void VTJUT_SHIFT___024root___eval_triggers__ico(VTJUT_SHIFT___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__ico(VTJUT_SHIFT___024root* vlSelf);
#endif  // VL_DEBUG
void VTJUT_SHIFT___024root___eval_triggers__act(VTJUT_SHIFT___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__act(VTJUT_SHIFT___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_SHIFT___024root___dump_triggers__nba(VTJUT_SHIFT___024root* vlSelf);
#endif  // VL_DEBUG

void VTJUT_SHIFT___024root___eval(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VTJUT_SHIFT___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VTJUT_SHIFT___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/TJUT_SHIFT.v", 2, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VTJUT_SHIFT___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VTJUT_SHIFT___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTJUT_SHIFT___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/TJUT_SHIFT.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VTJUT_SHIFT___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTJUT_SHIFT___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/TJUT_SHIFT.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTJUT_SHIFT___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTJUT_SHIFT___024root___eval_debug_assertions(VTJUT_SHIFT___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_SHIFT__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_SHIFT___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->sft_num & 0xf8U))) {
        Verilated::overWidthError("sft_num");}
    if (VL_UNLIKELY((vlSelf->sft_dir & 0xfeU))) {
        Verilated::overWidthError("sft_dir");}
    if (VL_UNLIKELY((vlSelf->is_signed & 0xfeU))) {
        Verilated::overWidthError("is_signed");}
}
#endif  // VL_DEBUG
