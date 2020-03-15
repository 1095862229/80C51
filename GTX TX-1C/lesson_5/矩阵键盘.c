#include <reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0,0x76,0x79,0x38,0x3f};
uchar temp,num,t0,t1,bai,shi,ge,flag,flag1,num1;
uint shu;
void init();
uchar keyscan();
void deplay();
void display(uchar,uchar,uchar,uchar,uchar,uchar);
void delay(uint z)
{
	uint t1,y;
	for(t1=z;t1>0;t1--)
		for(y=110;y>0;y--);
}
void main()
{

	P0=0;
	dula=1;
	dula=0;
	wela=1;
	P0=0xc0;
	wela=0;
	num=17;
	while(1)
	{
 		deplay();
	}
}


uchar keyscan()
{
		P3=0xfe;
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			delay(5);
			temp=P3;
			temp=temp&0xf0;
			while(temp!=0xf0)
			{	switch(temp)
					{
						case 0xe0: num=1; break;
						case 0xd0: num=2; break;
						case 0xb0: num=3; break;
						case 0x70: num=4; break;
	         		} 

				break;
			}
			break;
		}

		P3=0xfd;
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			delay(5);
			temp=P3;
			temp=temp&0xf0;
			while(temp!=0xf0)
			{	switch(temp)
					{
						case 0xe0: num=5; break;
						case 0xd0: num=6; break;
						case 0xb0: num=7; break;
						case 0x70: num=8; break;
	         		} 

				break;
			}
			break;
		}
			  
		P3=0xfb;
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			delay(5);
			temp=P3;
			temp=temp&0xf0;
			while(temp!=0xf0)
			{	switch(temp)
					{
						case 0xe0: num=9; break;
						case 0xd0: num=10; break;
						case 0xb0: num=11; break;
						case 0x70: num=12; break;
	         		} 

				break;
			}
			break;
		}



		P3=0xf7;
		temp=P3;
		temp=temp&0xf0;
		while(temp!=0xf0)
		{
			delay(5);
			temp=P3;
			temp=temp&0xf0;
			while(temp!=0xf0)					
			{	switch(temp)
					{
						case 0xe0: num=13; break;
						case 0xd0: num=14; break;
						case 0xb0: num=15; break;
						case 0x70: num=16; break;
	         		} 

				break;
			}
			break;
		}

		return num;
}

void deplay()
{

	  	num1=keyscan();
		dula=1;
		P0=table[num1-1];
		dula=0;

}