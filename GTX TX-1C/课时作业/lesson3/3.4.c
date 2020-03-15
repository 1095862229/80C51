#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
uchar tabwe[]=
{
0xfe,0xfd,0xfb,0xf7,0xef,0xdf
};
uchar code tabdu[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

uchar tt,i,j;
sbit dula=P2^6;
sbit wela=P2^7;
void main()
{
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
	while(1);
}

void timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
	if(tt==10)
	{
		tt=0;
		wela=1;
		
		P0=tabwe[i];
		i++;
		if(i==6)i=0;
		wela=0;
		dula=1;
		P0=tabdu[j];
		j++;
		if(j==16)j=0;
		dula=0;
	}
	
}