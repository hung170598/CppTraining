#ifndef ADDRESS_MAP_H
#define ADDRESS_MAP_H

#include "stdint.h"
#include "stdbool.h"
/*---------------------SysTick------------------------*/
typedef struct
{
    volatile uint32_t CTRL;
    volatile uint32_t LOAD;
    volatile uint32_t VAL;
    volatile uint32_t CALIB;
}SysTick_t;

#define SysTickBaseAdress   0xE000E010UL
#define STK                 ((SysTick_t*)SysTickBaseAdress)


/*---------------------RCC------------------------*/
typedef struct 
{
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
}my_RCC_t;

#define MY_RCC_BASE    0x40021000UL
#define MY_RCC         (( my_RCC_t*)MY_RCC_BASE)

/*---------------------GIO------------------------*/
typedef struct 
{
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
}my_GPIO_t;

#define MY_GPIOA_BASE    0x40010800UL
#define MY_GPIOB_BASE    0x40010C00UL
#define MY_GPIOC_BASE    0x40011000UL
#define MY_GPIOD_BASE    0x40011400UL
#define MY_GPIOE_BASE    0x40011800UL

#define MY_GPIOA         (( my_GPIO_t*)MY_GPIOA_BASE)
#define MY_GPIOB         (( my_GPIO_t*)MY_GPIOB_BASE)
#define MY_GPIOC         (( my_GPIO_t*)MY_GPIOC_BASE)
#define MY_GPIOD         (( my_GPIO_t*)MY_GPIOD_BASE)
#define MY_GPIOE         (( my_GPIO_t*)MY_GPIOE_BASE)

typedef enum
{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE
}Port_t;
/*---------------------AFIO------------------------*/
typedef struct 
{
    volatile uint32_t EVCR;
    volatile uint32_t MAPR;
    volatile uint32_t EXTICR1;
    volatile uint32_t EXTICR2;
    volatile uint32_t EXTICR3;
    volatile uint32_t EXTICR4;
    volatile uint32_t MAPR2;
}AFIO_t;

#define AFIO_BaseAdress 0x40010000
#define AFIO            ((AFIO_t*)AFIO_BaseAdress)

/*---------------------EXTI------------------------*/
typedef struct 
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
}EXTI_t;

#define EXTI_BaseAdress 0x40010400
#define EXTI            ((EXTI_t*)EXTI_BaseAdress)

/*---------------------NVIC------------------------*/
typedef struct
{
    volatile uint32_t ISER[16U];              /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[16U];
    volatile uint32_t ICER[16U];              /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[16U];
    volatile uint32_t ISPR[16U];              /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[16U];
    volatile uint32_t ICPR[16U];              /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[16U];
    volatile uint32_t IABR[16U];              /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[16U];
    volatile uint32_t ITNS[16U];              /*!< Offset: 0x280 (R/W)  Interrupt Non-Secure State Register */
        uint32_t RESERVED5[16U];
    volatile uint32_t IPR[124U];              /*!< Offset: 0x300 (R/W)  Interrupt Priority Register */
}NVIC_Type;

#define NVIC_BaseAddress    0xE000E100UL
#define NVIC    ((NVIC_Type*)NVIC_BaseAddress)   

/*---------------------SCB------------------------*/
typedef struct
{
    volatile    uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
    volatile    uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
    volatile    uint32_t RESERVED0;
    volatile    uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
    volatile    uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
    volatile    uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
    volatile    uint32_t RESERVED1;
    volatile    uint32_t SHPR[2U];               /*!< Offset: 0x01C (R/W)  System Handlers Priority Registers. [0] is RESERVED */
    volatile    uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
} SCB_Type;

#define SCS_BASE            (0xE000E000UL)    
#define SCB_BASE            (SCS_BASE +  0x0D00UL)     
#define SCB                 ((SCB_Type       *)     SCB_BASE         )
/*---------------------MPU------------------------*/
typedef struct 
{
    volatile uint32_t TYPER;
    volatile uint32_t CR;
    volatile uint32_t RNR;
    volatile uint32_t RBAR;
    volatile uint32_t RASR;
}MPU_t;

#define MPU_BASE    0xE000ED90
#define MPU         ((MPU_t*)MPU_BASE)


#endif
