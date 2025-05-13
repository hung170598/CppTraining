#include "driver.h"

void MemManage_Handler(void) {
    uint32_t faultAddr;
    uint8_t faultStatus;
    MPU_GetErrorDetails(&faultAddr, &faultStatus);
    while (1);
}

int main(void) {
    //config 2 region
    MPU_RegionConfig_t regions[] = {
        {0, 0x00000000, 31, MPU_MEM_STRONG_ORDER, MPU_ACCESS_FULL, 1},      // Region 0: Background
        {1, 0x40000000, 9, MPU_MEM_NORMAL_NONCACHE, MPU_ACCESS_READ_ONLY, 1} // Region 1: Test
    };
    MPU_Config_t mpuConfig = {
        MPU_ENABLE_DEFAULT_MEM, 
				MPU_ENABLE_IN_EXCEPTION, 
				1, 
				regions, 
				2
    };

    MPU_Init(&mpuConfig);

		//ghi vao region 1
    volatile uint32_t* test_addr = (uint32_t*)0x40000000;
    *test_addr = 0xDEADBEEF; //MemFault
		
		
		MPU_RegionConfig_t newRegion = {
			1,
			0x40000000,
			9,
			MPU_MEM_NORMAL_NONCACHE,
			MPU_ACCESS_FULL,
			1
		};
		
		MPU_SetRegionConfig(&newRegion);
		*test_addr = 0x12345678;

    while (1);
}