#include <define.h>

void setLED(unsigned char LED_on) //feito lembrando que liga no logic low
{
	if (LED_on==1)
		PORTA_LEDS = 0000;//porta leds liga	
	else
		PORTA_LEDS = ~(0000);//porta leds não liga
}