#include<reg52.h>
sbit d1=P1^0;
sbit key1=P3^4;
sbit dula=P2^6;
sbit wela=P2^7;
unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
unsigned char a=0,x,y,z;
void delay(unsigned char z);
void main()
{	
	P3=0xff;
	while(1)
	{
		if(key1==0)
		{
			delay(10);
			if(key1==0)
			{
				d1=0;
			    a++;
				wela=1;
				P0=0xfe;
				wela=0;
			//	deply(5); 
				dula=1;
				P0=table[a];
				dula=0;
				if(a==16)
				    a=0;
				while(!key1);
				delay(10);
				while(!key1);
			}
		}
		else d1=1;	
	}
}

void delay(unsigned char z)
{
	for(x=z;x>0;x--)
	for(y=110;y>0;y--);	
}