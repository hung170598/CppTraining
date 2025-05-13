#include <stdint.h>

/* Linker script symbols (defined in .ld file) */
extern uint32_t _sidata;  // Start of initialized data in flash
extern uint32_t _sdata;   // Start of .data in RAM
extern uint32_t _edata;   // End of .data in RAM
extern uint32_t _sbss;    // Start of .bss
extern uint32_t _ebss;    // End of .bss
extern uint32_t _estack;  // Top of stack

extern void SystemInit(void);
extern void __libc_init_array(void);
extern int main(void);


/* Weak aliases for all exception handlers to Default_Handler */
#define WEAK __attribute__ ((weak, alias("Default_Handler")))


/* Forward declaration of default handler */
void Default_Handler(void);


/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/
void Reset_Handler(void);
void NMI_Handler(void) WEAK;
void HardFault_Handler(void) WEAK;
void MemManage_Handler(void) WEAK;
void BusFault_Handler(void) WEAK;
void UsageFault_Handler(void) WEAK;
void SVC_Handler(void) WEAK;
void DebugMon_Handler(void) WEAK;
void PendSV_Handler(void) WEAK;
void SysTick_Handler(void) WEAK;
void WWDG_IRQHandler(void) WEAK;
void PVD_IRQHandler(void) WEAK;
void TAMPER_IRQHandler(void) WEAK;
void RTC_IRQHandler(void) WEAK;
void FLASH_IRQHandler(void) WEAK;
void RCC_IRQHandler(void) WEAK;
void EXTI0_IRQHandler(void) WEAK;
void EXTI1_IRQHandler(void) WEAK;
void EXTI2_IRQHandler(void) WEAK;
void EXTI3_IRQHandler(void) WEAK;
void EXTI4_IRQHandler(void) WEAK;
void DMA1_Channel1_IRQHandler(void) WEAK;
void DMA1_Channel2_IRQHandler(void) WEAK;
void DMA1_Channel3_IRQHandler(void) WEAK;
void DMA1_Channel4_IRQHandler(void) WEAK;
void DMA1_Channel5_IRQHandler(void) WEAK;
void DMA1_Channel6_IRQHandler(void) WEAK;
void DMA1_Channel7_IRQHandler(void) WEAK;
void ADC1_2_IRQHandler(void) WEAK;
void USB_HP_CAN_TX_IRQHandler(void) WEAK;
void USB_LP_CAN_RX0_IRQHandler(void) WEAK;
void CAN_RX1_IRQHandler(void) WEAK;
void CAN_SCE_IRQHandler(void) WEAK;
void EXTI9_5_IRQHandler(void) WEAK;
void TIM1_BRK_IRQHandler(void) WEAK;
void TIM1_UP_IRQHandler(void) WEAK;
void TIM1_TRG_COM_IRQHandler(void) WEAK;
void TIM1_CC_IRQHandler(void) WEAK;
void TIM2_IRQHandler(void) WEAK;
void TIM3_IRQHandler(void) WEAK;
void TIM4_IRQHandler(void) WEAK;
void I2C1_EV_IRQHandler(void) WEAK;
void I2C1_ER_IRQHandler(void) WEAK;
void I2C2_EV_IRQHandler(void) WEAK;
void I2C2_ER_IRQHandler(void) WEAK;
void SPI1_IRQHandler(void) WEAK;
void SPI2_IRQHandler(void) WEAK;
void USART1_IRQHandler(void) WEAK;
void USART2_IRQHandler(void) WEAK;
void USART3_IRQHandler(void) WEAK;
void EXTI15_10_IRQHandler(void) WEAK;
void RTCAlarm_IRQHandler(void) WEAK;
void TIM8_BRK_IRQHandler(void) WEAK;
void TIM8_UP_IRQHandler(void) WEAK;
void TIM8_TRG_COM_IRQHandler(void) WEAK;
void TIM8_CC_IRQHandler(void) WEAK;
void ADC3_IRQHandler(void) WEAK;
void FSMC_IRQHandler(void) WEAK;
void SDIO_IRQHandler(void) WEAK;
void TIM5_IRQHandler(void) WEAK;
void SPI3_IRQHandler(void) WEAK;
void UART4_IRQHandler(void) WEAK;
void UART5_IRQHandler(void) WEAK;
void TIM6_IRQHandler(void) WEAK;
void TIM7_IRQHandler(void) WEAK;
void DMA2_Channel1_IRQHandler(void) WEAK;
void DMA2_Channel2_IRQHandler(void) WEAK;
void DMA2_Channel3_IRQHandler(void) WEAK;
void DMA2_Channel4_5_IRQHandler(void) WEAK;
void SystemInit(void) __attribute__((weak));


/* Vector Table */
void (* const Vectors[])(void) __attribute__ ((section(".isr_vector"))) = {
    (void (*)(void))(&_estack),
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,
    WWDG_IRQHandler,                            /* Window Watchdog interrupt */
    PVD_IRQHandler,                             
    TAMPER_IRQHandler,                          
    RTC_IRQHandler,                             
    FLASH_IRQHandler,                           
    RCC_IRQHandler,                             
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_Channel1_IRQHandler,
    DMA1_Channel2_IRQHandler,
    DMA1_Channel3_IRQHandler,
    DMA1_Channel4_IRQHandler,
    DMA1_Channel5_IRQHandler,
    DMA1_Channel6_IRQHandler,
    DMA1_Channel7_IRQHandler,
    ADC1_2_IRQHandler,
    USB_HP_CAN_TX_IRQHandler,
    USB_LP_CAN_RX0_IRQHandler,
    CAN_RX1_IRQHandler,
    CAN_SCE_IRQHandler,
    EXTI9_5_IRQHandler,
    TIM1_BRK_IRQHandler,
    TIM1_UP_IRQHandler,
    TIM1_TRG_COM_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,
    EXTI15_10_IRQHandler,
    RTCAlarm_IRQHandler,
    0,
    TIM8_BRK_IRQHandler,
    TIM8_UP_IRQHandler,
    TIM8_TRG_COM_IRQHandler,
    TIM8_CC_IRQHandler,
    ADC3_IRQHandler,
    FSMC_IRQHandler,
    SDIO_IRQHandler,
    TIM5_IRQHandler,
    SPI3_IRQHandler,
    UART4_IRQHandler,
    UART5_IRQHandler,
    TIM6_IRQHandler,
    TIM7_IRQHandler,
    DMA2_Channel1_IRQHandler,
    DMA2_Channel2_IRQHandler,
    DMA2_Channel3_IRQHandler,
    DMA2_Channel4_5_IRQHandler
};

/* Reset Handler */
void Reset_Handler(void){
    // 1. Initialize Stack Pointer (optional in C, usually done in startup.s)


    // 2. System clock initialization
    SystemInit();

    // 3. Copy .data section from FLASH to RAM
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while(dst < &_edata){
        *dst++ = *src++;
    }

    // 4. Zero initialize the .bss section
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    // 5. Call static constructors (for C++)
    __libc_init_array();

    // 6. Call the application's entry point
    main();

    // 7. If main ever returns, loop forever
    while(1);
}

/* Default interrupt handler */
void Default_Handler(void) {
    while (1);
}