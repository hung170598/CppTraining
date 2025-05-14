/******************************************************************************************************************************
 * @file    mpu_config.c
 * @brief   Cấu hình MPU.
 * @details Người dùng cấu hình các region, 
 *          các chức năng của MPU cần sử dụng tại MPU_Region_Config và MPU_Config.
 * @version 1.0
 * @date    2025-05-10
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===========================================[ INCLUDE FILE ]===========================================*/
#include "mpu_config.h"          /**< Thư viện chứa các kiểu dữ liệu config. */

/* ========================================[ MACRO DEFINITIONS ]==========================================*/
#define MPU_REGION_NUMBER (sizeof(MPU_Region_Config) / sizeof(MPU_Region_Config[0]))


/* ========================================[ STATIC VARIABLES ]===========================================*/
/**
  * @brief   Thêm các cấu hình region trong MPU.
  * @details Thêm các cấu hình region trong MPU theo các cấu trúc enum trong mpu_type.h.
  * @note    Cấu hình region, base address, size, access permissions, 
  *          memory type, instruction access, disable subregion, enable region.
  */
static MPU_Region_Config_t MPU_Region_Config[]={
    {   
        .region_Number          = MPU_REGION_0,                   /**< Số thứ tự region */   
        .base_Address           = 0x40000000,                     /**< Địa chỉ bắt đầu của region */
        .size                   = MPU_SIZE_1KB,                   /**< Kích thước region */
        .access_Permissions     = MPU_READ_ONLY_ACCESS,           /**< Quyền truy cập của privileged/unprivileged */
        .memory_Type            = &PERIPH_mem,                    /**< Loại vùng nhớ cấu hình */
        .instruction_Access     = MPU_INSTRUCTION_ACCESS_ENABLE,  /**< Quyền truy cập lệnh */
        .disable_Subregion      = MPU_NO_DISABLE_SUBREGION,       /**< Tắt subregion */
        .enable                 = MPU_ENABLE_REGION,              /**< Bật/tắt region */
    },
    /* ... */
};

/* ==================================[ EXTERNAL VARIABLES DEPLOYMENT ]=====================================*/
/**
  * @brief   Cấu hình MPU.
  * @details Cấu hình MPU theo các cấu trúc enum trong mpu_type.h.
  * @note    Cấu hình background region, in exception, in memfault, 
  *          region config được lấy từ tất cả các region được chọn cofig bên trên, 
  *          number of regions là số lượng region tự động tính.
  */
MPU_Config_t MPU_Config = {
    .enable_Background_Region   = MPU_ENABLE_BACKGROUND_REGION,   /**< Bật/tắt chế độ background region */
    .enable_In_Exception        = MPU_DISABLE_IN_EXCEPTION,       /**< Cho phép MPU hoạt động trong exception */
    .enable_In_MemFault         = MPU_ENABLE_IN_MEMFAULT,         /**< Sử dụng MemFault để xử lý lỗi thay cho HardFault */
    .Region_Config              = MPU_Region_Config,              /**< Mảng các region đã cấu hình */
    .number_Of_Regions          = MPU_REGION_NUMBER               /**< Số lượng region đã cấu hình */
};

/* =====================================[ FUNCTION DEPLOYMENT ]===========================================*/
/* Function deployment for MPU config */


