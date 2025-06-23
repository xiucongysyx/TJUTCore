// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_TOP.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTJUT_TOP__Syms.h"
#include "VTJUT_TOP__Syms.h"
#include "VTJUT_TOP___024root.h"

void VTJUT_TOP___024root___ctor_var_reset(VTJUT_TOP___024root* vlSelf);

VTJUT_TOP___024root::VTJUT_TOP___024root(VTJUT_TOP__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTJUT_TOP___024root___ctor_var_reset(this);
}

void VTJUT_TOP___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VTJUT_TOP___024root::~VTJUT_TOP___024root() {
}
