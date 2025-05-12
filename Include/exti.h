#ifndef EXTI_H
#define EXTI_H

#include "AddressMap.h"
#include "myGPIO.h"
#include "NVIC.h"
#include "myRCC.h"

typedef enum
{
    RISING_EDGE,
    FALLING_EDGE
}EdgeDetect_t;
void EXTI_Init(my_GPIO_t* GPIOx,Pin_t Pin,PullOpt_t PullOpt,EdgeDetect_t EdgeOpt,int prio);
void EXTI_Disable(Pin_t Pin);

#endif