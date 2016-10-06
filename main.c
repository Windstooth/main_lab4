/* ************************************************************
UFRGS – Universidade Federal do Rio Grande do Sul
EE – Escola de Engenharia
DELET – Departamento de Engenharia Elétrica
Disciplina: Microprocessadores I
Código: ENG04475
Professor: Alexandre A. Junqueira

Programa: programa C que ajusta a luminosidade dos LEDs do
Kit via teclado, utilizando PWM

Autores: Bruno Zanchetta, Ícaro Dupont, Luciano Bongiorni.
Data: 2016/2
*************************************************************** */

#include <define.h>

void main(void)
{
	PORTA_TECLAS = 0xFF;
	PORTA_LEDS = 0x00;
	while(1)
	{
		unsigned char show = 0, count, temp, LAST_KEY;
		//pega a intensidade adequada show = x, para intensidade = x0%
		if(!debouncing(LAST_KEY))
		{
			switch (PORTA_TECLAS) 
			{
				case (~0x01):	show=0;		break;
				case (~0x02):	show=2;		break;
				case (~0x04):	show=4;		break;
				case (~0x08):	show=6;		break; 
				case (~0x10):	show=8;		break;		
				case (~0x20): show=10;	break; 
				case (~0x40):
					if(show != 10)
						show++;
						break;
				case (~0x80):
					if(show != 0)
						show--;
						break;
				
				default: break;
			}
		}
		
		LAST_KEY = PORTA_TECLAS;

		//onde liga os leds por tempo definido de acordo
		for (count = 1; count <= show; count++)
		{
			setLED(1);
			for(temp=1;temp<=temp_ten;temp++)
				delay1mseg();
		}
		while (count <=10) //faz a contagem que sobra no tempo restante
		{
			setLED(0);
			for(temp=1;temp<=temp_ten;temp++)
				delay1mseg();
			count++;
		}
	}//fim do while(1)
}//fim do main