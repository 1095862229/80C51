#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit adwr=P3^6;
sbit adrd=P3^7;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

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
	P0=0xef;
	wela=1;
	wela=0;
	delay(1);
	
	P0=table[shi];
	dula=1;
	dula=0;
	P0=0xfb;
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

void main()
{
	uchar a,bai,shi,ge,adval;
	wela=1;
	P0=0x7f;
	wela=0;
	while(1)
	{
		adwr=1;
		_nop_();
		adwr=0;
		_nop_();
		adwr=1;
		_nop_();
	
	for(a=20;a>0;a--)
		display(bai,shi,ge);
	P1=0xff;
	adrd=1;
	_nop_();
	adrd=0;
	_nop_();
	adval=P1;
	adrd=1;
	bai=adval/100;
	shi=adval%100/10;
	ge=adval%10; 
	
	}
}









