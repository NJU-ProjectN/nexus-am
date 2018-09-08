#ifndef __ARCH_H__
#define __ARCH_H__

#include <am.h>

#define PMEM_SIZE (128 * 1024 * 1024)
#define PGSIZE    4096    // Bytes mapped by a page

typedef uint32_t size_t;

struct _Context {
  uintptr_t esi, ebx, eax, eip, edx, err, eflags, ecx, cs, esp, edi, ebp;
  struct _Protect *prot;
  int       irq;
};

#define GPR1 eax
#define GPR2 eip
#define GPR3 eip
#define GPR4 eip
#define GPRx eip

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
#endif
