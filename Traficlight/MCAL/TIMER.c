
#include "TIMER.h"

void TIMER_init(){
	TCCR0 = 0;
	TCCR0 |= (1<<1);	//normal mode, prescaler of 8 , each tech take 8 uSec at clock of 1MHz
}

void TIMER_delay(uint16_t millisec)
{
	uint16_t ms_iterator ;
	TIMER_init();
	for(ms_iterator = 0 ; ms_iterator < millisec ; ms_iterator++)
	{
		TCNT0 = 256-125; /* Load TCNT0*/	//delay for 1 ms
		while(! (READ_BIT(TIFR,0) )); /* Wait for TOV0 to roll over */
		TIFR = 0x1; /* Clear TOV0 §ag*/		
	}
}

