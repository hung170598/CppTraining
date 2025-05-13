#define RCC (*((volatile unsigned int*) 0x40021000))
#define RCC_APB2ENR   (*((volatile unsigned int*)0x40021018))

//input button
#define GPIOA (*((volatile unsigned int*) 0x40010800))
#define GPIOA_CRL (*((volatile unsigned int*) 0x40010800))
#define GPIOA_IDR (*((volatile unsigned int*) 0x40010808))
#define GPIOA_ODR (*((volatile unsigned int*) 0x4001080C))

//output led
#define GPIOB (*((volatile unsigned int*) 0x40010C00))
#define GPIOB_CRL (*((volatile unsigned int*) 0x40010C00))
#define GPIOB_ODR (*((volatile unsigned int*) 0x40010C0C))

	
void delay(volatile unsigned int t) {
    while(t--);
}



int main() {
		RCC_APB2ENR |= (1 << 2);
		RCC_APB2ENR |= (1 << 3);
	
		GPIOA_CRL &= ~(0xF << 20);
		GPIOA_CRL |= (0x8  << 20);
		GPIOA_ODR &= ~(1 << 5); //kich hoat pullup
	
		GPIOB_CRL &= ~(0xF << 20);
		GPIOB_CRL |= (0x2 << 20);
		GPIOB_ODR &= ~(1 << 5);//khoi tao led tat

unsigned char button_state = 0;	

		while(1){
			if(!(GPIOA_IDR & (1 << 5))){
					delay(10000);
					if(!(GPIOA_IDR & (1 << 5)) && button_state == 0){
						GPIOB_ODR ^= (1 <<5);
						button_state = 1;
					}
			}else {
				button_state = 0;
				delay(1000);
			}
		}
}