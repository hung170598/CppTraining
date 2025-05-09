#ifndef STM32F103XB_H
#define STM32F103XB_H

#include <stdint.h>

/* Base addresses */
#define PERIPH_BASE       ((uint32_t)0x40000000)
#define AHBPERIPH_BASE    (PERIPH_BASE + 0x00018000)
#define APB2PERIPH_BASE   (PERIPH_BASE + 0x00010000)

/* RCC */
#define RCC_BASE          (AHBPERIPH_BASE + 0x00001000)
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
} RCC_TypeDef;
#define RCC               ((RCC_TypeDef *)RCC_BASE)

/* GPIOA GPIOC */
#define GPIOA_BASE        (APB2PERIPH_BASE + 0x0800) //Base address for GPIOA
#define GPIOC_BASE        (APB2PERIPH_BASE + 0x1000) //Base address for GPIOC  

typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_TypeDef;

#define GPIOA             ((GPIO_TypeDef *)GPIOA_BASE) // Define GPIOA
#define GPIOC             ((GPIO_TypeDef *)GPIOC_BASE) // Define GPIOC

/* Register bit definitions */
#define RCC_APB2ENR_IOPAEN   ((uint32_t)0x00000004) //Enable clock GPIOA
#define RCC_APB2ENR_IOPCEN   ((uint32_t)0x00000010) //Enable clock GPIOA

/* PA5 */
#define GPIO_CRL_MODE5_Pos   (20)
#define GPIO_CRL_MODE5       ((uint32_t)0x3 << GPIO_CRL_MODE5_Pos)
#define GPIO_CRL_MODE5_1     ((uint32_t)0x2 << GPIO_CRL_MODE5_Pos)
#define GPIO_CRL_CNF5_Pos    (22)
#define GPIO_CRL_CNF5        ((uint32_t)0x3 << GPIO_CRL_CNF5_Pos)

/* PC13 */
#define GPIO_CRH_MODE13_Pos   (20)
#define GPIO_CRH_MODE13       ((uint32_t)0x3 << GPIO_CRH_MODE13_Pos)
#define GPIO_CRH_MODE13_1     ((uint32_t)0x2 << GPIO_CRH_MODE13_Pos)
#define GPIO_CRH_CNF13_Pos    (22)
#define GPIO_CRH_CNF13        ((uint32_t)0x3 << GPIO_CRH_CNF13_Pos)

#endif /* STM32F103XB_H */