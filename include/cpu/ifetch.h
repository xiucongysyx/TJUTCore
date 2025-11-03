#ifndef __CPU_IFETCH_H__

#include <common.h>
#include <memory/vaddr.h>

static inline uint32_t inst_fetch(data_t pc, int len) {
  uint32_t inst = vaddr_ifetch(pc, len);
  return inst;
}

#endif
