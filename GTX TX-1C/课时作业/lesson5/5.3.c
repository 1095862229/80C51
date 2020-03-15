#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};

uint shu;
uchar temp,key;
uchar wan1,wan,qian,bai,shi,ge;
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

void keyscans()
{
	P3=0xfe;
	temp=P3;
	temp=temp&0xf0;
	while(temp!=0xf0)
	{
		delay(5);
		temp=P3;
		temp=temp&0xf0;;
		while(temp!=0xf0)
		{
			switch(temp)
			{
				case 0xe0: key=1; break;
				case 0xd0: key=2; break;
				case 0xb0: key=3; break;
				case 0x70: key=4; break;
			}

		  while(temp!=0xf0)
		  {
		  	temp=P3;
			temp=P3&0xf0;
			display(bai,shi,ge);
		  }
		}
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
		{
			switch(temp)
			{
				case 0xe0: key=5; break;
				case 0xd0: key=6; break;
				case 0xb0: key=7; break;
				case 0x70: key=8; break;
			}
		  while(temp!=0xf0)
		  {
		  	temp=P3;
			temp=temp&0xf0;
			display(bai,shi,ge);
		  }
		}
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
		{
			switch(temp)
			{
				case 0xe0: key=9; break;
				case 0xd0: key=10; break;
				case 0xb0: key=11; break;
				case 0x70: key=12; break;
			}
		  while(temp!=0xf0)
		  {
		  	temp=P3;
			temp=temp&0xf0;
  			display(bai,shi,ge);
		  }
		}
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
		{
			switch(temp)
			{
				case 0xe0: key=13; break;
				case 0xd0: key=14; break;
				case 0xb0: key=15; break;
				case 0x70: key=16; break;
			}
		  while(temp!=0xf0)
		  {
		  	temp=P3;
			temp=temp&0xf0;
			display(bai,shi,ge);
		  }
		}
	}

}

void calculation()
{
	shu=key*key;
	bai=shu/100;
	shi=shu%100/10;
	ge=shu%10;
}

void main()
{
	dula=1;
	P0=0;
	dula=0;
	wela=1;
	wela=0;
	while(1)
	{
		keyscans();
		calculation();
		display(bai,shi,ge);
	}
}