#ifndef _STM32F103C8T6_H__
#define _STM32F103C8T6_H__

#include <stdint.h>

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for RCC                                                                        *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;
} RCC_Type;

#define RCC_BASE                    (0x40021000u)
#define RCC                         ((RCC_Type *)RCC_BASE)

#define RCC_APB2ENR_IOPCEN_SHIFT    (4u)
#define RCC_APB2ENR_IOPCEN_MASK     (0x10u)
#define RCC_APB2ENR_IOPCEN(x)       (((x) << RCC_APB2ENR_IOPCEN_SHIFT) & (RCC_APB2ENR_IOPCEN_MASK))

#define RCC_APB1ENR_TIM2EN_SHIFT    (0u)
#define RCC_APB1ENR_TIM2EN_MASK     (0x1u)
#define RCC_APB1ENR_TIM2EN(x)       (((x) << RCC_APB1ENR_TIM2EN_SHIFT) & (RCC_APB1ENR_TIM2EN_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for GPIO                                                                       *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} GPIO_Type;

#define GPIOC_BASE                  (0x40011000u)
#define GPIOC                       ((GPIO_Type *)GPIOC_BASE)

#define GPIO_CRH_MODE13_SHIFT       (20u)
#define GPIO_CRH_MODE13_MASK        (0x300000u)
#define GPIO_CRH_MODE13(x)          (((x) << GPIO_CRH_MODE13_SHIFT) & (GPIO_CRH_MODE13_MASK))

#define GPIO_CRH_CNF13_SHIFT        (22u)
#define GPIO_CRH_CNF13_MASK         (0xC00000u)
#define GPIO_CRH_CNF13(x)           (((x) << GPIO_CRH_CNF13_SHIFT) & (GPIO_CRH_CNF13_MASK))

#define GPIO_BSRR_BS13_SHIFT        (13u)
#define GPIO_BSRR_BS13_MASK         (0x2000u)
#define GPIO_BSRR_BS13(x)           (((x) << GPIO_BSRR_BS13_SHIFT) & (GPIO_BSRR_BS13_MASK))

#define GPIO_BSRR_BR13_SHIFT        (29u)
#define GPIO_BSRR_BR13_MASK         (0x20000000u)
#define GPIO_BSRR_BR13(x)           (((x) << GPIO_BSRR_BR13_SHIFT) & (GPIO_BSRR_BR13_MASK))

/*******************************************************************************************************************
 * Peripheral Hardware Access Layer for GPIO                                                                       *
 *******************************************************************************************************************
 */

typedef struct
{
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SMCR;
    uint32_t DIER;
    uint32_t SR;
    uint32_t EGR;
    uint32_t CCMR1;
    uint32_t CCMR2;
    uint32_t CCER;
    uint32_t CNT;
    uint32_t PSC;
    uint32_t ARR;
    uint32_t RESERVED_1;
    uint32_t CCR1;
    uint32_t CCR2;
    uint32_t CCR3;
    uint32_t CCR4;
    uint32_t RESERVED_2;
    uint32_t DCR;
    uint32_t DMAR;
} TIM_Type;

#define TIM2_BASE                   (0x40000000u)
#define TIM2                        ((TIM_Type *)TIM2_BASE)

#define TIM_CR1_CEN_SHIFT           (0u)
#define TIM_CR1_CEN_MASK            (0x1u)
#define TIM_CR1_CEN(x)              (((x) << TIM_CR1_CEN_SHIFT) & (TIM_CR1_CEN_MASK))

#define TIM_PSC_PSC_SHIFT           (0u)
#define TIM_PSC_PSC_MASK            (0xFFFFu)
#define TIM_PSC_PSC(x)               (((x) << TIM_PSC_PSC_SHIFT) & (TIM_PSC_PSC_MASK))

#define TIM_ARR_ARR_SHIFT           (0u)
#define TIM_ARR_ARR_MASK            (0xFFFFu)
#define TIM_ARR_ARR(x)               (((x) << TIM_ARR_ARR_SHIFT) & (TIM_ARR_ARR_MASK))

#endif /* _STM32F103C8T6_H__ */
