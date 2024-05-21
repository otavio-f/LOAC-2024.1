#include <reg51.h>

void
select_segment(int);

void
light_up(int);

int lookup_table[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};

void
main()
{
	int i;
	for(i=0; i<=99; i++)
	{
		P0 = lookup_table[i/10];
		select_segment(0);
		/*light_up(i/10);*/
		P0 = lookup_table[i%10];
		select_segment(1);
		/*light_up(i%10);*/

		P1 = 0XFF;
		P0 = 0;
	}
}


void
select_segment(int s)
{
	if(s) /*s==1*/
	{
		P1_0 = 1;
		P1_1 = 0;
	}
	else
	{
		P1_0 = 0;
		P1_1 = 1;
	}
}

void
light_up(int i)
{
	if(i==0)
		P0 = 0b00111111;
		return;
	if(i==1)
		P0 = 0b00000110;
		return;
	if(i==2)
		P0 = 0b01011011;
		return;
	if(i==3)
		P0 = 0b01001111;
		return;
	if(i==4)
		P0 = 0b01100110;
		return;
	if(i==5)
		P0 = 0b01101101;
		return;
	if(i==6)
		P0 = 0b01111101;
		return;
	if(i==7)
		P0 = 0b00000111;
		return;
	if(i==8)
		P0 = 0b01111111;
		return;
	if(i==9)
		P0 = 0b01100111;
		return;
}
