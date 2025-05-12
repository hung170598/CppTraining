#ifndef MPU_H
#define MPU_H

#include <stdint.h>

// Thanh ghi MPU với các offset và các giá trị reset
typedef struct {
    uint32_t MPU_TYPER;  // 0x00: Các thông tin về MPU
    uint32_t MPU_CR;     // 0x04: Điều khiển MPU
    uint32_t MPU_RNR;    // 0x08: Chỉ số vùng hiện tại
    uint32_t MPU_RBAR;   // 0x0C: Địa chỉ vùng bộ nhớ (Region Base Address)
    uint32_t MPU_RASR;   // 0x10: Cấu hình vùng bộ nhớ (Region Attribute and Size Register)
    uint32_t MPU_RBAR_A1; // 0x14: Địa chỉ vùng bộ nhớ A1
    uint32_t MPU_RASR_A1; // 0x18: Cấu hình vùng bộ nhớ A1
    uint32_t MPU_RBAR_A2; // 0x1C: Địa chỉ vùng bộ nhớ A2
    uint32_t MPU_RASR_A2; // 0x20: Cấu hình vùng bộ nhớ A2
    uint32_t MPU_RBAR_A3; // 0x24: Địa chỉ vùng bộ nhớ A3
    uint32_t MPU_RASR_A3; // 0x28: Cấu hình vùng bộ nhớ A3
} MPU_Type;

// Các bit của thanh ghi MPU_TYPER (0x00)
#define MPU_TYPER_I_REGION_SHIFT      16  // Vị trí số vùng bộ nhớ lệnh (IREGION) bắt đầu từ bit 16
#define MPU_TYPER_I_REGION_MASK       (0xFF << MPU_TYPER_I_REGION_SHIFT) // 8 bit cho IREGION (từ 16 đến 23)

#define MPU_TYPER_D_REGION_SHIFT      8   // Vị trí số vùng bộ nhớ dữ liệu (DREGION) bắt đầu từ bit 8
#define MPU_TYPER_D_REGION_MASK       (0xFF << MPU_TYPER_D_REGION_SHIFT) // 8 bit cho DREGION (từ 8 đến 15)

#define MPU_TYPER_SEPARATE_SHIFT      0   // Cờ tách biệt bộ nhớ lệnh và bộ nhớ dữ liệu (SEPARATE) ở bit 0
#define MPU_TYPER_SEPARATE_MASK       (1U << MPU_TYPER_SEPARATE_SHIFT)  // SEPARATE là 1 bit ở bit 0


// Các bit của thanh ghi MPU_CR (0x04)
#define MPU_CR_PRIVDEFEN_SHIFT        2   // Vị trí cho phép quyền mặc định
#define MPU_CR_PRIVDEFEN_MASK         (1U << MPU_CR_PRIVDEFEN_SHIFT)

#define MPU_CR_HFNMIENA_SHIFT         1   // Vị trí cho phép MPU trong NMI/HardFault
#define MPU_CR_HFNMIENA_MASK          (1U << MPU_CR_HFNMIENA_SHIFT)

#define MPU_CR_ENABLE_SHIFT           0   // Vị trí bật/tắt MPU
#define MPU_CR_ENABLE_MASK            (1U << MPU_CR_ENABLE_SHIFT)

// Các bit của thanh ghi MPU_RNR (0x08)
#define MPU_RNR_REGION_SHIFT          0   // Vị trí chỉ số vùng (Region Number)
#define MPU_RNR_REGION_MASK           (0xFF << MPU_RNR_REGION_SHIFT)

// Các bit của thanh ghi MPU_RBAR (0x0C)
#define MPU_RBAR_ADDR_SHIFT           5   // Vị trí địa chỉ vùng bộ nhớ
#define MPU_RBAR_ADDR_MASK            (0xFFFFFF << MPU_RBAR_ADDR_SHIFT)

#define MPU_RBAR_VALID_SHIFT          4   // Vị trí bit hợp lệ của vùng
#define MPU_RBAR_VALID_MASK           (1U << MPU_RBAR_VALID_SHIFT)

#define MPU_RBAR_REGION_SHIFT         0   // Vị trí chỉ số vùng (Region Number)
#define MPU_RBAR_REGION_MASK          (0xF << MPU_RBAR_REGION_SHIFT)

// Các bit của thanh ghi MPU_RASR (0x10)
#define MPU_RASR_XN_SHIFT             28  // Vị trí cho phép truy cập vùng không thực thi (XN)
#define MPU_RASR_XN_MASK              (1U << MPU_RASR_XN_SHIFT)

#define MPU_RASR_AP_SHIFT             24  // Vị trí quyền truy cập (Access Permission)
#define MPU_RASR_AP_MASK              (0x7 << MPU_RASR_AP_SHIFT)

#define MPU_RASR_TEX_SHIFT            19  // Vị trí thông tin về bộ nhớ (TEX)
#define MPU_RASR_TEX_MASK             (0x7 << MPU_RASR_TEX_SHIFT)

#define MPU_RASR_SRD_SHIFT            8   // Vị trí cho phép vùng cho các quyền truy cập (Subregion Disable)
#define MPU_RASR_SRD_MASK             (0xFF << MPU_RASR_SRD_SHIFT)

#define MPU_RASR_SIZE_SHIFT           1   // Vị trí kích thước vùng
#define MPU_RASR_SIZE_MASK            (0x1F << MPU_RASR_SIZE_SHIFT)

#define MPU_RASR_ENABLE_SHIFT         0   // Vị trí bật vùng (Region Enable)
#define MPU_RASR_ENABLE_MASK          (1U << MPU_RASR_ENABLE_SHIFT)

// Các bit thuộc tính bộ nhớ
#define MPU_RASR_S_SHIFT              18  // Vị trí thuộc tính Shareable
#define MPU_RASR_S_MASK               (1U << MPU_RASR_S_SHIFT) // 1: Shareable, 0: Non-shareable

#define MPU_RASR_C_SHIFT              17  // Vị trí thuộc tính Cacheable
#define MPU_RASR_C_MASK               (1U << MPU_RASR_C_SHIFT) // 1: Cacheable, 0: Non-cacheable

#define MPU_RASR_B_SHIFT              16  // Vị trí thuộc tính Bufferable
#define MPU_RASR_B_MASK               (1U << MPU_RASR_B_SHIFT) // 1: Bufferable, 0: Non-bufferable

#define MPU_BASE_ADDR      (0xE000ED90UL)
#define MPU                ((MPU_Type *)MPU_BASE_ADDR)

#endif // MPU_H
