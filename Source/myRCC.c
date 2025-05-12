#include "myRCC.h"

uint32_t SystemClock=8000000UL;


void PLL_Init(PLL_ClkSrc_t ClkSrc, uint8_t multiplication)
{
    switch(ClkSrc) // select input clock source for PLL
    {
        case HSE_IN_NOR:
            MY_RCC->CR |= (1 << 16); // HSE ON
            while (!(MY_RCC->CR & (1 << 17))); // Wait for HSE ready
            MY_RCC->CFGR |= (1<<16);
            MY_RCC->CFGR &= ~(1<<17);
            SystemClock=8000000UL;
            break;
        case HSE_IN_DIV:
            MY_RCC->CR |= (1 << 16); // HSE ON
            while (!(MY_RCC->CR & (1 << 17))); // Wait for HSE ready
            MY_RCC->CFGR |= (1<<16);
            MY_RCC->CFGR |= (1<<17);
            SystemClock=8000000UL;
            break;
        case HSI_IN:
            MY_RCC->CFGR &= ~(1<<16);
            break;
        default:
            break;
    }
    MY_RCC->CFGR &= ~(0xF << 18);                      // reset bits PLLMUL[3:0]
    MY_RCC->CFGR |= ((multiplication - 2) << 18); 

    MY_RCC->CR |= (1<<24);// enable PLL
    while( !((MY_RCC->CR) & (1<<17)) ); // wait to PLL ready  

    MY_RCC->CFGR &= ~(3<<0);
    MY_RCC->CFGR |=  (2<<0);
    while( (MY_RCC->CFGR & (3<<2)) != (2<<2) );
    SystemClock*=multiplication;
}


void HSE_Init()
{
    MY_RCC->CR |= (1<<16); // set bit HSEON to enable HSE
    while( !((MY_RCC->CR) & (1<<17)) ); // wait to HSE stable

    MY_RCC->CFGR &= ~(3<<0);
    MY_RCC->CFGR |=  (1<<0);
    while( (MY_RCC->CFGR & (3<<2)) != (1<<2) );
}

void GPIO_ClockEnable(my_GPIO_t* GPIOx)
{
    if(GPIOx==MY_GPIOA)
    {
        MY_RCC->APB2RSTR |= (1<<2);
        MY_RCC->APB2RSTR &= ~(1<<2);   // Clear bit: deassert reset
        MY_RCC->APB2ENR |= (1<<2);
    }
    else if(GPIOx==MY_GPIOB)
    {
        MY_RCC->APB2RSTR |= (1<<3);
        MY_RCC->APB2RSTR &= ~(1<<3);   // Clear bit: deassert reset
        MY_RCC->APB2ENR |= (1<<3);
    }
    else if(GPIOx==MY_GPIOC)
    {
        MY_RCC->APB2RSTR |= (1<<4);
        MY_RCC->APB2RSTR &= ~(1<<4);   // Clear bit: deassert reset
        MY_RCC->APB2ENR |= (1<<4);
    }
    else if(GPIOx==MY_GPIOD)
    {
        MY_RCC->APB2RSTR |= (1<<5);
        MY_RCC->APB2RSTR &= ~(1<<5);   // Clear bit: deassert reset
        MY_RCC->APB2ENR |= (1<<5);
    }
    else if(GPIOx==MY_GPIOE)
    {
        MY_RCC->APB2RSTR |= (1<<6);
        MY_RCC->APB2RSTR &= ~(1<<6);   // Clear bit: deassert reset
        MY_RCC->APB2ENR |= (1<<6);
    }
}

void AFIO_ClockEnable()
{
    MY_RCC->APB2RSTR |= (1<<0);
    MY_RCC->APB2RSTR &= ~(1<<0);   // Clear bit: deassert reset
    MY_RCC->APB2ENR |= (1<<0);
}