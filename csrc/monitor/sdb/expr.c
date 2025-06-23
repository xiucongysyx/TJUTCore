#include <isa/isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/paddr.h>

enum {
  TK_NOTYPE = 256, TK_EQ, TK_NEGATIVE, TK_POINTER, TK_REG,
  TK_NEQ, TK_AND, TK_OR, TK_XOR,

  /* TODO: Add more token types */
  TK_NUMBER_D = 100 ,TK_NUMBER_X = 120,

  FIR_PRIORITY = 0, SEC_PRIORITY, THR_PRIORITY, FOUR_PRIORITY, FIVE_PRIORITY, SIX_PRIORITY, SEV_PRIORITY, EIG_PRIORITY,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {

  /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

  {" +", TK_NOTYPE},    // spaces
  {"\\+", '+'},         // plus
  {"\\-", '-'},         // minus
  {"\\*", '*'},         // multiply
  {"\\/", '/'},         // divide
  {"\\(", '('},         // left bracket
  {"\\)", ')'},         // right bracket
  {"==", TK_EQ},        // equal
  {"!=", TK_NEQ},       // no equal
  {"\\&\\&", TK_AND},   // and
  {"\\|\\|", TK_OR},    // or
  {"\\^", TK_XOR},   // xor
  {"\\$\\$*[a-z0-9]+", TK_REG},        // reg
  {"0x[0-9a-f]+", TK_NUMBER_X},// hex number
  {"[0-9]+", TK_NUMBER_D},// dec number
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

static void recode_token(int TK_C, int TK_type, int TK_len, char *TK_data);

static word_t eval(int p, int q, bool *success);

static bool check_parentheses(int p, int q, bool *success);

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[64] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        /****
        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);
        ****/

        position += substr_len;

        /* TODO: Now a new token is recognized with rules[i]. Add codes
         * to record the token in the array `tokens'. For certain types
         * of tokens, some extra actions should be performed.
         */

        switch (rules[i].token_type) {
          case TK_NOTYPE: break;
          case '+': case '-': case '*': case '/': case '(': case ')':  case TK_EQ: case TK_NEQ: case TK_AND: case TK_OR: case TK_XOR:
            recode_token(nr_token++, rules[i].token_type, 0, NULL);break;
          case TK_NUMBER_D: case TK_NUMBER_X: case TK_POINTER:
            recode_token(nr_token++, rules[i].token_type, substr_len, substr_start); break;
          case TK_REG: 
            recode_token(nr_token++, rules[i].token_type, substr_len - 1, substr_start + 1); break;
          default: printf("Input expr is incorrect.\n");break;
        }
        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  /* TODO: Insert codes to evaluate the expression. */
  //TODO();
  /****
  for(int i = 0; i < 32 ; i++) {
    //if(tokens[i].type == 0) break;
    printf("tokens[%d]: type = %c str = %s\n", i, tokens[i].type, tokens[i].str);
  }
  ****/

  return eval(0, nr_token - 1, success);
}

static void recode_token(int TK_C, int TK_type, int TK_len, char *TK_data) {
    if(TK_C == 0) {memset(tokens, 0, sizeof(tokens));}
    switch(TK_type) {
      case '-': 
        if(TK_C == 0 || tokens[TK_C - 1].type == '+' || tokens[TK_C - 1].type == '-' || tokens[TK_C - 1].type == '*' || tokens[TK_C - 1].type == '/' || tokens[TK_C - 1].type == '(' || tokens[TK_C - 1].type == TK_NEGATIVE)
          tokens[TK_C].type = TK_NEGATIVE;
        else
          tokens[TK_C].type = '-';
        break;
      case '*':
        if(TK_C == 0 || tokens[TK_C - 1].type == '+' || tokens[TK_C - 1].type == '-' || tokens[TK_C - 1].type == '*' || tokens[TK_C - 1].type == '/' || tokens[TK_C - 1].type == '(' || tokens[TK_C - 1].type == TK_NEGATIVE)
          tokens[TK_C].type = TK_POINTER;
        else
          tokens[TK_C].type = '*';
        break;
      default: tokens[TK_C].type = TK_type; break;
    }
    if(TK_data != NULL && TK_len != 0) {
      Assert(TK_len < 32, "The number is too long!");
      memcpy(tokens[TK_C].str, TK_data, TK_len);
    }
}

static word_t eval(int p, int q, bool *success) {
  if(*success == false) {return 0;}
  else if(p > q) {
    *success = false;
    printf("Please input expr!\n");
    return 0;
  }
  else if(p == q) {
    if(tokens[p].type == TK_NUMBER_D) {return atoi(tokens[p].str);}
    else if(tokens[p].type == TK_NUMBER_X) {return strtol(tokens[p].str,NULL,16);}
    else if(tokens[p].type == TK_REG) {return isa_reg_str2val(tokens[p].str, success);}
    else {
      printf("190:Expr is incorrect.\n");
      *success = false;
      return 0;
    }
  }
  else if(check_parentheses(p, q, success)) {return eval(p + 1, q - 1, success);}
  else {
    int min_priority = FIR_PRIORITY;
    int main_operator = -1;
    int parentheses_count = 0;
    word_t left_value, right_value;
    for(int i = p; i <= q; i++) {
      if(tokens[i].type == '(') {parentheses_count++;}
      else if(tokens[i].type == ')') {parentheses_count--; /***printf("')' p_count = %d\n", parentheses_count);***/}
      if(parentheses_count == 0) {
        switch (tokens[i].type) {
          case TK_OR:
            if(min_priority <= EIG_PRIORITY) {min_priority = EIG_PRIORITY; main_operator = i;} break;
          case TK_AND:
            if(min_priority <= SEV_PRIORITY) {min_priority = SEV_PRIORITY; main_operator = i;} break;
          case TK_XOR:
            if(min_priority <= SIX_PRIORITY) {min_priority = SIX_PRIORITY; main_operator = i;} break;
          case TK_NEQ: case TK_EQ:
            if(min_priority <= FIVE_PRIORITY) {min_priority = FIVE_PRIORITY; main_operator = i;} break;
          case '+': case '-': 
            if(min_priority <= FOUR_PRIORITY) {min_priority = FOUR_PRIORITY; main_operator = i;} break;
          case '*': case '/':
            if(min_priority <= THR_PRIORITY) {min_priority = THR_PRIORITY; main_operator = i;} break;
          case TK_NEGATIVE: case TK_POINTER: case TK_REG:
            if(min_priority < SEC_PRIORITY) {min_priority = SEC_PRIORITY; main_operator = i;} break;
          default: break;
        }
      }
      else if(parentheses_count < 0) {
        printf("Expr is incorrect.\n");
        *success = false;
        return 0;
        }
    }
    //printf("The main operator is %c and the main operator is %d.\n", tokens[main_operator].type, min_priority);
    if(main_operator != -1) {
      //printf("%d %d\n", main_operator, tokens[main_operator].type);
      if(tokens[main_operator].type == TK_NEGATIVE || tokens[main_operator].type == TK_POINTER) left_value = 0; 
      else {left_value = eval(p, main_operator - 1, success);}
      right_value = eval(main_operator + 1, q, success);
      switch (tokens[main_operator].type) {
        case '+': return left_value + right_value; break;
        case '-': return left_value - right_value; break;
        case '*': return left_value * right_value; break;
        case '/': if(right_value == 0) {printf("error: the divisor is 0.\n"); return 0;} 
                  else {return (word_t)((int)left_value / (int)right_value);}
                  break;
        case TK_NEGATIVE: return -right_value; break;
        case TK_REG: return isa_reg_str2val(tokens[main_operator].str, success); break;
        case TK_POINTER: return paddr_read(right_value, 4); 
        case TK_EQ: return left_value == right_value;
        case TK_NEQ: return left_value != right_value;
        case TK_AND: return left_value && right_value;
        case TK_OR: return left_value || right_value;
        case TK_XOR: return left_value ^ right_value;
        default: break;
      }
    }
  }
  printf("Expr error!\n");
  *success = false;
  return 0;
}

static bool check_parentheses(int p, int q, bool *success) {
  int count = 0;
  if(tokens[p].type != '(' || tokens[q].type != ')') {return false;}
  else {
    for(int i = p + 1; i < q; i++) {
      if(tokens[i].type == '(') count++;
      else if(tokens[i].type == ')') count--;
      if(count < 0) {return false;}
    }
    if(count != 0) {
      printf("Parentheses mismatch!\n");
      *success = false;
      return false;
    }
  }
  //printf("Match a pair of parentheses.\n");
  return true;
}