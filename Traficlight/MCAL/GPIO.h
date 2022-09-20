

#ifndef GPIO_H_
#define GPIO_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define IN 0 
#define OUT 1

#define LOW 0 
#define HIGH 1


void GPIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction);// Initialize GPIO direction
void GPIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to GPIO
void GPIO_toggle(uint8_t portNumber, uint8_t pinNumber); //toggle GPIO
void GPIO_READ(uint8_t portNumber, uint8_t pinNumber, uint8_t* value); //read GPIO


#endif