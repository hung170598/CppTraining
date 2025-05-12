#ifndef SYSTICK_H
#define SYSTICK_H
#include "AddressMap.h"
#include "myRCC.h"

void SysTickInit();
uint32_t GetTick();
void delay(uint32_t ms);

#endif