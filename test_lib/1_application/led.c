#include "led.h"
#include "stdint.h"
#include "config.h"
__no_init Led_TypeDef Led;
void Led_Init(){
  Led.IsOn              = 0;
  CFG_LED(0);
  Led.Times             = 0;
  Led.EdgeTime          = 0;
  Led.CountEdgeTime     = 0;
}

void Led_Process(void(*FinishFunction)()){
  if(Led.Times){
    if(Led.CountEdgeTime++ >= Led.EdgeTime){
      Led.CountEdgeTime = 0;
      Led.IsOn = !Led.IsOn; // turn on/ turn off led
      CFG_LED(Led.IsOn);
//      if(Led.Times != 255){
          if(!(--Led.Times) && FinishFunction){
            FinishFunction();
          }
//      }
    }
  }
}
void Led_Blink(uint32_t Times, uint32_t EdgeTime){
  Led.IsOn              = 0;
  CFG_LED(0);
  Led.CountEdgeTime     = 0xFE;
  Led.EdgeTime          = EdgeTime;
  Led.Times             = Times * 2;
  
}