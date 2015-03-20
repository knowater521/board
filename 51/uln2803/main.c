#include <reg51.h>
sbit LE=P3^0;
sbit _RD=P3^7;
sbit _WR=P3^6;
sbit s=P3^0;
sbit A15=P2^7;
sbit A12=P2^4;
unsigned char code DSY_CODE[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf};
unsigned char Time_Buff[8]={4,3,10,2,1,10,2,1};
void DelayMs(unsigned int x)
{
	unsigned char j;
	while(x!=0)
	{
		x--;
		for(j=0;j<116;j++);
	}
}
int main()
{
	P2=0x33;
	P0=0xf0;
}