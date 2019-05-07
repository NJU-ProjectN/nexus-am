#ifndef __ARCH_H__
#define __ARCH_H__

struct _Context {
  uintptr_t hi, gpr[32], epc, cause, lo, status;
  struct _AddressSpace *prot;
};

#define GPR1 gpr[4]
#define GPR2 gpr[0]
#define GPR3 gpr[0]
#define GPR4 gpr[0]
#define GPRx gpr[0]

#endif
