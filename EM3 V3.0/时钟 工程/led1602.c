#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit rs=P2^6;
sbit wr=P2^5;
sbit en=P2^7;
sbit key1=P1^0;
sbit key2=P1^1;
sbit key3=P1^2;
sbit key4=P1^3;
uchar code date[]="    2017 12 31";   //3+4+2+3=13
uchar code time[]="     12:12:12";	   //3+3+3+2+2=13
uchar code table[]={
0x3f,0x06,0x5b,0x4f,
0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,
0x39,0x5e,0x79,0x71,
0,0x76,0x79,0x38,0x3f};
uchar tt=0,i,j,num=0;
uchar flag=':';
int miaohou=0,miaoqian=0,fenhou=0,fenqian=0,shihou=0,shiqian=0;
int riqian=3,rihou=1,yueqian=1,yuehou=2,nian2=2,nian0=0,nian1=1,nian7=7;
int nian;
void delay(uchar z)
{
	uchar x,y;
	for(x=z;x>0;x--)
		for(y=110;y>0;y--);	
}
void led_com(uchar com)
{
	P0=com;	
	rs=0;
	delay(1);
	en=1;
	delay(1);
	en=0;
}

void led_date(uchar date)
{
	rs=1;
	P0=date;
	delay(1);
	en=1;
	delay(1);
	en=0;
}
void init()
{
//	miaohou=0;miaoqian=0;fenhou=0;fenqian=0;shihou=0;shiqian=0;
	en=0;
	wr=0;
	led_com(0x38);
	led_com(0x0e);
	led_com(0x06);		
	led_com(0x01);
	led_com(0x80);
		for(i=0;i<14;i++)
		{
			led_date(date[i]);
			delay(5);
		}
		led_com(0x80+0x40);
	for(j=0;j<13;j++)
		{
			led_date(time[j]);
			delay(5);
		} 	 
	TMOD=0x01;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}
void zengshi()
{
	if(tt==20)
	{
		tt=0;
		miaohou++;
	if(miaohou==10)
		{	miaohou=0;	miaoqian++; }
		if(miaoqian==6)
		{	miaoqian=0;  fenhou++;}
		if(fenhou==10)
		{	fenhou=0;	fenqian++;}
		if(fenqian==6 )
		{	fenqian=0;	shihou++;}
		if(shihou==10)
		{shihou=0;		shiqian++;}
		if(shiqian==2 && shihou==4)
		{shiqian=0; shihou=0;}
	}
}

void zengtian()
{
	nian=nian2*1000+nian0*100+nian1*10+nian7;
	if(shiqian==0 && shihou==0 && fenqian==0 && fenhou==0 && miaoqian==0 && miaohou==0)
	{
      while((shiqian==0 && shihou==0 && fenqian==0 && fenhou==0 && miaoqian==0 && miaohou==0));
		if((nian%4==0 &&nian%100!=0)||nian%400==0)
		{
			if(yueqian==0)
			{
			  	if(yuehou==1 || yuehou==3 || yuehou==5 || yuehou==7 || yuehou==8)
				{	rihou++;
					if(riqian<3 &&	rihou==10) 
					{	rihou=0;  riqian++;}
					if(riqian==3 && rihou==2)
					{	yuehou++;	riqian=0; 	rihou=1;	}
				}
				else if(yuehou==4||yuehou==6||yuehou==9)
				{
					rihou++;
					if( riqian<3 && rihou==10)
					{rihou=0;	riqian++;	}
					if(riqian==3 && rihou==10)
					{yuehou++;	riqian=0; rihou=1;}
				}
				else
				{
					rihou++;
					if(riqian==3 && rihou==10)
					{riqian=0;	rihou=1;	yuehou++;}
					if(riqian<2 && rihou==10)
					{rihou=0;	riqian++;}
				}
				if(yuehou==10)
				{
					yueqian++;	yuehou=0;
				}		
			}
			else
			{
				if(yuehou==0 || yuehou==2)
				{
					rihou++;
					if(riqian<3 && rihou==10)
					{rihou=0;	riqian++;}
					if(riqian==3 && rihou==2)
					{rihou=1;	riqian=0;	yuehou++;}
				}
				if(yuehou==1)
				{
					rihou++;
					if(riqian<3 && rihou==10)
					{rihou=1;		riqian++;	}
					if(riqian==3 && rihou==10)
					{yuehou++;	riqian=0;	rihou=1;}
				}

			}
			
		}
		else
		{
			if(yueqian==0)
			{
			  	if(yuehou==1 || yuehou==3 || yuehou==5 || yuehou==7 || yuehou==8)
				{	rihou++;
					if(riqian<3 &&	rihou==10) 
					{	rihou=0;  riqian++;}
					if(riqian==3 && rihou==2)
					{	yuehou++;	riqian=0; 	rihou=1;	}
				}
				else if(yuehou==4||yuehou==6||yuehou==9)
				{
					rihou++;
					if(riqian<3 && rihou==10)
					{rihou=0;	riqian++;	}
					if(riqian==3 && rihou==10)
					{yuehou++;	riqian=0;	rihou=1;}
				}
				else
				{
					rihou++;
					if(riqian==2 && rihou==9)
					{riqian=0;	rihou=1;	yuehou++;}
					if(riqian<2 && rihou==10)
					{rihou=0;	riqian++;}
				}		
		
				if(yuehou==10)
				{
					yueqian++;	yuehou=0;
				}
		 	}
			else
			{
				if(yuehou==0 || yuehou==2)
				{
					rihou++;
					if(riqian<3 && rihou==10)
					{rihou=0;	riqian++;} 
					if(riqian==3 && rihou==2)
					{rihou=1;	riqian=0;	yuehou++;}
				}
				if(yuehou==1)
				{
					rihou++;
					if(riqian<3 && rihou==10)
					{rihou=0;	riqian++;	}
					if(riqian==3 && rihou==10)
					{yuehou++;	riqian=0; rihou=1;}
				}
			}

		}
	}
	if(yueqian==1 && yuehou==3)
	{
		yueqian=0;	yuehou=1;	nian++;
	}
	nian2=nian/1000;
	nian0=nian%1000/100;
	nian1=nian%100/10;
	nian7=nian%10;
}

void display(uchar shiqian,uchar shihou,uchar fenqian,uchar fenhou,uchar miaoqian,uchar miaohou)
{
	led_com(0x80+0x40+5);
	led_date(0x30+shiqian);
	delay(5);
	led_com(0x80+0x40+6);
	led_date(0x30+shihou);
	delay(5);
	led_com(0x80+0x40+7);
	led_date(flag);
	delay(5);
	led_com(0x80+0x40+8);
	led_date(0x30+fenqian);
	delay(5);
	led_com(0x80+0x40+9);
	led_date(0x30+fenhou);
	delay(5);
	led_com(0x80+0x40+10);
	led_date(flag);
	delay(5);
	led_com(0x80+0x40+11);
	led_date(0x30+miaoqian);
	delay(5);
	led_com(0x80+0x40+12);
	led_date(0x30+miaohou);
	delay(5);
}


void displaydate(uchar nian2,uchar nian0,uchar nian1,uchar nian7,uchar yueqian,uchar yuehou,uchar riqian,uchar rihou)
{
	led_com(0x80+3);
	led_date(0x30+nian2);
	delay(5);
	led_com(0x80+4);
	led_date(0x30+nian0);
	delay(5);
	led_com(0x80+5);
	led_date(0x30+nian1);
	delay(5);
	led_com(0x80+6);
	led_date(0x30+nian7);
	delay(5);
	led_com(0x80+8);
	led_date(0x30+yueqian);
	delay(5);
	led_com(0x80+9);
	led_date(0x30+yuehou);
	delay(5);
	led_com(0x80+11);
	led_date(0x30+riqian);
	delay(5);
	led_com(0x80+12);
	led_date(0x30+rihou);
	delay(5);
}

void keyscans()
{
	if(key1==0)
	{
		delay(5);
		if(key1==0)
		{
			 TR0=0;
			 num++;
			 led_com(0x0c);
		}
		while(!key1);
	}
	if(num==7) 
	{ num=0;
		TR0=1;
	}
	if(num==1)
	{
		while(key1==1)
		{	led_com(0x80+0x40+12);
			led_com(0x0f);
			if(key2==0)
			{	delay(5);
				if(key2==0)
				{
					miaohou++;
					if(miaohou==10)
						miaohou=0;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key2);
			}
			if(key3==0)
			{
				delay(5);
				if(key3==0)
				{
					miaohou--;
					if(miaohou==-1)
						miaohou=9;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key3);
			}
			if(key4==0)
			{
			delay(5);
			if(key4==0)
			{
				  led_com(0x0c);
				  TR0=1;
				  num=0;
			}
			while(!key4);
			return;
			}					
		}
	} 
	if(num==2)
	{
		while(key1==1)
		{	led_com(0x80+0x40+11);
			led_com(0x0f);
			if(key2==0)
			{	delay(5);
				if(key2==0)
				{
					miaoqian++;
					if(miaoqian==6)
						miaoqian=0;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key2);
			}
			if(key3==0)
			{
				delay(5);
				if(key3==0)
				{
					miaoqian--;
					if(miaoqian==-1)
						miaoqian=5;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key3);
			}
			if(key4==0)
			{
			delay(5);
			if(key4==0)
			{
				  led_com(0x0c);
				  TR0=1;
				  num=0;
			}
			while(!key4);
			return;
			}		
	
			 }
	}
	if(num==3)
	{
		while(key1==1)
		{	led_com(0x80+0x40+9);
			led_com(0x0f); 
			if(key2==0)
			{	delay(5);
				if(key2==0)
				{
					fenhou++;
					if(fenhou==10)
						fenhou=0;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key2);
			}
			if(key3==0)
			{
				delay(5);
				if(key3==0)
				{
					fenhou--;
					if(fenhou==-1)
						fenhou=9;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key3);
			}
						if(key4==0)
			{
			delay(5);
			if(key4==0)
			{
				  led_com(0x0c);
				  TR0=1;
				  num=0;
			}
			while(!key4);
			return;
			}		
	
		}
	} 
	if(num==4)
	{
		while(key1==1)
		{	led_com(0x80+0x40+8);
			led_com(0x0f);
						if(key2==0)
			{	delay(5);
				if(key2==0)
				{
					fenqian++;
					if(fenqian==6)
						fenqian=0;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key2);
			}
			if(key3==0)
			{
				delay(5);
				if(key3==0)
				{
					fenqian--;
					if(fenqian==-1)
						fenqian=5;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key3);
			}
						if(key4==0)
			{
			delay(5);
			if(key4==0)
			{
				  led_com(0x0c);
				  TR0=1;
				  num=0;
			}
			while(!key4);
			return;
			}		

		 }
	} 
	if(num==5)
	{
		while(key1==1)
		{	led_com(0x80+0x40+6);
			led_com(0x0f);
					if(key2==0)
			{	delay(5);
				if(key2==0)
				{
					shihou++;
					if(shiqian==2)
					{	if(shihou==4)	shihou=0;}
					else{if(shihou==10)		shihou=0;}
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
					
				}
				while(!key2);
			}
			if(key3==0)
			{
				delay(5);
				if(key3==0)
				{
					shihou--;
					if(shihou==-1)
					{
						if(shiqian==2)shihou=3;
						else	shihou=9;
					}
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key3);
			}
						if(key4==0)
			{
			delay(5);
			if(key4==0)
			{
				  led_com(0x0c);
				  TR0=1;
				  num=0;
			}
			while(!key4);
			return;
			}		

		 }
	} 
	if(num==6)
	{
		while(key1==1)
		{	led_com(0x80+0x40+5);
			led_com(0x0f);
					if(key2==0)
			{	delay(5);
				if(key2==0)
				{
					shiqian++;
					if(shiqian==3)
						shiqian=0;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key2);
			}
			if(key3==0)
			{
				delay(5);
				if(key3==0)
				{
					shiqian--;
					if(shiqian==-1)
						shiqian=2;
						display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
						led_com(0x0c);
				}
				while(!key3);
			}
						if(key4==0)
			{
			delay(5);
			if(key4==0)
			{
				  led_com(0x0c);
				  TR0=1;
				  num=0;
			}
			while(!key4);
			return;
			}		

		 }
	} 
}


void main()
{
	init();
	while(1)
	{
//	zengshi();
	zengtian();
	display(shiqian,shihou,fenqian,fenhou,miaoqian,miaohou);
	displaydate(nian2,nian0,nian1,nian7,yueqian,yuehou,riqian,rihou);
	keyscans();
	}
}

void timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	tt++;
	zengshi();
}