/*
 * SCB_Address.h
 *
 *  Created on: May 9, 2025
 *      Author: tuan.nguyenhuu1
 */

#ifndef SCB_ADDRESS_H_
#define SCB_ADDRESS_H_

/*******************************************************************************
 **************************** Includes
 ******************************************************************************/
#include "BasicTypes.h"  // chứa định nghĩa _I, _IO, _O


/*******************************************************************************
 ***************************** Defines
 ******************************************************************************/
#define SCB_A_COUNT        	  (1u)
#define SCB_INSTANCE_COUNT    (1u)
#define SCB_BASE              (0xE000ED00u)

#define SCB                   ((SCB_Type *)SCB_BASE)
#define SCB_BASE_ADDRS        {SCB_BASE}
#define SCB_BASE_PTRS         {SCB}


/*******************************************************************************
 ********************* Typedef structs & enums
 ******************************************************************************/

/* SCB Register Map - System Control Block */
typedef struct
{
    _IO uint32_t CPUID;     // 0xE000ED00 - CPU ID Base Register
    _IO uint32_t ICSR;      // 0xE000ED04 - Interrupt Control and State Register
    _IO uint32_t VTOR;      // 0xE000ED08 - Vector Table Offset Register
    _IO uint32_t AIRCR;     // 0xE000ED0C - Application Interrupt and Reset Control Register
    _IO uint32_t SCR;       // 0xE000ED10 - System Control Register
    _IO uint32_t CCR;       // 0xE000ED14 - Configuration and Control Register
    _IO uint8_t  SHPR1[4];  // 0xE000ED18 - System Handler Priority Register 1 (MSP faults)
    _IO uint8_t  SHPR2[4];  // 0xE000ED1C - System Handler Priority Register 2 (SVCall)
    _IO uint8_t  SHPR3[4];  // 0xE000ED20 - System Handler Priority Register 3 (PendSV, SysTick)
    _IO uint32_t SHCSR;     // 0xE000ED24 - System Handler Control and State Register
    _IO uint32_t CFSR;      // 0xE000ED28 - Configurable Fault Status Register
    _IO uint32_t HFSR;      // 0xE000ED2C - HardFault Status Register
    _IO uint32_t DFSR;      // 0xE000ED30 - Debug Fault Status Register
    _IO uint32_t MMFAR;     // 0xE000ED34 - MemManage Fault Address Register
    _IO uint32_t BFAR;      // 0xE000ED38 - BusFault Address Register
    _IO uint32_t AFSR;      // 0xE000ED3C - Auxiliary Fault Status Register
} SCB_Type;

#endif /* SCB_ADDRESS_H_ */

/*******************************************************************************
 ********************************** EOF
 ******************************************************************************/
