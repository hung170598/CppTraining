#include "stm32h562xx.h"

void delay(volatile uint32_t time) {
    while(time--);   
}

// Define a constant for LED toggle delay
#define LED_DELAY 500000 																						
																																																																	
int main(){
    // Enable clock for GPIOB 
    RCC->AHB2ENR |= (1UL << 1); 		

    // Configure GPIOB Pin 2 as output
    GPIOB->MODER |= (1UL << 4);  		
    GPIOB->MODER &= ~(1UL << 5);  	

    // Set output speed for GPIOB Pin 2 to high speed
    GPIOB->OSPEEDR |= (1UL << 4) | (1UL << 5); 

    // Configure pull-down resistors for GPIOB Pin 2
    GPIOB->PUPDR |= (1UL << 5);   	
    GPIOB->PUPDR &= ~(1UL << 4);   

    while(1){
				// Toggle output state for Pin 2 
        GPIOB->ODR ^= (1UL << 2);
				// Delay
        delay(LED_DELAY);          	
    }
}
