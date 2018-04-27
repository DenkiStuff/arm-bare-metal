#include "stm32f1xx.h"
#include "interrupt.h"

// Begin and End addresses for the .bss section; symbols defined in linker script
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;

extern void __attribute__((noreturn,weak)) c_entry(void);

void __attribute__ ((section(".after_vectors"),noreturn)) Reset_Handler (void)
{

	// Initialize bss section by iterating and clearing word by word.
	// It is assumed that the pointers are word aligned.
	unsigned int *p = &__bss_start__;
	while (p < &__bss_end__) {
		*p++ = 0;	
	}

	c_entry();
}

void __attribute__ ((section(".after_vectors"))) Default_Handler(void)
{
	while(1);
}
