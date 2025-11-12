#include <common.h>
#include <memory/paddr.h>

word_t vaddr_ifetch(data_t addr, int len) {
  return iaddr_read(addr, len);
}

