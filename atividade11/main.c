#include <reg51.h>

void
select_segment(int);

void
set_pin(int, int);

void
display_digit(int);

void
sleep(int);

void
clear_display();

void
zero();

void
two();

void
three();

void
four();

void
five();

void
six();

void
seven();

void
eight();

void
nine();

/*const int digits[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};*/

void
main()
{
	int i;
	for(i=0; i<=99; i++)
	{
		P0 = 0; /*limpa tudo imediato*/
		select_segment(0);
		display_digit(i/10); /*00, 10, 20, ...*/
		clear_display();
		select_segment(1);
		display_digit(i%10); /*1, 2, 3...*/
		sleep(10);
	}
}


void
display_digit(int d)
{
	if(d==0)
		zero();
	else if(d==1)
		one();
	else if(d==2)
		two();
	else if(d==3)
		three();
	else if(d==4)
		four();
	else if(d==5)
		five();
	else if(d==6)
		six();
	else if(d==7)
		seven();
	else if(d==8)
		eight();
	else if(d==9)
		nine();
}

void
select_segment(int s)
{
	if(s) /*s==1*/
	{
		P1 = 0b00000001;
	}
	else
	{
		P1 = 0b00000010;
	}
}

void
set_pin(int pin, int value)
{
	if(pin==0)
		P0_0 = value;
	else if(pin==1)
		P0_1 = value;
	else if(pin==2)
		P0_2 = value;
	else if(pin==3)
		P0_3 = value;
	else if(pin==4)
		P0_4 = value;
	else if(pin==5)
		P0_5 = value;
	else if(pin==6)
		P0_6 = value;
	else if(pin==7)
		P0_7 = value;
}

void
sleep(int time)
{
	while(time--);
}

void
clear_display()
{
	P0_0 = 0;
	P0_1 = 0;
	P0_2 = 0;
	P0_3 = 0;
	P0_4 = 0;
	P0_5 = 0;
	P0_6 = 0;
	P0_7 = 0;
}

void
zero()
{
	P0_0 = 1;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 1;
	P0_4 = 1;
	P0_5 = 1;
	P0_6 = 0;
	P0_7 = 0;
}


void
one()
{
	P0_0 = 0;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 0;
	P0_4 = 0;
	P0_5 = 0;
	P0_6 = 0;
	P0_7 = 0;
}


void
two() /*0b01011011*/
{
	P0_0 = 1;
	P0_1 = 1;
	P0_2 = 0;
	P0_3 = 1;
	P0_4 = 1;
	P0_5 = 0;
	P0_6 = 1;
	P0_7 = 0;
}

void
three() /*0b01001111*/
{
	P0_0 = 1;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 1;
	P0_4 = 0;
	P0_5 = 0;
	P0_6 = 1;
	P0_7 = 0;
}

void
four() /*0b01100110*/
{
	P0_0 = 0;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 0;
	P0_4 = 0;
	P0_5 = 1;
	P0_6 = 1;
	P0_7 = 0;
}

void
five() /*0b01101101*/
{
	P0_0 = 1;
	P0_1 = 0;
	P0_2 = 1;
	P0_3 = 1;
	P0_4 = 0;
	P0_5 = 1;
	P0_6 = 1;
	P0_7 = 0;
}


void
six() /*0b01111101*/
{
	P0_0 = 1;
	P0_1 = 0;
	P0_2 = 1;
	P0_3 = 1;
	P0_4 = 1;
	P0_5 = 1;
	P0_6 = 1;
	P0_7 = 0;
}

void
seven() /*0b00000111*/
{
	P0_0 = 1;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 0;
	P0_4 = 0;
	P0_5 = 0;
	P0_6 = 0;
	P0_7 = 0;
}

void
eight() /*0b01111111*/
{
	P0_0 = 1;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 1;
	P0_4 = 1;
	P0_5 = 1;
	P0_6 = 1;
	P0_7 = 0;
}

void
nine() /*0b01100111*/
{
	P0_0 = 1;
	P0_1 = 1;
	P0_2 = 1;
	P0_3 = 0;
	P0_4 = 0;
	P0_5 = 1;
	P0_6 = 1;
	P0_7 = 0;
}

