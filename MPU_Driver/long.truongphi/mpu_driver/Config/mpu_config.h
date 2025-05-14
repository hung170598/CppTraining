/******************************************************************************************************************************
 * @file    mpu_config.h
 * @brief   Cấu hình MPU.
 * @details Khung cấu hình các region và các chức năng của MPU.
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===================================================[ Guard Start ]===================================================*/
#ifndef __MPU_CONFIG_H__
#define __MPU_CONFIG_H__

/* ============================================[ INCLUDE FILE ]=============================================*/
#include "mpu_type.h"               /**< Thư viện chứa các kiểu dữ liệu config. */

/* ==========================================[ MACRO DEFINITIONS ]==========================================*/
/* Macro definitions for MPU config */


/* ===========================================[ TYPE DEFINITIONS ]==========================================*/
/**
 * @struct  MPU region config
 * @brief   Cấu trúc cấu hình MPU region.
 * @details Cấu trúc này chứa các cấu hình về region, bao gồm số lượng region,
 *           địa chỉ bắt đầu, kích thước, quyền truy cập, loại vùng nhớ, 
 *           quyền truy cập lệnh và subregion.
 */
typedef struct {
    eRegion_Number region_Number;                   /**< Số thứ tự region */
    uint32_t base_Address;                          /**< Địa chỉ bắt đầu của region */
    eSize size;                                     /**< Kích thước region 2^(size) => (log2(size) - 1) */
    eAccess_Permissions access_Permissions;         /**< Quyền truy cập của privileged/unprivileged */
    Memory_Type *memory_Type;                       /**< Loại vùng nhớ cấu hình */
    eInstruction_Access instruction_Access;         /**< Quyền truy cập lệnh */
    eDisable_Subregion disable_Subregion;           /**< Tắt subregion */
    eEnable_Region enable;                          /**< Bật/tắt region */
} MPU_Region_Config_t;


// 
/**
 * @struct  MPU config
 * @brief   Cấu trúc cấu hình MPU.
 * @details Cấu trúc này chứa các cấu hình về MPU, bao gồm số lượng region, 
 *          các region đã cấu hình, và các cấu hình về chế độ hoạt động.
 */
typedef struct {
    eEnable_Background_Region enable_Background_Region;     /**< Bật/tắt chế độ background region */
    eEnable_In_Exception enable_In_Exception;               /**< Cho phép MPU hoạt động trong exception */
    eEnable_In_Memfault enable_In_MemFault;                 /**< Sử dụng MemFault để xử lý lỗi thay cho HardFault */
    MPU_Region_Config_t *Region_Config;                     /**< Mảng các region đã cấu hình */
    uint8_t number_Of_Regions;                              /**< Số lượng region đã cấu hình */
} MPU_Config_t;                 

/* =======================================[ EXTERNAL VARIABLES ]===========================================*/
extern MPU_Config_t MPU_Config;

/* =====================================[ FUNCTION IMPLEMENTATION ]========================================*/
/* Function implementation for MPU config */

#endif /* MPU_CONFIG_H */
/* ===================================================[ Guard End ]===================================================*/
