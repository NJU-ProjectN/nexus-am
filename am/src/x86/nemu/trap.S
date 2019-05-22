#----|-------entry-------|----irq id----|---handler---|
.globl vecsys;    vecsys:  pushl $0x80;  jmp asm_trap
.globl vectrap;  vectrap:  pushl $0x81;  jmp asm_trap
.globl irq0;        irq0:  pushl   $32;  jmp asm_trap
.globl vecnull;  vecnull:  pushl   $-1;  jmp asm_trap

asm_trap:
  pushal

  pushl $0

  pushl %esp
  call irq_handle

  addl $4, %esp

  addl $4, %esp
  popal
  addl $4, %esp

  iret
