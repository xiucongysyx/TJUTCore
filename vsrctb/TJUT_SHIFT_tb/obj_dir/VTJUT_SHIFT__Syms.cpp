// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTJUT_SHIFT__Syms.h"
#include "VTJUT_SHIFT.h"
#include "VTJUT_SHIFT___024root.h"

// FUNCTIONS
VTJUT_SHIFT__Syms::~VTJUT_SHIFT__Syms()
{
}

VTJUT_SHIFT__Syms::VTJUT_SHIFT__Syms(VerilatedContext* contextp, const char* namep, VTJUT_SHIFT* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
