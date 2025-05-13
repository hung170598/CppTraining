#include "driver.h"

void MPU_Init(MPU_Config_t* config) {

    MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;

    // ham cau hinh cac region
    for (uint8_t i = 0; i < config->RegionCount; i++) {
        MPU_RegionConfig_t* region = &config->Regions[i];
        MPU->RNR  = region->RegionNum;
        MPU->RBAR = region->BaseAddr;
        MPU->RASR = (region->Size << MPU_RASR_SIZE_Pos) |
                    (region->AccessRights << MPU_RASR_AP_Pos) |
                    (region->MemType == MPU_MEM_STRONG_ORDER ? (0x2 << MPU_RASR_TEX_Pos) :
                     region->MemType == MPU_MEM_NORMAL_CACHEABLE ? (0x1 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk :
                     (0x1 << MPU_RASR_TEX_Pos)) |
                    (region->Enable ? MPU_RASR_ENABLE_Msk : 0);
    }

    // ham cau hinh mpu ctrl
    uint32_t ctrl = 0;
    if (config->EnableDefaultMem) ctrl |= MPU_CTRL_PRIVDEFENA_Msk;
    if (config->EnableInException) ctrl |= MPU_CTRL_HFNMIENA_Msk;
    ctrl |= MPU_CTRL_ENABLE_Msk;
    MPU->CTRL = ctrl;

    // kich hoat memManage handler
    if (config->EnableMemManage) {
	SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
        NVIC_EnableIRQ(MemoryManagement_IRQn);
    }

    // sync 
    __DSB();
    __ISB();
}

void MPU_DeInit(void) {
    MPU->CTRL = 0; 
    for (uint8_t i = 0; i < 8; i++) {
        MPU->RNR = i;
        MPU->RBAR = 0;
        MPU->RASR = 0;
    }
    __DSB();
    __ISB();
}

void MPU_SetRegionConfig(MPU_RegionConfig_t* region)
	{
    MPU->RNR  = region->RegionNum;
    MPU->RBAR = region->BaseAddr;
    MPU->RASR = (region->Size << MPU_RASR_SIZE_Pos) |
                (region->AccessRights << MPU_RASR_AP_Pos) |
                (region->MemType == MPU_MEM_STRONG_ORDER ? (0x2 << MPU_RASR_TEX_Pos) :
                 region->MemType == MPU_MEM_NORMAL_CACHEABLE ? (0x1 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk :
                 (0x1 << MPU_RASR_TEX_Pos)) |
                (region->Enable ? MPU_RASR_ENABLE_Msk : 0);
    __DSB();
    __ISB();
}

void MPU_GetErrorDetails(uint32_t* faultAddr, uint8_t* faultStatus) {
    *faultAddr = SCB->MMFAR;   // addr gay loi
    *faultStatus = SCB->CFSR & 0xFF; // trang thai loi
}
