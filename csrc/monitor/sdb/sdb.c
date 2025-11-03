#include <common.h>
#include <cpu/cpu.h>
#include <isa/isa.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <utils.h>
#include <memory/paddr.h>

int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void isa_exit();
void wp_add(char *args);
void wp_display();
void wp_watch();
void wp_delete(int NO);

static char* rl_gets() {
  static char *line_read = NULL;

  if(line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");
  if(strlen(line_read) == 0) {
    HIST_ENTRY *previous_command = previous_history();
    if(previous_command) line_read = previous_command->line;
    else line_read = NULL;
  }

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args);
static int cmd_q(char *args);
static int cmd_x(char *args);
static int cmd_p(char *args);
static int cmd_w(char *args);
static int cmd_d(char *args);
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "x", "Scan memory", cmd_x },
  { "p", "Print result of expr", cmd_p},
  { "w", "Add a watchpoint", cmd_w},
  { "d", "Delete a watchpoint", cmd_d},
  { "si", "Execution step", cmd_si },
  { "info", "Info reg or info watch point", cmd_info},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_q(char *args) {
  npc_state.state = NPC_QUIT;
  isa_exit();
  return -1;
}

static int cmd_x(char *args) {
  char *N = strtok(NULL, " ");
  char *EXPR = strtok(NULL, " ");
  int n;
  paddr_t memory;
  paddr_t expr;
  if(N != NULL && EXPR != NULL && isdigit(*N)) {
    EXPR += 2;
    n = atoi(N);
    expr = strtol(EXPR, NULL, 16);
    for(int i = 0; i < n; i++) {
      memory = paddr_read(expr, 4);
      printf("0x%x: %-10x %-10d\n", expr, memory, memory);
      expr += 4;
    }
  }
  else {
    printf("USGE: x N EXPR\n");
    return 0;
  }
  return 0;
}

static int cmd_p(char *args) {
  char *arg1 = strtok(NULL, " ");
  char *arg2 = strtok(NULL, "\n");
  bool success = true;
  if(*arg1 != 'u' && *arg1 != 'x' && *arg1 != 'd') {
    printf("Please input format!\n");
    return 0;
  }

  if(arg2 == NULL) {
    printf("Please input expr!\n");
    return 0;
  }

  word_t result;
  result = expr(arg2, &success); 
  if(*arg1 == 'd') {printf("Expr:%s = %d\n", arg2, result);}
  else if (*arg1 == 'u'){printf("Expr:%s = %u\n", arg2, result);}
  else {printf("Expr:%s = %x\n", arg2, result);}
  return 0;
}

static int cmd_w(char *args) {
  char *arg = strtok(NULL, "\n");
  if(arg == NULL) {
    printf("Please input expr!\n");
    return 0;
  }
  wp_add(arg);
  return 0;
}

static int cmd_d(char *args) {
  char *arg = strtok(NULL, "\n");
  for(int i = 0; arg[i] != '\0'; i++) {
     if(!isdigit(arg[i])) {printf("Please input correct num.\n"); return 0;}
  }
  int NO = atoi(arg);
  wp_delete(NO);
  return 0;
}

static int cmd_si(char *args) {
    int n;
    char *arg = strtok(NULL, " ");
    if(arg == NULL) {n = 1;} 
    else {
      if(!isdigit(*arg)) {
        printf("USGE:si [n].\n");
        return 0;}
      else { n = atoi(arg);}
    }
    cpu_exec(n);
    return 0;
}

static int cmd_info(char *args) {
  char *arg = strtok(NULL, " ");
  if(arg == NULL) {
    printf("USGE:Using \'info r\' to print reg or using \'info w\' to print watch point\n");
    return 0;
  }
  if(strcmp(arg, "r") == 0) {isa_reg_display();}
  else if(strcmp(arg, "w") ==0) {wp_display();}
  else {
    printf("USGE:Using \'info r\' to print reg or using \'info w\' to print watch point\n");
  }
  return 0;
}

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL;) {
    char *str_end = str + strlen(str);

    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }
    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  init_regex();

  init_wp_pool();
}