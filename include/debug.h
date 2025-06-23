#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <common.h>
#include <stdio.h>
#include <utils.h>

#define Log(format, ...) \
  do { \
    const char *file = __FILE__; \
    const char *csrc_start = strstr(file, "csrc"); \
    _Log(ANSI_FMT("[%s:%d %s] " format, ANSI_FG_BLUE) "\n", \
        csrc_start, __LINE__, __func__, ## __VA_ARGS__); \
  } while (0)

#define Assert(cond, format, ...) \
  do { \
    if (!(cond)) { \
      (fflush(stdout), fprintf(stderr, ANSI_FMT(format, ANSI_FG_RED) "\n", ##  __VA_ARGS__)); \
      extern FILE* log_fp; \
      assert(cond); \
    } \
  } while (0)

#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

#define TODO() panic("please implement me")

#endif