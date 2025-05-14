/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Interrupt.h"

/**
 * @brief Enables the interrupt specified by the IRQ number.
 */
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	/* Determine which ISER IRQn is at regIndex */
	uint32_t regIndex = (uint32_t)IRQn / 32;

	/* Determine which bit it is in */
	uint32_t bitPos = (uint32_t)IRQn % 32;

	/* Write 1 to the corresponding bit in the NVIC_ISERx register */
	NVIC->ISER[regIndex] |= (1UL << bitPos);
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
