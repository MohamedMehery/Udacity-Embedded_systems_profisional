
#include "INT.h"

void init_int0()
{
    DDRD &= ~(1<<2); /* PORTD as input */
    PORTD |= (1<<2); /* Make pull up high */
    GICR = 1<<INT0; /* Enable INT0*/
    MCUCR = 1<<ISC01 ; /* Trigger INT0 on falling edge */
    sei(); /* Enable Global Interrupt */
}
