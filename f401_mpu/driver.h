#ifndef MPU_DRIVER_H
#define MPU_DRIVER_H

#include "stm32f4xx.h"

#define MPU_ENABLE_DEFAULT_MEM 1
#define MPU_DISABLE_DEFAULT_MEM 0
#define MPU_ENABLE_IN_EXCEPTION 1
#define MPU_DISABLE_IN_EXCEPTION 0

//memory type
#define MPU_MEM_STRONG_ORDER 0x00
#define MPU_MEM_NORMAL_CACHEABLE 0x01
#define MPU_MEM_NORMAL_NONCACHE 0x02

//quyen truy cap
#define MPU_ACCESS_NO_ACCESS 0x00
#define MPU_ACCESS_FULL 0x03
#define MPU_ACCESS_READ_ONLY 0x05

//cau truc du lieu cho 1 region
typedef struct {
	uint8_t RegionNum;
	uint32_t BaseAddr;
	uint8_t Size;
	uint8_t MemType;
	uint8_t AccessRights;
	uint8_t Enable;
} MPU_RegionConfig_t;

//cau truc du lieu tong quat de khoi tao MPU
typedef struct {
	uint8_t EnableDefaultMem;
	uint8_t EnableInException;
	uint8_t EnableMemManage;
	MPU_RegionConfig_t* Regions;
	uint8_t RegionCount;
} MPU_Config_t;

void MPU_Init(MPU_Config_t* config);
void MPU_DeInit(void);
void MPU_SetRegionConfig(MPU_RegionConfig_t* region);
void MPU_GetErrorDetails(uint32_t* faultAddr, uint8_t* faultStatus);

#endif /*MPU_DRIVER_H */