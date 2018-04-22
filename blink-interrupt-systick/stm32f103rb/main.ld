ENTRY(Reset_Handler)

MEMORY
{
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K
  FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 128K
}


SECTIONS
{
  .text : { *(.isr_vector) *(.after_vectors) *(.text) } > FLASH
  .bss : { *(.bss) } > RAM
}
