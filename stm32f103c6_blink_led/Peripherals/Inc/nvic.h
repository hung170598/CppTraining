#ifndef __NVIC_H
#define __NVIC_H

#include "main.h"

#define _IP_IDX(IRQn)           (((uint32_t)(int32_t) IRQn) >> 2UL) /* tìm thanh ghi priority tương ứng với irqn (irqn / 4) */
#define _BIT_SHIFT(IRQn)        ((((uint32_t)(int32_t) IRQn) & 3UL) * 8UL) /* tìm số bit dịch phải của irqn (irqn % 4) */
//#define _SHP_IDX(IRQn)          ( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >>    2UL) ) 
#define _SHP_IDX(IRQn) (                                     \
    ((IRQn) == -12 || (IRQn) == -11 || (IRQn) == -10) ? 0 :          /* Memory management, Bus fault, Usage fault -> SHPR1 */ \
    ((IRQn) == -5 || (IRQn) == -4) ? 1 :                             /* SVCall, DebugMonitor -> SHPR2 */ \
    ((IRQn) == -2 || (IRQn) == -1) ? 2 : 0                           /* PendSV, SysTick -> SHPR3 */ \
)


static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
    if((int32_t)IRQn > 0)
    {
        /* tìm thanh ghi ISER tương ứng với IRQn (IRQn/32) */
        /* tìm số bit cần dịch phải tương ứng với IRQn (IRQn%32) */
        NVIC->ISER[(uint32_t)IRQn >> 5UL] = (1UL << (uint32_t)((uint32_t)IRQn & 0x1FUL));
    }
}

static inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
    if((int32_t)IRQn > 0)
    {
        NVIC->ICER[(uint32_t)IRQn >> 5UL] = (1UL << (uint32_t)((uint32_t)IRQn & 0x1FUL));
        
        // Data Synchronization Barrier - đảm bảo lệnh ghi hoàn tất
        __asm volatile ("dsb 0xF" : : : "memory");
            
        // Instruction Synchronization Barrier - làm sạch pipeline
        __asm volatile ("isb 0xF" : : : "memory");
    }
}

static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
    if((int32_t)IRQn > 0)
    {
        NVIC->IPR[_IP_IDX(IRQn)] = ((uint32_t)NVIC->IPR[_IP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
        ((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)(0xFFUL)) << (_BIT_SHIFT(IRQn));
    }
    else
    {
        SCB->SHPR[_SHP_IDX(IRQn)] = ((uint32_t)SCB->SHPR[_SHP_IDX(IRQn)] & ~(0xFFUL << _BIT_SHIFT(IRQn))) |
        ((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)(0xFFUL)) << (_BIT_SHIFT(IRQn));
    }

}

static inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{
    if ((int32_t)(IRQn) >= 0)
    {
        return((uint32_t)(((NVIC->IPR[ _IP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
    }
    else
    {
        return((uint32_t)(((SCB->SHPR[_SHP_IDX(IRQn)] >> _BIT_SHIFT(IRQn) ) & (uint32_t)0xFFUL) >> (8U - __NVIC_PRIO_BITS)));
    }
}

static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
    if((int32_t)IRQn > 0)
    {
        NVIC->ISPR[(uint32_t)IRQn >> 5UL] = (1UL << (uint32_t)((uint32_t)IRQn & 0x1FUL));
    }
}

static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
    if((int32_t)IRQn > 0)
    {
        NVIC->ICPR[(uint32_t)IRQn >> 5UL] = (1UL << (uint32_t)((uint32_t)IRQn & 0x1FUL));
    }
}

#endif
