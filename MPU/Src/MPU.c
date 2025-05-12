#include "MPU.h"  // Include file header định nghĩa các thanh ghi và macro của MPU

// Hàm bật MPU
void MPU_Enable(uint8_t enablePrivDef, uint8_t enableHFNMI)
{
    uint32_t value = 0;  // Biến tạm để lưu giá trị cấu hình

    if (enablePrivDef) {  // Nếu bật default memory map (cho privilege access)
        value |= MPU_CR_PRIVDEFEN_MASK;  // Set bit PRIVDEFEN
    }

    if (enableHFNMI) {  // Nếu bật cho phép MPU hoạt động trong HardFault/NMI
        value |= MPU_CR_HFNMIENA_MASK;  // Set bit HFNMIENA
    }

    value |= MPU_CR_ENABLE_MASK;  // Bật MPU (set bit ENABLE)

    MPU->MPU_CR = value;  // Ghi giá trị vào thanh ghi Control Register (MPU_CR)
}

// Hàm tắt MPU
void MPU_Disable(void)
{
    MPU->MPU_CR &= ~MPU_CR_ENABLE_MASK;  // Clear bit ENABLE → tắt MPU
}

// Hàm chọn region (vùng bộ nhớ) cần cấu hình
void MPU_SelectRegion(uint8_t region)
{
    MPU->MPU_RNR = (region & 0xFF);  // Ghi số vùng (0-7) vào Region Number Register
}

// Hàm thiết lập địa chỉ base cho region
void MPU_SetRegionBaseAddress(uint32_t address, uint8_t region, uint8_t valid)
{
    uint32_t value = (address & MPU_RBAR_ADDR_MASK);  // Lấy địa chỉ, mask theo chuẩn RBAR

    if (valid) {  // Nếu địa chỉ hợp lệ (có chọn region)
        value |= MPU_RBAR_VALID_MASK;  // Set bit VALID
        value |= (region & 0xF);  // Ghi số region (4 bit)
    }

    MPU->MPU_RBAR = value;  // Ghi vào Region Base Address Register
}

// Hàm thiết lập thuộc tính cho region
void MPU_SetRegionAttributes(uint8_t xn, uint8_t ap, uint8_t tex, uint8_t s, uint8_t c, uint8_t b,
                              uint8_t srd, uint8_t size, uint8_t enable)
{
    uint32_t rasr = 0;  // Biến lưu giá trị cấu hình RASR

    rasr |= ((xn & 0x1) << MPU_RASR_XN_SHIFT);  // Set bit XN (Execute Never)
    rasr |= ((ap & 0x7) << MPU_RASR_AP_SHIFT);  // Set Access Permission (AP)
    rasr |= ((tex & 0x7) << MPU_RASR_TEX_SHIFT);  // Set TEX (type extension)
    rasr |= ((s & 0x1) << MPU_RASR_S_SHIFT);  // Set S (shareable)
    rasr |= ((c & 0x1) << MPU_RASR_C_SHIFT);  // Set C (cacheable)
    rasr |= ((b & 0x1) << MPU_RASR_B_SHIFT);  // Set B (bufferable)
    rasr |= ((srd & 0xFF) << MPU_RASR_SRD_SHIFT);  // Set SRD (Subregion Disable)
    rasr |= ((size & 0x1F) << MPU_RASR_SIZE_SHIFT);  // Set SIZE (log2(region size) -1)
    rasr |= ((enable & 0x1) << MPU_RASR_ENABLE_SHIFT);  // Bật/tắt region

    MPU->MPU_RASR = rasr;  // Ghi vào Region Attribute and Size Register
}

// Hàm lấy số lượng data region hỗ trợ
uint8_t MPU_GetDataRegionCount(void)
{
    return (uint8_t)((MPU->MPU_TYPER & MPU_TYPER_D_REGION_MASK) >> MPU_TYPER_D_REGION_SHIFT);  // Mask và dịch bit
}

// Hàm lấy số lượng instruction region hỗ trợ
uint8_t MPU_GetInstructionRegionCount(void)
{
    return (uint8_t)((MPU->MPU_TYPER & MPU_TYPER_I_REGION_MASK) >> MPU_TYPER_I_REGION_SHIFT);  // Mask và dịch bit
}

// Hàm kiểm tra xem MPU có tách biệt instruction/data không
uint8_t MPU_IsSeparateEnabled(void)
{
    return (uint8_t)((MPU->MPU_TYPER & MPU_TYPER_SEPARATE_MASK) >> MPU_TYPER_SEPARATE_SHIFT);  // Mask và dịch bit
}
