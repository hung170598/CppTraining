#ifndef MY_RCC_H
#define MY_RCC_H

#include "AddressMap.h"

extern uint32_t SystemClock;

typedef enum
{
    HSE_IN_DIV,
    HSE_IN_NOR,
    HSI_IN,
}PLL_ClkSrc_t;


void PLL_Init(PLL_ClkSrc_t ClkSrc, uint8_t multiplication);
void HSE_Init(void);
void GPIO_ClockEnable(my_GPIO_t* GPIOx);
void AFIO_ClockEnable();
#endif
