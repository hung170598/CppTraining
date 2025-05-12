#include "STM32F103C8T6.h"

void delay_us(uint32_t us);
void delay_ms(uint32_t ms);

int main(void)
{
    /* Enable clock for port C */
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN(1u);

    GPIOC->CRH &= ~GPIO_CRH_MODE13_MASK;
    GPIOC->CRH &= ~GPIO_CRH_CNF13_MASK;
    /* Set PC13 to  GPIO output and push-pull mode */
    GPIOC->CRH |= (0x2 << GPIO_CRH_MODE13_SHIFT) | GPIO_CRH_CNF13(0);

    /* Enable clock for TIM2 */
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN(1u);

    /**
     * Setup clock frequency for TIM2. When POR (power of reset):
     * RCC_CR:      Reset value: 0x0000 XX83:   HSION and HSIRDY -> clock source is HSI (8MHz)
     * RCC_CFRG:    Reset value: 0x0
     *      + PLLSRC = 0 -> HSI oscillator clock / 2 selected as PLL input clock (4MHz)
     *      + PLLMUL = 0 -> PLL input clock * 2 (8MHz)
     *      + SW = 0 ->  HSI selected as system clock (8MHz)
     *      + HPRE = 0 -> SYSCLK not divided
     *      + PPRE1 = 0 -> HCLK not divided
     * Summary: PCLK1 = 8MHz
     */

    /* Set PSR = 7 -> Fclock = CK_PSC / (PSC[15:0] + 1) = 8 / (7 + 1) = 1MHz */
    TIM2->PSC = TIM_PSC_PSC(7u);
    TIM2->ARR = TIM_ARR_ARR(0xFFFFu);

    /* Enable counter */
    TIM2->CR1 |= TIM_CR1_CEN(1u);

    /* Loop forever */
    while (1)
    {
        /* Set 1 to OFF PC13 LED */
        GPIOC->BSRR |= GPIO_BSRR_BS13_MASK;
        delay_ms(500);

        /* Clear to ON PC13 LED */
        GPIOC->BSRR |= GPIO_BSRR_BR13_MASK;
        delay_ms(500);
    }
}

void delay_us(uint32_t us)
{
    TIM2->CNT = 0;
    while ((TIM2->CNT) < us);   /* delay 1 us */
}

void delay_ms(uint32_t ms)
{
    uint32_t count;

    for (count = 0; count < ms; count++)
    {
        delay_us(1000);         /* delay 1ms */
    }
}
