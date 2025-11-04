#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t n = 0;
  while(*s != '\0') {
    s++;
    n++;
  }
  return n;
}

char *strcpy(char *dst, const char *src) {
  char *dstp = dst;
  while(*src != '\0') {
    *dstp++ = *src++;
  }
  *dstp = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  char *dstp = (char *)dst;
  while(n-- != 0) {
    *dstp++ = *src++;
  }
  return dst;
}

char *strcat(char *dst, const char *src) {
  char *dstp = dst;
  dstp = dstp + strlen(dst);
  strcpy(dstp, src);
  return dst; 
}

int strcmp(const char *s1, const char *s2) {
  while(*s1 == *s2) {
    if(*s1 == '\0') return 0;
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  while(n-- != 0) {
    if(*s1 != *s2) return (*s1 - *s2);
    s1++;
    s2++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  char *dstp = (char *)s;
  while(n-- != 0) {
    *dstp++ = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  char *dstp = (char *)dst;
  char *srcp = (char *)src;
  if(src > dst || src + n < dst) {
    while(n-- != 0) *dstp++ = *srcp++;
  }
  else {
    while(n-- != 0) *(dstp+n+1) = *(srcp+n+1);
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  char *outp = (char *)out;
  char *inp = (char *)in;
  while(n-- != 0) {
    *outp++ = *inp++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  char *s1p = (char *)s1;
  char *s2p = (char *)s2;
  while(n-- != 0) {
    if(*s1p++ != *s2p++) {
      return (*(s1p-1) - *(s2p-1));
    }
  }
  return 0;
}

#endif
