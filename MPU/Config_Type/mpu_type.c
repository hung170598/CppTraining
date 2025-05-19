/******************************************************************************************************************************
 * @file    mpu_type.c
 * @brief   Type MPU.
 * @details Triển khai 1 số kiểu dữ liệu mặc định để người dùng có thể sử dụng luôn.
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===========================================[ INCLUDE FILE ]===========================================*/
#include "mpu_type.h"              /**< Thư viện chứa các kiểu dữ liệu config. */

/* ========================================[ MACRO DEFINITIONS ]==========================================*/
/* Macro definitions for MPU type */


/* ==================================[ EXTERNAL VARIABLES DEPLOYMENT ]=====================================*/
/**
  * @brief   FLASH memory type.
  * @details Cấu hình sẵn Memory type và Attribute Memory sử dụng cho vùng nhớ FLASH.
  * @note    Cấu hình Normal memory, Write-through, Non-shareable, Non-bufferable, Cacheable.
  *          Cấu hình dựa trên tài liệu coretex-m4 generic user guide.
  */
Memory_Type FLASH_mem = {   
    .TEX = 0, 
    .Cacheable = 1, 
    .Bufferable = 0, 
    .Shareable = 0
};

/**
  * @brief   SRAM Internal memory type.
  * @details Cấu hình sẵn Memory type và Attribute Memory sử dụng cho vùng nhớ SRAM Internal.
  * @note    Cấu hình Normal memory, Shareable, Write-through, Non-bufferable, Cacheable.
  *          Cấu hình dựa trên tài liệu coretex-m4 generic user guide.
  */
Memory_Type SRAM_Intenal_mem = {       
    .TEX = 0, 
    .Cacheable = 1, 
    .Bufferable = 0, 
    .Shareable = 1
};

/**
  * @brief   SRAM External memory type.
  * @details Cấu hình sẵn Memory type và Attribute Memory sử dụng cho vùng nhớ SRAM External.
  * @note    Cấu hình Normal memory, Shareable, Write-back, Write-allocate, Cacheable.
  *          Cấu hình dựa trên tài liệu coretex-m4 generic user guide.
  */
Memory_Type SRAM_External_mem = {      
    .TEX = 0, 
    .Cacheable = 1, 
    .Bufferable = 1, 
    .Shareable = 1
};

/**
  * @brief   Peripheral memory type.
  * @details Cấu hình sẵn Memory type và Attribute Memory sử dụng cho vùng nhớ Peripheral.
  * @note    Cấu hình Device memory, Shareable, Non-cacheable, Non-bufferable.
  *          Cấu hình dựa trên tài liệu coretex-m4 generic user guide.
  */
Memory_Type PERIPH_mem = {             
    .TEX = 0, 
    .Cacheable = 0, 
    .Bufferable = 0, 
    .Shareable = 1
};

/* =====================================[ FUNCTION DEPLOYMENT ]===========================================*/
/* Function deployment for MPU type */
