#include <common.h>

FILE *log_fp = NULL;
IFDEF(CONFIG_MTRACE, FILE *mtrace_fp = NULL);
IFDEF(CONFIG_FTRACE, FILE *ftrace_fp = NULL);
IFDEF(CONFIG_DTRACE, FILE *dtrace_fp = NULL);

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }

#ifdef CONFIG_MTRACE
  char mtrace_file[512];
  strcpy(mtrace_file, log_file);
  *(mtrace_file + (strlen(log_file) - strlen(".txt"))) = '\0';
  strcat(mtrace_file, ".mlog");
  if (mtrace_file != NULL) {
    FILE *fp = fopen(mtrace_file, "w");
    Assert(fp, "Can not open '%s'", mtrace_file);
    mtrace_fp = fp;
  }
  log_write(mtrace_fp, "==========npc_mtrace===========\n===============================\n");
#endif

#ifdef CONFIG_FTRACE
  char ftrace_file[512];
  strcpy(ftrace_file, log_file);
  *(ftrace_file + (strlen(log_file) - strlen(".txt"))) = '\0';
  strcat(ftrace_file, ".flog");
  if (ftrace_file != NULL) {
    FILE *fp = fopen(ftrace_file, "w");
    Assert(fp, "Can not open '%s'", ftrace_file);
    ftrace_fp = fp;
  }
  log_write(ftrace_fp, "==========npc_ftrace==========\n==========================\n");
#endif 

#ifdef CONFIG_DTRACE
  char dtrace_file[511];
  strcpy(dtrace_file, log_file);
  *(dtrace_file + (strlen(log_file) - strlen(".txt"))) = '\0';
  strcat(dtrace_file, ".dlog");
  if (dtrace_file != NULL) {
    FILE *fp = fopen(dtrace_file, "w");
    Assert(fp, "Can not open '%s'", dtrace_file);
    dtrace_fp = fp;
  }
  log_write(dtrace_fp, "==========npc_dtrace===========\n===============================\n");
#endif 

IFDEF(CONFIG_LOG, Log("Log is written to %s", SLASH(log_file, 4)));
}

