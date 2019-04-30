#include <am.h>
#include <mips32.h>
#include <nemu.h>

#define PG_ALIGN __attribute((aligned(PGSIZE)))

static void* (*pgalloc_usr)(size_t);
static void (*pgfree_usr)(void*);

_Area segments[] = {      // Kernel memory mappings
  {.start = (void*)0,          .end = (void*)PMEM_SIZE}
};

#define NR_KSEG_MAP (sizeof(segments) / sizeof(segments[0]))

int _vme_init(void* (*pgalloc_f)(size_t), void (*pgfree_f)(void*)) {
  pgalloc_usr = pgalloc_f;
  pgfree_usr = pgfree_f;

  return 0;
}

int _protect(_AddressSpace *p) {
  p->ptr = (PDE*)(pgalloc_usr(1));
  p->pgsize = 4096;

  return 0;
}

void _unprotect(_AddressSpace *p) {
}

static _AddressSpace *cur_as = NULL;
void get_cur_as(_Context *c) {
  c->prot = cur_as;
}

void _switch(_Context *c) {
  cur_as = c->prot;
}

int _map(_AddressSpace *p, void *va, void *pa, int mode) {
  return 0;
}

_Context *_ucontext(_AddressSpace *p, _Area ustack, _Area kstack, void *entry, void *args) {
  return NULL;
}
