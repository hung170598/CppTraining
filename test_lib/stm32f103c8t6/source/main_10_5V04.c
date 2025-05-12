#include "rcc.h"
#include "gpio.h"
#include "led.h"

void main(){
  // turn on clock for GPIOC
  RCC.APB2_ENR.BITS.IOPC = 1;
  // config GPIOC.c13 to Output
  GPIO_Mode(&GPIOC, 1UL << 13, GPIO_MODE_OUTPUT_PUSH_PULL_10Mhz);
  // init led
  Led_Init();
  Led_Blink(255, 20);
  while(1){
      Led_Process((void*)0);
//    GPIOC.ODR.REG = ~GPIOC.ODR.REG;
//    for(uint32_t i = 0; i < 22855; i++);
    for(uint32_t i = 0; i < 2424; i++);
  
  }
}