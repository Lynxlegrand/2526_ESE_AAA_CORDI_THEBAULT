/*
 * motor.c
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#include "motor_control/motor.h"


// VARIABLES
uint8_t pwm_duty = PWM_DUTY_INIT;


// STATIC PROTOTYPES
static uint32_t calc_duty(uint8_t percent);
static int sh_set_ccr(h_shell_t* h_shell, int argc, char** argv);


// FUNCTIONS
void motor_init(void){

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1); // démarrer CH1N
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2); // démarrer CH2N


	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, calc_duty(pwm_duty));
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ARR - calc_duty(pwm_duty));


	shell_add(&hshell1, "setCRR", sh_set_ccr, "Set PWM duty cycle (0-100%)");


}



static int sh_set_ccr(h_shell_t* h_shell, int argc, char** argv) {
    if (argc != 2) {
        int size = snprintf(h_shell->print_buffer, SHELL_PRINT_BUFFER_SIZE,
                            "Usage: set_ccr <value 0-100>\r\n");
        h_shell->drv.transmit(h_shell->print_buffer, size);
        return -1;
    }

    // Vérifier que argv[1] est bien un nombre entre 0 et 100
    char *endptr;
    long val = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || val < 0 || val > 100) {
        int size = snprintf(h_shell->print_buffer, SHELL_PRINT_BUFFER_SIZE,
                            "Error: value must be an integer between 0 and 100\r\n");
        h_shell->drv.transmit(h_shell->print_buffer, size);
        return -1;
    }

    // Calculer CCR et appliquer sur PWM (canaux 1 et 2)
    uint32_t ccr_value = calc_duty((uint8_t)val);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, ccr_value);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ARR - ccr_value);


    int size = snprintf(h_shell->print_buffer, SHELL_PRINT_BUFFER_SIZE,
                        "PWM duty cycle set to %ld%% (CCR=%lu)\r\n", val, ccr_value);
    h_shell->drv.transmit(h_shell->print_buffer, size);

    return 0;
}




void motor_set_duty(uint8_t){
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, calc_duty(pwm_duty));
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, ARR - calc_duty(pwm_duty));
}


static uint32_t calc_duty(uint8_t percent) {
    if (percent > 100) percent = 100;
    return (ARR * percent) / 100;
}

