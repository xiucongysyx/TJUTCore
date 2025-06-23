// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTJUT_TOP__SYMS_H_
#define VERILATED_VTJUT_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VTJUT_TOP.h"

// INCLUDE MODULE CLASSES
#include "VTJUT_TOP___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VTJUT_TOP__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VTJUT_TOP* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VTJUT_TOP___024root            TOP;

    // CONSTRUCTORS
    VTJUT_TOP__Syms(VerilatedContext* contextp, const char* namep, VTJUT_TOP* modelp);
    ~VTJUT_TOP__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
