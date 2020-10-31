.extern main

.section ".text","ax",@progbits
.globl _start
_start:
  nop
  nop
  li sp, 0xf0fffffc
  j main
