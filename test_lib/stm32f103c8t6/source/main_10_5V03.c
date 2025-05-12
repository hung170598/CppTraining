#include "rcc.h"
#include "gpio.h"
__root __no_init RCC_TypeDef RCC @ 0x40021000;
__root __no_init GPIO_TypeDef GPIOA @ 0x40010800;
__root __no_init GPIO_TypeDef GPIOB @ 0x40010c00;
__root __no_init GPIO_TypeDef GPIOC @ 0x40011000;
__root __no_init GPIO_TypeDef GPIOD @ 0x40011400;
__root __no_init GPIO_TypeDef GPIOE @ 0x40011800;

void main(){
  // turn on clock for GPIOC
  RCC.APB2_ENR.BITS.IOPC = 1;
  // config GPIOC.c13 to Output
  GPIO_Mode(&GPIOC, 1UL << 13, GPIO_MODE_OUTPUT_PUSH_PULL_10Mhz);

  
  while(1){
/*
    GPIOC.BSRR.BR.BITS.c0 = 1; // tuong duong GPIOC.ODR.BITS.c0 = 0; 
    GPIOC.BSRR.BSR.BITS.c0 = 1;// tuong duong GPIOC.ODR.BITS.c0 = 1;
*/  
//    GPIOC.ODR.REG = ~GPIOC.ODR.REG;
//    for(unsigned long i = 0; i < 500000; i++);
//    GPIOC.ODR.BITS.c13 = !GPIOC.ODR.BITS.c13;
    GPIOC.BSRR.REG = (1UL << 13);
    for(unsigned long i = 0; i < 500000; i++);
    GPIOC.BSRR.REG = (1UL << (13 + 16)); // BR13 nam o 28
    for(unsigned long i = 0; i < 500000; i++);      
  }
}