/******************************************************************************************************************************
 * @file    mpu_hw.h
 * @brief   Hardware MPU.
 * @details Khai báo các hàm cấu hình trực tiếp phần cứng MPU và 
 *          phục vụ cho driver MPU sử dụng các API để gọi xuống phần cứng.
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===================================================[ Guard Start ]===================================================*/
#ifndef __MPU_HW_H__
#define __MPU_HW_H__

/* ==========================================[ INCLUDE FILE ]=============================================*/
#include "mpu_type.h"               /**< Thư viện chứa các kiểu dữ liệu config. */

/* ========================================[ MACRO DEFINITIONS ]==========================================*/
/* Macro definitions for MPU hardware */

/* ========================================[ TYPE DEFINITIONS ]===========================================*/
/* Type definitions for MPU hardware */

/* =======================================[ EXTERNAL VARIABLES ]==========================================*/
/* External variables for MPU hardware */

/* =====================================[ FUNCTION INPLEMENTATION ]=======================================*/
/**
  * @brief   Khởi tạo MPU.
  * @details Khởi tạo MPU bằng thanh ghi.
  * @param   void
  * @return  void
  */
void MPU_hw_Init(void);

/**
  * @brief   Hủy bỏ MPU.
  * @details Hủy bỏ MPU bằng thanh ghi.
  * @param   void
  * @return  void
  */        
void MPU_hw_DeInit(void);

/**
  * @brief   Bật MPU.
  * @details Bật MPU bằng thanh ghi.
  * @param   void
  * @return  void
  */
void MPU_hw_Enable(void);

/**
  * @brief   Tắt MPU.
  * @details Tắt MPU bằng thanh ghi.
  * @param   void
  * @return  void
  */        
void MPU_hw_Disable(void);

/**
  * @brief   Bật region.
  * @details Bật region bằng thanh ghi.
  * @param   region_Number   Số thứ tự region.
  * @return  void
  */    
void MPU_hw_Region_Enable(eRegion_Number region_Number);

/**
  * @brief   Tắt region.
  * @details Tắt region bằng thanh ghi.
  * @param   region_Number   Số thứ tự region.
  * @return  void
  */
void MPU_hw_Region_Disable(eRegion_Number region_Number);

/**
  * @brief   Gán hàm callback xử lý lỗi MPU trong ngắt
  * @details Gán hàm callback xử lý lỗi MPU trong ngắt
  * @param   callback   Con trỏ callback xử lý lỗi MPU trong ngắt
  * @return  void
  */    
void MPU_hw_Memfault_Callback(void (*callback)(uint32_t error_Status, uint32_t error_Address));

#endif /* __MPU_HW_H__ */
/* ===================================================[ Guard End ]===================================================*/
