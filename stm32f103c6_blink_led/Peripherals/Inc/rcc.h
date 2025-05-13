#ifndef __RCC_H
#define __RCC_H

#include "main.h"

void RCC_HSE_Config();
void RCC_HSI_Config();
void RCC_SYSTICK_Config(uint32_t arr);
uint32_t RCC_msGetTicks();
void RCC_msDelay(uint32_t ms);
void SysTick_Handler(); 

#endif
