/* Select the ADCx_IN16 input channel.
2. Select a sample time of 17.1 µs
3. Set the TSVREFE bit in the ADC control register 2 (ADC_CR2) to wake up the
temperature sensor from power down mode.
4. Start the ADC conversion by setting the ADON bit (or by external trigger).
5. Read the resulting V SENSE data in the ADC data register
6. Obtain the temperature using the following formula:
Temperature (in °C) = {(V 25 - V SENSE ) / Avg_Slope} + 25.
Where,
V 25 = V SENSE value for 25° C and
Avg_Slope = Average Slope for curve between Temperature vs. V SENSE (given in
mV/° C or µV/ °C).
Refer to the Electrical characteristics section for the actual values of V 25 and
Avg_Slope.
*/

#include "temp.h"
#include <stdint.h>
#include <stdio.h>
#include "adc.h"
#include "rcc.h"
void select_input_chanel(void)
{
    // selec pin 16 in SQ1
    ADC1->ADC_SQR3 |= (16U << 0);
}
void select_sample_time(void)
{
    // 17.1us + 8MHG => 136,8 cycles
    // Select a sample time of 17.1 µs
    ADC1->ADC_SMPR1 |= (1U << 18); // chọn cycles cho kênh 16
}
void enabled_sensor(uint8_t bit_index) { ADC1->ADC_CR2 |= 1U << 23; }
void start_conversion(void)
{
    ADC1->ADC_CR2 |= 1U << 0;
    for (int i = 0; i < 100000; i++) { }
    ADC1->ADC_CR2 |= 1U << 0;
}
void obtain_temperature(uint32_t value)
{

    const float V25 = 1.43; // Điện áp cảm biến tại 25°C (V)
    const float Avg_Slope = 0.0043; // Độ dốc trung bình (V/°C)

    // Tính điện áp cảm biến từ giá trị ADC
    float v_sense = ((float)value / 4095.0f) * 3.3f;

    // Tính nhiệt độ theo công thức datasheet
    float temperature = ((V25 - v_sense) / Avg_Slope) + 25.0;
}
void config_mode(void)
{
    RCC->RCC_APB2ENR |= RCC_APB2ENR_ADC1EN;
    select_input_chanel();
    select_sample_time();
    enabled_sensor(1);
}

