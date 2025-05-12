#ifndef _RCC_H_
#define _RCC_H_
#include <stdint.h>
#define ADRESS_BASE_RCC 0x40021000

#define RCC_APB2ENR_TIM17EN (1 << 18)
#define RCC_APB2ENR_TIM16EN (1 << 17)
#define RCC_APB2ENR_TIM15EN (1 << 16)
#define RCC_APB2ENR_ADC3EN (1 << 15) /* (XX) */
#define RCC_APB2ENR_USART1EN (1 << 14)
#define RCC_APB2ENR_TIM8EN (1 << 13) /* (XX) */
#define RCC_APB2ENR_SPI1EN (1 << 12)
#define RCC_APB2ENR_TIM1EN (1 << 11)
#define RCC_APB2ENR_ADC2EN (1 << 10)
#define RCC_APB2ENR_ADC1EN (1 << 9)
#define RCC_APB2ENR_IOPGEN (1 << 8) /* (XX) */
#define RCC_APB2ENR_IOPFEN (1 << 7) /* (XX) */
#define RCC_APB2ENR_IOPEEN (1 << 6)
#define RCC_APB2ENR_IOPDEN (1 << 5)
#define RCC_APB2ENR_IOPCEN (1 << 4)
#define RCC_APB2ENR_IOPBEN (1 << 3)
#define RCC_APB2ENR_IOPAEN (1 << 2)
#define RCC_APB2ENR_AFIOEN (1 << 0)

typedef struct
{
    volatile uint32_t RCC_CR;
    volatile uint32_t RCC_CFGR;
    volatile uint32_t RCC_CIR;
    volatile uint32_t RCC_APB2RSTR;
    volatile uint32_t RCC_APB1RSTR;
    volatile uint32_t RCC_AHBENR;
    volatile uint32_t RCC_APB2ENR;
    volatile uint32_t RCC_APB1ENR;
    volatile uint32_t RCC_BDCR;
    volatile uint32_t RCC_CSR;
} RCC_REGISTER_t;
#define RCC ((RCC_REGISTER_t *)(ADRESS_BASE_RCC))
void enable_clock(void);
#endif

