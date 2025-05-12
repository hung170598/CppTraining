#include "stm32f10x.h"

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 8000; i++) {
        __NOP();
    }
}

int main(void) {
    // B?t clock cho GPIOA
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    // C?u hình PA0 làm output push-pull, 2 MHz
    GPIOA->CRL &= ~(0xF << 0);   // Xóa MODE0[1:0] và CNF0[1:0]
    GPIOA->CRL |=  (0x3 << 0);   // MODE0 = 0b10 (2 MHz), CNF0 = 0b00 (Push-pull)

    while (1) {
        GPIOA->ODR ^= GPIO_ODR_ODR0; // Toggle PA0
        delay_ms(500);
    }
}
