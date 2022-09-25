#ifndef _APP_H
#define _APP_H

#include "../MCAL/GPIO.h"
#include "../MCAL/TIMER.h"
#include "../HAL/LED.h"
#include "../main.h"


void HAL_init(void);
void appStart(void);
void Handlepedestrian(void);


#endif 