ENTRY(_Reset)

MEMORY
{
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K
  FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 128K
}


SECTIONS
{
 .text : { startup.o(STACK_INIT) startup.o(INTERRUPT_VECTOR) *(.text) } > FLASH
}
