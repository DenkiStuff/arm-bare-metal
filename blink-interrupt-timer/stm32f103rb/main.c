volatile unsigned int * const RCC_APB2ENR = (unsigned int *)0x40021018;
volatile unsigned int * const GPIOA_CRL = (unsigned int *)0x40010800;
volatile unsigned int * const GPIOA_IDR = (unsigned int *)0x40010808;
volatile unsigned int * const GPIOA_BSR = (unsigned int *)0x40010810;
volatile unsigned int * const GPIOA_BRR = (unsigned int *)0x40010814;

volatile unsigned int * const RCC_APB1ENR = (unsigned int *)0x4002101c;
volatile unsigned int * const TIM2_CR1 = (unsigned int *)0x40000000;
volatile unsigned int * const TIM2_PSC = (unsigned int *)0x40000028;
volatile unsigned int * const TIM2_DIER = (unsigned int *)0x4000000c;
volatile unsigned int * const TIM2_ARR = (unsigned int *)0x4000002c;

volatile unsigned int * const NVIC_ISER0 = (unsigned int *)0xE000E100;
volatile unsigned int * const NVIC_ICPR0 = (unsigned int *)0xE000E280;

int c_entry(){
	// enable GIOA clock and set PB5 to output
	*RCC_APB2ENR |= (unsigned int)0x00000004;
	*GPIOA_CRL = (unsigned int)0x44244444;

	// enable TIM2 clock and configure the timer interrupt
	*RCC_APB1ENR |= (unsigned int)0x00000001;
	*TIM2_PSC = (unsigned short)0x0fff;
	*TIM2_ARR = (unsigned short)31250u;
	*TIM2_DIER = (unsigned short)0x0001;
	*TIM2_CR1 = (unsigned short)0x0001;

	// enable TIM2 global interrupt in NVIC
	*NVIC_ISER0 |= (unsigned int)(0x01<<0x1c); //0x1c, Global Interrupt position 28

	while(1);
	return 0;
}

void TIM2_IRQHandler(){
	// Toggle PA5
	if (*GPIOA_IDR & 0x20){
		*GPIOA_BRR = 0x20;
	} else {
		*GPIOA_BSR = 0x20;
	}
	// Clear TIM2 Pending BIt
	*NVIC_ICPR0 |= (unsigned int)(0x01<<0x1c);
}