#include <isa/isa.h>

#define NR_WP 32

typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */

  char expr[64];
  word_t result;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

static WP *new_wp() {
  if(free_ == NULL) {printf("No more available watchpoints.\n"); return NULL;}
  WP *new_wp = free_;
  free_ = free_->next;
  new_wp->next = head;
  head = new_wp;
  return new_wp;
}

static void free_wp(WP *wp) {
  if(wp == NULL) {printf("Invalid watchpoint to free.\n"); return;}
  if(wp == head) {
    head = head->next;
    wp->next = free_;
    free_ = wp;
    memset(wp->expr, 0, strlen(wp->expr));
    wp->result = 0;
  }
  else {
    WP *pro_wp = head;
    while(pro_wp->next != wp) {
      if(pro_wp->next == NULL) {printf("The watchpoint to be deleted does not exit.\n"); return;}
      pro_wp = pro_wp->next;
    }
    pro_wp->next = wp->next;
    wp->next = free_;
    free_ = wp;
    memset(wp->expr, 0, strlen(wp->expr));
    wp->result = 0;
  }
}

void wp_add(char *args) {
  char *arg = args;
  bool success = true;
  word_t ret = expr(arg, &success);
  if(success == false) return;
  WP *wp = new_wp();
  memcpy(wp->expr, arg, strlen(arg));
  wp->result = ret;
  printf("%d: %s\n", wp->NO, wp->expr);
  return;
}

bool wp_watch() {
  WP *wp = head;
  bool change = false;
  while(wp != NULL) {
    bool success = true;
    word_t new_ret = expr(wp->expr, &success);
    if(success == false) return change;
    if(wp->result != new_ret) {
      change = true;
      printf("Watchpoint %d: %s\ncpu.pc: 0x%x\n", wp->NO, wp->expr, *cpu.pc);
      printf("Old value = %d\nNew value = %d\n", wp->result, new_ret);
      wp->result = new_ret;
    }
    wp = wp->next;
  }
  return change;
}

void wp_display() {
  WP *wp = head;
  if(wp == NULL) {printf("Watchpoint not set.\n"); return;}
  printf("Num What\n");
  while(wp != NULL) {
    printf("%-4d%s\n", wp->NO, wp->expr);
    wp = wp->next;
  }
}

void wp_delete(int NO) {
  WP *wp = head;
  while(wp != NULL) {
    if(wp->NO == NO) {
      free_wp(wp);
      printf("The watchpoint %d has been deleted.\n", wp->NO);
      return;
    }
    wp = wp->next;
  }
  printf("The watchpoint to be deleted is not set.\n");
  return;
}
