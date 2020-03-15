#include<reg52.h>
#include<intrins.h>
sbit d1=P1^0;	
sbit d2=P1^1;
sbit d3=P1^2;
sbit d4=P1^3;
sbit d5=P1^4;
sbit d6=P1^5;
sbit d7=P1^6;
sbit d8=P1^7;
unsigned int a=200;
unsigned int b=2;
unsigned char temp;
void zuoyi();
void shuxun();
void yanshi();
void main()
{
	while(1)
	{
		unsigned int i=8;
		temp=0xfe;
		while(i--)
		zuoyi();
		i=8;
		P1=0xff;
        shuxun();




	}
}	

void yanshi()
{
     for(;b-->0;)
		while(a--);
	   a=200;
		  b=2;
} 	


void zuoyi()
{

		P1=temp;
		yanshi();
		temp=_crol_(temp,1);

}

void shuxun()
{
		d1=0;
		yanshi();
		d1=1;
		yanshi();
		d1=0;
		d2=0;
		yanshi();
		d1=1;d2=1;
		yanshi();
		d1=0;d2=0;d3=0;
		yanshi();
		d1=1;d2=1;d3=1;
		yanshi();
		d1=0;d2=0;d3=0;d4=0;
		yanshi();
		d1=1;d2=1;d3=1;d4=1;
		yanshi();
		d1=0;d2=0;d3=0;d4=0;d5=0;
		yanshi();
		d1=1;d2=1;d3=1;d4=1;d5=1;
		yanshi();
		d1=0;d2=0;d3=0;d4=0;d5=0;d6=0;
		yanshi();
		d1=1;d2=1;d3=1;d4=1;d5=1;d6=1;
		yanshi();
		d1=0;d2=0;d3=0;d4=0;d5=0;d6=0;d7=0;
		yanshi();
		d1=1;d2=1;d3=1;d4=1;d5=1;d6=1;d7=1;
		yanshi();
		d1=0;d2=0;d3=0;d4=0;d5=0;d6=0;d7=0;d8=0;
		yanshi();
		d1=1;d2=1;d3=1;d4=1;d5=1;d6=1;d7=1;d8=1;
		yanshi();
}