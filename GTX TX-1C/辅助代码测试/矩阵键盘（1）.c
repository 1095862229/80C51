#include<reg52.h>
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;
code P1_scan[]={0x7F,0xBF,0xDF,0xEF};
code key_temp[]={0xEE,0xED,0xEB,0xE7,0xDE,0xDD,0xDB,0xD7,
				0xBE,0xBD,0xBB,0xB7,0x7E,0x7D,0x7B,0x77};
code uchar seven_seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,
							0x80,0x90};
void delay(uchar x)
{
	while(x) x--;
}

uchar key_scan(void)
{
	uchar i,j;
	for(i=0;i<4;i++)
	{
		P1=P1_scan[i];
		if(P1!=P1_scan[i])
		{
			delay(200);
			if(P1!=P1_scan[i])
			{
				for(j=0;j<16;j++)
				{
					if(P1==key_temp[j])
						return j;

				}
			}
		}
	}
	return(88);
}

void display(uchar i)
{
	dula=1;
	P0=seven_seg[i%10];
	dula=0;
	P0=0xFF;
	wela=1;
	P0=0xfe;
	wela=0;
	delay(300);
	dula=1;
	P0=seven_seg[i/10];
	dula=0;
	P0=0xFF;
	wela=1;
	P0=0xfd;
	wela=0;
	delay(300);
	P0=0xFF;
}

void main(void)
{
	uchar i;
	while(1)
	{
		i=key_scan();
		display(i);
	}
}