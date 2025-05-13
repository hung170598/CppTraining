#include "rcc.h"
#include "nvic.h"

static volatile uint32_t msTicks = 0;

void RCC_HSE_Config()
{
    
    /* PLL MUL = 9 */
    RCC->CFGR &= ~((0xFUL << 18));
    RCC->CFGR |= (0x7UL << 18);

    /* HSE ON */
    RCC->CR |= (1<<16);
    while(!(RCC->CR & (1<<17))); 

    /* PLL Src = HSE */
    RCC->CFGR |= (1<<16);

    /* PLL ON */
    RCC->CR |= (1<<24);
    while(!(RCC->CR & (1<<25)));

    /* flash prefetch and wait stage (p60 rm) */
	    // system clock 72 MHz ---> 2 wait states
		FLASH->ACR &= ~((0x7UL << 0)); //clear latency field
		FLASH->ACR |= ((0x2UL << 0));

	    //enable prefetch buffer
		FLASH->ACR |= (1<<4);

    /* select system clock */    
    RCC->CFGR &= ~(0x3UL << 0);
    RCC->CFGR |= (0x2UL << 0);
    while(!(RCC->CFGR & (0x2UL << 2)));

    /* AHB pres */
    RCC->CFGR &= ~(0xFUL << 4);

    /* APB1 pres */
    RCC->CFGR &= ~(0x7UL << 8);
    RCC->CFGR |= (0x4UL << 8);

    /* APB2 pres */
    RCC->CFGR &= ~(0x7UL << 11);

    /* ADC pres */
    RCC->CFGR &= ~(0x3UL << 14);
    RCC->CFGR |= (0x2UL << 14);

}

void RCC_HSI_Config()
{
    // Flash wait state
    FLASH->ACR &= ~(0x7UL << 0);      // Clear latency field
    FLASH->ACR |= (0x2UL << 0);       // 2 wait states
    FLASH->ACR |= (1 << 4);           // Enable prefetch buffer

    // AHB prescaler = SYSCLK
    RCC->CFGR &= ~(0xFUL << 4);

    // APB1 prescaler = HCLK/2 (recommend when SYSCLK > 36MHz)
    RCC->CFGR &= ~(0x7UL << 8);
    RCC->CFGR |=  (0x4UL << 8);       // divide by 2

    // APB2 prescaler = HCLK
    RCC->CFGR &= ~(0x7UL << 11);

    // ADC prescaler = PCLK2 / 6
    RCC->CFGR &= ~(0x3UL << 14);
    RCC->CFGR |=  (0x2UL << 14);

    // Use HSI as system clock (already default)
    RCC->CFGR &= ~(0x3UL << 0);       // SYSCLK = HSI
}

void RCC_SYSTICK_Config(uint32_t arr)
{
    /* set ctrl = 0 trước */
    SysTick->CTRL = 0;

    /* set arr */
    SysTick->LOAD = arr - 1;

    /* set systick interupt request priority to 0 */
    NVIC_SetPriority(SysTick_IRQn, 0);

    /* reset value counter về 0 */
    SysTick->VAL = 0;

    SysTick->CTRL |= (1 << 2); /* AHB src */
    SysTick->CTRL |= (1 << 1); /* bật ngắt systick */
    SysTick->CTRL |= (1 << 0); /* enable systick counter */

}

static void RCC_msIncTicks()
{
    msTicks++;
}

uint32_t RCC_msGetTicks()
{
    return msTicks;
}

void RCC_msDelay(uint32_t ms)
{
	uint32_t startticks = RCC_msGetTicks(); //set tgian luc dau
	while(RCC_msGetTicks() - startticks < ms); //vong lap khi thoi gian - thoi gian luc dau < thoi gian muon delay
}

void SysTick_Handler() 
{
	RCC_msIncTicks();
}