/******************************************************************************************************************************
 * @file    startup.c
 * @brief   Startup file for STM32F4 - Apply for GCC Compiler
 * @version 1.0
 * @date    2025-05-10
 * @author  long.truongphi
 ******************************************************************************************************************************/

/* ===========================================[ INCLUDE FILE ]===========================================*/
#include <stdint.h>                      /**< Thư viện chứa các kiểu dữ liệu cơ bản. */

/* Linker script symbols (defined in .ld file)*/
extern uint32_t __data_flash_start;      /**< Địa chỉ bắt đầu của dữ liệu trong flash */
extern uint32_t __data_start;            /**< Địa chỉ bắt đầu của dữ liệu trong RAM */
extern uint32_t __data_end;              /**< Địa chỉ kết thúc của dữ liệu trong RAM */
extern uint32_t __bss_start;             /**< Địa chỉ bắt đầu của vùng nhớ không khởi tạo */
extern uint32_t __bss_end;               /**< Địa chỉ kết thúc của vùng nhớ không khởi tạo */
extern uint32_t __end_stack;             /**< Địa chỉ kết thúc của stack */

extern void SystemInit(void);            /**< Hàm khởi tạo hệ thống */
extern void Default_Handler(void);       /**< Hàm mặc định xử lý lỗi */
extern void __libc_init_array(void);     /**< Hàm khởi tạo thư viện C */
extern int main(void);                   /**< Hàm main */

/**< Khai báo trước của handler mặc định */
void Default_Handler(void);


/**< MACRO định nghĩa WEAK là attribute yếu và được tạm thời thay thế bằng Default_Handler */
#define WEAK __attribute__ ((weak,alias("Default_Handler")))

/*******************************************************************************
*
* Cung cấp các bí danh yếu (weak aliases) cho mỗi Exception handler đến Default_Handler.
* Vì chúng là các bí danh yếu, bất kỳ hàm nào có cùng tên sẽ ghi đè lên
* định nghĩa này.
*
*******************************************************************************/
/**< Core System Exception Handlers */
void Reset_Handler(void);                                       /**< Reset Handler */
void NMI_Handler(void)                         WEAK;            /**< NMI Handler */
void HardFault_Handler(void)                   WEAK;            /**< HardFault Handler */
void MemManage_Handler(void)                   WEAK;            /**< MemManage Handler */
void BusFault_Handler(void)                    WEAK;            /**< BusFault Handler */
void UsageFault_Handler(void)                  WEAK;            /**< UsageFault Handler */ 
void SVC_Handler(void)                         WEAK;            /**< SVC Handler */
void DebugMon_Handler(void)                    WEAK;            /**< DebugMon Handler */
void PendSV_Handler(void)                      WEAK;            /**< PendSV Handler */
void SysTick_Handler(void)                     WEAK;            /**< SysTick Handler */

/**< External Interrupts */
void WWDG_IRQHandler(void)                     WEAK;
void PVD_IRQHandler(void)                      WEAK;
void TAMP_STAMP_IRQHandler(void)               WEAK;
void RTC_WKUP_IRQHandler(void)                 WEAK;
void FLASH_IRQHandler(void)                    WEAK;
void RCC_IRQHandler(void)                      WEAK;
void EXTI0_IRQHandler(void)                    WEAK;
void EXTI1_IRQHandler(void)                    WEAK;
void EXTI2_IRQHandler(void)                    WEAK;
void EXTI3_IRQHandler(void)                    WEAK;
void EXTI4_IRQHandler(void)                    WEAK;
void DMA1_Stream0_IRQHandler(void)             WEAK;
void DMA1_Stream1_IRQHandler(void)             WEAK;
void DMA1_Stream2_IRQHandler(void)             WEAK;
void DMA1_Stream3_IRQHandler(void)             WEAK;
void DMA1_Stream4_IRQHandler(void)             WEAK;
void DMA1_Stream5_IRQHandler(void)             WEAK;
void DMA1_Stream6_IRQHandler(void)             WEAK;
void ADC_IRQHandler(void)                      WEAK;
void CAN1_TX_IRQHandler(void)                  WEAK;
void CAN1_RX0_IRQHandler(void)                 WEAK;
void CAN1_RX1_IRQHandler(void)                 WEAK;
void CAN1_SCE_IRQHandler(void)                 WEAK;
void EXTI9_5_IRQHandler(void)                  WEAK;
void TIM1_BRK_TIM9_IRQHandler(void)            WEAK;
void TIM1_UP_TIM10_IRQHandler(void)            WEAK;
void TIM1_TRG_COM_TIM11_IRQHandler(void)       WEAK;
void TIM1_CC_IRQHandler(void)                  WEAK;
void TIM2_IRQHandler(void)                     WEAK;
void TIM3_IRQHandler(void)                     WEAK;
void TIM4_IRQHandler(void)                     WEAK;
void I2C1_EV_IRQHandler(void)                  WEAK;
void I2C1_ER_IRQHandler(void)                  WEAK;
void I2C2_EV_IRQHandler(void)                  WEAK;
void I2C2_ER_IRQHandler(void)                  WEAK;
void SPI1_IRQHandler(void)                     WEAK;
void SPI2_IRQHandler(void)                     WEAK;
void USART1_IRQHandler(void)                   WEAK;
void USART2_IRQHandler(void)                   WEAK;
void USART3_IRQHandler(void)                   WEAK;
void EXTI15_10_IRQHandler(void)                WEAK;
void RTC_Alarm_IRQHandler(void)                WEAK;
void OTG_FS_WKUP_IRQHandler(void)              WEAK;
void TIM8_BRK_TIM12_IRQHandler(void)           WEAK;
void TIM8_UP_TIM13_IRQHandler(void)            WEAK;
void TIM8_TRG_COM_TIM14_IRQHandler(void)       WEAK;
void TIM8_CC_IRQHandler(void)                  WEAK;
void DMA1_Stream7_IRQHandler(void)             WEAK;
void FSMC_IRQHandler(void)                     WEAK;
void SDIO_IRQHandler(void)                     WEAK;
void TIM5_IRQHandler(void)                     WEAK;
void SPI3_IRQHandler(void)                     WEAK;
void UART4_IRQHandler(void)                    WEAK;
void UART5_IRQHandler(void)                    WEAK;
void TIM6_DAC_IRQHandler(void)                 WEAK;
void TIM7_IRQHandler(void)                     WEAK;
void DMA2_Stream0_IRQHandler(void)             WEAK;
void DMA2_Stream1_IRQHandler(void)             WEAK;
void DMA2_Stream2_IRQHandler(void)             WEAK;
void DMA2_Stream3_IRQHandler(void)             WEAK;
void DMA2_Stream4_IRQHandler(void)             WEAK;
void ETH_IRQHandler(void)                      WEAK;
void ETH_WKUP_IRQHandler(void)                 WEAK;
void CAN2_TX_IRQHandler(void)                  WEAK;
void CAN2_RX0_IRQHandler(void)                 WEAK;
void CAN2_RX1_IRQHandler(void)                 WEAK;
void CAN2_SCE_IRQHandler(void)                 WEAK;
void OTG_FS_IRQHandler(void)                   WEAK;
void DMA2_Stream5_IRQHandler(void)             WEAK;
void DMA2_Stream6_IRQHandler(void)             WEAK;
void DMA2_Stream7_IRQHandler(void)             WEAK;
void USART6_IRQHandler(void)                   WEAK;
void I2C3_EV_IRQHandler(void)                  WEAK;
void I2C3_ER_IRQHandler(void)                  WEAK;
void OTG_HS_EP1_OUT_IRQHandler(void)           WEAK;
void OTG_HS_EP1_IN_IRQHandler(void)            WEAK;
void OTG_HS_WKUP_IRQHandler(void)              WEAK;
void OTG_HS_IRQHandler(void)                   WEAK;
void DCMI_IRQHandler(void)                     WEAK;
void HASH_RNG_IRQHandler(void)                 WEAK;
void FPU_IRQHandler(void)                      WEAK;
void SystemInit(void)         __attribute__((weak));                /**< Hàm khởi tạo hệ thống */
 

/**< Bảng Vector ngắt */
void (*const vector_table[])(void) __attribute__ ((section(".isr_vector"))) = {
    (void (*)(void))(&__end_stack),             /**< Con trỏ stack ban đầu */
    Reset_Handler,                              /**< Reset Handler */
    NMI_Handler,                                /**< NMI Handler */
    HardFault_Handler,                          /**< HardFault Handler */
    MemManage_Handler,                          /**< MemManage Handler */
    BusFault_Handler,                           /**< BusFault Handler */
    UsageFault_Handler,                         /**< UsageFault Handler */
    0, 0, 0, 0,                                 /**< Reserved */
    SVC_Handler,                                /**< SVC Handler */
    DebugMon_Handler,                           /**< DebugMon Handler */
    0,                                          /**< Reserved */
    PendSV_Handler,                             /**< PendSV Handler */
    SysTick_Handler,                            /**< SysTick Handler */

    /**< Các ngắt ngoại vi */
    WWDG_IRQHandler,                             /**< WWDG */
    PVD_IRQHandler,                              /**< PVD */
    TAMP_STAMP_IRQHandler,                       /**< TAMP_STAMP */
    RTC_WKUP_IRQHandler,                         /**< RTC_WKUP */
    FLASH_IRQHandler,                            /**< FLASH */
    RCC_IRQHandler,                              /**< RCC */
    EXTI0_IRQHandler,                            /**< EXTI0 */
    EXTI1_IRQHandler,                            /**< EXTI1 */
    EXTI2_IRQHandler,                            /**< EXTI2 */
    EXTI3_IRQHandler,                            /**< EXTI3 */
    EXTI4_IRQHandler,                            /**< EXTI4 */
    DMA1_Stream0_IRQHandler,                     /**< DMA1_Stream0 */   
    DMA1_Stream1_IRQHandler,                     /**< DMA1_Stream1 */
    DMA1_Stream2_IRQHandler,                     /**< DMA1_Stream2 */
    DMA1_Stream3_IRQHandler,                     /**< DMA1_Stream3 */
    DMA1_Stream4_IRQHandler,                     /**< DMA1_Stream4 */
    DMA1_Stream5_IRQHandler,                     /**< DMA1_Stream5 */
    DMA1_Stream6_IRQHandler,                     /**< DMA1_Stream6 */
    ADC_IRQHandler,                              /**< ADC */
    CAN1_TX_IRQHandler,                          /**< CAN1_TX */
    CAN1_RX0_IRQHandler,                         /**< CAN1_RX0 */
    CAN1_RX1_IRQHandler,                         /**< CAN1_RX1 */
    CAN1_SCE_IRQHandler,                         /**< CAN1_SCE */
    EXTI9_5_IRQHandler,                          /**< EXTI9_5 */
    TIM1_BRK_TIM9_IRQHandler,                    /**< TIM1_BRK_TIM9 */
    TIM1_UP_TIM10_IRQHandler,                    /**< TIM1_UP_TIM10 */
    TIM1_TRG_COM_TIM11_IRQHandler,               /**< TIM1_TRG_COM_TIM11 */
    TIM1_CC_IRQHandler,                          /**< TIM1_CC */
    TIM2_IRQHandler,                             /**< TIM2 */
    TIM3_IRQHandler,                             /**< TIM3 */
    TIM4_IRQHandler,                             /**< TIM4 */
    I2C1_EV_IRQHandler,                          /**< I2C1_EV */
    I2C1_ER_IRQHandler,                          /**< I2C1_ER */
    I2C2_EV_IRQHandler,                          /**< I2C2_EV */
    I2C2_ER_IRQHandler,                          /**< I2C2_ER */
    SPI1_IRQHandler,                             /**< SPI1 */
    SPI2_IRQHandler,                             /**< SPI2 */
    USART1_IRQHandler,                           /**< USART1 */
    USART2_IRQHandler,                           /**< USART2 */
    USART3_IRQHandler,                           /**< USART3 */
    EXTI15_10_IRQHandler,                        /**< EXTI15_10 */
    RTC_Alarm_IRQHandler,                        /**< RTC_Alarm */
    OTG_FS_WKUP_IRQHandler,                      /**< OTG_FS_WKUP */
    TIM8_BRK_TIM12_IRQHandler,                   /**< TIM8_BRK_TIM12 */
    TIM8_UP_TIM13_IRQHandler,                    /**< TIM8_UP_TIM13 */
    TIM8_TRG_COM_TIM14_IRQHandler,               /**< TIM8_TRG_COM_TIM14 */
    TIM8_CC_IRQHandler,                          /**< TIM8_CC */
    DMA1_Stream7_IRQHandler,                     /**< DMA1_Stream7 */
    FSMC_IRQHandler,                             /**< FSMC */
    SDIO_IRQHandler,                             /**< SDIO */
    TIM5_IRQHandler,                             /**< TIM5 */
    SPI3_IRQHandler,                             /**< SPI3 */
    UART4_IRQHandler,                            /**< UART4 */
    UART5_IRQHandler,                            /**< UART5 */
    TIM6_DAC_IRQHandler,                         /**< TIM6_DAC */
    TIM7_IRQHandler,                             /**< TIM7 */
    DMA2_Stream0_IRQHandler,                     /**< DMA2_Stream0 */
    DMA2_Stream1_IRQHandler,                     /**< DMA2_Stream1 */
    DMA2_Stream2_IRQHandler,                     /**< DMA2_Stream2 */
    DMA2_Stream3_IRQHandler,                     /**< DMA2_Stream3 */
    DMA2_Stream4_IRQHandler,                     /**< DMA2_Stream4 */
    ETH_IRQHandler,                              /**< ETH */
    ETH_WKUP_IRQHandler,                         /**< ETH_WKUP */
    CAN2_TX_IRQHandler,                          /**< CAN2_TX */
    CAN2_RX0_IRQHandler,                         /**< CAN2_RX0 */
    CAN2_RX1_IRQHandler,                         /**< CAN2_RX1 */
    CAN2_SCE_IRQHandler,                         /**< CAN2_SCE */
    OTG_FS_IRQHandler,                           /**< OTG_FS */
    DMA2_Stream5_IRQHandler,                     /**< DMA2_Stream5 */
    DMA2_Stream6_IRQHandler,                     /**< DMA2_Stream6 */
    DMA2_Stream7_IRQHandler,                     /**< DMA2_Stream7 */
    USART6_IRQHandler,                           /**< USART6 */
    I2C3_EV_IRQHandler,                          /**< I2C3_EV */
    I2C3_ER_IRQHandler,                          /**< I2C3_ER */
    OTG_HS_EP1_OUT_IRQHandler,                   /**< OTG_HS_EP1_OUT */
    OTG_HS_EP1_IN_IRQHandler,                    /**< OTG_HS_EP1_IN */
    OTG_HS_WKUP_IRQHandler,                      /**< OTG_HS_WKUP */    
    OTG_HS_IRQHandler,                           /**< OTG_HS */
    DCMI_IRQHandler,                             /**< DCMI */
    0,                                           /**< Reserved */
    HASH_RNG_IRQHandler,                         /**< HASH_RNG */
    FPU_IRQHandler                               /**< FPU */
};

/**< Hàm Reset_Handler */
void Reset_Handler(void){
    /**< Khởi tạo MSB*/ 

    /**< Copy data từ flash sang RAM */
    uint32_t *src = &__data_flash_start;
    uint32_t *dst = &__data_start;
    while(dst < &__data_end){
        *dst++ = *src++;    
    }

    /**< Khởi tạo vùng nhớ .bss bằng 0 */
    dst = &__bss_start;
    while(dst < &__bss_end){
        *dst++ = 0;
    }

    /**< Gọi hàm khởi tạo hệ thống */
    SystemInit();

    /**< Gọi hàm khởi tạo thư viện */
    __libc_init_array();

    /**< Gọi hàm main */
    main();

    /**< Vô hạn loop */
    while(1);               /**< Debug */
}

/**< Hàm mặc định xử lý lỗi */
void Default_Handler(void){
    /**< Vô hạn loop */
    while(1);               /**< Debug lỗi */
}   






