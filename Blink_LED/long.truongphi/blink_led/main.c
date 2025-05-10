#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t*)0x40021018)
#define GPIOC_CRH     (*(volatile uint32_t*)0x40011004)
#define GPIOC_ODR     (*(volatile uint32_t*)0x4001100C)

#define RCC_APB2ENR_IOPCEN (1 << 4)
#define GPIO_CRH_MODE13    (3 << 20)
#define GPIO_CRH_CNF13     (3 << 22)
#define GPIO_CRH_MODE13_1  (1 << 21)

void delay(volatile uint32_t t) {
    while (t--);
}

int main(void) {
    RCC_APB2ENR |= RCC_APB2ENR_IOPCEN;  // Enable GPIOC clock
    GPIOC_CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);  // Clear config
    GPIOC_CRH |= GPIO_CRH_MODE13_1;  // Output mode, 2 MHz

    while (1) {
        GPIOC_ODR ^= (1 << 13);  // Toggle PC13
        delay(500000);
    }
}