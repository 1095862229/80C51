#include<reg52.h>
#include<intrins.h>
unsigned char code tab[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
sbit dula=P2^6;
sbit wela=P2^7;

void delay(unsigned int x)
{
	unsigned int i,j;
		for(i=x;i>0;i--)
			for(j=110;j>0;j--);
}
void main()
{
	unsigned char i;
	wela=1;
	P0=0xfe;
	wela=0;
	dula=1;
	while(1)
	{
		for(i=0;i<16;i++)
		{
			P0=tab[i];
			delay(500);
		}
	}
}