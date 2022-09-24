#include "main.h"
#define LEDTOGGLETEST
// #define APP


#ifdef APP

int main()
{
    
    while(1)
    {

    }
    return 0;
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

/*Interrupt Service Routine for INT0*/
ISR(INT0_vect)
{
    TOGGLE_BIT(PORTA , 0);    
}
