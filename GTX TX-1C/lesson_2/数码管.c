#include <reg52.h>
sbit duan=P2^6;
sbit wei=P2^7;
sbit d0=P0^0;
sbit d1=P0^1;
sbit d2=P0^2;
sbit d3=P0^3;
sbit d4=P0^4;
sbit d5=P0^5;
sbit d6=P0^6;
sbit d7=P0^7;
unsigned int a=150;
unsigned int b=2;
unsigned char code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71};
void yanshi();
void main()
{
	
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
	
	wei=1;
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
	yanshi();	
}
 void yanshi()
{
     for(;b-->0;)
		while(a--);
	   a=150;
		  b=2;
} 	
