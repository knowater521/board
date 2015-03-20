#include <LPC21xx.H>
#define P0_1 0x02 /*P0.1*/

void delay(void)
{
	unsigned volatile long i;
	for(i=0;i<10000;i++);
}
int main()
{
    int P01_State;
    PINSEL0=0;
    IO0DIR=0x000001;
    IO0SET=0x000001;
    while(1)
    {
        P01_State=IO0PIN&P0_1;
        if(P01_State==0)
        {
            IO1CLR=0x000001;
            delay();
        }
        else
        {
            IO0SET=0x000001;
            delay();
        }
        /*IO0CLR=0x000001;
        delay();
        IO0SET=0x000001;
        delay();*/
    }
}