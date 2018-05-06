// RCC base 0x40021000
volatile unsigned int * const RCC_APB2ENR = (unsigned int *)0x40021018;		// offset 0x18 APB2ENR
volatile unsigned int * const RCC_APB1ENR = (unsigned int *)0x4002101C;		// offset 0x1c APB1ENR

#define RCC_APB2ENR_IOPAEN (unsigned int)0x00000004							// GPIOAED bit mask
#define RCC_APB2ENR_SPI1EN (unsigned int)0x00001000‬							// SPI1EN bit mask
#define RCC_APB1ENR_USART2EN (unsigned int)0x0020000						// USART2EN bit mask


// GPIOA base 0x40010800
volatile unsigned int * const GPIOA_CRL = (unsigned int *)0x40010800;		// offset 0x00 CRL

#define GPIOA_CRL_PIN2_AFIO (unsigned int)0x44444A44						// set pin 2 to AFIO_PP for USART2, remaining pins default


// USART2 base 0x40004400
volatile unsigned int * const USART2_SR = (unsigned int *)0x40004400;		// offset 0x00 SR
volatile unsigned int * const USART2_DR = (unsigned int *)0x40004404;		// offset 0x04 DR
volatile unsigned int * const USART2_BRR = (unsigned int *)0x40004408;		// offset 0x08 BRR
volatile unsigned int * const USART2_CR1 = (unsigned int *)0x4000440C;		// offset 0x0C CR1

#define USART2_SR_RXNE (unsigned int)0x20									// RXNE mask
#define USART2_SR_TXE (unsigned int)0x80									// TXE mask
#define USART2_BRR_9600 (unsigned int)0x341									// 9600 bps with 8Mhz PCLK1
#define USART2_CR1_UE_RE (unsigned int)0x2004								// Enable the USART and enable receiver mask
#define USART2_CR1_UE_TE (unsigned int)0x2008								// Enable the USART and enable transmitter mask

// SPI1 base 0x40013000



int c_entry()
{
	// enable GPIOA clock
	*RCC_APB2ENR = RCC_APB2ENR_IOPAEN;

	// set PA2 to AFIO at 2MHz speed
	*GPIOA_CRL = GPIOA_CRL_PIN2_AFIO;

	// enable USART2 clock
	*RCC_APB1ENR |= RCC_APB1ENR_USART2EN;

	// configure USART2
	*USART2_BRR = USART2_BRR_9600;
	*USART2_CR1 |= USART2_CR1_UE_RE;

	while(1){
		if(*USART2_SR & USART2_SR_RXNE){
			*USART2_DR = *USART2_DR;
			*USART2_CR1 |= USART2_CR1_UE_TE;
			while(!(*USART2_SR & USART2_SR_TXE));
		}
	}
}

