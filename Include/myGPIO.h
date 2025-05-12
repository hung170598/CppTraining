#ifndef MY_GPIO_H
#define MY_GPIO_H

#include "AddressMap.h"

typedef enum
{
    PULL_UP,
    PULL_DOWN
}PullOpt_t;

typedef enum
{
    Pin_0=0,
    Pin_1,
    Pin_2,
    Pin_3,
    Pin_4,
    Pin_5,
    Pin_6,
    Pin_7,
    Pin_8,
    Pin_9,
    Pin_10,
    Pin_11,
    Pin_12,
    Pin_13,
    Pin_14,
    Pin_15
}Pin_t;

int GPIO_SetInput(my_GPIO_t* GPIOx, Pin_t Pin,PullOpt_t Opt);
int GPIO_SetOutput(my_GPIO_t* GPIOx, Pin_t Pin);
int GPIO_ReadPin(my_GPIO_t* GPIOx, Pin_t Pin);
int GPIO_TogglePin(my_GPIO_t* GPIOx, Pin_t Pin);

#endif
