#include<reg52.h>  //52��Ƭ��ͷ�ļ�
#include <intrins.h> //����������ѭ����λ�Ӻ����Ŀ�
#define uint unsigned int    //�궨��
#define uchar unsigned char  //�궨��
sbit P1_0=P1^0;
uchar table[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
uchar tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar tt,i;
void main()		    //������
{
	TMOD=0x01;//���ö�ʱ��0Ϊ������ʽ1
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;//�����ж�
	ET0=1;//����ʱ��0�ж�
	TR0=1;//������ʱ��0
	i=0;
	while(1);//�ȴ��жϲ���
	
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