#include "rcc.h"
//#include "define.h"
typedef struct{
  union{
    unsigned long REG;
    struct{
      unsigned long Mode_0 : 2;
      unsigned long   CNF0 : 2;
      unsigned long Mode_1 : 2;
      unsigned long   CNF1 : 2;
      unsigned long Mode_2 : 2;
      unsigned long   CNF2 : 2;
      unsigned long Mode_3 : 2;
      unsigned long   CNF3 : 2;
      unsigned long Mode_4 : 2;  
      unsigned long   CNF4 : 2;
      unsigned long Mode_5 : 2;
      unsigned long   CNF5 : 2;
      unsigned long Mode_6 : 2;
      unsigned long   CNF6 : 2;    
      unsigned long Mode_7 : 2;
      unsigned long   CNF7 : 2;
    }BITS;
  }CRL;
  union{
    unsigned long REG;
    struct{
      unsigned long Mode_8  : 2;
      unsigned long   CNF8  : 2;
      unsigned long Mode_9  : 2;
      unsigned long   CNF9  : 2;
      unsigned long Mode_10 : 2;
      unsigned long   CNF10 : 2;
      unsigned long Mode_11 : 2;
      unsigned long   CNF11 : 2;
      unsigned long Mode_12 : 2;
      unsigned long   CNF12 : 2;
      unsigned long Mode_13 : 2;
      unsigned long   CNF13 : 2;
      unsigned long Mode_14 : 2;
      unsigned long   CNF14 : 2;
      unsigned long Mode_15 : 2;
      unsigned long   CNF15 : 2;  
    }BITS;
  }CRH;
  union{
    unsigned long REG;
    struct{
      unsigned long c0  : 1;
      unsigned long c1  : 1;
      unsigned long c2  : 1;
      unsigned long c3  : 1;
      unsigned long c4  : 1;
      unsigned long c5  : 1;
      unsigned long c6  : 1;
      unsigned long c7  : 1;
      unsigned long c8  : 1;
      unsigned long c9  : 1;
      unsigned long c10 : 1;
      unsigned long c11 : 1;
      unsigned long c12 : 1;
      unsigned long c13 : 1;
      unsigned long c14 : 1;
      unsigned long c15 : 1;
      unsigned long _reserved : 16;
    }BITS;
  }IDR;
  union{
    unsigned long REG;
    struct{
      unsigned long c0  : 1;
      unsigned long c1  : 1;
      unsigned long c2  : 1;
      unsigned long c3  : 1;
      unsigned long c4  : 1;
      unsigned long c5  : 1;
      unsigned long c6  : 1;
      unsigned long c7  : 1;
      unsigned long c8  : 1;
      unsigned long c9  : 1;
      unsigned long c10 : 1;
      unsigned long c11 : 1;
      unsigned long c12 : 1;
      unsigned long c13 : 1;
      unsigned long c14 : 1;
      unsigned long c15 : 1;
      unsigned long _reserved : 16;
    }BITS;    
  }ODR; 
  union{
    unsigned long REG;
    struct{
      union{
        unsigned short REG;
        struct{
          unsigned short c0  : 1;
          unsigned short c1  : 1;
          unsigned short c2  : 1;
          unsigned short c3  : 1;
          unsigned short c4  : 1;
          unsigned short c5  : 1;
          unsigned short c6  : 1;
          unsigned short c7  : 1;
          unsigned short c8  : 1;
          unsigned short c9  : 1;
          unsigned short c10 : 1;
          unsigned short c11 : 1;
          unsigned short c12 : 1;
          unsigned short c13 : 1;
          unsigned short c14 : 1;
          unsigned short c15 : 1;
        }BITS;
      }BSR;
      union{
        unsigned short REG;
        struct{
          unsigned short c0  : 1;
          unsigned short c1  : 1;
          unsigned short c2  : 1;
          unsigned short c3  : 1;
          unsigned short c4  : 1;
          unsigned short c5  : 1;
          unsigned short c6  : 1;
          unsigned short c7  : 1;
          unsigned short c8  : 1;
          unsigned short c9  : 1;
          unsigned short c10 : 1;
          unsigned short c11 : 1;
          unsigned short c12 : 1;
          unsigned short c13 : 1;
          unsigned short c14 : 1;
          unsigned short c15 : 1;
        }BITS;
      }BR;
    };
  }BSRR;
  union{
    unsigned long REG;
    struct{
        unsigned long c0  : 1;
        unsigned long c1  : 1;
        unsigned long c2  : 1;
        unsigned long c3  : 1;
        unsigned long c4  : 1;
        unsigned long c5  : 1;
        unsigned long c6  : 1;
        unsigned long c7  : 1;
        unsigned long c8  : 1;
        unsigned long c9  : 1;
        unsigned long c10 : 1;
        unsigned long c11 : 1;
        unsigned long c12 : 1;
        unsigned long c13 : 1;
        unsigned long c14 : 1;
        unsigned long c15 : 1;
        unsigned long _reserved : 16;
    }BITS;
  }BRR;
  union{
    unsigned long REG;
    struct{
      unsigned long c0  : 1;
      unsigned long c1  : 1;
      unsigned long c2  : 1;
      unsigned long c3  : 1;
      unsigned long c4  : 1;
      unsigned long c5  : 1;
      unsigned long c6  : 1;
      unsigned long c7  : 1;
      unsigned long c8  : 1;
      unsigned long c9  : 1;
      unsigned long c10 : 1;
      unsigned long c11 : 1;
      unsigned long c12 : 1;
      unsigned long c13 : 1;
      unsigned long c14 : 1;
      unsigned long c15 : 1;
      unsigned long LCKK : 1;
      unsigned long _reserved : 15;
    }BITS;  
   }LCKR;  


}GPIO_TypeDef;
__root __no_init RCC_TypeDef RCC        @ 0x40021000;
__root __no_init GPIO_TypeDef GPIOA     @ 0x40010800;
__root __no_init GPIO_TypeDef GPIOB     @ 0x40010c00;
__root __no_init GPIO_TypeDef GPIOC     @ 0x40011000;
__root __no_init GPIO_TypeDef GPIOD     @ 0x40011400;
__root __no_init GPIO_TypeDef GPIOE     @ 0x40011800;

void main(){
  // turn on clock for GPIOC
  RCC.APB2_ENR.BITS.IOPC = 1;
  // config GPIOC.c13 to Output
  GPIOC.CRH.BITS.Mode_13 = 3;
  GPIOC.CRH.BITS.CNF13   = 0;
  
  while(1){
/*
    GPIOC.BSRR.BR.BITS.c0 = 1; // tuong duong GPIOC.ODR.BITS.c0 = 0;
    GPIOC.BSRR.BSR.BITS.c0 = 1;// tuong duong GPIOC.ODR.BITS.c0 = 1;
*/  
//    GPIOC.ODR.REG = ~GPIOC.ODR.REG;
//    for(unsigned long i = 0; i < 500000; i++);
//    GPIOC.ODR.BITS.c13 = !GPIOC.ODR.BITS.c13;
    GPIOC.BSRR.REG = (1UL << 13);
    for(unsigned long i = 0; i < 500000; i++);
    GPIOC.BSRR.REG = (1UL << (13 + 16)); // BR13 nam o 28
    for(unsigned long i = 0; i < 500000; i++);      
  }
}