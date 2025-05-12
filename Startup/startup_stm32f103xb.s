.syntax unified
.cpu cortex-m3
.fpu softvfp
.thumb

.global g_pfnVectors
.global Reset_Handler

/* Start of the vector table */
.section .isr_vector, "a", %progbits
.type g_pfnVectors, %object
.size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  .word _estack                  /* Initial Stack Pointer */
  .word Reset_Handler           /* Reset Handler */
  .word NMI_Handler             /* NMI Handler */
  .word HardFault_Handler       /* Hard Fault Handler */
  .word MemManage_Handler       /* MPU Fault Handler */
  .word BusFault_Handler        /* Bus Fault Handler */
  .word UsageFault_Handler      /* Usage Fault Handler */
  .word 0                       /* Reserved */
  .word 0                       /* Reserved */
  .word 0                       /* Reserved */
  .word 0                       /* Reserved */
  .word SVC_Handler             /* SVCall Handler */
  .word DebugMon_Handler        /* Debug Monitor Handler */
  .word 0                       /* Reserved */
  .word PendSV_Handler          /* PendSV Handler */
  .word SysTick_Handler         /* SysTick Handler */

  /* External Interrupts */
  .word WWDG_IRQHandler
  .word PVD_IRQHandler
  .word TAMPER_IRQHandler
  .word RTC_IRQHandler
  .word FLASH_IRQHandler
  .word RCC_IRQHandler
  .word EXTI0_IRQHandler
  .word EXTI1_IRQHandler
  .word EXTI2_IRQHandler
  .word EXTI3_IRQHandler
  .word EXTI4_IRQHandler
  .word DMA1_Channel1_IRQHandler
  .word DMA1_Channel2_IRQHandler
  .word DMA1_Channel3_IRQHandler
  .word DMA1_Channel4_IRQHandler
  .word DMA1_Channel5_IRQHandler
  .word DMA1_Channel6_IRQHandler
  .word DMA1_Channel7_IRQHandler
  .word ADC1_2_IRQHandler
  .word USB_HP_CAN_TX_IRQHandler
  .word USB_LP_CAN_RX0_IRQHandler
  .word CAN_RX1_IRQHandler
  .word CAN_SCE_IRQHandler
  .word EXTI9_5_IRQHandler
  .word TIM1_BRK_IRQHandler
  .word TIM1_UP_IRQHandler
  .word TIM1_TRG_COM_IRQHandler
  .word TIM1_CC_IRQHandler
  .word TIM2_IRQHandler
  .word TIM3_IRQHandler
  .word TIM4_IRQHandler
  .word I2C1_EV_IRQHandler
  .word I2C1_ER_IRQHandler
  .word I2C2_EV_IRQHandler
  .word I2C2_ER_IRQHandler
  .word SPI1_IRQHandler
  .word SPI2_IRQHandler
  .word USART1_IRQHandler
  .word USART2_IRQHandler
  .word USART3_IRQHandler
  .word EXTI15_10_IRQHandler
  .word RTCAlarm_IRQHandler
  .word USBWakeUp_IRQHandler

/* Default handlers */
.section .text.Default_Handler, "ax", %progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop

.weak NMI_Handler
.set NMI_Handler, Default_Handler

.weak HardFault_Handler
.set HardFault_Handler, Default_Handler

.weak MemManage_Handler
.set MemManage_Handler, Default_Handler

.weak BusFault_Handler
.set BusFault_Handler, Default_Handler

.weak UsageFault_Handler
.set UsageFault_Handler, Default_Handler

.weak SVC_Handler
.set SVC_Handler, Default_Handler

.weak DebugMon_Handler
.set DebugMon_Handler, Default_Handler

.weak PendSV_Handler
.set PendSV_Handler, Default_Handler

.weak SysTick_Handler
.set SysTick_Handler, Default_Handler

/* External interrupt handlers (all weakly linked to Default_Handler) */
.weak WWDG_IRQHandler
.set WWDG_IRQHandler, Default_Handler
.weak PVD_IRQHandler
.set PVD_IRQHandler, Default_Handler
.weak TAMPER_IRQHandler
.set TAMPER_IRQHandler, Default_Handler
.weak RTC_IRQHandler
.set RTC_IRQHandler, Default_Handler
.weak FLASH_IRQHandler
.set FLASH_IRQHandler, Default_Handler
.weak RCC_IRQHandler
.set RCC_IRQHandler, Default_Handler
.weak EXTI0_IRQHandler
.set EXTI0_IRQHandler, Default_Handler
.weak EXTI1_IRQHandler
.set EXTI1_IRQHandler, Default_Handler
.weak EXTI2_IRQHandler
.set EXTI2_IRQHandler, Default_Handler
.weak EXTI3_IRQHandler
.set EXTI3_IRQHandler, Default_Handler
.weak EXTI4_IRQHandler
.set EXTI4_IRQHandler, Default_Handler
.weak DMA1_Channel1_IRQHandler
.set DMA1_Channel1_IRQHandler, Default_Handler
.weak DMA1_Channel2_IRQHandler
.set DMA1_Channel2_IRQHandler, Default_Handler
.weak DMA1_Channel3_IRQHandler
.set DMA1_Channel3_IRQHandler, Default_Handler
.weak DMA1_Channel4_IRQHandler
.set DMA1_Channel4_IRQHandler, Default_Handler
.weak DMA1_Channel5_IRQHandler
.set DMA1_Channel5_IRQHandler, Default_Handler
.weak DMA1_Channel6_IRQHandler
.set DMA1_Channel6_IRQHandler, Default_Handler
.weak DMA1_Channel7_IRQHandler
.set DMA1_Channel7_IRQHandler, Default_Handler
.weak ADC1_2_IRQHandler
.set ADC1_2_IRQHandler, Default_Handler
.weak USB_HP_CAN_TX_IRQHandler
.set USB_HP_CAN_TX_IRQHandler, Default_Handler
.weak USB_LP_CAN_RX0_IRQHandler
.set USB_LP_CAN_RX0_IRQHandler, Default_Handler
.weak CAN_RX1_IRQHandler
.set CAN_RX1_IRQHandler, Default_Handler
.weak CAN_SCE_IRQHandler
.set CAN_SCE_IRQHandler, Default_Handler
.weak EXTI9_5_IRQHandler
.set EXTI9_5_IRQHandler, Default_Handler
.weak TIM1_BRK_IRQHandler
.set TIM1_BRK_IRQHandler, Default_Handler
.weak TIM1_UP_IRQHandler
.set TIM1_UP_IRQHandler, Default_Handler
.weak TIM1_TRG_COM_IRQHandler
.set TIM1_TRG_COM_IRQHandler, Default_Handler
.weak TIM1_CC_IRQHandler
.set TIM1_CC_IRQHandler, Default_Handler
.weak TIM2_IRQHandler
.set TIM2_IRQHandler, Default_Handler
.weak TIM3_IRQHandler
.set TIM3_IRQHandler, Default_Handler
.weak TIM4_IRQHandler
.set TIM4_IRQHandler, Default_Handler
.weak I2C1_EV_IRQHandler
.set I2C1_EV_IRQHandler, Default_Handler
.weak I2C1_ER_IRQHandler
.set I2C1_ER_IRQHandler, Default_Handler
.weak I2C2_EV_IRQHandler
.set I2C2_EV_IRQHandler, Default_Handler
.weak I2C2_ER_IRQHandler
.set I2C2_ER_IRQHandler, Default_Handler
.weak SPI1_IRQHandler
.set SPI1_IRQHandler, Default_Handler
.weak SPI2_IRQHandler
.set SPI2_IRQHandler, Default_Handler
.weak USART1_IRQHandler
.set USART1_IRQHandler, Default_Handler
.weak USART2_IRQHandler
.set USART2_IRQHandler, Default_Handler
.weak USART3_IRQHandler
.set USART3_IRQHandler, Default_Handler
.weak EXTI15_10_IRQHandler
.set EXTI15_10_IRQHandler, Default_Handler
.weak RTCAlarm_IRQHandler
.set RTCAlarm_IRQHandler, Default_Handler
.weak USBWakeUp_IRQHandler
.set USBWakeUp_IRQHandler, Default_Handler

/* Reset Handler */
.section .text.Reset_Handler, "ax", %progbits
.type Reset_Handler, %function
Reset_Handler:
  /* Copy .data section to SRAM */
  ldr r0, =_sidata
  ldr r1, =_sdata
  ldr r2, =_edata
1:
  cmp r1, r2
  ittt lt
  ldrlt r3, [r0], #4
  strlt r3, [r1], #4
  blt 1b

  /* Zero initialize .bss section */
  ldr r0, =_sbss
  ldr r1, =_ebss
  movs r2, #0
2:
  cmp r0, r1
  itt lt
  strlt r2, [r0], #4
  blt 2b

  /* Call main */
  bl main
  b .

.size Reset_Handler, . - Reset_Handler
