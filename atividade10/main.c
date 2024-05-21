#include <reg51.h>


/* Prototipos */
void
set_port(int, int);

int
int_to_led(int);

void
sleep(int);

void
main()
{
	int i; /* contador */
	int lv; /* valor do led */
	for(i=0; i<=0XF; i++)
	{ 
		set_port(0, 0X00); /* limpa o valor da porta */
		lv = int_to_led(i); /* calcula o valor equivalente para o display de led */
		set_port(0, lv); /* mostra o valor no display */
		sleep(5); /* espera um pouco */
	}
	sleep(-1);
}


/*
 * Atribui um valor a porta selecionada
 */
void
set_port(int port, int value)
{
	if(port == 0)
		P0 = value;
	else if(port == 1)
		P1 = value;
	else if(port == 2)
		P2 = value;
	else if(port == 3)
		P3 = value;
}

/*
 * Converte o valor de um numero (entre 0 e 16) para o valor das portas em um display led de oito segmentos
 * O display led deve ser configurado de modo que o segmento A seja acionado por P0_0, o segmento  B por P0_1, e assim em diante, ate o segmento G por P0_6 e o ponto decimal por P0_7
 * O display deve ser do tipo catodo comum, no qual um pino ativo (valor 1) acende o segmento de led correspondente
 */
int
int_to_led(int num)
{
	switch(num)
	{
		case 0: /* A,B,C,D,E,F = 0,1,2,3,4,5 */
			return 0B00111111;
		case 1: /* B,C = 1,2 */
			return 0B00000110;
		case 2: /* A,B,G,E,D = 0,1,3,4,6 */
			return 0B1011011;
		case 3: /* A,B,G,C,D = 0,1,2,3,6*/
			return 0B01001111;
		case 4: /* F,G,B,C = 1,2,5,6*/
			return 0B01100110;
		case 5: /* A,F,G,C,D = 0,2,3,5,6 */
			return 0B01101101;
		case 6: /* A,F,E,C,D,G = 0,2,3,4,5,6 */
			return 0B01111101;
		case 7: /* A,B,C = 0,1,2 */
			return 0B00000111;
		case 8: /* A,B,C,D,E,F,G = 0,1,2,3,4,5,6 */
			return 0B01111111;
		case 9: /* G,F,A,B,C = 0,1,2,5,6 */
			return 0B01100111;
		case 0XA: /* A,B,C,E,F,G = 0,1,2,4,5,6 */
			return 0B01110111;
		case 0XB: /* C,D,E,F,G = 2,3,4,5,6 */
			return 0B01111100;
		case 0XC: /* A,F,E,D = 0,3,4,5 */
			return 0B00111001;
		case 0XD: /* B,C,D,E,G = 1,2,3,4,6 */
			return 0B01011110;
		case 0XE: /* A,F,G,E,D = 0,3,4,5,6 */
			return 0B01111001;
		case 0XF: /* A,F,G,E = 0,4,5,6 */
			return 0B01110001;
		default: /* Invalid */
			return 0B00000000;
	}
}

void
sleep(int duration)
{
	while(duration--);
}
