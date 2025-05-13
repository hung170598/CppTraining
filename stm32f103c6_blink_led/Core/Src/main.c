#include "main.h"
#include "mygpio.h"
#include "rcc.h"
#include "exti.h"

void SystemInit(void){}
void _init(void) {}

uint8_t extiflag = 0;
uint8_t state = 0;

int main(void)
{
	RCC_HSE_Config();
	RCC_SYSTICK_Config(72000);

	GPIO_Init(GPIOB, 14, GPIO_MODE_OUTPUT_2M, GPIO_CNF_GP_OUTPUT_PP, GPIO_NOPULL);
	GPIO_Init(GPIOA, 0, GPIO_MODE_INPUT, GPIO_CNF_INPUT_PULL, GPIO_PULLUP);
	EXTI_Config(GPIOA, 0, 5, FALLING_TRIGGER);
	
	uint32_t last_tick = 0;
	while(1)
	{
		// if(GPIO_ReadPin(GPIOA, 0) == GPIO_PIN_RESET)
		// {
		// 	RCC_msDelay(20); 
		// 	if(GPIO_ReadPin(GPIOA, 0) == GPIO_PIN_RESET)
		// 	{				
		// 		while(GPIO_ReadPin(GPIOA, 0) == GPIO_PIN_RESET);
		// 		state = !state;
		// 	}
		// }

		// if(state)
		// {
		// 	if(RCC_msGetTicks() - last_tick >= 1000)
		// 	{
		// 		last_tick = RCC_msGetTicks();
		// 		GPIO_TogglePin(GPIOB, 14);
		// 	}
		// }
		// else
		// {
		// 	GPIO_WritePin(GPIOB, 14, GPIO_PIN_RESET);
		// }

		if(extiflag)
		{
			// GPIO_TogglePin(GPIOB,14);
			EXTI_SetIT(0);
			extiflag = 0;
			RCC_msDelay(20);
		}

		if(state)
		{
			if(RCC_msGetTicks() - last_tick >= 1000)
			{
				last_tick = RCC_msGetTicks();
				GPIO_TogglePin(GPIOB, 14);
			}
		}
		else
		{
			GPIO_WritePin(GPIOB, 14, GPIO_PIN_RESET);
		}
	}
}

void EXTI0_IRQHandler(void)
{
	EXTI_ClearIT(0);
	extiflag = 1;
	state = !state;
}