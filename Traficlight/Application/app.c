
#include "app.h"

uint8_t carLED=0; 		//0 green - 1 yellow - 2 red
uint8_t prevcarLED=1;	
volatile uint8_t normalmode = 1; //1 normal - 0 pedestrian
void HAL_init(void){
	
	//Car LED initialization
	LED_init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	//Pedestrian LED initialization
	LED_init(LED_PED_PORT,LED_PED_G_PIN);
	LED_init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_init(LED_PED_PORT,LED_PED_R_PIN);
	
	//INT0 initialization
	init_int0();
	
	//Timer initialization
	TIMER_init();

}

void Handlepedestrian(void)
{
// Handle the Pedestrian mode
	uint8_t iter, carledred = 0;
	//car red light is off

	//LED_off(LED_CAR_PORT,LED_CAR_R_PIN);

	// LED_on(PORT_C,PIN0);	//turn on debug led
	
	//blink both yellow while ped green is on
	for(iter=0;iter<5;iter++)
	{
		if(carLED<2)LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_on(LED_PED_PORT,LED_PED_Y_PIN);
		TIMER_delay(250);
		if(carLED<2)LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		TIMER_delay(500);
		if(carLED<2)LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
		LED_on(LED_PED_PORT,LED_PED_Y_PIN);
		TIMER_delay(250);
	}
	//Turn off yellow LEDs 
	LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_off(LED_PED_PORT,LED_PED_Y_PIN);
	//setup PED LEDs
	LED_on(LED_PED_PORT,LED_PED_G_PIN);
	LED_off(LED_PED_PORT,LED_PED_Y_PIN);
	LED_off(LED_PED_PORT,LED_PED_R_PIN);
	
	//setup CAR LEDs
	LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
	TIMER_delay(5000);//5 sec delay
	

	//turn on PED red LED
	LED_on(LED_PED_PORT,LED_PED_R_PIN);
	//reset normalmode
	normalmode=1;
	//setup carLED variables
	carLED=0;
	prevcarLED=1;
	// LED_off(PORT_C,PIN0);	//turn off debug led

}

void appStart(void){
	uint8_t iter;
	
	//if normal mode or need transition (car green led or yellow is on)
	if(normalmode || (carLED==0) || (carLED==1))
	{
		if(!normalmode){
			carLED=1;
			Handlepedestrian();
		}
		//Configuring Pedestrian LEDs 
		LED_off(LED_PED_PORT,LED_PED_G_PIN);
		LED_off(LED_PED_PORT,LED_PED_Y_PIN);
		LED_on(LED_PED_PORT,LED_PED_R_PIN);
		
		switch(carLED){
			//Case GREEN LED
			case 0:
				LED_on(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_R_PIN);
				// poll on mode change
				for(iter=0;iter<50;iter++){
					TIMER_delay(100);	// 500*10 = 5000 ms
					if(!normalmode)
					{
						Handlepedestrian();
						break;
					}
				}
				carLED=1;
				prevcarLED=0;
				break;
			//Case YELLOW LED 
			case 1:
				//if not normalmode then we need to blink both
				if(!normalmode){
					Handlepedestrian();
					prevcarLED=1;//to go to Ped lights logic
					carLED=2;
					LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
				}
				else{
					//blink car yellow led
					for(iter=0;iter<5;iter++){
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(250);
						LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(500);
						LED_on(LED_CAR_PORT,LED_CAR_Y_PIN);
						TIMER_delay(250);
						if(!normalmode)
						{//check pedestrian button
							prevcarLED=1;
							Handlepedestrian();
							break;
						}
					}
				}
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_off(LED_PED_PORT,LED_PED_Y_PIN);
				//setup variables for correct switching
				if(prevcarLED==0){
					carLED=2;
					prevcarLED=1;
				}
				else if(prevcarLED==2){
					carLED=0;
					prevcarLED=1;
				}
				break;
			//Case RED LED
			case 2:
				LED_off(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_off(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_on(LED_CAR_PORT,LED_CAR_R_PIN);
				for(iter=0;iter<50;iter++)
				{
					TIMER_delay(100);
					if(!normalmode)
					{
						Handlepedestrian();
						break;
					}
				}
				prevcarLED=2;
				carLED=1;
				break;
			default:
				carLED=2;
				prevcarLED=1;
				break;
		}
		
	}

}

#ifdef APP
ISR(INT0_vect)
{
	normalmode=0;
    SET_BIT(PORTD , 2);	//set the DIO pin to high again
}
#endif