ENTRY(Reset_Handler)

MEMORY
{
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 20K
  FLASH (rx) : ORIGIN = 0x8000000, LENGTH = 128K
}


SECTIONS
{
	.text :
		{
			*(.isr_vector)
			*(.after_vectors)
			*(.text)
		} > FLASH

	.bss :
		{
			__bss_start__ = .;     	/* symbol for c code to initialize bss section */
			*(.bss)
			__bss_end__ = .;        /* symbol for c code to initialize bss section */
		} > RAM
}
