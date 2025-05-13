#include "exti.h"
#include "mygpio.h"
#include "nvic.h"

#define _EXTICR_IDX(line)               ((uint32_t)line >> 2UL)
#define _BIT_SHIFT_EXTICR(line)         (((uint32_t)line & 3UL) * 4UL)

static IRQn_Type get_irqn(uint8_t line)
{
    IRQn_Type exti_irqn;
    if(line == 0)                       exti_irqn = EXTI0_IRQn;
    else if(line == 1)                  exti_irqn = EXTI1_IRQn;
    else if(line == 2)                  exti_irqn = EXTI2_IRQn;
    else if(line == 3)                  exti_irqn = EXTI3_IRQn;
    else if(line == 4)                  exti_irqn = EXTI4_IRQn;
    else if(line >= 5 && line <=9)       exti_irqn = EXTI9_5_IRQn;
    else if(line >= 10 && line <=15)     exti_irqn = EXTI15_10_IRQn;
    else return -1;

    return exti_irqn;
}

void EXTI_Config(GPIO_TypeDef *GPIOx, uint8_t line, uint32_t priority, trigger_edge_t edge)
{
    uint32_t line_config = 0;
    if (GPIOx == GPIOA)
        line_config = 0x0UL;
    else if (GPIOx == GPIOB)
        line_config = 0x1UL;
    else if (GPIOx == GPIOC)
        line_config = 0x2UL;
    else if (GPIOx == GPIOD)
        line_config = 0x3UL;
    else if (GPIOx == GPIOE)
        line_config = 0x4UL;

    /* enable AFIO clock */
    RCC->APB2ENR |= (1 << 0);

    /* choose interrupt line */
    AFIO->EXTICR[_EXTICR_IDX(line)] =  AFIO->EXTICR[_EXTICR_IDX(line)] & ~((0xFUL << _BIT_SHIFT_EXTICR(line))) |
                                    ((line_config & (uint32_t)(0xFUL)) << _BIT_SHIFT_EXTICR(line));

    /* unmask (unblock) EXTI 0 interupt */
    EXTI->IMR |= (1 << line);

    if(edge == RISING_TRIGGER)
    {
        /* enable rising trigger & disable falling trigger */
        EXTI->RTSR |=  (1 << line); //rising
        EXTI->FTSR &=  ~(1 << line);
    }

    else if(edge == FALLING_TRIGGER)
    {
        /* enable falling trigger & disable rising trigger */
        EXTI->RTSR &=  ~(1 << line); 
        EXTI->FTSR |=  (1 << line);
    }

    else if(edge == RISING_FALLING_TRIGGER)
    {
        /* enable falling trigger & disable rising trigger */
        EXTI->RTSR |=  (1 << line); 
        EXTI->FTSR |=  (1 << line);
    }

    IRQn_Type exti_irqn = get_irqn(line);
    if(exti_irqn == -1) return;

    /* enable NVIC interrupt */
	NVIC_SetPriority(exti_irqn,priority);
	NVIC_EnableIRQ(exti_irqn);
}

void EXTI_ClearIT(uint8_t line)
{

    IRQn_Type exti_irqn = get_irqn(line);
    if(exti_irqn == -1) return;

    /* clear pending  interrupt */
	NVIC_ClearPendingIRQ(exti_irqn);

	/* clear interrupt by setting this bit to 1 */
	EXTI->PR |= (line << 0);

	/* sau khi nhan lenh thi chan cac interrupt khac, de phong ngua th bam nut qua nhanh*/
	EXTI->IMR &= ~(line << 0);
}

void EXTI_SetIT(uint8_t line)
{
    /* enable lại line ngắt */
	EXTI->IMR |= (line << 0);
}