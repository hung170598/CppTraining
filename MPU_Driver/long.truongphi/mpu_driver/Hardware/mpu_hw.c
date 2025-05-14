/******************************************************************************************************************************
 * @file    mpu_hw.c
 * @brief   Hardware MPU.
 * @details Triển khai các hàm cấu hình trực tiếp phần cứng MPU bằng thanh ghi.
 * @version 1.0
 * @date    2025-05-09
 * @author  long.truongphi
 ******************************************************************************************************************************/
/* ===========================================[ INCLUDE FILE ]===========================================*/
#include "mpu_hw.h"          /**< Thư viện chứa các hàm cấu hình phần cứng MPU. */
#include "stm32f4xx.h"       /**< Thư viện chứa các hàm của STM32F4. */
#include "mpu_config.h"      /**< Thư viện chứa các kiểu dữ liệu config. */

/* ========================================[ MACRO DEFINITIONS ]==========================================*/
/* Macro definitions for MPU hardware */

/* ======================================[ EXTERNAL VARIABLES ]===========================================*/
/* External variables for MPU hardware */

/* =====================================[ FUNCTION DEPLOYMENT ]===========================================*/
/**
  * @brief   Cấu hình từng region.
  * @details Cấu hình region bằng thanh ghi.
  * @param   region_Config   Cấu trúc cấu hình của 1 region.
  * @return  void
  */
static void MPU_hw_Region_Config(MPU_Region_Config_t *region_Config){
    /**< Chọn region */
    MPU->RNR = 0;
    MPU->RNR = region_Config->region_Number;                            

    /**< Gán địa chỉ cơ sở của region */
    MPU->RBAR = 0;
    MPU->RBAR = region_Config->base_Address;                           

    /**< Gán kích thước của region */
    MPU->RASR &= ~(MPU_RASR_SIZE_Msk);
    MPU->RASR |= (region_Config->size << MPU_RASR_SIZE_Pos);          

    /**< Gán quyền truy cập của region */
    MPU->RASR &= ~(MPU_RASR_AP_Msk);
    MPU->RASR |= (region_Config->access_Permissions << MPU_RASR_AP_Pos); 

    /**< Gán kiểu mở rộng của region */
    MPU->RASR &= ~(MPU_RASR_TEX_Msk);
    MPU->RASR |= (region_Config->memory_Type->TEX << MPU_RASR_TEX_Pos); 

    /**< Gán cacheable của region */
    MPU->RASR &= ~(MPU_RASR_C_Msk);
    MPU->RASR |= (region_Config->memory_Type->Cacheable << MPU_RASR_C_Pos); 

    /**< Gán bufferable của region */
    MPU->RASR &= ~(MPU_RASR_B_Msk);
    MPU->RASR |= (region_Config->memory_Type->Bufferable << MPU_RASR_B_Pos); 

    /**< Gán shareable của region */
    MPU->RASR &= ~(MPU_RASR_S_Msk);
    MPU->RASR |= (region_Config->memory_Type->Shareable << MPU_RASR_S_Pos); 

    /**< Gán instruction access của region */
    MPU->RASR &= ~(MPU_RASR_XN_Msk);
    MPU->RASR |= (region_Config->instruction_Access << MPU_RASR_XN_Pos); 

    /**< Gán disable subregion của region */
    MPU->RASR &= ~(MPU_RASR_SRD_Msk);
    MPU->RASR |= (region_Config->disable_Subregion << MPU_RASR_SRD_Pos); 
    
    /**< Gán enable của region */
    MPU->RASR &= ~(MPU_RASR_ENABLE_Msk);
    MPU->RASR |= (region_Config->enable << MPU_RASR_ENABLE_Pos); 

    /**< Đồng bộ hóa pipeline */
    __DSB();
    __ISB();
}

/**
  * @brief   Cấu hình memfault.
  * @details Cấu hình chế độ memfault bằng thanh ghi.
  * @param   void
  * @return  void
  */
static void MPU_hw_MemFault_Config(void){
    /**< Bật memfault */
    SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;

    /**< Bật memfault interrupt */
    NVIC_EnableIRQ(MPU_Memfault_IRQn);
}

/**
  * @brief   Khởi tạo MPU.
  * @details Khởi tạo từng region đã config để cấu hình.
  *          Sau đó cấu hình background region, exception và memfault.
  *          Cuối cùng bật MPU.
  * @param   void
  * @return  void
  */
void MPU_hw_Init(void){
    /**< Tắt MPU */
    MPU_hw_Disable();

    /**< Cấu hình region */
    for(uint8_t i = 0; i < MPU_Config.number_Of_Regions; i++){
        MPU_hw_Region_Config(&MPU_Config.Region_Config[i]);
    }

    /**< Cấu hình background region */
    MPU->CTRL &= ~(MPU_CTRL_PRIVDEFENA_Msk);
    MPU->CTRL |= (MPU_Config.enable_Background_Region << MPU_CTRL_PRIVDEFENA_Pos);

    /**< Cấu hình exception */
    MPU->CTRL &= ~(MPU_CTRL_HFNMIENA_Msk);
    MPU->CTRL |= (MPU_Config.enable_In_Exception << MPU_CTRL_HFNMIENA_Pos);

    /**< Cấu hình memfault */
    if(MPU_Config.enable_In_MemFault == MPU_ENABLE_IN_MEMFAULT){
        MPU_hw_MemFault_Config();
    }

    /**< Bật toàn bộ MPU */
    MPU_hw_Enable();
}

/**
  * @brief   Hủy bỏ MPU.
  * @details Hủy bỏ toàn bộ các cấu hình trên các region và MPU.
  * @param   void
  * @return  void
  */
void MPU_hw_DeInit(void){

    /**< Reset toàn bộ MPU */
    MPU->CTRL = 0;

    /**< Xóa tất cả region */
    for(uint8_t i = 0; i < 8; i++){
        MPU->RNR = i;
        MPU->RBAR = 0;
        MPU->RASR = 0;
    }

    /**< Tắt memfault */
    SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
    
    /**< Đồng bộ hóa pipeline */
    __DSB();
    __ISB();
}

/**
  * @brief   Bật MPU.
  * @details Bật toàn bộ các region trong MPU.
  * @param   void
  * @return  void
  */
void MPU_hw_Enable(void){
    /**< Bật MPU */
    MPU->CTRL |= MPU_CTRL_ENABLE_Msk;

    /**< Đồng bộ hóa pipeline */
    __DSB();
    __ISB();
}

/**
  * @brief   Tắt MPU.
  * @details Tắt toàn bộ các region trong MPU.
  * @param   void
  * @return  void
  */
void MPU_hw_Disable(void){
    /**< Tắt MPU */
    MPU->CTRL &= ~MPU_CTRL_ENABLE_Msk;

    /**< Đồng bộ hóa pipeline */
    __DSB();
    __ISB();
}

/**
  * @brief   Bật một region cụ thể đã cấu hình.
  * @details Bật một region cụ thể đã cấu hình.
  * @param   region_Number   Số của region.
  * @return  void
  */
void MPU_hw_Region_Enable(eRegion_Number region_Number){
   for(uint8_t i = 0; i < MPU_Config.number_Of_Regions; i++){
        if(MPU_Config.Region_Config[i].region_Number == region_Number){
            /**< Gán số thứ tự region */
            MPU->RNR = region_Number;

            /**< Bật region */
            MPU->RASR |= (MPU_ENABLE_REGION << MPU_RASR_ENABLE_Pos);

            /**< Đồng bộ hóa pipeline */
            __DSB();
            __ISB();
        }
    }     
}

/**
  * @brief   Tắt một region cụ thể đã cấu hình.
  * @details Tắt một region cụ thể đã cấu hình.
  * @param   region_Number   Số của region.
  * @return  void
  */
void MPU_hw_Region_Disable(eRegion_Number region_Number){
    for(uint8_t i = 0; i < MPU_Config.number_Of_Regions; i++){
        if(MPU_Config.Region_Config[i].region_Number == region_Number){
            /**< Gán số thứ tự region */
            MPU->RNR = region_Number;

            /**< Tắt region */
            MPU->RASR &= ~(MPU_ENABLE_REGION << MPU_RASR_ENABLE_Pos);

            /**< Đồng bộ hóa pipeline */
            __DSB();
            __ISB();
        }
    }     
}

/* =====================================[ EXCEPTION HANDLE ]===========================================*/

/**
  * @brief   Con trỏ callback xử lý lỗi MPU trong ngắt
  * @details Con trỏ callback xử lý lỗi MPU trong ngắt
  */    
static void (*MemFault_Callback)(uint32_t error_Status, uint32_t error_Address) = 0;

/**
  * @brief   Lấy thông tin lỗi MPU
  * @details Lấy thông tin lỗi MPU bằng thanh ghi
  * @param   error_Status   Trạng thái lỗi
  * @param   error_Address   Địa chỉ lỗi
  * @return  void
  */
static void MPU_hw_Error_Details_Get(uint32_t *error_Status, uint32_t *error_Address){
    /**< Lấy trạng thái lỗi */
    *error_Status = SCB->CFSR & SCB_CFSR_MEMFAULTSR_Msk;

    /**< Lấy địa chỉ lỗi */
    *error_Address = SCB->MMFAR; 
}   

/**
  * @brief   Ngắt xử lý lỗi MPU 
  * @details Ngắt xử lý lỗi MPU bằng thanh ghi
  */
void MemManage_Handler(void){

    uint32_t error_Status = 0;
    uint32_t error_Address = 0;

    /**< Lấy thông tin lỗi */
    MPU_hw_Error_Details_Get(&error_Status, &error_Address);

    /**< Xử lý lỗi MPU ở tầng trên */
    if(MemFault_Callback != 0){
        MemFault_Callback(error_Status, error_Address);
    }
    else{
       while(1);    /**< Debug lỗi */
    }
}

/**
  * @brief   Gán hàm callback xử lý lỗi MPU trong ngắt
  * @details Gán hàm callback xử lý lỗi MPU trong ngắt
  * @param   callback   Con trỏ callback xử lý lỗi MPU trong ngắt
  * @return  void
  */    
void MPU_hw_Memfault_Callback(void (*callback)(uint32_t error_Status, uint32_t error_Address)){
    /**< Gán hàm callback */
    MemFault_Callback = callback;
}
