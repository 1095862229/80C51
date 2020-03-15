#include<reg52.h>  //52单片机头文件
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
ucahr tt,i;
sbit beep=P2^3;
void main()
{
	TMOD=0x11;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
	while(1);
}


void timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
	if(tt==5) tt=0;
}

void timer1() interrupt 2
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
	if(tt==5) tt=0;
}


