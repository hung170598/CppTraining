#include "MPU.h"


void MPU_ConfigRegion(int region_num, uint32_t base_addr, uint32_t size, 
    access_permission_t permission,bool executeNever, uint8_t tex, uint8_t cacheable, 
    uint8_t bufferable, uint8_t shareable)
{

    MPU->RNR &= ~(0xFF<<0);
    MPU->RNR = region_num;      /*write the required region number to this register 
                                before accessing the MPU_RBAR or MPU_RASR*/ 

    MPU->RBAR = base_addr & 0xFFFFFFE0;  // đảm bảo align 32-byte
    
    MPU->RASR &= ~(0x7 <<24);
    MPU->RASR |= (permission<<24); // write Access permission

    if(executeNever){
        MPU->RASR |= (1<<28);  // Instruction fetches disabled.
    }else{
        MPU->RASR &= ~(1<<28);  // Instruction fetches enable.
    }

    /* memory attribute*/
    MPU->RASR &= ~(0x7 <<19);
    MPU->RASR |= (tex <<19);
    MPU->RASR |= (shareable <<18);
    MPU->RASR |= (cacheable <<17);
    MPU->RASR |= (bufferable <<16);

    /*cofirm enable all Subregion*/
    MPU->RASR &= ~(0xFF <<8);
    
    int N= REGION_SIZE_LOG2(size);
    MPU->RASR |= ((N-1) << 1); // Size field

    MPU->RASR |= (1<<0); //  Region enable bit

}

void MPU_Enable(bool privileged_permission, bool EnaDuringSysExption)
{
    if(privileged_permission){
        MPU->CR |= (1<<2); //  Enable privileged software access to default memory map. 
    }else{
        MPU->CR &= ~(1<<2);
    }
    if(EnaDuringSysExption){
        MPU->CR |= (1<<1); //  Enables the operation of MPU during hard fault, NMI, and FAULTMASK handlers.
    }else{
        MPU->CR &= ~(1<<1);
    }
    SCB->SHCSR |= (1 << 16); // Enable MemManage fault
    MPU->CR |= (1<<0); // MPU enabled
}
void MPU_Disable(void)
{
    MPU->CR &= ~(1<<0); // MPU enabled
}

void MPU_EnableRegion(uint8_t region_num)
{
    MPU->RNR &= ~(0xFF<<0);
    MPU->RNR = region_num;      /*write the required region number to this register 
                                before accessing the MPU_RBAR or MPU_RASR*/ 
    MPU->RASR |= (1<<0); //  Region enable bit
}

void MPU_DisableRegion(uint8_t region_num)
{
    MPU->RNR &= ~(0xFF<<0);
    MPU->RNR = region_num;      /*write the required region number to this register 
                                before accessing the MPU_RBAR or MPU_RASR*/ 
    MPU->RASR &= ~(1<<0); //  Region enable bit
}