#include "main.h"
// #define LEDTOGGLETEST


int main()
{

    return 0;
}

#ifdef LEDTOGGLETEST
int main()
{
    GPIO_init(PORT_A, 0 , OUT);
    while(1)
    {
        TOGGLE_BIT(PORTA , 0);
        _delay_ms(1000);
    }
    return 0;
}
#endif