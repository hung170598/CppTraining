#ifndef __EXTI_H
#define __EXTI_H

#include "main.h"

typedef enum{
    RISING_TRIGGER,
    FALLING_TRIGGER,
    RISING_FALLING_TRIGGER
}trigger_edge_t;

void EXTI_Config(GPIO_TypeDef *GPIOx, uint8_t line, uint32_t priority, trigger_edge_t edge);
void EXTI_ClearIT(uint8_t line);
void EXTI_SetIT(uint8_t line);
#endif
