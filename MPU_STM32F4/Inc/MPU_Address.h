/*
 * MPU_Address.h
 *
 *  Created on: May 9, 2025
 *      Author: tuan.nguyenhuu1
 */

#ifndef MPU_ADDRESS_H_
#define MPU_ADDRESS_H_

/*******************************************************************************
 **************************** Includes
 ******************************************************************************/
#include "BasicTypes.h"

/*******************************************************************************
 **************************** Defines
 ******************************************************************************/
#define MPU_A_COUNT				(3u)

/*******************************************************************************
 ******************** Typedef structs & enums
 ******************************************************************************/
typedef struct
{
	_I  uint32_t TYPE;
	_IO	uint32_t CTRL;
	_IO uint32_t RNR;
	_IO uint32_t RBAR;
	_IO uint32_t RASR;
	struct
	{
		_IO uint32_t RBAR;
		_IO uint32_t RASR;
	}A[MPU_A_COUNT];
}MPU_Type;

//*MPU_MemMapPtr
#define MPU_INSTANCE_COUNT			(1u)

#define MPU_BASE			(0xE000ED90u)

#define MPU					((MPU_Type*)MPU_BASE)

#define MPU_BASE_ADDRS		{MPU_BASE}

#define MPU_BASE_PTRS		{MPU}

#endif /* MPU_ADDRESS_H_ */
/*******************************************************************************
 ***************************** EOF
 ******************************************************************************/
