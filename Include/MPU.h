#ifndef MPU_H
#define MPU_H

#include "AddressMap.h"

#define REGION_SIZE_LOG2(size) (31 - __builtin_clz(size))

/* 
   Pri: Privileged permissions
   UnPri: Unprivileged permissions
   NA: No Access
*/
typedef enum 
{
    Pri_NA_UnPri_NA=0,
    Pri_RW_UnPri_NA=1,
    Pri_RW_UnPri_RO=2,
    Pri_RW_UnPri_RW=3,
    Pri_RO_UnPri_NA=5,
    Pri_RO_UnPri_RO=6,
}access_permission_t;

void MPU_Enable(bool privileged_permission, bool EnaDuringSysExption);
void MPU_Disable(void);
void MPU_ConfigRegion(int region_num, uint32_t base_addr, uint32_t size, 
    access_permission_t permission,bool executeNever, uint8_t tex, uint8_t cacheable, 
    uint8_t bufferable, uint8_t shareable);

void MPU_EnableRegion(uint8_t region_num);
void MPU_DisableRegion(uint8_t region_num);


#endif

