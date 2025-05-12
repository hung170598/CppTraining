#ifndef __LED_H_
#define __LED_H_
#include "stdint.h"
typedef struct{
  unsigned char IsOn;
  unsigned char Times;
  unsigned char EdgeTime;
  unsigned char CountEdgeTime;
}Led_TypeDef;

void Led_Init();
void Led_Process(void(*FinishFunction)());
void Led_Blink(uint32_t Times, uint32_t EdgeTime);
#endif