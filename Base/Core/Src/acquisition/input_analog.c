/*
 * analog_input.c
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#include "acquisition/input_analog.h"
#include "adc.h"
#include "tim.h"
#include "user_interface/shell.h"

#define CURRENT_MEAS_BUFF_SIZE 1
#define COEF_ADC (float) 3.3f/4096.0f //(mV)
uint32_t current_meas_buff[CURRENT_MEAS_BUFF_SIZE];



static int sh_get_current(h_shell_t* h_shell, int argc, char** argv);


void input_analog_init(void){
	HAL_TIM_Base_Start(&htim7);
	HAL_ADC_Start_DMA(&hadc1, current_meas_buff, CURRENT_MEAS_BUFF_SIZE);
	shell_add(&hshell1, "getI", sh_get_current, "Get I in mA");
}




static int sh_get_current(h_shell_t* h_shell, int argc, char** argv)
{
    float currentx1000 = (float)(current_meas_buff[0] * COEF_ADC - 1.650f) / 0.05f;

    int size = snprintf(h_shell->print_buffer, SHELL_PRINT_BUFFER_SIZE,
                        "Current = %f A\r\n", currentx1000);

    h_shell->drv.transmit(h_shell->print_buffer, size);

    return 0;
}



void ADC1_Calibrate(void)
{
    // L’ADC doit être OFF
    HAL_ADC_DeInit(&hadc1);

    // Calibration en mode single-ended
    if (HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED) != HAL_OK)
    {
        Error_Handler();
    }
}
