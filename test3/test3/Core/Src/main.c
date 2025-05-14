
#include "main.h"
#include "usb_host.h"
#include "stm32f4xx.h"
#define GREEN_lED_PIN  (1<<12)
#define BLUE_LED_PIN   (1<<15)
#define ORANGE_LED_PIN (1<<13)
#define RED_LED_PIN    (1<<14)
#define BLINK_CYCLE    100
#define MAX_DUTY_CYCLE 100
#define MICRO_SECONDS  370
#define button         (1<<0)
typedef enum{
	LED_OFF,
	BLINK_LED,
	PWM,
}state_t_t;
state_t_t state_t = LED_OFF;
typedef struct{
	state_t_t prev;
	state_t_t cur;
}progress_t;

void initprogress(progress_t * sm)
{
	sm->cur = LED_OFF;
	sm->prev = LED_OFF;
}
void statemachine(progress_t * sw)
{
	switch(sw->cur)
	{
	case LED_OFF:
		led_off();
		sw->prev = LED_OFF;
		sw->cur = BLINK_LED;
	case BLINK_LED:
		if(sw->prev == LED_OFF)
		{
			led_off();
		}else if(sw->prev == BLINK_LED){
			blink_led();
			sw->cur = PWM;

		}
	case PWM:
	{
		if(sw->prev == BLINK_LED)
		{
			blink_led();

		}
		else if(sw->prev = PWM){
			twinkled();
			sw->cur == LED_OFF;
		}
	}
	}
}
void GPIO_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;


	/*set up led4 is output*/
	GPIOD->MODER |= 1<<24;
	GPIOD->MODER &= ~(1<<25);

	GPIOD->MODER |= 1<<26;
	GPIOD->MODER &= ~(1<<27);

	GPIOD->MODER |= 1<<28;
	GPIOD->MODER &= ~(1<<29);

	GPIOD->MODER |= 1<<30;
	GPIOD->MODER &= ~(1<<31);



	RCC->CR = RCC_CR_HSION;
}
void button_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	GPIOA->MODER &= (1<<0);
	GPIOA->MODER &= (1<<1);

	//GPIOA->PUPDR |= (1<<0);
	//GPIOA->PUPDR &= ~(1<<1);

}
void twinkled(void)
{
	uint8_t dutycycle;
	for ( dutycycle = 0; dutycycle < MAX_DUTY_CYCLE; dutycycle++)
			{
				/*T=4s*/
				pwm(dutycycle);/*0.01s x 100*/
				pwm(dutycycle);/*0.01s x 100*/
				pwm(dutycycle);/*0.01s x 100*/
				pwm(dutycycle);/*0.01s x 100*/

			}
			for ( dutycycle = 0; dutycycle < MAX_DUTY_CYCLE; dutycycle++)
			{
				/*T=4s*/
				pwm(dutycycle);/*0.01s x 100*/
				pwm(dutycycle);/*0.01s x 100*/
				pwm(dutycycle);/*0.01s x 100*/
				pwm(dutycycle);/*0.01s x 100*/


			}
}
void blink_led()
{
	delay(10000);
	GPIOD->ODR |= (GREEN_lED_PIN);
	GPIOD->ODR |= (BLUE_LED_PIN);
	GPIOD->ODR |= (ORANGE_LED_PIN);
	GPIOD->ODR |= (RED_LED_PIN);
	delay(10000);
	GPIOD->ODR &= ~(GREEN_lED_PIN);
	GPIOD->ODR &= ~(BLUE_LED_PIN);
	GPIOD->ODR &= ~(ORANGE_LED_PIN);
	GPIOD->ODR &= ~(RED_LED_PIN);

}
void pwm(uint8_t dutyCycle) {
	uint32_t downTime;
	uint32_t ontime;
	downTime = BLINK_CYCLE * (MAX_DUTY_CYCLE - dutyCycle) / MAX_DUTY_CYCLE;
	ontime = BLINK_CYCLE - downTime;

	delay(downTime);
	GPIOD->ODR |= (GREEN_lED_PIN);
	GPIOD->ODR |= (BLUE_LED_PIN);
	GPIOD->ODR |= (ORANGE_LED_PIN);
	GPIOD->ODR |= (RED_LED_PIN);
	delay(ontime);
	GPIOD->ODR &= ~(GREEN_lED_PIN);
	GPIOD->ODR &= ~(BLUE_LED_PIN);
	GPIOD->ODR &= ~(ORANGE_LED_PIN);
	GPIOD->ODR &= ~(RED_LED_PIN);
}
void led_off()
{
	GPIOD->ODR &= ~(GREEN_lED_PIN);
	GPIOD->ODR &= ~(BLUE_LED_PIN);
	GPIOD->ODR &= ~(ORANGE_LED_PIN);
	GPIOD->ODR &= ~(RED_LED_PIN);
}
	void delay(int delay)
	{
		int i = 0;
		int delayrt = 0;
		delayrt = delay * MICRO_SECONDS;
		for (i=0; i<delayrt;i++)
		{
			asm("nop");
		}
	}
void main()
{
	GPIO_init();
	button_init();
	progress_t sm;
	initprogress(&sm);
	while (1)
	{

		if ((GPIOA->IDR & (1 << 0))) {
		       statemachine(&sm);


		}

	}
}
