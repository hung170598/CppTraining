/*******************************************************************************
 **************** Includes
 ******************************************************************************/
#include "MPU_Driver.h"


/*******************************************************************************
 ************************* Codes
 ******************************************************************************/

/* Initialize and configure the Memory Protection Unit (MPU) */
void MPU_Init(MPU_Config_t* config)
{
	//Disable MPU
	MPU->CTRL &= ~ MPU_CTRL_ENABLE_Msk;
	//Config Region
	for(uint8_t i = 0; i < config->RegionCount; i ++)
	{
		MPU_RegionConfig_t* region = &config->Regions[i];
		MPU->RNR = region->RegionNumber;
		MPU->RBAR = region->StartAddress;
		MPU->RASR = (region->Size << MPU_RASR_SIZE_Pos) |
					(region->AccessRight << MPU_RASR_AP_Pos) |
					(region->MemoryType == MPU_MEM_STRONG_ORDER ? (0x2 << MPU_RASR_TEX_Pos) :
					region->MemoryType == MPU_MEM_NORMAL_CACHEABLE ? (0x1 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk :
					 (0x1 << MPU_RASR_TEX_Pos)) |
					(region->Enable ? MPU_RASR_ENABLE_Msk : 0);
	}
	uint32_t ctrl = 0;
	if(config->EnableDefaultMem) ctrl |= MPU_CTRL_PRIVDEFENA_Msk;
	if(config->EnableInException) ctrl |= MPU_CTRL_HFNMIENA_Msk;

	ctrl |= MPU_CTRL_ENABLE_Msk;
	MPU->CTRL = ctrl;

	//Kich hoat MemManage Handler neu can
	if(config->EnableMemManage)
	{
		//Kich hoat MemManage Handler
		SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
		//Enable Interrupt ccho MemManage
		NVIC_EnableIRQ(MemoryManagement_IRQn);
	}

	//Dong bo hoa
	__DSB();
	__ISB();

}

/* De-initialize the MPU and clear all configured regions */
void MPU_DeInit(void) {
	MPU->CTRL = 0; //Disable MPU và reset all
	for(uint8_t i = 0; i < 8; i++)
	{
		MPU->RNR = i;
		MPU->RBAR = 0;
		MPU->RASR = 0;
	}
	//Dong bo hoa
	__DSB();
	__ISB();
}


/* Configure a single MPU region. */
void MPU_SetRegionConfig(MPU_RegionConfig_t* region)
{
	MPU->RNR = region->RegionNumber;
	MPU->RBAR = region->StartAddress;
	MPU->RASR = (region->Size << MPU_RASR_SIZE_Pos) |
			(region->AccessRight << MPU_RASR_AP_Pos) |
			(region->MemoryType == MPU_MEM_STRONG_ORDER ? (0x2 << MPU_RASR_TEX_Pos) :
			region->MemoryType == MPU_MEM_NORMAL_CACHEABLE ? (0x1 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk :
			(0x1 << MPU_RASR_TEX_Pos)) |
			(region->Enable ? MPU_RASR_ENABLE_Msk : 0);
	//Dong bo hoa
	__DSB();
	__ISB();
}


/* Retrieve details about a memory management fault. */
void MPU_GetErrorDetails(uint32_t* faultAddr, uint8_t* faultStatus)
{
	*faultAddr = SCB->MMFAR;	//Dia chi gay loi
	*faultStatus = SCB->CFSR & 0xFF;	//Trang thai loi (MMFSR)
}
/*******************************************************************************
 **************************** EOF
 ******************************************************************************/
