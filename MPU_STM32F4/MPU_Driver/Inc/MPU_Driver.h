#ifndef MPU_DRIVER_H_
#define MPU_DRIVER_H_

/*******************************************************************************
 ********************* Includes
 ******************************************************************************/
#include "MPU_Address.h"
#include "SCB_Address.h"
#include "Interrupt.h"


/*******************************************************************************
 ********************* Defines
 ******************************************************************************/
#define __DSB() __asm volatile ("dsb 0xF" ::: "memory")
#define __ISB() __asm volatile ("isb 0xF" ::: "memory")

/* Macro config MPU */
#define MPU_ENABLE_DEFAULT_MEM		(1u)
#define	MPU_DISABLE_DEFAULT_MEM		(0u)

#define MPU_ENABLE_IN_EXCEPTION		(1u)
#define MPU_DISABLE_IN_EXCEPTION	(0u)

/* Memory Types*/
#define MPU_MEM_STRONG_ORDER		(0x00)
#define MPU_MEM_NORMAL_CACHEABLE	(0x01)
#define MPU_MEM_NORMAL_NONCACHE		(0x02)

/* Access Rights */
#define MPU_ACCESS_NO_ACCESS		(0x00)
#define MPU_ACCESS_FULL				(0x03)
#define MPU_ACCESS_READ_ONLY		(0x05)

/* Fault Status (MMFSR bits) */
#define MPU_FAULT_IACCVIOL			(1 << 0) //Instruction Access Violation
#define MPU_FAULT_DACCVIOL			(1 << 1) //Data Access Violation
#define MPU_FAULT_MUNSTKERR			(1 << 3) //Unstacking Error
#define MPU_FAULT_MSTKERR			(1 << 4) //Stacking Error
#define MPU_FAULT_MLSPERR			(1 << 5) //Lazy State Preservation Error
#define MPU_FAULT_MMARVALID			(1 << 7) // MMFAR Valid

/* MPU_RASR Position */
#define MPU_RASR_SIZE_Pos			(1u)
#define MPU_RASR_AP_Pos				(24u)
#define MPU_RASR_TEX_Pos			(19u)

/* MPU_RASR bit mask*/
#define MPU_RASR_C_Msk				(1 << 16u)
#define MPU_RASR_ENABLE_Msk			(1 << 0u)

/* MPU_CTRL bit mask */
#define MPU_CTRL_PRIVDEFENA_Msk		(1 << 2)
#define MPU_CTRL_HFNMIENA_Msk		(1 << 1)
#define MPU_CTRL_ENABLE_Msk			(1 << 0)

/* SCB_SHCSR bit mask */
#define SCB_SHCSR_MEMFAULTENA_Msk   (1 << 16)
#define SCB_SHCSR_BUSFAULTENA_Msk   (1 << 17)
#define SCB_SHCSR_USGFAULTENA_Msk   (1 << 18)

/*******************************************************************************
 *************** Typedef structs & enums
 ******************************************************************************/
/* Config MPU Region */
typedef struct
{
	uint8_t RegionNumber;
	uint32_t StartAddress;
	uint8_t Size;
	uint8_t MemoryType;
	uint8_t AccessRight;
	uint8_t Enable;
} MPU_RegionConfig_t;

/* Config MPU */
typedef struct
{
	uint8_t EnableDefaultMem;
	uint8_t EnableInException;
	uint8_t EnableMemManage;
	MPU_RegionConfig_t* Regions;
	uint8_t RegionCount;
} MPU_Config_t;


/*******************************************************************************
 *********************** APIs MPU DRIVER
 ******************************************************************************/
/**
 * @brief   Initialize and configure the Memory Protection Unit (MPU).
 *
 * This function disables the MPU, sets up the specified memory regions,
 * and then re-enables the MPU with control options. If enabled, it also
 * activates the MemManage exception handler to catch memory access violations.
 *
 * @param   config  Pointer to an MPU_Config_t structure containing region
 *                  definitions and control settings.
 *
 * @note
 *  - MPU must be disabled before configuring regions.
 *  - __DSB() and __ISB() are used to ensure memory and instruction synchronization.
 *  - If MemManage exception is enabled, SCB->SHCSR will be updated accordingly.
 */

void MPU_Init(MPU_Config_t* config);


/**
 * @brief   De-initialize the MPU and clear all configured regions.
 *
 * This function disables the MPU and resets all 8 configurable regions
 * by clearing their base address and attribute registers. It also ensures
 * memory and instruction synchronization after the operation.
 *
 * @param   None
 *
 * @note
 *  - After this call, all MPU protection is removed.
 *  - __DSB() and __ISB() are used to ensure safe and synchronized deactivation.
 */
void MPU_DeInit(void);


/**
 * @brief   Configure a single MPU region.
 *
 * This function sets the region number, base address, size, access permissions,
 * memory type, and enable/disable flag for a single MPU region.
 *
 * @param   region  Pointer to an MPU_RegionConfig_t structure containing the
 *                  configuration for the specified region.
 *
 * @note
 *  - This function does not modify MPU global control (MPU->CTRL).
 *  - __DSB() and __ISB() are used to ensure immediate effect of the configuration.
 */
void MPU_SetRegionConfig(MPU_RegionConfig_t* region);


/**
 * @brief   Retrieve details about a memory management fault.
 *
 * This function reads the faulting address and fault status code when a
 * MemManage fault occurs. It is typically called from within the
 * MemManage_Handler to diagnose the cause of the memory violation.
 *
 * @param[out] faultAddr     Pointer to a variable that will hold the faulting address.
 * @param[out] faultStatus   Pointer to a variable that will hold the MemManage fault status bits.
 *
 * @note
 *  - MMFAR (MemManage Fault Address Register) contains the address that caused the fault.
 *  - The lowest 8 bits of CFSR (Configurable Fault Status Register) correspond to MMFSR.
 */
void MPU_GetErrorDetails(uint32_t* faultAddr, uint8_t* faultStatus);

#endif /* MPU_DRIVER_H_ */
/*******************************************************************************
 *********************** EOF
 ******************************************************************************/
