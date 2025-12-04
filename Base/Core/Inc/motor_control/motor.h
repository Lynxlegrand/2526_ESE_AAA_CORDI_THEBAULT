/*
 * motor.h
 *
 *  Created on: Nov 11, 2025
 *      Author: nicolas
 */

#ifndef INC_MOTOR_CONTROL_MOTOR_H_
#define INC_MOTOR_CONTROL_MOTOR_H_

#include "tim.h"
#include "user_interface/shell.h"
#include <stdlib.h>

// SETTINGS
#define PWM_DUTY_INIT 50 	//en pourcentage
#define ARR 4250

// PUBLIC FUNCTIONS
void motor_init(void);
void motor_set_duty(uint8_t);

#endif /* INC_MOTOR_CONTROL_MOTOR_H_ */
