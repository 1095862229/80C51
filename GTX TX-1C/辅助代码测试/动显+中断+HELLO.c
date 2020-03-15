#include<reg52.h>
#include <intrins.h> //����������ѭ����λ�Ӻ����Ŀ�
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={   //��ʾ���ݱ���
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0x76,0x79,0x38,0x3f,0};
uint shu;
uchar ge,shi,bai,tt0,tt1,flag,temp,flag1;


void timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt0++;
	if(flag!=1)
		{
			if(tt0==10)
			{
				tt0=1;
				temp=_crol_(temp,1);
				P1=temp;
			}
		}
	else              //������е���˸
		{
			if(tt0%4==0)  //С��ÿ200����仯һ��
				P1=~P1;
			if(tt0==60)
			{
				TR0=0;   //3���رն�ʱ��0���رյƣ�����flag=1
				P1=0xff;
				flag1=1;
			}
		}	

}

void timer1() interrupt 3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	tt1++;
	if(tt1==2)
		{
			tt1=0;
			shu--;
			bai=shu/100;
			shi=shu%100/10;
			ge=shu%10;
			if(shu==398)    //����398ʱ��ԭ��T0�е�����������¼Ӳó�ֵ��С����˸
				{
					TR0=0;
					TH0=(65536-50000)/256;
					TL0=(65536-50000)%256;
					TR0=1;
					flag=1;
					tt0=0;
					P1=0xff;
					TR1=0;
				}	
		}	
}

void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);
}

void init()
{
	temp=0xfe;
	shu=432;
	bai=shu/100;
	shi=shu%100/10;
	ge=shu%10;
	P1=temp;
	TH1=(65536-50000)/256;  //��ʱ����ʼ��
	TL1=(65536-50000)%256;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	TMOD=0x11;
	ET0=1;
	ET1=1;
	TR1=1;
	TR0=1;
}

void display(uchar bai1,uchar shi1,uchar ge1,uchar bai,uchar shi,uchar ge)
{
	P0=table[bai1];				  //��ʾ 7
	dula=1;
	dula=0;
	P0=0xfe;
	wela=1;
	wela=0;
	delay(1);

	P0=table[shi1];				   //��ʾ 6
	dula=1;
	dula=0;
	P0=0xfd;
	wela=1;
	wela=0;
	delay(1);

	P0=table[ge1];				   //��ʾ 5
	dula=1;
	dula=0;
	P0=0xfb;
	wela=1;
	wela=0;
	delay(1);

	P0=table[bai];				   //��ʾ bai
	dula=1;
	dula=0;
	P0=0xf7;
	wela=1;
	wela=0;
	delay(1);

	P0=table[shi];				   //��ʾ shi
	dula=1;
	dula=0;
	P0=0xef;
	wela=1;
	wela=0;
	delay(1);

	P0=table[ge];				   //��ʾ ge
	dula=1;
	dula=0;
	P0=0xdf;
	wela=1;
	wela=0;
	delay(1);
}


void main()
{
	init();
	while(1)
	{
		if(flag1!=1)   //���flagi���ٵ���1����ʾ����
			display(7,6,5,bai,shi,ge);
		else
			display(16,17,18,18,19,20);	  //������ʾhello
	}
}