volatile unsigned int * const RCC_APB2ENR = (unsigned int *)0x40021018;
volatile unsigned int * const GPIOA_CRL = (unsigned int *)0x40010800;
volatile unsigned int * const GPIOA_BSR = (unsigned int *)0x40010810;
volatile unsigned int * const GPIOA_BRR = (unsigned int *)0x40010814;

int c_entry() {
	*RCC_APB2ENR |= (unsigned int)0x00000004;
	*GPIOA_CRL = (unsigned int)0x44244444; //0100 0100 0010 0100 0100 0100 0100 0100

	while (1){
		int c, d;
		for (c = 1; c <= 262143; c++){
			//for (d = 1; d <= 32767; d++)
			//	{}
		}
		*GPIOA_BSR = 0x20;

		for (c = 1; c <= 262143; c++){
			//for (d = 1; d <= 32767; d++)
			//	{}
		}
		*GPIOA_BRR = 0x20;
	}
	return 0;
}
