// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTJUT_ADDER.h for the primary calling header

#include "verilated.h"

#include "VTJUT_ADDER__Syms.h"
#include "VTJUT_ADDER__Syms.h"
#include "VTJUT_ADDER___024root.h"

void VTJUT_ADDER___024root___ctor_var_reset(VTJUT_ADDER___024root* vlSelf);

VTJUT_ADDER___024root::VTJUT_ADDER___024root(VTJUT_ADDER__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTJUT_ADDER___024root___ctor_var_reset(this);
}

void VTJUT_ADDER___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VTJUT_ADDER___024root::~VTJUT_ADDER___024root() {
}
