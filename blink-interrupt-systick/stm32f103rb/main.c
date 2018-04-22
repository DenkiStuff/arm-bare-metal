volatile unsigned int * const RCC_APB2ENR = (unsigned int *)0x40021018;
volatile unsigned int * const GPIOA_CRL = (unsigned int *)0x40010800;
volatile unsigned int * const GPIOA_BSR = (unsigned int *)0x40010810;
volatile unsigned int * const GPIOA_BRR = (unsigned int *)0x40010814;
volatile unsigned int * const STK_CTRL = (unsigned int *)0xE000E010;
volatile unsigned int * const STK_LOAD = (unsigned int *)0xE000E014;
volatile unsigned int * const STK_VAL = (unsigned int *)0xE000E018;

volatile unsigned int timer_delayCount;

int c_entry() {
	// enable GIOA clock and set PB5 to output
	*RCC_APB2ENR |= (unsigned int)0x00000004;
	*GPIOA_CRL = (unsigned int)0x44244444; //0100 0100 0010 0100 0100 0100 0100 0100

	// COnfigure Systick Timer for 1 millisecond interrupts
	*STK_VAL = 0x00;
	*STK_LOAD = 7999U; //tick every 1 ms
	*STK_CTRL = 0x07;


	while (1){
		int c, d;
		timer_delayCount = 500u;
		while(timer_delayCount != 0u);
		*GPIOA_BSR = 0x20;

		timer_delayCount = 500u;
		while(timer_delayCount != 0u);
		*GPIOA_BRR = 0x20;
	}
	return 0;
}

void SysTick_Handler() {
	// Decrement to coutner to zero.
	if (timer_delayCount != 0u)
	{
		--timer_delayCount;
	}
}