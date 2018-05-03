// RCC base 0x40021000
volatile unsigned int * const RCC_APB2ENR = (unsigned int *)0x40021018;		// offset 0x18 APB2ENR
volatile unsigned int * const RCC_APB1ENR = (unsigned int *)0x4002101c;		// offset 0x1c APB1ENR

// GPIOA base 0x40010800
volatile unsigned int * const GPIOA_CRL = (unsigned int *)0x40010800;		// offset 0x00 CRL
volatile unsigned int * const GPIOA_ODR = (unsigned int *)0x4001080c;		// offset 0x0c ODR

// GPIOC base 0x40011000
volatile unsigned int * const GPIOC_CRL = (unsigned int *)0x40011000;		// offset 0x00 CRL
volatile unsigned int * const GPIOC_CRH = (unsigned int *)0x40011004;		// offset 0x04 CRH
volatile unsigned int * const GPIOC_IDR = (unsigned int *)0x40011008;		// offset 0x08 IDR
volatile unsigned int * const GPIOC_ODR = (unsigned int *)0x4001100c;		// offset 0x0c ODR

// TIM2 base 0x40000000
volatile unsigned int * const TIM2_CR1 = (unsigned int *)0x40000000; 		// offset 0x00 CR1
volatile unsigned int * const TIM2_PSC = (unsigned int *)0x40000028;		// offset 0x28 PSC
volatile unsigned int * const TIM2_DIER = (unsigned int *)0x4000000c;		// offset 0x0c DIER
volatile unsigned int * const TIM2_ARR = (unsigned int *)0x4000002c;		// offset 0x2c ARR
volatile unsigned int * const TIM2_SC = (unsigned int *)0x40000010;			// offset 0x10 SC

// NVIC base 0xE000E100
volatile unsigned int * const NVIC_ISER0 = (unsigned int *)0xE000E100;		// offset 0x00 ISER0
volatile unsigned int * const NVIC_ISER1 = (unsigned int *)0xE000E104;		// offset 0x04 ISER1

// EXIT base 0x40010400
volatile unsigned int * const EXTI_IMR = (unsigned int *)0x40010400; 		// offset 0x00 IMR
volatile unsigned int * const EXTI_FTSR = (unsigned int *)0x4001040c; 		// offset 0x0c FTSR
volatile unsigned int * const EXTI_PR = (unsigned int *)0x40010414; 		// offset 0x14 PR

// AFIO base 0x40010000
volatile unsigned int * const AFIO_EXTICR4  = (unsigned int *)0x40010014;	// offset 0x14 EXTICR4

int c_entry()
{
	// enable GPIOA clock and set PB5 to output
	*RCC_APB2ENR |= (unsigned int)0x00000004;
	*GPIOA_CRL = (unsigned int)0x44244444;

	// enable GPIOC clock and set PC13 to input with pull up
	*RCC_APB2ENR |= (unsigned int)0x00000010;
	*GPIOC_CRH = (unsigned int)0x44844444;

	// enable AFIO clock and set EXTI13 to PORTC
	*RCC_APB2ENR |= (unsigned int)0x00000001;
	*AFIO_EXTICR4 |= (unsigned int)0x00000020;

	// enable EXTI on PC13
	*EXTI_IMR |= (unsigned int)0x00002000;
	*EXTI_FTSR |= (unsigned int)0x00002000;

	// enable TIM2 clock and configure the timer interrupt
	*RCC_APB1ENR |= (unsigned int)0x00000001;
	*TIM2_PSC = (unsigned short)0x00ff;
	*TIM2_ARR = (unsigned short)31250u;
	*TIM2_DIER = (unsigned short)0x0001;
	*TIM2_CR1 = (unsigned short)0x0001;

	// enable TIM2 global interrupt in NVIC
	*NVIC_ISER0 |= (unsigned int)(0x01<<0x1c); //0x1c, TIM2 global interrupt position 28

	// enable EXTI15_10 global interrupt in NVIC
	*NVIC_ISER1 |= (unsigned int)(0x01<<0x08); //0x08, EXTI_15_10 interrupt position 40	

	while(1);
	//return 0;
}

void TIM2_IRQHandler()
{
	//toggle PA5
	*GPIOA_ODR ^= 0x20u;
	// clear TIM2 int pending bit
	*TIM2_SC &= ~(unsigned short)0x0001; 
}

void EXTI15_10_IRQHandler()
{
	if (*TIM2_ARR == (unsigned short)31250u){
		*TIM2_ARR = (unsigned short)15625u;
	} else {
		*TIM2_ARR = (unsigned short)31250u;
	}
	*EXTI_PR = (unsigned int)0x00002000;
}
