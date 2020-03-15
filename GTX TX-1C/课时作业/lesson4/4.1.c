#include<reg52.h>
#define uchar unsigned char
#define uing unsigned int
uchar tabwe[]=
{
0xfe,0xfd,0xfb,0xf7,0xef,0xdf
};
uchar code tabdu[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
sbit dula=P2^6;
sbit wela=P2^7;
uchar wei,duan;
void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}
void main()
{
	wei=0;duan=6;
	while(1)
	{
		P0=tabdu[duan];			
		dula=1;

		dula=0;
//		P0=0xff;
		P0=tabwe[wei];
		wela=1;

		wela=0;
		P0=0x00;
		delay(1);
		wei++;
		duan--;
		if(wei==6) wei=0;
		if(duan==0) duan=6;
		
	}
}
