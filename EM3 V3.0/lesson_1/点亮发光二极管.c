#include<reg52.h>
void Delay10ms(unsigned int c)  ;
void display();
void main()
{
	while(1)
	{
		display();

	}
	
}  
void Delay10ms(unsigned int c)  
{
    unsigned char a, b;
    for (;c>0;c--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}
           
	}
        
}

void display()
{
			P0=0x01;
		Delay10ms(50);  
		P0=0x02;	
 		Delay10ms(50); 
		P0=0x04;	
 		Delay10ms(50);
		P0=0x08;	
 		Delay10ms(50);
		P0=0x10;	
 		Delay10ms(50);    
 		P0=0x40;	
 		Delay10ms(50);   
		P0=0x80;	
 		Delay10ms(50);   
		P0=0x81;
			Delay10ms(50); 
		P0=0x82;
			Delay10ms(50); 
		P0=0x84;
			Delay10ms(50); 
		P0=0x88;
			Delay10ms(50); 
		P0=0x90;
			Delay10ms(50); 
		P0=0xc0;
			Delay10ms(50); 
		P0=0xc1;
			Delay10ms(50); 
		P0=0xc2;
			Delay10ms(50); 
		P0=0xc4;
			Delay10ms(50); 
		P0=0xc8;
			Delay10ms(50); 
		P0=0xd0;
			Delay10ms(50); 
		P0=0xd1;
			Delay10ms(50); 
		P0=0xd2;
			Delay10ms(50); 
		P0=0xd4;
			Delay10ms(50); 
		P0=0xd8;
			Delay10ms(50); 
		P0=0xf9;
			Delay10ms(50); 
		P0=0xfa;
			Delay10ms(50); 
		P0=0xfc;
			Delay10ms(50); 
		P0=0xfd;
			Delay10ms(50); 
		P0=0xfe; 
			Delay10ms(50);
		P0=0xff;			   
			Delay10ms(100); 
		P0=0x00;
			Delay10ms(50); 
		P0=0xff;
			Delay10ms(50); 
		P0=0x00;
			Delay10ms(50);
		P0=0xff;
			Delay10ms(50); 
		P0=0x00; 
			Delay10ms(50);
		P0=0xff;			   
			Delay10ms(50); 


}