#ifndef __MACRO_H__
#define __MACRO_H__

#include <string.h>

#define str_tmep(x) #x
#define str(x) str_tmep(x)

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#define concat_temp(x, y) x ## y
#define concat(x, y) concat_temp(x, y)

#define CHOOSE2nd(a, b, ...) b
#define MUX_WITH_COMMA(contain_comma, a, b) CHOOSE2nd(contain_comma a, b)
#define MUX_MACRO_PROPERTY(p, macro, a, b) MUX_WITH_COMMA(concat(p, macro), a, b)

#define __P_DEF_0  X,
#define __P_DEF_1  X,

#define MUXDEF(macro, X, Y)  MUX_MACRO_PROPERTY(__P_DEF_, macro, X, Y)
#define MUXNDEF(macro, X, Y) MUX_MACRO_PROPERTY(__P_DEF_, macro, Y, X)

#define __IGNORE(...)
#define __KEEP(...) __VA_ARGS__

#define IFDEF(macro, ...) MUXDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)
#define IFNDEF(macro, ...) MUXNDEF(macro, __KEEP, __IGNORE)(__VA_ARGS__)

#define MAP(c, f) c(f)

#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1))

#if !defined(likely)
#define likely(cond)   __builtin_expect(cond, 1)
#define unlikely(cond) __builtin_expect(cond, 0)
#endif

#endif