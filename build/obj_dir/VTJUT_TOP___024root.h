// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTJUT_TOP.h for the primary calling header

#ifndef VERILATED_VTJUT_TOP___024ROOT_H_
#define VERILATED_VTJUT_TOP___024ROOT_H_  // guard

#include "verilated.h"


class VTJUT_TOP__Syms;

class alignas(VL_CACHE_LINE_BYTES) VTJUT_TOP___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        VL_OUT8(breakpoint,0,0);
        VL_OUT8(invalid,0,0);
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_28;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_26;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_24;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_22;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_20;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_18;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_16;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_12;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_10;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_8;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_6;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_4;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level2P_2;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_26;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_26;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_22;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_22;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_18;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_18;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_10;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_10;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_6;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_6;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3G_2;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level3P_2;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_22;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_22;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4G_6;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level4P_6;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5G_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5P_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5G_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level5P_14;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level6G_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__level6P_30;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_COMPARE__DOT__adder_out_31;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__hit;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__hit;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte0;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte1;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_MC__DOT__addr_byte2;
        CData/*0:0*/ TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__hit;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        VL_OUT(pc,31,0);
        IData/*31:0*/ TJUT_TOP__DOT__inst;
        IData/*31:0*/ TJUT_TOP__DOT__memregdata;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_IF__DOT__dnpc;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__add_result;
    };
    struct {
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__log_result;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__bra_result;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__ex_result;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level2G;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level2P;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level3G;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level3P;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level4G;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level4P;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level5G;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level5P;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level6G;
        IData/*30:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u_TJUT_ADDER__DOT__level6P;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__lut_out;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__lut_out;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out;
        IData/*31:0*/ TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__lut_out;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*34:0*/, 3> TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*2:0*/, 3> TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 3> TJUT_TOP__DOT__u_TJUT_EX__DOT__u2_MuxKeyWithDefault__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*35:0*/, 4> TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*3:0*/, 4> TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 4> TJUT_TOP__DOT__u_TJUT_EX__DOT__u1_MuxKeyWithDefault__DOT__i0__DOT__data_list;
        VlUnpacked<QData/*38:0*/, 7> TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*6:0*/, 7> TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 7> TJUT_TOP__DOT__u_TJUT_EX__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list;
        VlUnpacked<IData/*31:0*/, 32> TJUT_TOP__DOT__u_TJUT_WB__DOT__u_TJUT_REGFILE__DOT__rf;
        VlUnpacked<QData/*34:0*/, 4> TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__pair_list;
        VlUnpacked<CData/*2:0*/, 4> TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__key_list;
        VlUnpacked<IData/*31:0*/, 4> TJUT_TOP__DOT__u_TJUT_MC__DOT__u0_MuxKeyWithDefault__DOT__i0__DOT__data_list;
        VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTJUT_TOP__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTJUT_TOP___024root(VTJUT_TOP__Syms* symsp, const char* v__name);
    ~VTJUT_TOP___024root();
    VL_UNCOPYABLE(VTJUT_TOP___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
