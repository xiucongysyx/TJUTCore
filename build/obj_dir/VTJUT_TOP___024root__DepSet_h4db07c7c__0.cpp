// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_TOP.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTJUT_TOP__Syms.h"
#include "VTJUT_TOP___024root.h"

void VTJUT_TOP___024root___eval_act(VTJUT_TOP___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root___eval_act\n"); );
}

void VTJUT_TOP___024root____Vdpiimwrap_TJUT_TOP__DOT__u_TJUT_IF__DOT__cpu_pmem_read_TOP(IData/*31:0*/ raddr, IData/*31:0*/ &rdata, CData/*7:0*/ rmask);

VL_INLINE_OPT void VTJUT_TOP___024root___nba_sequent__TOP__0(VTJUT_TOP___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vtask_TJUT_TOP__DOT__u_TJUT_IF__DOT__cpu_pmem_read__0__rdata;
    __Vtask_TJUT_TOP__DOT__u_TJUT_IF__DOT__cpu_pmem_read__0__rdata = 0;
    // Body
    if (vlSelf->rst) {
        vlSelf->pc = 0x80000000U;
    } else {
        VTJUT_TOP___024root____Vdpiimwrap_TJUT_TOP__DOT__u_TJUT_IF__DOT__cpu_pmem_read_TOP(vlSelf->TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc, __Vtask_TJUT_TOP__DOT__u_TJUT_IF__DOT__cpu_pmem_read__0__rdata, 4U);
        vlSelf->TJUT_TOP__DOT__inst = __Vtask_TJUT_TOP__DOT__u_TJUT_IF__DOT__cpu_pmem_read__0__rdata;
        vlSelf->pc = vlSelf->TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc;
    }
    vlSelf->breakpoint = (0x100073U == vlSelf->TJUT_TOP__DOT__inst);
    vlSelf->invalid = (0U != vlSelf->TJUT_TOP__DOT__inst);
    vlSelf->TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc = ((IData)(4U) 
                                                   + vlSelf->pc);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[2U] 
        = (0x200000000ULL | (QData)((IData)(((IData)(4U) 
                                             + vlSelf->pc))));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[2U] 
        = ((IData)(4U) + vlSelf->pc);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[0U] 
        = (0x800000000ULL | (QData)((IData)(((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                              ? vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result
                                              : ((IData)(4U) 
                                                 + vlSelf->pc)))));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list[1U] 
        = (0x400000000ULL | (QData)((IData)(((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31)
                                              ? ((IData)(4U) 
                                                 + vlSelf->pc)
                                              : vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result))));
    if (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31) {
        vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[0U] 
            = vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result;
        vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[1U] 
            = ((IData)(4U) + vlSelf->pc);
    } else {
        vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[0U] 
            = ((IData)(4U) + vlSelf->pc);
        vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list[1U] 
            = vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result;
    }
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit)
            ? vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out
            : 0U);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list[3U] 
        = (0x2000000000ULL | (QData)((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result)));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list[3U] 
        = vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result;
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
           [0U]);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
           [0U]);
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [1U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [1U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [2U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [2U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [3U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [4U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [4U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [5U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [5U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [5U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
        = (vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
                          [6U]))) & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list
              [6U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit) 
           | (0U == vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list
              [6U]));
    vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result 
        = ((IData)(vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit)
            ? vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out
            : 0U);
    vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte2 
        = (IData)((3U == (3U & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result)));
    vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte1 
        = (IData)((2U == (3U & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result)));
    vlSelf->TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte0 
        = (IData)((1U == (3U & vlSelf->TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result)));
}

void VTJUT_TOP___024root___eval_nba(VTJUT_TOP___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VTJUT_TOP___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VTJUT_TOP___024root___eval_triggers__act(VTJUT_TOP___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_TOP___024root___dump_triggers__act(VTJUT_TOP___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTJUT_TOP___024root___dump_triggers__nba(VTJUT_TOP___024root* vlSelf);
#endif  // VL_DEBUG

void VTJUT_TOP___024root___eval(VTJUT_TOP___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            VTJUT_TOP___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTJUT_TOP___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/xiucong/TJUTCore/vsrc/TJUT_TOP.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
                VTJUT_TOP___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTJUT_TOP___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/xiucong/TJUTCore/vsrc/TJUT_TOP.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTJUT_TOP___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTJUT_TOP___024root___eval_debug_assertions(VTJUT_TOP___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTJUT_TOP__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTJUT_TOP___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
