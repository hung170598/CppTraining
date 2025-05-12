#include "rcc.h"
//                                      |               //Address       Default         Description
typedef struct{
  BUNION(CRL, unsigned long,                                                                                            
      Mode_0                            , 2,            //0-1           0               00: Input mode (reset state)
                                                        //                              01: Output mode, max speed 10 MHz.
                                                        //                              10: Output mode, max speed 2 MHz.
                                                        //                              11: Output mode, max speed 50 MHz.                                           
        CNF0                            , 2,            //2-3           1               In input mode:
                                                        //                                      00: Analog mode
                                                        //                                      01: Floating input (reset state)
                                                        //                                      10: Input with pull-up / pull-down
                                                        //                                      11: Reserved
                                                        //                              In output mode:
                                                        //                                      00: General purpose output push-pull
                                                        //                                      01: General purpose output Open-drain
                                                        //                                      10: Alternate function output Push-pull
                                                        //                                      11: Alternate function output Open-drain
      Mode_1                            , 2,            //
        CNF1                            , 2,            //
      Mode_2                            , 2,            //
        CNF2                            , 2,            //
      Mode_3                            , 2,            //
        CNF3                            , 2,            //
      Mode_4                            , 2,            //
        CNF4                            , 2,            //
      Mode_5                            , 2,            //
        CNF5                            , 2,            //
      Mode_6                            , 2,            //
        CNF6                            , 2,            //
      Mode_7                            , 2,            //
        CNF7                            , 2);           //
  BUNION(CRH, unsigned long,                            //
      Mode_8                            , 2,            //
        CNF8                            , 2,            //
      Mode_9                            , 2,            //
        CNF9                            , 2,            //
      Mode_10                           , 2,            //
        CNF10                           , 2,            //
      Mode_11                           , 2,            //
        CNF11                           , 2,            //
      Mode_12                           , 2,            //
        CNF12                           , 2,            //
      Mode_13                           , 2,            //
        CNF13                           , 2,            //
      Mode_14                           , 2,            //
        CNF14                           , 2,            //
      Mode_15                           , 2,            //
        CNF15                           , 2);           //
  BUNION(IDR, unsigned long,
    xBITS_B(c, 0, 15, 1),
    _reserve                              , 16);        //
  BUNION(ODR, unsigned long,
    xBITS_B(c, 0, 15, 1),
    _reserve                            , 16);          //
//  union{
//    unsigned long REG;
//    struct{
//      xBITS(unsigned long,c, 0, 15, 1);
//      unsigned long _reserved : 16;
//    }BITS;
//  }IDR;
  
//  union{
//    unsigned long REG;
//    struct{
//      xBITS(unsigned long, c, 0, 15, 1);
//      unsigned long _reserved : 16;
//    }BITS;    
//  }ODR; 
  
  union{
    unsigned long REG;
    struct{
      xBUNION(BSR, unsigned short, c, 0, 15, 1);                
      xBUNION(BR, unsigned short, c, 0, 15, 1);
    };
  }BSRR;
  
  BUNION(BRR, unsigned long,
    xBITS_B(c, 0, 15, 1),
    _reserve                                , 16);
  BUNION(LCKR, unsigned long,
    xBITS_B(c, 0, 15, 1),
    LCKK                                    , 1,
  _reserve                                , 15);
    
  
//  union{
//    unsigned long REG;
//    struct{
//      xBITS(unsigned long, c, 0, 15, 1);
//        unsigned long _reserved : 16;
//    }BITS;
//  }BRR;
  
//  union{
//    unsigned long REG;
//    struct{
//      xBITS(unsigned long, c, 0, 15, 1);
//      unsigned long LCKK : 1;
//      unsigned long _reserved : 15;
//    }BITS;  
//   }LCKR;  


}GPIO_TypeDef;
__root __no_init RCC_TypeDef RCC @ 0x40021000;
__root __no_init GPIO_TypeDef GPIOA @ 0x40010800;
__root __no_init GPIO_TypeDef GPIOB @ 0x40010c00;
__root __no_init GPIO_TypeDef GPIOC @ 0x40011000;
__root __no_init GPIO_TypeDef GPIOD @ 0x40011400;
__root __no_init GPIO_TypeDef GPIOE @ 0x40011800;

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