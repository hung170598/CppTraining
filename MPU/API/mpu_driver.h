/******************************************************************************************************************************
 * @file    mpu_driver.h
 * @brief   Driver MPU
 * @details Driver MPU tạo các API để cấu hình phần cứng
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===================================================[ Guard Start ]===================================================*/
#ifndef __MPU_DRIVER_H__
#define __MPU_DRIVER_H__

/* ===========================================[ INCLUDE FILE ]============================================*/
#include "mpu_type.h"                       /**< Thư viện chứa các kiểu dữ liệu config. */

/* ========================================[ MACRO DEFINITIONS ]==========================================*/
/* Macro definitions for MPU driver */


/* ========================================[ TYPE DEFINITIONS ]===========================================*/
/**
  * @brief   API MPU driver.
  * @details Khung API MPU driver.
  * @note    Các API sẽ thông qua các hàm trong driver để gọi xuống phần cứng.
  */
typedef struct{
    void (*Init)(void);                                         /**< Khởi tạo MPU. */  
    void (*DeInit)(void);                                       /**< Hủy bỏ MPU. */
    void (*Enable)(void);                                       /**< Bật MPU. */
    void (*Disable)(void);                                      /**< Tắt MPU. */
    void (*Region_Enable)(eRegion_Number region_Number);        /**< Bật region. */
    void (*Region_Disable)(eRegion_Number region_Number);       /**< Tắt region. */
    void (*Memfault_Callback)(void (*callback)(uint32_t error_Status, uint32_t error_Address)); /**< Gọi callback khi xảy ra lỗi MPU. */
} MPU_driver;

/* =======================================[ EXTERNAL VARIABLES ]===========================================*/
extern MPU_driver MPU_Driver;               /**< Biến global để lưu trữ API driver MPU. */ 

/* =====================================[ FUNCTION INPLEMENTATION ]=======================================*/
/* Function implementation for MPU driver */


#endif /* __MPU_DRIVER_H__ */
/* ===================================================[ Guard End ]===================================================*/
