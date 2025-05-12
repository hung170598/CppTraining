#include "systick.h"

volatile uint32_t tickCount = 0;
void SysTickInit()
{
    STK->CTRL = 0;
    uint32_t tickInt = SystemClock / 1000 - 1;  // 1ms interval
    STK->LOAD = tickInt;
    STK->VAL  = 0; // reset current value
    STK->CTRL = (1 << 2) | (1 << 1) | (1 << 0); // CLKSOURCE, TICKINT, ENABLE
}

void SysTick_Handler()
{
    tickCount++;
}

uint32_t GetTick()
{
    return tickCount;
}

void delay(uint32_t ms)
{
    uint32_t start = GetTick();
    while ((int32_t)(GetTick() - start) < (int32_t)ms);
}
