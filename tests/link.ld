OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS
{
  . = 0xf0000000;
  .text : { *(.text) }
  . = ALIGN(0x4);
  .data : { *(.data) }
  .bss : { *(.bss) }
  . = 0xf0ffffff;
  _end = .;
}
