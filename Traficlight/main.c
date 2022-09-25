#include "main.h"


#ifdef APP
int main()
{
	//Initialize
    HAL_init();
    // LED_init(PORT_C , PIN0);    //debug led

	//Main loop
	while(1){
		appStart();
	}
    
}
#endif


#ifdef LEDTOGGLETEST
int main()
{
    GPIO_init(PORT_A, 0 , OUT);
    init_int0();
    while(1)
    {
        TOGGLE_BIT(PORTA , 0);
        TIMER_delay(1000);
    }
    return 0;
}
#endif

#ifdef LEDTOGGLETEST

/*Interrupt Service Routine for INT0*/
ISR(INT0_vect)
{
    TOGGLE_BIT(PORTA , 0);    
    SET_BIT(PORTD , 2);
}
#endif