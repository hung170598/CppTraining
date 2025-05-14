#include "mpu_driver.h"

uint32_t test_value = 0;

void HardFault_Handler(void){
	test_value = 2;
}

void MPU_Memfault_Callback(uint32_t error_Status, uint32_t error_Address){
    // TODO: Xử lý lỗi MPU trong ngắt
    test_value = 1;
}

int main(void){
    MPU_Driver.Init();
    MPU_Driver.Enable();
    MPU_Driver.Memfault_Callback(MPU_Memfault_Callback);

    // TEST ghi vào vùng read only
    volatile uint32_t *test_addr = (volatile uint32_t *)0x40000000;
    *test_addr = 0x12345678;    // HardFault or MemFault

    while(1);
}

