#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={   //ÊýÂë¹ÜÏÔÊ¾±àÂë
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
uchar tt,shu=0,ge,shi; uchar z=0;
void main()
{
	uchar i,j;
	TMOD=0x10;
	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	EA=1;
	ET1=1;
	TR1=1;
	while(1)
	{	
	    wela=1;
		P0=0xfd;
		wela=0;
		P0=0x00;			
		dula=1;
		P0=table[ge];
		dula=0;
	//	for(i=999;i>0;i--)
		 for(j=569;j>0;j--);   
		P0=0xff;
		wela=1;
		P0=0xfe;
		wela=0;
		P0=0x00;
		dula=1;
		P0=table[shi];
		dula=0;
		P0=0xff;
//		   	for(i=699;i>0;i--) 
		for(j=599;j>0;j--);
 		if(shu==99)
			shu=0;
			

	}
}


void timer1() interrupt 3
{

	TH1=(65536-10000)/256;
	TL1=(65536-10000)%256;
	 tt++;
	 if(tt%5==0)
	{tt=0;
	shu++;
	shi=shu/10;
		ge=shu%10; }
		
	
}