/******************************************************************************************************************************
 * @file    mpu_type.h
 * @brief   Type MPU.
 * @details Khai báo các kiểu dữ liệu config 
 *          phù hợp cho quá trình cấu hình và sử dụng của người dùng.
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* =====================================================[ Guard Start ]===================================================*/
#ifndef __MPU_TYPE_H__
#define __MPU_TYPE_H__

/* ===========================================[ INCLUDE FILE ]===========================================*/
#include <stdint.h>              /**< Thư viện chứa các kiểu dữ liệu cơ bản. */

/* =========================================[ TYPE DEFINITIONS ]=========================================*/
/**
 * @struct  Memory_Type
 * @brief   Cấu trúc cấu hình Memory Type của region.
 * @details Cấu trúc này chứa các cấu hình về Memory Type, bao gồm TEX, Cacheable, Bufferable, Shareable.
 */
typedef struct{
    uint8_t TEX;
    uint8_t Cacheable;
    uint8_t Bufferable;
    uint8_t Shareable;
} Memory_Type;


/**
 * @enum  eRegion_Number
 * @brief  Enum chứa các số thứ tự region có thể lựa chọn.
 */
typedef enum{
    MPU_REGION_0 = 0,                   /**< Region 0 */
    MPU_REGION_1 = 1,                   /**< Region 1 */
    MPU_REGION_2 = 2,                   /**< Region 2 */
    MPU_REGION_3 = 3,                   /**< Region 3 */
    MPU_REGION_4 = 4,                   /**< Region 4 */
    MPU_REGION_5 = 5,                   /**< Region 5 */
    MPU_REGION_6 = 6,                   /**< Region 6 */
    MPU_REGION_7 = 7                    /**< Region 7 */
} eRegion_Number;

/**
 * @enum  eSize
 * @brief  Enum chứa các kích thước region có thể lựa chọn.
 */
typedef enum{
    MPU_SIZE_32B    = 4U,                /**< 32 bytes */
    MPU_SIZE_64B    = 5U,                /**< 64 bytes */
    MPU_SIZE_128B   = 6U,                /**< 128 bytes */
    MPU_SIZE_256B   = 7U,                /**< 256 bytes */
    MPU_SIZE_512B   = 8U,                /**< 512 bytes */
    MPU_SIZE_1KB    = 9U,                /**< 1KB */
    MPU_SIZE_2KB    = 10U,               /**< 2KB */
    MPU_SIZE_4KB    = 11U,               /**< 4KB */
    MPU_SIZE_8KB    = 12U,               /**< 8KB */
    MPU_SIZE_16KB   = 13U,               /**< 16KB */
    MPU_SIZE_32KB   = 14U,               /**< 32KB */
    MPU_SIZE_64KB   = 15U,               /**< 64KB */
    MPU_SIZE_128KB  = 16U,               /**< 128KB */
    MPU_SIZE_256KB  = 17U,               /**< 256KB */
    MPU_SIZE_512KB  = 18U,               /**< 512KB */
    MPU_SIZE_1MB    = 19U,               /**< 1MB */
    MPU_SIZE_2MB    = 20U,               /**< 2MB */
    MPU_SIZE_4MB    = 21U,               /**< 4MB */
    MPU_SIZE_8MB    = 22U,               /**< 8MB */
    MPU_SIZE_16MB   = 23U,               /**< 16MB */
    MPU_SIZE_32MB   = 24U,               /**< 32MB */
    MPU_SIZE_64MB   = 25U,               /**< 64MB */
    MPU_SIZE_128MB  = 26U,               /**< 128MB */
    MPU_SIZE_256MB  = 27U,               /**< 256MB */
    MPU_SIZE_512MB  = 28U,               /**< 512MB */
    MPU_SIZE_1GB    = 29U,               /**< 1GB */
    MPU_SIZE_2GB    = 30U,               /**< 2GB */
    MPU_SIZE_4GB    = 31U                /**< 4GB */
} eSize;

/**
 * @enum  eAccess_Permissions
 * @brief  Enum chứa các lựa chọn quyền truy cập của region cho privileged/unprivileged.
 */
typedef enum{
    MPU_NO_ACCESS           = 0U,           /**< Không có quyền truy cập */
    MPU_PRIVILEGED_RW       = 1U,           /**< Quyền truy cập đọc/ghi cho privileged */
    MPU_PRIVILEGED_RW_UNPRIVILEGED_RO = 2U, /**< Quyền truy cập đọc/ghi cho privileged và unprivileged (chỉ đọc) */
    MPU_FULL_ACCESS         = 3U,           /**< Quyền truy cập đọc/ghi cho privileged và unprivileged */
    MPU_PRIVILEGED_RO       = 5U,           /**< Quyền truy cập đọc cho privileged */
    MPU_READ_ONLY_ACCESS    = 6U            /**< Quyền truy cập đọc cho unprivileged và privileged */
} eAccess_Permissions;
    

/**
 * @enum  eInstruction_Access
 * @brief  Enum chứa các lựa chọn quyền truy cập lệnh của region.
 */
typedef enum{
    MPU_INSTRUCTION_ACCESS_ENABLE = 0U,    /**< Bật quyền truy cập lệnh */
    MPU_INSTRUCTION_ACCESS_DISABLE = 1U    /**< Tắt quyền truy cập lệnh */
} eInstruction_Access;

/**
 * @enum  eDisable_Subregion
 * @brief  Enum chứa các quyền lựa chọn tắt các subregion của region.
 */
typedef enum{
    MPU_NO_DISABLE_SUBREGION = 0U,        /**< Không tắt subregion */
    MPU_DISABLE_SUBREGION_0  = 1U,        /**< Tắt subregion 0 */
    MPU_DISABLE_SUBREGION_1  = 2U,        /**< Tắt subregion 1 */
    MPU_DISABLE_SUBREGION_2  = 4U,        /**< Tắt subregion 2 */
    MPU_DISABLE_SUBREGION_3  = 8U,        /**< Tắt subregion 3 */
    MPU_DISABLE_SUBREGION_4  = 16U,       /**< Tắt subregion 4 */
    MPU_DISABLE_SUBREGION_5  = 32U,       /**< Tắt subregion 5 */
    MPU_DISABLE_SUBREGION_6  = 64U,       /**< Tắt subregion 6 */
    MPU_DISABLE_SUBREGION_7  = 128U       /**< Tắt subregion 7 */
} eDisable_Subregion;

/**
 * @enum  eEnable_Region
 * @brief  Enum chứa các quyền bật/ tắt region.
 */
typedef enum{
    MPU_DISABLE_REGION  = 0U,                   /**< Tắt region */
    MPU_ENABLE_REGION   = 1U                    /**< Bật region */
} eEnable_Region;


/**
 * @enum  eEnable_Background_Region
 * @brief  Enum chứa các quyền lựa chọn sử dụng background region.
 */
typedef enum{
    MPU_DISABLE_BACKGROUND_REGION   = 0U,        /**< Tắt chế độ background region */
    MPU_ENABLE_BACKGROUND_REGION    = 1U         /**< Bật chế độ background region */
} eEnable_Background_Region;

/**
 * @enum  eEnable_In_Exception
 * @brief  Enum chứa các quyền lựa chọn truy cập khi đang xảy ra exception hay không.
 */
typedef enum{
    MPU_DISABLE_IN_EXCEPTION    = 0U,            /**< Tắt chế độ in exception */
    MPU_ENABLE_IN_EXCEPTION     = 1U             /**< Bật chế độ in exception */
} eEnable_In_Exception;

/**
 * @enum  eEnable_In_Memfault
 * @brief  Enum chứa các lựa chọn xử lý lỗi MPU ở Memfault hay không.
 */
typedef enum{
    MPU_DISABLE_IN_MEMFAULT = 0U,                /**< Tắt chế độ dùng memfault */
    MPU_ENABLE_IN_MEMFAULT  = 1U                 /**< Bật chế độ dùng memfault */
} eEnable_In_Memfault;

/* =======================================[ EXTERNAL VARIABLES ]==========================================*/
extern Memory_Type FLASH_mem;                    /**< Memory Type của vùng nhớ FLASH */
extern Memory_Type SRAM_Intenal_mem;             /**< Memory Type của vùng nhớ SRAM Internal */
extern Memory_Type SRAM_External_mem;            /**< Memory Type của vùng nhớ SRAM External */
extern Memory_Type PERIPH_mem;                   /**< Memory Type của vùng nhớ Peripheral */

/* =====================================[ FUNCTION INPLEMENTATION ]=======================================*/
/* Function implementation for MPU type */

#endif /* __MPU_TYPE_H__ */
/* ===================================================[ Guard End ]===================================================*/

