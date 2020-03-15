//数码管前三位显示一个跑表，从000到999之间以1%秒速度运行，***//
/*当按下一个独立键盘时跑表停止，松开手后跑表继续运行。*******/ 
/*(用定时器设计表)******************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit key=P3^4;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uchar code tablewe[]={
0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
uchar ge,shi,bai;
void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void display(uchar bai,uchar shi,uchar ge)
{
	P0=table[ge];
	dula=1;
	dula=0;
	P0=0xfb;
	wela=1;
	wela=0;
	delay(1);
	
	P0=table[shi];
	dula=1;
	dula=0;
	P0=0xfd;
	wela=1;
	wela=0;
	delay(1);
	
	P0=table[bai];
	dula=1;
	dula=0;
	P0=0xfe;
	wela=1;
	wela=0;
	delay(1);	
}



void timer0() interrupt 1
{
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	ge++;
	if(ge==10)
	{
		ge=0;
		shi++;
		if(shi==10)
		{
			shi=0;
			bai++;
			if(bai==10)
			{
				ge=0;
				shi=0;
				bai=0;
			}
		} 
	}	    
}						 


				 



void init()
{
	ge=0;shi=0;bai=0;tt0=0;
	TMOD=0x01;
	TH0=(65536-10000)/256;
	TL0=(65536-10000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void main()
{
	init();
	while(1)
	{
		display(bai,shi,ge);
		if(key==0)
		{
			delay(5);
			if(key==0)
			{	 
					TR0=0;
					while(!key)
					display(bai,shi,ge);			
			}
		}
		TR0=1;
	}
}