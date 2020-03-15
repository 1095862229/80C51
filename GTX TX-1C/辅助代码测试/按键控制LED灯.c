#include<reg52.h>
#define uchar unsigned char;
sbit led=P1^0;
sbit key=P3^4;
void delay(unsigned int x)
{
	unsigned int i,j;
		for(i=x;i>0;i--)
			for(j=110;j>0;j--);
}

void main()
{
	while(1)
	{
		if(key==0)
		{
			delay(10);
			if(key==0)
			led=0;
			
			while(!key);
			delay(10);
			while(!key);

		}
		else led=1;

	
	}	
}