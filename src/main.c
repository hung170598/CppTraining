#include <stdint.h>
#include <stdio.h>
#include "rcc.h"
#include "gpio.h"
#include "stdbool.h"
#include "uart.h"
#include "adc.h"
#include "drivers/log_info.h"
#include "drivers/temp.h"
int main(void)
{
    config_mode();

    RCC->RCC_APB2ENR |= 1 << 4;
    GPIO_Config_t blink = {
        .pin = 1U << 13,
        .port = GPIOC,
        .mode = GPIO_MODE_OUTPUT_2MHz,
        .outputType = GPIO_OUTPUT_PUSH_PULL,
    };

    uart_config_t uart = {
        .uart_num = USART1,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .baud_rate = 9600,
    };
    uart_init_driver(&uart);
    uart_set_pin(9, 10);
    GPIO_Config(&blink);
    while (1)
    {
        uart_write_data(&uart, "Hello World !!!", 16);

        start_conversion();
        uint32_t value = ADC1->ADC_DR;
        obtain_temperature(value);

        gpio_set_level(&blink, false);
        for (int i = 0; i < 1000000; i++)
            ;
        gpio_set_level(&blink, true);
        for (int i = 0; i < 1000000; i++)
            ;
    }
}
