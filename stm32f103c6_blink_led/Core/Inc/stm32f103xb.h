#ifndef __STM32F103xB_H
#define __STM32F103xB_H

#include "stdint.h"

 /*!< Interrupt Number Definition */
 typedef enum
 {
 /******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
   NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
   HardFault_IRQn              = -13,    /*!< 3 Cortex-M3 Hard Fault Interrupt                     */
   MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
   BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
   UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
   SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
   DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
   PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
   SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */
 
 /******  STM32 specific Interrupt Numbers *********************************************************/
   WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
   PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
   TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
   RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
   FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
   RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
   EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
   EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
   EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
   EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
   EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
   DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
   DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
   DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
   DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
   DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
   DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
   DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */
   ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
   USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
   USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
   CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
   CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
   EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
   TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
   TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
   TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
   TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
   TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
   TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
   TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
   I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
   I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
   I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
   I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
   SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
   SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
   USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
   USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
   USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
   EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
   RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
   USBWakeUp_IRQn              = 42,     /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */
 } IRQn_Type;

#define __NVIC_PRIO_BITS           4U 
/**
  \brief  Structure type to access the Nested Vectored Interrupt Controller (NVIC).
 */
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
}  NVIC_Type;

typedef struct{
  volatile const uint32_t CPUID;
  volatile uint32_t ICSR;
  volatile uint32_t VTOR;
  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
           uint32_t RESERVED;
  volatile uint32_t SHPR[2U];
  volatile uint32_t SHCSR;
}SCB_Type;

typedef struct{
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
}RCC_Typedef;

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
} FLASH_TypeDef;

typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile uint32_t CALIB;
} SysTick_TypeDef;

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
           uint32_t RESERVED;
  volatile uint32_t MAPR2;
} AFIO_TypeDef;

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;


#define FLASH_BASE              0x08000000UL
#define SRAM_BASE               0x20000000UL
#define PERIPH_BASE             0x40000000UL

#define AHB_PERIPH_BASE         (PERIPH_BASE + 0x00020000UL)
#define APB1_PERIPH_BASE        PERIPH_BASE
#define APB2_PERIPH_BASE        (PERIPH_BASE + 0x00010000UL)

#define RCC_BASE                (AHB_PERIPH_BASE + 0x00001000UL)
#define FLASH_R_BASE            (AHB_PERIPH_BASE + 0x00002000UL)

#define GPIOA_BASE              (APB2_PERIPH_BASE + 0x00000800UL)
#define GPIOB_BASE              (APB2_PERIPH_BASE + 0x00000C00UL)
#define GPIOC_BASE              (APB2_PERIPH_BASE + 0x00001000UL)
#define GPIOD_BASE              (APB2_PERIPH_BASE + 0x00001400UL)
#define GPIOE_BASE              (APB2_PERIPH_BASE + 0x00001800UL)

#define AFIO_BASE               (APB2_PERIPH_BASE)

#define EXTI_BASE               (APB2_PERIPH_BASE + 0x00000400UL)

#define RCC                     ((RCC_Typedef *)RCC_BASE)
#define FLASH                   ((FLASH_TypeDef *)FLASH_R_BASE)

#define SysTick                 ((SysTick_TypeDef *)0xE000E010UL)

#define GPIOA                   ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                   ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                   ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                   ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                   ((GPIO_TypeDef *)GPIOE_BASE)

#define AFIO                    ((AFIO_TypeDef *)AFIO_BASE)

#define EXTI                    ((EXTI_TypeDef *)EXTI_BASE)

#define NVIC_BASE                0xE000E100UL
#define NVIC                     ((NVIC_Type *)NVIC_BASE)

#define SCB_BASE                 0xE000ED00UL
#define SCB                      ((SCB_Type *)SCB_BASE)


#endif

