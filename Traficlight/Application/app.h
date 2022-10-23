#ifndef _APP_H
#define _APP_H

#include "../MCAL/gpio/GPIO.h"
#include "../MCAL/timer/TIMER.h"
#include "../HAL/led/LED.h"
#include "../main.h"


void HAL_init(void);
void appStart(void);
void Handlepedestrian(void);


#endif 