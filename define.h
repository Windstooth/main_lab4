#include <AT89X52.h>
#define  PORTA_LEDS	   P2	// porta P2 é onde estão ligados os LEDS
#define  PORTA_TECLAS  P3	// porta P3 é onde estão ligados os botoes

/*
CONSTANTES TEMPORAIS:
frequência ocular:          24 Hz
frequência selecionada:     100 Hz
tempo por período:          0,01 s = 10 ms
*/
#define temp_total  10
#define temp_ten    1 //sempre temp_total/10

//Protótipos de funções
char debouncing(unsigned char);
void delay1mseg();
void setLED(unsigned char on);
