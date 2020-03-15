#include <reg52.h>
sbit duan=P2^6;
sbit wei=P2^7;
sbit d0=P1^0;
sbit d1=P0^1;
sbit d2=P0^2;
sbit d3=P0^3;
sbit d4=P0^4;
sbit d5=P0^5;
sbit d6=P0^6;
sbit d7=P0^7;
unsigned int a=150;
unsigned int b=2;
unsigned char tt=0;
sbit beep=P2^3;
void yanshi();
void main()
{
  TMOD=0x01;
  TH0=(65536-50000)/256;
  TL0=(65536-50000)%256;
  EA=1;
  ET0=1;
  TR0=1; 	 
	if(tt==3)
	{
	tt=0; 
	wei=1;
	P0=0xfe;
	wei=0;		                                      //1
	duan=1;
	P0=0x06;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	

	wei=1;
	P0=0xfd;
	wei=0;											 //2
	duan=1;
	P0=0x5b;
	duan=0;

	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();
		
	wei=1;
	P0=0xfb;										//3
	wei=0;
	duan=1;
	P0=0x4f;
	duan=0;

	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();  
	}
	
/*	wei=1;
	P0=0xf7;								   //4
	wei=0;
	duan=1;
	P0=0x66;
	duan=0;

	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();
	
	wei=1;
	P0=0xef;									 //5
	wei=0;
	duan=1;
	P0=0x6d;
	duan=0;

	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();
	
	wei=1;
	P0=0xdf;
	wei=0;
	duan=1;										  //6
	P0=0x7d;
	duan=0;	

 
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();
	
	wei=1;
	P0=0xdf;
	wei=0;
	duan=1;										  //7
	P0=0x07;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	

	wei=1;
	P0=0xef;									   //8
	wei=0;
	duan=1;
	P0=0x7f;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	wei=1;
	P0=0xf7;
	wei=0;
	duan=1;										//9
	P0=0x6f;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	wei=1;
	P0=0xfb;
	wei=0;									   //a
	duan=1;
	P0=0x77;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	wei=1;										//b
	P0=0xfd;
	wei=0;
	duan=1;
	P0=0x7c;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	wei=1;
	P0=0xfe;
	wei=0;										 //c
	duan=1;
	P0=0x39;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	wei=1;
	P0=0xfd;										 //d
	wei=0;
	duan=1;
	P0=0x5e;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	wei=1;
	P0=0xfb;										//e
	wei=0;
	duan=1;
	P0=0x7b;
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	


	
	wei=1;
	P0=0xf7;
	wei=0;
	duan=1;
	P0=0x71;												//f
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();	   */
}
 void yanshi()
{
     for(;b-->0;)
		while(a--);
	   a=150;
		  b=2;
} 	

void exter0() interrupt 1
{
	TH0=(65536-50000)/256;
    TL0=(65536-50000)%256;
	tt++;

	wei=1;
	P0=0xf7;
	wei=0;
	duan=1;
	P0=0x71;												//f
	duan=0;
	
	
	yanshi();
	wei=1;
	P0=0xff;
	wei=0;
	yanshi();

}

