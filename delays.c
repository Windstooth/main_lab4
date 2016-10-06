#include <define.h>

void delay1mseg() 		//gasta 1ms
{
	char a,b;
	
	for (a=0; a<10; a++)
	{
		for (b=0; b<29; b++) 
		{}
	}
}

char debouncing(unsigned char last_bt)  //Retorna 0 se o botão foi pressionado e 1 se o botão foi solto
{																			
	unsigned char m = 10;
	while (m > 0 && m < 20)
	{
		delay1mseg();
		if (last_bt == PORTA_TECLAS)
			m--;
		else
			m++;
	}
	if(m==0) 	return 0;
	else		  return 1;
}