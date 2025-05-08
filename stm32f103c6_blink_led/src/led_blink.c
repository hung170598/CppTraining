
/*
 * led_blink.c
 *
 *  Created on: May 6, 2025
 *      Author: hieu.nguyentri
 */


 #include "led_blink.h"

 #define GPIOC_BASE    0x40011000UL
 #define GPIOC_ODR     (*(volatile uint32_t *)(GPIOC_BASE + 0x0C)) // ODR
 
 static void delay(uint32_t count) {
     while (count--) {
         __asm("nop");
     }
 }
 
 void LED_Toggle(uint32_t delay_count) {
     // PC13 = 1 → LED off (since LED jump to GND); PC13 = 0 → LED on
    GPIOC_ODR &= ~(1 << 13);
    delay(1000000);
 }
 