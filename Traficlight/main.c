#include "main.h"

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
