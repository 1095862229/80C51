#include<reg52.h>
unsigned char tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void delay(unsigned char x)
{
	unsigned char i,j;
		for(i=x;i>0;i--)
			for(j=110;j>0;j--);
}
void main()
{
	unsigned char i=0;
	while(1)
	for(i=0;i<8;i++)
	{
		P1=tab[i];
		delay(200);
	}  
}





