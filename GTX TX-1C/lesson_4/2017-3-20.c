#include<reg52.h>
#define uint unsigned int 
#define uchar unsigned char 						   //dong  xian
sbit dula=P2^6;										   //dong  xian
sbit wela=P2^7;
sbit led1=P1^0;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uchar num,num1,num2,ge,shi,bai;
void delay(uint z);
void display(uchar,uchar ,uchar);
void main()
{	led1=0;
	TMOD=0X11;
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	TH1=(65536-45872)/256;
	TL1=(65536-45872)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
	while(1)
	{
		display(bai,shi,ge);
	}
}

void display(uchar bai,uchar shi,uchar ge)
{
	wela=1;		    //ge
	P0=0xfe;
	wela=0;

	dula=1;
	P0=table[ge];
	dula=0;			delay(5);

	wela=1;				//shi
	P0=0xfd;
	wela=0;

	dula=1;
	P0=table[shi];
	dula=0;	     	delay(5);
	
	
	wela=1;				  //bai
	P0=0xfb;
	wela=0;

	dula=1;
	P0=table[bai];
	dula=0;	     	delay(5);
}

void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}

void T0_time() interrupt 1
{
	TH0=(65536-45872)/256;
	TL0=(65536-45872)%256;
	num1++;
	if(num1==10)
	{	
		num1=0;
		led1=~led1;
	}
}						 		

void T1_time() interrupt 3
{
	TH1=(65536-45872)/256;
	TL1=(65536-45872)%256;
	num2++;
	if(num2==5)
	{
		num2=0;
		num++;
		if(num==152)
			num=0;
			bai=num/100;
			shi=(num/10)%10;
			ge=num%10;
	}
}





