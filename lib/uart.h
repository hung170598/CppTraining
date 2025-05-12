#ifndef _UART_H_
#define _UART_H_
#include <stdint.h>

#define USART1_ADDRESS 0x40013800
#define USART2_ADDRESS 0x40004400
#define USART3_ADDRESS 0x40004800

typedef struct
{
    volatile uint32_t USART_SR;
    volatile uint32_t USART_DR;
    volatile uint32_t USART_BR;
    volatile uint32_t USART_CR1;
    volatile uint32_t USART_CR2;
    volatile uint32_t USART_CR3;
    volatile uint32_t USART_GTPR;
} USART_t;

#define USART1 ((USART_t *)(USART1_ADDRESS))
#define USART2 ((USART_t *)(USART2_ADDRESS))
#define USART3 ((USART_t *)(USART3_ADDRESS))

/**
 * @brief UART word length constants
 */
typedef enum
{
    UART_DATA_8_BITS, /*!< word length: 8bits*/
    UART_DATA_9_BITS, /*!< word length: 9bits*/
} uart_word_length_t;
/**
 * @brief UART stop bits number
 */
typedef enum
{
    UART_STOP_BITS_1, /*!< stop bit: 1bit*/
    UART_STOP_BITS_0_5, /*!< stop bit: 0.5bits*/
    UART_STOP_BITS_2, /*!< stop bit: 2bits*/
    UART_STOP_BITS_1_5, /*!< stop bit: 1.5 bits*/
    // The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.
} uart_stop_bits_t;

/**
 * @brief UART parity constants
 */
typedef enum
{
    UART_PARITY_DISABLE = 0x0, /*!< Disable UART parity*/
    UART_PARITY_EVEN = 0x2, /*!< Enable UART even parity*/
    UART_PARITY_ODD = 0x3 /*!< Enable UART odd parity*/
} uart_parity_t;

typedef struct
{
    int baud_rate; /*!< UART baud rate*/
    uart_word_length_t data_bits; /*!< UART byte size*/
    uart_parity_t parity; /*!< UART parity mode*/
    uart_stop_bits_t stop_bits; /*!< UART stop bits*/
    USART_t *uart_num;

} uart_config_t;
typedef uart_config_t *uart_config;
void uart_init_driver(uart_config uart);
void uart_set_pin(int8_t tx_pin, int8_t rx_pin);
void uart_write_byte(uart_config uart, char byte);
void uart_write_data(uart_config uart, char *buf, int len);
#endif
