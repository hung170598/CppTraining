
#include "myGPIO.h"
#include "myRCC.h"
#include "systick.h"
#include "NVIC.h"
#include "exti.h"

void EXTI_Callback(Pin_t Pin)
{
  if(Pin == Pin_0)
  {
    GPIO_TogglePin(MY_GPIOB,Pin_11);
  }
}

int main(void)
{

  PLL_Init(HSE_IN_NOR,4);
	GPIO_ClockEnable(MY_GPIOB);

  SysTickInit();

  GPIO_SetOutput(MY_GPIOB,Pin_11);
	GPIO_SetInput(MY_GPIOB,Pin_9,PULL_UP);
  
  EXTI_Init(MY_GPIOA,Pin_0,PULL_UP,RISING_EDGE,15);
  while (1)
  {
    // GPIO_TogglePin(GPIOB,Pin_11);
    // delay(1000);

    if(GPIO_ReadPin(MY_GPIOB,Pin_9) == 0)
    {
        GPIO_TogglePin(MY_GPIOB,Pin_11);
    } 

  }
}

