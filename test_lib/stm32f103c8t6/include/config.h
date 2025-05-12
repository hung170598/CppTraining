#ifndef __CONFIG_H_
#define __CONFIG_H_
#include "stdint.h"
#include "gpio.h"
#define CFG_LED(Value) GPIOC.ODR.BITS.c13=!(Value)

#endif