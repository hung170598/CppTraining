#include "exti.h"
__attribute__((weak)) void EXTI_Callback(Pin_t Pin){}



void AFIO_ConfigEXTI(my_GPIO_t* GPIOx,int Pin)
{
    int regVal;
    if (GPIOx == MY_GPIOA) regVal=0;
    else if(GPIOx == MY_GPIOB) regVal=1;
    else if(GPIOx == MY_GPIOC) regVal=2;
    else if(GPIOx == MY_GPIOD) regVal=3;
    else if(GPIOx == MY_GPIOE) regVal=4;

    if(Pin>=0 && Pin<= 3)
    {
        AFIO->EXTICR1 &= ~(0xF << ((Pin & 0x03)*4)); 
        AFIO->EXTICR1 |= (regVal << ((Pin & 0x03)*4));
    }
    else if(Pin>=4 && Pin<= 7)
    {
        AFIO->EXTICR2 &= ~(0xF << ((Pin & 0x03)*4));
        AFIO->EXTICR2 |= (regVal << ((Pin & 0x03)*4));
    }
    else if(Pin>=8 && Pin<= 11)
    {
        AFIO->EXTICR3 &= ~(0xF << ((Pin & 0x03)*4));
        AFIO->EXTICR3 |= (regVal << ((Pin & 0x03)*4));
    }
    else if(Pin>=12 && Pin<= 15)
    {
        AFIO->EXTICR4 &= ~(0xF << ((Pin & 0x03)*4));
        AFIO->EXTICR4 |= (regVal << ((Pin & 0x03)*4));
    }
}

void EXTI_Enable_Mask(int extiLine)
{
    EXTI->IMR |= (1<<extiLine);
}

void EXTI_EdgeConfig(int extiLine, EdgeDetect_t EdgeOpt)
{
    if(EdgeOpt == RISING_EDGE)
    {
        EXTI->FTSR &= ~(1<<extiLine);
        EXTI->RTSR |=  (1<<extiLine);
    }
    else if(EdgeOpt == FALLING_EDGE)
    {
        EXTI->RTSR &= ~(1<<extiLine);
        EXTI->FTSR |=  (1<<extiLine);
    }
}

void EXTI_EnableNVIC(int extiLine)
{
    if(extiLine==0)                         __NVIC_EnableIRQ(EXTI0_IRQn);
    else if(extiLine==1)                    __NVIC_EnableIRQ(EXTI1_IRQn);
    else if(extiLine==2)                    __NVIC_EnableIRQ(EXTI2_IRQn);
    else if(extiLine==3)                    __NVIC_EnableIRQ(EXTI3_IRQn);
    else if(extiLine==4)                    __NVIC_EnableIRQ(EXTI4_IRQn);
    else if(extiLine>=5 && extiLine<=9)     __NVIC_EnableIRQ(EXTI9_5_IRQn);
    else if(extiLine>=10 && extiLine<=15)   __NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI_SetPriority(int extiLine, int prio)
{
    if(extiLine==0)                         __NVIC_SetPriority(EXTI0_IRQn,prio);
    else if(extiLine==1)                    __NVIC_SetPriority(EXTI1_IRQn,prio);
    else if(extiLine==2)                    __NVIC_SetPriority(EXTI2_IRQn,prio);
    else if(extiLine==3)                    __NVIC_SetPriority(EXTI3_IRQn,prio);
    else if(extiLine==4)                    __NVIC_SetPriority(EXTI4_IRQn,prio);
    else if(extiLine>=5 && extiLine<=9)     __NVIC_SetPriority(EXTI9_5_IRQn,prio);
    else if(extiLine>=10 && extiLine<=15)   __NVIC_SetPriority(EXTI15_10_IRQn,prio);
}

void EXTI_Init(my_GPIO_t* GPIOx,Pin_t Pin,PullOpt_t PullOpt,EdgeDetect_t EdgeOpt,int prio)
{
    GPIO_ClockEnable(GPIOx);
    AFIO_ClockEnable();
    GPIO_SetInput(GPIOx,Pin,PullOpt);
    AFIO_ConfigEXTI(GPIOx,Pin);
    EXTI_Enable_Mask(Pin);
    EXTI_EdgeConfig(Pin,EdgeOpt);
    EXTI_SetPriority(Pin,prio);
    EXTI_EnableNVIC(Pin);
}

void EXTI_Disable(Pin_t Pin)
{
    EXTI->IMR &= ~(1<<Pin);
    if(Pin==0)                         __NVIC_DisableIRQ(EXTI0_IRQn);
    else if(Pin==1)                    __NVIC_DisableIRQ(EXTI1_IRQn);
    else if(Pin==2)                    __NVIC_DisableIRQ(EXTI2_IRQn);
    else if(Pin==3)                    __NVIC_DisableIRQ(EXTI3_IRQn);
    else if(Pin==4)                    __NVIC_DisableIRQ(EXTI4_IRQn);
    else if(Pin>=5 && Pin<=9)          __NVIC_DisableIRQ(EXTI9_5_IRQn);
    else if(Pin>=10 && Pin<=15)        __NVIC_DisableIRQ(EXTI15_10_IRQn);
}

void EXTI0_IRQHandler()
{
    if (EXTI->PR & (1<<0)) {
        EXTI_Callback(Pin_0);
        EXTI->PR |= (1<<0);
    }
}
void EXTI1_IRQHandler()
{
    if (EXTI->PR & (1<<1)) {
        EXTI_Callback(Pin_1);
        EXTI->PR |= (1<<1);
    }
}
void EXTI2_IRQHandler()
{
    if (EXTI->PR & (1<<2)) {
        EXTI_Callback(Pin_2);
        EXTI->PR |= (1<<2);
    }
}
void EXTI3_IRQHandler()
{
    if (EXTI->PR & (1<<3)) {
        EXTI_Callback(Pin_3);
        EXTI->PR |= (1<<3);
    }
}
void EXTI4_IRQHandler()
{
    if (EXTI->PR & (1<<4)) {
        EXTI_Callback(Pin_4);
        EXTI->PR |= (1<<4);
    }
}
void EXTI9_5_IRQHandler()
{
    if (EXTI->PR & (1<<5)) {
        EXTI_Callback(Pin_5);
        EXTI->PR |= (1<<5);
    }
    if (EXTI->PR & (1<<6)) {
        EXTI_Callback(Pin_6);
        EXTI->PR |= (1<<6);
    }
    if (EXTI->PR & (1<<7)) {
        EXTI_Callback(Pin_7);
        EXTI->PR |= (1<<7);
    }
    if (EXTI->PR & (1<<8)) {
        EXTI_Callback(Pin_8);
        EXTI->PR |= (1<<8);
    }
    if (EXTI->PR & (1<<9)) {
        EXTI_Callback(Pin_9);
        EXTI->PR |= (1<<9);
    }
}
void EXTI15_10_IRQHandler()
{
    if (EXTI->PR & (1<<10)) {
        EXTI_Callback(Pin_10);
        EXTI->PR |= (1<<10);
    }
    if (EXTI->PR & (1<<11)) {
        EXTI_Callback(Pin_11);
        EXTI->PR |= (1<<11);
    }
    if (EXTI->PR & (1<<12)) {
        EXTI_Callback(Pin_12);
        EXTI->PR |= (1<<12);
    }
    if (EXTI->PR & (1<<13)) {
        EXTI_Callback(Pin_13);
        EXTI->PR |= (1<<13);
    }
    if (EXTI->PR & (1<<14)) {
        EXTI_Callback(Pin_14);
        EXTI->PR |= (1<<14);
    }
    if (EXTI->PR & (1<<15)) {
        EXTI_Callback(Pin_15);
        EXTI->PR |= (1<<15);
    }
}