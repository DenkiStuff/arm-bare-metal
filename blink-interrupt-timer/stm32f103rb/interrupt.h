// Reset_Handler prototype. full def in startup.o
void __attribute__ ((section(".after_vectors"),noreturn)) Reset_Handler (void);


// cortex-m core exceptions
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) NMI_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) HardFault_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) MemManage_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) BusFault_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) UsageFault_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) SVC_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) DebugMon_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) PendSV_Handler(void);
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler"))) SysTick_Handler(void);

// chip level interrupts
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  WWDG_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  PVD_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TAMPER_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  RTC_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  FLASH_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  RCC_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI0_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI1_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI4_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel1_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel4_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel5_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel6_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA1_Channel7_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  ADC1_2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  USB_HP_CAN1_TX_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  USB_LP_CAN1_RX0_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  CAN1_RX1_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  CAN1_SCE_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI9_5_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM1_BRK_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM1_UP_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM1_TRG_COM_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM1_CC_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM4_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  I2C1_EV_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  I2C1_ER_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  I2C2_EV_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  I2C2_ER_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  SPI1_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  SPI2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  USART1_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  USART2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  USART3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  EXTI15_10_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  RTCAlarm_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  USBWakeUp_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM8_BRK_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM8_UP_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM8_TRG_COM_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM_CC_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  ADC3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  FSMC_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  SDIO_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM5_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  SPI3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  UART4_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  UART5_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM6_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  TIM7_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA2_Channel1_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA2_Channel2_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA2_Channel3_IRQHandler(void)
void __attribute__ ((section(".after_vectors"),weak, alias ("Default_Handler")))  DMA2_Channel4_5_IRQHandler(void)










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

	WWDG_IRQHandler, 			/* Window Watachdog */
	PVD_IRQHandler,				/* PVD EXTI Line Detect */
	TAMPER_IRQHandler,			/* Tamper */
	RTC_IRQHandler,				/* RTC Global */
	FLASH_IRQHandler,			/* Flash Global */
	RCC_IRQHandler,				/* RCC Global */
	EXTI0_IRQHandler,			/* EXTI Line 0 */
	EXTI1_IRQHandler,			/* EXTI Line 1 */
	EXTI2_IRQHandler,			/* EXTI Line 2 */
	EXTI3_IRQHandler,			/* EXTI Line 3 */
	EXTI4_IRQHandler,			/* EXTI Line 4 */
	DMA1_Channel1_IRQHandler,	/* DMA1 Channel1 Global */
	DMA1_Channel2_IRQHandler,	/* DMA1 Channel2 Global */
	DMA1_Channel3_IRQHandler,	/* DMA1 Channel3 Global */
	DMA1_Channel4_IRQHandler,	/* DMA1 Channel4 Global */
	DMA1_Channel5_IRQHandler,	/* DMA1 Channel5 Global */
	DMA1_Channel6_IRQHandler,	/* DMA1 Channel6 Global */
	DMA1_Channel7_IRQHandler,	/* DMA1 Channel7 Global */
	ADC1_2_IRQHandler,			/* ADC1 and ADC2 Global */
	USB_HP_CAN1_TX_IRQHandler,	/* USB High Priority or CAN TX */
	USB_LP_CAN1_RX0_IRQHandler,	/* USB Low Priority or CAN RX0 */
	CAN1_RX1_IRQHandler,		/* CAN RX1 */
	CAN1_SCE_IRQHandler,		/* CAN SCE */
	EXTI9_5_IRQHandler,			/* EXTI Line[9:5] */
	TIM1_BRK_IRQHandler,		/* TIM1 Break */
	TIM1_UP_IRQHandler,			/* TIM1 Update */
	TIM1_TRG_COM_IRQHandler,	/* TIM1 Trigger and Commutation */
	TIM1_CC_IRQHandler,			/* TIM1 Capture Compare */
	TIM2_IRQHandler,			/* TIM2 Global */
	TIM3_IRQHandler,			/* TIM3 Global */
	TIM4_IRQHandler,			/* TIM4 Global */
	I2C1_EV_IRQHandler,			/* I2C1 Event */
	I2C1_ER_IRQHandler,			/* I2C1 Error */
	I2C2_EV_IRQHandler,			/* I2C2 Event */
	I2C2_ER_IRQHandler,			/* I2C2 Error */
	SPI1_IRQHandler,			/* SPI1 Global */
	SPI2_IRQHandler,			/* SPI2 Global */
	USART1_IRQHandler,			/* USART1 Global */
	USART2_IRQHandler,			/* USART2 Global */
	USART3_IRQHandler,			/* USART3 Global */
	EXTI15_10_IRQHandler,		/* EXTI Line[15:10] */
	RTCAlarm_IRQHandler,		/* RTC Alarm EXTI Line */
	USBWakeUp_IRQHandler,		/* USB WakeUp EXTI Line */
	TIM8_BRK_IRQHandler,		/* TIM8 Break */
	TIM8_UP_IRQHandler,			/* TIM8 Update */
	TIM8_TRG_COM_IRQHandler,	/* TIM8 Trigger and Commutation */
	TIM_CC_IRQHandler,			/* TIM8 Capture Compare */
	ADC3_IRQHandler,			/* ADC3 Global */
	FSMC_IRQHandler,			/* FSMC Global */
	SDIO_IRQHandler,			/* SDIO Global */
	TIM5_IRQHandler,			/* TIM5 Global */
	SPI3_IRQHandler,			/* SPI3 Global */
	UART4_IRQHandler,			/* UART4 Global */
	UART5_IRQHandler,			/* UART5 Global */
	TIM6_IRQHandler,			/* TIM6 Global */
	TIM7_IRQHandler,			/* TIM7 Global */
	DMA2_Channel1_IRQHandler,	/* DMA2 Channel1 global */
	DMA2_Channel2_IRQHandler,	/* DMA2 Channel2 global */
	DMA2_Channel3_IRQHandler,	/* DMA2 Channel3 global */
};
