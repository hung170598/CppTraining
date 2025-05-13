#ifndef __MYGPIO_H
#define __MYGPIO_H

#include "main.h"


// MODE (2 bit)
#define GPIO_MODE_INPUT      0x00
#define GPIO_MODE_OUTPUT_10M 0x01
#define GPIO_MODE_OUTPUT_2M  0x02
#define GPIO_MODE_OUTPUT_50M 0x03

// CNF (2 bit)
#define GPIO_CNF_ANALOG          0x00
#define GPIO_CNF_FLOATING_INPUT  0x01
#define GPIO_CNF_INPUT_PULL      0x02
#define GPIO_CNF_GP_OUTPUT_PP    0x00
#define GPIO_CNF_GP_OUTPUT_OD    0x01
#define GPIO_CNF_AF_OUTPUT_PP    0x02
#define GPIO_CNF_AF_OUTPUT_OD    0x03

// PULL type
#define GPIO_NOPULL  0
#define GPIO_PULLUP  1
#define GPIO_PULLDOWN 2

typedef enum
{
  GPIO_PIN_RESET = 0u,
  GPIO_PIN_SET
} GPIO_PinState;

void GPIO_Led_Config(void);
void GPIO_Led_Write(bool state);
void GPIO_Led_Toggle(void);

void GPIO_Init(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode, uint8_t cnf, uint8_t pull);
GPIO_PinState GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin);
void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_PinState PinState);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin);

#endif
