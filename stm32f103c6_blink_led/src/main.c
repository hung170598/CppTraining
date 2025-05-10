// #include "stm32f103xb.h"

// // #define LED_PIN 13 //PC13
// #define LED_PIN 5 //PA5A5
// #define LED_PORT  GPIOA

// void delay(volatile uint32_t count){
//     while(count--);
// }

// int main(void){
//     //Enable GPIOC clock
//     // RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;

//     //Enable GPIOA Clock
//     RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

//     //Set PA5 push-pull output
//     GPIOA->CRL &= ~(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
//     GPIOA->CRL |= GPIO_CRL_MODE5_1; //output 2 MHz

//     // //Set PC13 as push-up output
//     // GPIOC->CRH &= ~(GPIO_CRH_MODE13) | (GPIO_CRH_CNF13);
//     // GPIOC->CRH |= GPIO_CRH_MODE13_1; //output 2 MHz

//     while(1){
//         // GPIOC->ODR ^= (1 << LED_PIN);
//         GPIOA->ODR ^= (1 << LED_PIN);
//         delay(1000000);
//     }
// }

 #include <stdint.h>
 #include "led_blink.h"
 
 // --- RCC & GPIO register defines for F103 ---
 #define RCC_BASE        0x40021000UL // UL: unsigned long type variables help complier know address is a unsigned number 32 bit
 #define RCC_APB2ENR     (*(volatile uint32_t *)(RCC_BASE + 0x18))
 
 #define GPIOC_BASE      0x40011000UL // UL: unsigned long type variables help complier know address is a unsigned number 32 bit
 #define GPIOC_CRL       (*(volatile uint32_t *)(GPIOC_BASE + 0x00)) // CRL for PC0–PC7
 #define GPIOC_CRH       (*(volatile uint32_t *)(GPIOC_BASE + 0x04)) // CRH for PC8–PC15
 #define GPIOC_ODR       (*(volatile uint32_t *)(GPIOC_BASE + 0x0C)) // ODR for output data
 
 int main(void) {
    /* 1) Enable clock for GPIOC (bit 4) */
    RCC_APB2ENR |= (1 << 4);

    /* 2) Configure PC13 as output push-pull, max 50MHz
        PC13 position in CRH (pin 8–15), each pin 4 bits: [CNF1 CNF0 MODE1 MODE0]
        use MODE=11 (50MHz), CNF=00 (push-pull): 0b0011
        position 4*(13-8)=20
    */
       GPIOC_CRH &= ~(0xF << 20);      // clear bits for PC13
       GPIOC_CRH |=  (0x3 << 20);      // MODE=11, CNF=00

    while (1) {
        // each toggle, call function module
        LED_Toggle(500000); 
    }
}
 