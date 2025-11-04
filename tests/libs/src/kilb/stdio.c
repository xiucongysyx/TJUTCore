#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// ntoa 转换buffer尺寸，32位时默认为32位
// 默认：32byte
#ifndef PRINTF_NTOA_BUFFER_SIZE
#define PRINTF_NTOA_BUFFER_SIZE 32U
#endif


// 支持longlong类型
#ifndef PRINTF_DISABLE_SUPPORT_LONG_LONG
#define PRINTF_SUPPORT_LONG_LONG
#endif

// 内部flag定义
#define FLAGS_ZEROPAD   (1U << 0U) // '0'
#define FLAGS_LEFT      (1U << 1U) // '-'
#define FLAGS_PLUS      (1U << 2U) // '+'
#define FLAGS_SPACE     (1U << 3U) // ' '
#define FLAGS_HASH      (1U << 4U) // '#'
#define FLAGS_PRECISION (1U << 5U) // '.'
#define FLAGS_LONG      (1U << 6U) // 'l'
#define FLAGS_LONG_LONG (1U << 7U) // 'll'
#define FLAGS_SHORT     (1U << 8U) // 'h'
#define FLAGS_CHAR      (1U << 9U) // 'hh'
#define FLAGS_UPPERCASE (1U << 10U) // 'X'

typedef void (*out_fct_type)(char character, void *buffer, size_t idx, size_t maxlen);

// 输出一个字符到buffer
static inline void _out_buffer(char character, void *buffer, size_t idx, size_t maxlen) {
  if(idx < maxlen) {
    ((char*)buffer)[idx] = character;
  }
}

// 这是一个字符输出包装器，用于将字符输出
// 其中前三条代码用于说明不使用其中的三个参数，因为这个函数要对应函数指针，因此需要使用这种办法来处理没有使用的参数
// 然后如果字符不是'\0'，就是用putch输出
// inline是关键字，用于提示编译器将函数的内容嵌入到调用该函数的地方，而不是进行跳转。这可以提高性能，但是会增加代码的大小。
static inline void _out_char(char character, void *buffer, size_t idx, size_t maxlen) {
  (void)buffer; (void)idx; (void)maxlen;
  if (character) {
    putch(character);
  }
}

// 内部空输出
static inline void _out_null(char charater, void *buffer, size_t idx, size_t maxlen) {
  (void)charater; (void)buffer; (void)idx; (void)maxlen;
}

// 判断是否为数字
static inline bool _is_digit(char ch) {
  return (ch >= '0') && (ch <= '9');
}

// 字符串转int类型
// 为什么要使用**str，因为这样的话可以直接修改format *str就是存放format的地址
static unsigned int _atoi(const char **str) {
  unsigned int i = 0U;
  // 这个循环巧妙的实现了将字符串转换成int类型
  while (_is_digit(**str)) {
    i = i * 10U + (unsigned int)(*((*str)++) - '0');
  }
  return i;
}

// 反向输出字符串，同时注意零充填，因为我们的字符串他的最高位是最先输出的，因此我们需要这个函数
static size_t _out_rev(out_fct_type out, char *buffer, size_t idx, size_t maxlen, const char *buf, size_t len, unsigned int width, unsigned int flags) {
  // idx就是我们目前输出的位置,是处理到%之前的位置
  const size_t start_idx = idx;

  // 充填空格给宽度
  if (!(flags & FLAGS_LEFT) && !(flags & FLAGS_ZEROPAD)) {
    for (size_t i = len; i < width; i++) {
      out(' ', buffer, idx++, maxlen);
    }
  }

  // 反向输出字符串
  while (len) {
    out(buf[--len], buffer, idx++, maxlen);
  }
  
  //反向充填空格
  if (flags & FLAGS_LEFT) {
    while (idx - start_idx < width) {
      out(' ', buffer, idx++, maxlen);
    }
  }

  return idx;
}


// 检查字符串长度的函数，可以被替代
/********************************************************
**********************************************************/
static inline unsigned int _strnlen_s(const char *str, size_t maxsize) {
  const char *s;
  for (s = str; *s && maxsize--; ++s);
  return (unsigned int)(s - str);
}



// 将值转换为对应的字符串
static size_t _ntoa_format(out_fct_type out, char *buffer, size_t idx, size_t maxlen, char *buf, size_t len, bool negative, unsigned int base, unsigned int prec, unsigned int width, unsigned int flags) {
  // 检查是否要减小宽度，并且充填0，如果需要显示符号，或者空格的话，就需要少充填一位0
  if (!(flags & FLAGS_LEFT)) {
    if (width && (flags & FLAGS_ZEROPAD) && (negative || (flags & (FLAGS_PLUS | FLAGS_SPACE)))) {
      width--;
    }
    while ((len < prec) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = '0';
    }
    while ((flags & FLAGS_ZEROPAD) && (len < width) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = '0';
    }
  } 

  // 显示hash，0x，o等
  if (flags & FLAGS_HASH) {
    // 其中len是目前已经转换的字符的长度，当长度为0时，不考虑显示前缀，只有当长度等于精度或者减一的宽度才会显示前缀
    if (!(flags & FLAGS_PRECISION) && len && ((len == prec) || (len == width))) {
      // len 是已经转换的数的长度，这个函数的目的是根据len和其他参数的长度来设置前缀和充填
      len--;
      if (len && (base == 16U)) {
        len--;
      }
    }

    if ((base == 16U) && !(flags & FLAGS_UPPERCASE) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = 'x';
    }
    else if ((base == 16U) && (flags & FLAGS_UPPERCASE) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = 'X';
    }
    else if ((base == 2U) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
      buf[len++] = 'b';
    }
    if (len < PRINTF_NTOA_BUFFER_SIZE) {
      buf[len++] = '0';
    }
  }

  if (len < PRINTF_NTOA_BUFFER_SIZE) {
    if (negative) {
      buf[len++] = '-';
    }
    else if (flags & FLAGS_PLUS) {
      buf[len++] = '+';
    }
    else if (flags & FLAGS_SPACE) {
      buf[len++] = ' ';
    }
  }

  return _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);

  
}

// 内不itoa转换long类型
static size_t _ntoa_long(out_fct_type out, char *buffer, size_t idx, size_t maxlen, unsigned long value, bool negative, unsigned long base, unsigned int prec, unsigned int width, unsigned int flags) {
  char buf[PRINTF_NTOA_BUFFER_SIZE];
  size_t len = 0U;

  if (!value) {
    flags &= ~FLAGS_HASH;
  }

  if (!(flags & FLAGS_PRECISION) || value) {
    do {
      const char digit = (char)(value % base);
      buf[len++] = digit < 10 ? '0' + digit : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
      value /= base;
    } while (value && (len < PRINTF_NTOA_BUFFER_SIZE));
  }

  return _ntoa_format(out, buffer, idx, maxlen, buf, len, negative, (unsigned int)base, prec, width, flags);
}

#if defined(PRINTF_SUPPORT_LONG_LONG)
// 内部itoa转换longlong类型
// value 是值， negative 是负数标志， Base 是输出进制， prec 是输出精度， width 是输出宽度
static size_t _ntoa_long_long(out_fct_type out, char *buffer, size_t idx, size_t maxlen, unsigned long long value, bool negative, unsigned long long base, unsigned int prec, unsigned int width, unsigned int flags) {
  char buf[PRINTF_NTOA_BUFFER_SIZE];
  size_t len = 0U;

  // 0值没有hash
  if (!value) {
    flags &= ~FLAGS_HASH;
  }

  // 如果精度或值不为0就输出
  if (!(flags & FLAGS_PRECISION) || value) {
    do {
      const char digit = (char)(value % base);
      buf[len++] = digit < 10 ? '0' + digit : (flags & FLAGS_UPPERCASE ? 'A' : 'a') + digit - 10;
      value /= base;
    } while (value && (len < PRINTF_NTOA_BUFFER_SIZE));
  }
  
  return _ntoa_format(out, buffer, idx, maxlen, buf, len, negative, (unsigned int)base, prec, width, flags);
}
#endif // PRINTF_SUPPORT_LONG_LONG

// 这个函数用于解析输入的字符串，并通过%来判断需要输出的内容
// 它的参数有输出的函数，缓冲指针，最大长度，输入的字符串，可选参数va
static int _vsnprintf(out_fct_type out, char *buffer, const size_t maxlen, const char *format, va_list va) {
  // 他们分别用来表示是否已经处理字符
  unsigned int flags, width, precision, n;
  size_t idx = 0U;

  // 如果buffer不是空的话，就将输出函数设置为_out_null
  // 如果buffer不是空的话，可能是将输出放置到buffer中，而不是输出，因此需要将输出函数设置为空输出
  if (!buffer) {
    out = _out_null;
  }

  // 开始分析format
  while (*format) {
    //格式说明 %[flags][width][.precision][length]
    if (*format != '%') {
      // no 输出*format，继续检测下一个字符
      out(*format, buffer, idx++, maxlen);
      format++;
      continue;
    }
    else {
      // yes，继续匹配
      format++;
    }

    // 匹配flags n表示已经处理的字符
    flags = 0U;
    do {
      switch (*format) {
        case '0': flags |= FLAGS_ZEROPAD; format++; n = 1U; break;  
        case '-': flags |= FLAGS_LEFT;    format++; n = 1U; break;
        case '+': flags |= FLAGS_PLUS;    format++; n = 1U; break;
        case ' ': flags |= FLAGS_SPACE;   format++; n = 1U; break;
        case '#': flags |= FLAGS_HASH;    format++; n = 1U; break;
        default :                                   n = 0U; break;
        // n = 1U表示已经处理一个参数，n = 0U表示没有处理参数
      }
    }while(n); // 用于处理多个参数

    // 匹配width 这一步需要将字符转化为int类型
    width = 0U;
    // 使用_is_digit判断是否为数字，在使用atoi将数字转为int
    if (_is_digit(*format)) {
      width = _atoi(&format);
    } 

    // 匹配精度
    precision = 0U;
    if (*format == '.') {
      flags |= FLAGS_PRECISION;
      format++;
      if (_is_digit(*format)) {
        precision = _atoi(&format);
      }
    }

    // 匹配长度类型 l h 
    switch (*format) {
      case 'l' :
        flags |= FLAGS_LONG;
        format++;
        if (*format) {
          flags |= FLAGS_LONG_LONG;
          format++;
        }
        break;
      case 'h' :
        flags |= FLAGS_SHORT;
        format++;
        if (*format == 'h') {
          flags |= FLAGS_CHAR;
          format++;
        }
        break;
    }

    // 匹配格式
    switch (*format) {
      case 'd': case 'i': case 'u': case 'x': case 'X': case 'o': case 'b': {
        //set the base 表示数据输出的类型，主要是数字
        unsigned int base;
        if (*format == 'x') {
          base = 16U;
        }
        else if (*format == 'X') {
          base = 16U;
          // 大写标志
          flags |= FLAGS_UPPERCASE; 
        }
        else if (*format == 'o') {
          base = 8U;
        }
        else if (*format == 'b') {
          base = 2U;
        }
        else {
          base = 10U;
          flags &= ~FLAGS_HASH;
        }
      
        // 只有%i和%d需要空格充填
        // 经过测试，%x等前面确实不需要显示空格，会打印警报
        // 虽然printf不支持%b打印二进制，但是确实可以打印
        if((*format != 'i') && (*format != 'd')) {
          flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
        }

        // 当存在精度时，忽略0标志，因为会默认充填空格
        if (flags & FLAGS_PRECISION) {
          flags &= ~FLAGS_ZEROPAD;
        }

        // 转换整数
        if ((*format == 'i') || (*format == 'd')) {
          //默认支持longlong类型
          if (flags & FLAGS_LONG_LONG) {
#if defined(PRINTF_SUPPORT_LONG_LONG)
            // 从va中取出一个longlong类型的数据
            const long long value = va_arg(va, long long);
            idx = _ntoa_long_long(out, buffer, idx, maxlen, (unsigned long long)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
#endif
          }
          else if (flags & FLAGS_LONG) {
            const long value = va_arg(va, long);
            idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned long)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
          }
          else {
            const int value = (flags & FLAGS_CHAR) ? (char)va_arg(va, int) : (flags & FLAGS_SHORT) ? (short int)va_arg(va, int) : va_arg(va, int);
            idx = _ntoa_long(out, buffer, idx, maxlen, (unsigned int)(value > 0 ? value : 0 - value), value < 0, base, precision, width, flags);
          }
        }
        else {
          if (flags & FLAGS_LONG_LONG) {
#if defined(PRINTF_SUPPORT_LONG_LONG)
            idx = _ntoa_long_long(out, buffer, idx, maxlen, va_arg(va, unsigned long long), false, base, precision, width, flags);
#endif
          }  
          else if (flags & FLAGS_LONG) {
            idx = _ntoa_long(out, buffer, idx, maxlen, va_arg(va, unsigned long), false, base, precision, width, flags);
          }
          else {
            const unsigned int value = (flags & FLAGS_CHAR) ? (unsigned char)va_arg(va, unsigned int) : (flags & FLAGS_SHORT) ? (unsigned short int)va_arg(va, unsigned int) : va_arg(va, unsigned int);
            idx = _ntoa_long(out, buffer, idx, maxlen, value, false, base, precision, width, flags);
          }
        }
        format++;
        break;
      }
      case 'c' : {
        unsigned int l = 1U;
        // 预充填，这一步感觉有些
        if (!(flags & FLAGS_LEFT)) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }
        // char 输出
        out((char)va_arg(va, int), buffer, idx++, maxlen);
        //post充填
        if (flags & FLAGS_LEFT) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }
        format++;
        break;
      }

      case 's' : {
        const char *p = va_arg(va, char*);
        unsigned int l = _strnlen_s(p, precision ? precision : (size_t) - 1);
        if (flags & FLAGS_PRECISION) {
          l = (l < precision ? l : precision);
        }
        if (!(flags & FLAGS_LEFT)) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }
        while ((*p != 0) && (!(flags & FLAGS_PRECISION) || precision--)) {
          out(*(p++), buffer, idx++, maxlen);
        }
        if (flags & FLAGS_LEFT) {
          while (l++ < width) {
            out(' ', buffer, idx++, maxlen);
          }
        }
        format++;
        break;
      }

      case '%' :
        out('%', buffer, idx++, maxlen);
        format++;
        break;

      default : 
        out(*format, buffer, idx++, maxlen);
        format++;
        break;
    }
  }
  out((char)0, buffer, idx < maxlen ? idx : maxlen - 1U, maxlen);
  return (int)idx;
}

int printf(const char *fmt, ...) {
  va_list va;
  va_start(va, fmt);
  char buffer[1];
  const int ret = _vsnprintf(_out_char, buffer, (size_t)-1, fmt, va);
  va_end(va);
  return ret;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  char buffer[1];
  return _vsnprintf(_out_char, buffer, (size_t)-1, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list va;
  va_start(va, fmt);
  const int ret = _vsnprintf(_out_buffer, out, (size_t)-1, fmt, va);
  va_end(va);
  return ret;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  va_list va;
  va_start(va, fmt);
  const int ret = _vsnprintf(_out_buffer, out, n, fmt, va);
  va_end(va);
  return ret;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  return _vsnprintf(_out_buffer, out, n, fmt, ap);
}

#endif
