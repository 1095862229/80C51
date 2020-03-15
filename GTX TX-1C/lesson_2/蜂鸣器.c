#include<reg52.h>
#include <intrins.h>
#define uint unsigned int 
#define uchar unsigned char 
uchar temp,num,num1;
sbit beep=P2^3;
void delay(uint);

void main()
{
		
       
	while(1)
	{	

			beep=0;
			delay(1000);
			beep=1;
			delay(1000);	
	}
}

void delay(uint z)
{
	uint x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}