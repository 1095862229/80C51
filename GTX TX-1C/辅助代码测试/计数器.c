#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={   //显示数据编码
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0x76,0x79,0x38,0x3f};

void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void display(uchar shi,uchar ge)
{
/*	P0=table[bai];				   //显示 bai
	dula=1;
	dula=0;
	P0=0xf7;
	wela=1;
	wela=0;
	delay(1);	   */

	P0=table[shi];				   //显示 shi
	dula=1;
	dula=0;
	P0=0xef;
	wela=1;
	wela=0;
	delay(1);

	P0=table[ge];				   //显示 ge
	dula=1;
	dula=0;
	P0=0xdf;
	wela=1;
	wela=0;
	delay(1);
}

uint read()
{
	uchar t1,th1,th2;
	uint val;
	while(1)
	{
		th1=TH0;
		t1=TL0;
		th2=TH0;
		if(th1==th2)
			break;
	}
	val=th1*256+t1;
	return val;
}

void main()
{
	uchar a,b;
	uint num;
	TMOD=0x05;
	TH0=0;
	TL0=0;
	TR0=1;
	while(1)
	{
		num=read();
		if(num>=100)
		{
			num=0;
			TH0=0;
			TL0=0;
		}
		a=num/10;
		b=num%10;
		display(a,b);
	}
}