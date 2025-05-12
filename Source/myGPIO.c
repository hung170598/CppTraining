#include "myGPIO.h"

int GPIO_SetOutput(my_GPIO_t* GPIOx, Pin_t Pin)
{
    if(Pin >7 && Pin < 16)
    {
        GPIOx->CRH &= ~(0xF << ((Pin-8)*4));      // clear bits
        GPIOx->CRH |=  (0x2 << ((Pin-8)*4));      // MODE = 10 (Output 2MHz), CNF = 00 (Push-pull)
    }
    else if(Pin <= 7 && Pin >=0 )
    {
        GPIOx->CRL &= ~(0xF << (Pin*4));      // clear bits
        GPIOx->CRL |=  (0x2 << (Pin*4));     // MODE = 10 (Output 2MHz), CNF = 00 (Push-pull)
    }
    else
    {
        return -1;
    }
    return 0;
}


int GPIO_SetInput(my_GPIO_t* GPIOx, Pin_t Pin, PullOpt_t Opt )
{
    if(Pin >7 && Pin < 16)
    {
        GPIOx->CRH &= ~(0xF << ((Pin-8)*4));      // clear bits
        GPIOx->CRH |=  (0x8 << ((Pin-8)*4));      // MODE = 10 (Output 2MHz), CNF = 00 (Push-pull)
        if(Opt==PULL_UP)
        {
            GPIOx->ODR |= (1 << Pin);     // Pull-up
        }
        else
        {
            GPIOx->ODR &= ~(1 << Pin);     // Pull-up
        }
    }
    else if(Pin <= 7 && Pin >=0 )
    {
        GPIOx->CRL &= ~(0xF << (Pin*4));      // clear bits
        GPIOx->CRL |=  (0x8 << (Pin*4));     // MODE = 10 (Output 2MHz), CNF = 00 (Push-pull)
        if(Opt==PULL_UP)
        {
            GPIOx->ODR |= (1 << Pin);     // Pull-up
        }
        else
        {
            GPIOx->ODR &= ~(1 << Pin);     // Pull-up
        }
    }
    else
    {
        return -1;
    }
    return 0;
}

int GPIO_TogglePin(my_GPIO_t* GPIOx, Pin_t Pin)
{
    if (Pin >=0 && Pin <=15)
    {
        GPIOx->ODR ^= (1<<Pin);
        return 0;
    }
    return -1;
}

int GPIO_ReadPin(my_GPIO_t* GPIOx, Pin_t Pin)
{
    int res=-1;
    if(Pin>=0 && Pin <=15)
    {
        if((GPIOx->IDR & (1<<Pin)) ==0)
        {
            res=0;
        }
        else
        {
            res=1;
        }
    }
    return res;
}