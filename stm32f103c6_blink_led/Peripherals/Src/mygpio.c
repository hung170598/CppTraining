#include "mygpio.h"

void GPIO_Led_Config(void)
{
    /* IO port B enable */
    RCC->APB2ENR |= (1<<3);

    /* config pin */
    //GPIOB->CRH &= ~(0x3UL << 26);

    GPIOB->CRH &= ~(0xFUL << 24);
    GPIOB->CRH |= (0x2UL << 24);
}

void GPIO_Init(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t mode, uint8_t cnf, uint8_t pull)
{
    if (GPIOx == GPIOA)
        RCC->APB2ENR |= (1<<2);
    else if (GPIOx == GPIOB)
        RCC->APB2ENR |= (1<<3);
    else if (GPIOx == GPIOC)
        RCC->APB2ENR |= (1<<4);
    else if (GPIOx == GPIOD)
        RCC->APB2ENR |= (1<<5);
    else if (GPIOx == GPIOE)
        RCC->APB2ENR |= (1<<6);

    if(pin < 8)
    {
        GPIOx->CRL &= ~(0xFUL << (4*pin));
        GPIOx->CRL |= (((cnf << 2) | mode) << (4*pin));
    }
    else
    {
        GPIOx->CRH &= ~(0xFUL << (4*(pin-8)));
        GPIOx->CRH |= (((cnf << 2) | mode) << (4*(pin-8)));
    }

    if(mode == GPIO_MODE_INPUT && cnf == GPIO_CNF_INPUT_PULL)
    {
        if (pull == GPIO_PULLUP)
            GPIOx->ODR |= (1 << pin);
        else if (pull == GPIO_PULLDOWN)
            GPIOx->ODR &= ~(1 << pin);
    }
}

GPIO_PinState GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
	if (GPIOx->IDR & (1<<pin))
        return GPIO_PIN_SET;
    else 
        return GPIO_PIN_RESET;
}

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t pin, GPIO_PinState PinState)
{
    if(PinState == GPIO_PIN_SET)
    {
        GPIOx->ODR |= (1 << pin); 
    }
    else
    {
        GPIOx->ODR &= ~(1 << pin); 
    }
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
    GPIOx->ODR ^= (1 << pin);
}

void GPIO_Led_Write(bool state)
{
	if(state)
		GPIOB->ODR |= (1 << 14); 
	else
		GPIOB->ODR &= ~(1 << 14);
}

void GPIO_Led_Toggle(void)
{
	GPIOB->ODR ^= (1 << 14);
}