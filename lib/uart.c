#include "uart.h"
#include "gpio.h"
#include <stdint.h>
#include "rcc.h"
void uart_init_driver(uart_config uart)
{
    // defaut UART1
    if (uart->uart_num == USART1)
    {
        RCC->RCC_APB2ENR |= (1U << 2); // enable clock PA
        RCC->RCC_APB2ENR |= (1U << 14); // enable clock USART1
    }
    uart->uart_num->USART_CR1 |= (1U << 13); // Enable

    if (uart->baud_rate == 9600)
    {
        uart->uart_num->USART_BR = (52U << 4 | 1U); // 8Mhz + 9600
    }
    uart->uart_num->USART_CR1 &= ~(1U << 12); // Clear word length
    uart->uart_num->USART_CR1 |= (uart->data_bits << 12); // World length
    uart->uart_num->USART_CR2 &= ~((3U) << 12); // Clear stop bits (2 bits 12-13)
    uart->uart_num->USART_CR2 |= (uart->stop_bits << 12); // 1 stop bit
    USART1->USART_CR1 &= ~(1U << 10); // Parity control disabled
}
void uart_set_pin(int8_t tx_pin, int8_t rx_pin)
{
    GPIO_Config_t uart_tx = {
        .pin = 1U << tx_pin,
        .mode = GPIO_MODE_OUTPUT_50MHz,
        .outputType = GPIO_OUTPUT_AF_PUSH_PULL,
        .port = GPIOA,
    };
    GPIO_Config_t uart_rx = {
        .port = GPIOA,
        .mode = GPIO_MODE_INPUT,
        .inputType = GPIO_INPUT_PULL_UP_DOWN,
        .pin = 1U << rx_pin,
    };
    GPIO_Config(&uart_rx);
    GPIO_Config(&uart_tx);
}

void uart_write_byte(uart_config uart, char byte)
{
    uart->uart_num->USART_DR = byte;
    while (!(uart->uart_num->USART_SR & (1U << 6)))
        ;
}
void uart_write_data(uart_config uart, char *buf, int len)
{
    uart->uart_num->USART_CR1 |= 1U << 3; // Enable
    for (int i = 0; i < len; i++)
    {
        uart_write_byte(uart, buf[i]);
    }
}
