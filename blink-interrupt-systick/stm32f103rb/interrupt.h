// Reset_Handler prototype. full def in startup.o
void __attribute__ ((section(".after_vectors"),noreturn)) Reset_Handler (void);



void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) NMI_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) HardFault_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) MemManage_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) BusFault_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) UsageFault_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) SVC_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) DebugMon_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) PendSV_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) SysTick_Handler(void);



typedef void(* const pHandler)(void);

// The vector table.
// The linker script to place at correct location in memory.

__attribute__ ((section(".isr_vector"),used)) pHandler __isr_vectors[] =
{
	//core exceptions
	(pHandler)_stackInit,	// Inital Stack Pointer
	Reset_Handler,			// reset handler
	NMI_Handler,			// NMI handler
	HardFault_Handler,		// hard fault handler
	MemManage_Handler,		// MPU fault handler
	BusFault_Handler,		// bus fault handler
	UsageFault_Handler,		// usage fault handler
	0x00,					// reserved
	0x00,					// reserved
	0x00,					// reserved
	0x00,					// reserved
	SVC_Handler,			// SVCall handler
	DebugMon_Handler,		// debug monitor handler
	0x00,					// reserved
	PendSV_Handler,			// PendSV handler
	SysTick_Handler,		// systick handler
};
