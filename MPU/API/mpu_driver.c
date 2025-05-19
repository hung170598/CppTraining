/******************************************************************************************************************************
 * @file    mpu_driver.c
 * @brief   Driver MPU
 * @details Driver MPU triển khai các API gọi xuống phần mpu_hw để cấu hình phần cứng.
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===========================================[ INCLUDE FILE ]===========================================*/
#include "mpu_driver.h"          /**< Thư viện chứa các API của MPU driver. */
#include "mpu_hw.h"              /**< Thư viện chứa các hàm của MPU hardware. */

/* ========================================[ MACRO DEFINITIONS ]==========================================*/
/* Macro definitions for MPU driver */

/* ======================================[ EXTERNAL VARIABLES ]===========================================*/
/* External variables for MPU driver */

/* =====================================[ FUNCTION DEPLOYMENT ]===========================================*/
static void MPU_Init(void);
static void MPU_DeInit(void);
static void MPU_Enable(void);
static void MPU_Disable(void);
static void MPU_Region_Enable(eRegion_Number region_Number);
static void MPU_Region_Disable(eRegion_Number region_Number);
static void MPU_Memfault_Callback(void (*callback)(uint32_t error_Status, uint32_t error_Address));

/**
  * @brief   Khởi tạo MPU.
  * @details Gọi xuống phần cứng để khởi tạo MPU.
  * @param   void
  * @return  void
  */
static void MPU_Init(void){
    MPU_hw_Init();
}

/**
  * @brief   Hủy bỏ MPU.
  * @details Gọi xuống phần cứng để hủy bỏ MPU.
  * @param   void
  * @return  void
  */
static void MPU_DeInit(void){
    MPU_hw_DeInit();
}

/**
  * @brief   Bật MPU.
  * @details Gọi xuống phần cứng để bật MPU.
  * @param   void
  * @return  void
  */
static void MPU_Enable(void){
    MPU_hw_Enable();
}

/**
  * @brief   Tắt MPU.
  * @details Gọi xuống phần cứng để tắt MPU.
  * @param   void
  * @return  void
  */
static void MPU_Disable(void){
    MPU_hw_Disable();
}

/**
  * @brief   Bật region.
  * @details Gọi xuống phần cứng để bật region.
  * @param   region_Number   Số thứ tự region.
  * @return  void
  */
static void MPU_Region_Enable(eRegion_Number region_Number){
    MPU_hw_Region_Enable(region_Number);
}

/**
  * @brief   Tắt region.
  * @details Gọi xuống phần cứng để tắt region.
  * @param   region_Number   Số thứ tự region.
  * @return  void
  */
static void MPU_Region_Disable(eRegion_Number region_Number){
    MPU_hw_Region_Disable(region_Number);
}

/**
  * @brief   Gọi callback khi xảy ra lỗi MPU.
  * @details Hàm ngắt MemFault sẽ gọi lên callback để xử lý lỗi.
  * @param   callback   hàm Callback sử dụng khi xảy ra lỗi MPU.
  * @return  void
  */
static void MPU_Memfault_Callback(void (*callback)(uint32_t error_Status, uint32_t error_Address)){
    MPU_hw_Memfault_Callback(callback);
}


/* ===========================================[ DRIVER HANDLE ]===========================================*/
/**
  * @brief   API MPU driver.
  * @details Khởi tạo các API để gọi driver xử lý các chức năng của MPU.
  * @note    Các API sẽ gọi các hàm trong driver để gọi xuống phần cứng.
  */
MPU_driver MPU_Driver={
    .Init = MPU_Init,                       /**< Khởi tạo MPU. */     
    .DeInit = MPU_DeInit,                   /**< Hủy bỏ MPU. */
    .Enable = MPU_Enable,                   /**< Bật MPU. */
    .Disable = MPU_Disable,                 /**< Tắt MPU. */
    .Region_Enable = MPU_Region_Enable,     /**< Bật region. */
    .Region_Disable = MPU_Region_Disable,   /**< Tắt region. */
    .Memfault_Callback = MPU_Memfault_Callback /**< Gọi callback khi xảy ra lỗi MPU. */
};

/* ===========================================[ DRIVER HANDLE ]===========================================*/

