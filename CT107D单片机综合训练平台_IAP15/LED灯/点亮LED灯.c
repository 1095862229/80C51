#include<reg52.h>  //52单片机头文件
#include <intrins.h> //包含有左右循环移位子函数的库
#define uint unsigned int    //宏定义
#define uchar unsigned char  //宏定义
sbit P1_0=P1^0;
uchar table[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uchar tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar tt,i;
void main()		    //主函数
{
	TMOD=0x01;//设置定时器0为工作方式1
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;//开总中断
	ET0=1;//开定时器0中断
	TR0=1;//启动定时器0
	i=0;
	while(1);//等待中断产生
	
}

void timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
	if(tt%2==0)
	{
		P1=tab[i];
			
	}
	else
		P1=0xff;
	if(tt==20)
	{
		tt=0;
		P1=tab[i];
		i++;
		if(i==8) i=0;
	}
}