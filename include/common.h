#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

// 宏定义参数
#include <generated/autoconf.h>
#include <macro.h>

#include <assert.h>
#include <stdlib.h>
#include <regex.h>

// verilator
#include <verilated.h>
#include <verilated_vcd_c.h>
#include <VTJUT_TOP.h>
#include <VTJUT_TOP___024root.h> 

typedef uint32_t word_t;
typedef int32_t sword_t;
#define FMT_WORD "0x%08" PRIx32

typedef word_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_PADDR "0x%08" PRIx32
typedef uint16_t ioaddr_t;

#include <debug.h>

#endif