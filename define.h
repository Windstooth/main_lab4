#include <AT89X52.h>
#define  PORTA_LEDS	   P2	// porta P2 � onde est�o ligados os LEDS
#define  PORTA_TECLAS  P3	// porta P3 � onde est�o ligados os botoes

/*
CONSTANTES TEMPORAIS:
frequ�ncia ocular:          24 Hz
frequ�ncia selecionada:     100 Hz
tempo por per�odo:          0,01 s = 10 ms
*/
#define temp_total  10
#define temp_ten    1 //sempre temp_total/10

//Prot�tipos de fun��es
char debouncing(unsigned char);
void delay1mseg();
void setLED(unsigned char on);
