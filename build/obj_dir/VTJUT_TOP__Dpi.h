// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VTJUT_TOP__DPI_H_
#define VERILATED_VTJUT_TOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/xiucong/TJUTCore/vsrc/TJUT_IF.v:17:30
    extern void cpu_pmem_read(int raddr, int* rdata, char rmask);
    // DPI import at /home/xiucong/TJUTCore/vsrc/TJUT_MC.v:44:30
    extern void cpu_pmem_write(int waddr, int wdata, char wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard
