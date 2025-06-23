#ifndef __UTILS_H__
#define __UTILS_H__

#include <common.h>

enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

typedef struct {
  int state;
  vaddr_t halt_pc;
  uint32_t halt_ret;
} NPCState;

extern NPCState npc_state;

uint64_t get_time();

#define ANSI_FG_BLACK   "\33[1;30m"
#define ANSI_FG_RED     "\33[1;31m"
#define ANSI_FG_GREEN   "\33[1;32m"
#define ANSI_FG_YELLOW  "\33[1;33m"
#define ANSI_FG_BLUE    "\33[1;34m"
#define ANSI_FG_MAGENTA "\33[1;35m"
#define ANSI_FG_CYAN    "\33[1;36m"
#define ANSI_FG_WHITE   "\33[1;37m"
#define ANSI_BG_BLACK   "\33[1;40m"
#define ANSI_BG_RED     "\33[1;41m"
#define ANSI_BG_GREEN   "\33[1;42m"
#define ANSI_BG_YELLOW  "\33[1;43m"
#define ANSI_BG_BLUE    "\33[1;44m"
#define ANSI_BG_MAGENTA "\33[1;35m"
#define ANSI_BG_CYAN    "\33[1;46m"
#define ANSI_BG_WHITE   "\33[1;47m"
#define ANSI_NONE       "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

extern FILE *log_fp;
extern FILE *ftrace_fp;
extern FILE *mtrace_fp;
extern FILE *dtrace_fp;

#define log_write(fp, ...) IFDEF(CONFIG_LOG, \
  do { \
    fprintf(fp, __VA_ARGS__); \
    fflush(fp); \
  } while (0) \
)

#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(log_fp, __VA_ARGS__); \
  } while (0)

#define SLASH(str, n) ({ \
    const char *nth_slash = (str); \
    for (int i = 0; i < (n); ++i) { \
        nth_slash = strchr(nth_slash, '/'); \
        if (nth_slash == NULL) { \
            nth_slash = (str) + strlen(str); \
            break; \
        } \
        nth_slash++; \
    } \
    nth_slash; \
})

#endif