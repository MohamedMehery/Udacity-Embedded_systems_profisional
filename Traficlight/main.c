#include "main.h"
#define LEDTOGGLETEST


#ifdef LEDTOGGLETEST
int main()
{
    GPIO_init(PORT_A, 0 , OUT);
    while(1)
    {
        TOGGLE_BIT(PORTA , 0);
        TIMER_delay(1000);
    }
    return 0;
}
#endif