
#include "myRCC.h"
#include "systick.h"
#include "NVIC.h"
#include "MPU.h"

#define Test_Add    0x08010000


int main(void)
{
    MPU_ConfigRegion(0,0x08010000,1024,Pri_NA_UnPri_NA,true,0b000,1,0,1);
    MPU_Enable(true, true);
    uint32_t *p = ((uint32_t*)0x08010000);
    *p =10;
}

void MemManage_Handler(void)    
{
    while(1);
}