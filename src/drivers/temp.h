
#ifndef _TEMP_H_
#define _TEMP_H_
#include <stdint.h>
void config_mode(void);
void select_input_chanel(void);
void select_sample_time(void);
void enabled_sensor(uint8_t bit_index);
void start_conversion(void);
void obtain_temperature(uint32_t value);

#endif
