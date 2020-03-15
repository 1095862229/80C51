#include<reg52.h>
#define uchar unsigned char
sbit sda=P2^0;
sbit scl=P2^1;
void delay()
{;;}
void start()		//��ʼ
{
	sda=1;
	delay();
	scl=1;
	delay();
	sda=0;
	delay();
	
}
void stop()					 //ֹͣ
{
	sda=0;
	delay();
	scl=1;
	delay();
	sda=1;
}
void respons()		     //Ӧ��
{
	uchar i;
	scl=1;
	delay();
	while((sda==1)&&(i<250)) i++;
	scl=0;
	delay();
}
void init()
{
	sda=1;
	scl=1;

}
void write_byte(uchar date)     //д��һ���ֽ�
{
	uchar i,temp;
	temp=date;
	scl=0;
	delay();
	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		sda=CY;
		delay();
		scl=1;
		delay();
		scl=0;
		delay();
	}
	sda=1;
	delay();
}
uchar read_byte()
{
	uchar i,j,k;
	scl=0;
	delay();
	sda=1;
	delay();
	for(i=0;i<8;i++)
	{
		scl=1;
		delay();	
		j=sda;
		k=(k<<1)|j;	
		scl=0;
		delay();			
	}
	return k;
}

void delay1(uchar x)
{
	uchar a,b;
	for(a=x;a>0;a--)
	 for(b=100;b>0;b--);
}


void main()
{
	init();				   //��ʼ��
	start();			   //��ʼ�ź�
	write_byte(0xa0);	   //������ַ
	respons();			   //Ӧ��
	write_byte(3);		   //�����ڲ���ַ
	respons();			   //Ӧ��
	start();			   //
	write_byte(0x55);	   //
	respons();			   //
	stop();


	delay1(100);
	start();				   //
	write_byte(0xa0);	   //
	respons();			   //
	write_byte(3);
	respons();
	start();
	write_byte(0xa1);	   //��
	P1=read_byte();
	stop();
	while(1);		
}