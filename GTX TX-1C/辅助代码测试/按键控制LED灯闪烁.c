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
	unsigned char key_s;
	while(1)
	{
		if(key==0)
		{
			delay(10);
			if(key==0)
			{led=0;  
//			 delay(5);
			  key_s=1;}

		}
		if(key==1)
  		{
//			delay(5);
			if(key==1)	
			{	led=1;
				key_s=0;}
		}
	
		while(key==0 && key_s==1)
		{
				delay(50);
			if(key==0)
			{led=!led;
			delay(500);}
		}

		key_s=0;
	
	}	
}





