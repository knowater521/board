#include <LPC21XX.H>
#define LED 0x000001
typedef unsigned int uint32;
typedef unsigned char uint8;
uint8 Timer0_Times=0;
void __irq Timer0_ISR();
void Timer0_Init()
{
    T0MR0=119999; //匹配寄存器 120000 00 为一秒
    T0MCR=3;//产生中断充值TC
    T0TCR=1;//使能定时器0
    VICVectAddr0=(unsigned long)Timer0_ISR;
    VICVectCntl0=0x20|4;//定时器为4号中断
    VICIntEnable=0x00000010;//开定时器0中断
}
void __irq Timer0_ISR()
{   
    uint32 i;
    Timer0_Times++;
    if(Timer0_Times==100)
    {
        i=IO0PIN;
        if((i&LED)==0)
        {
            IO0SET=LED;
        }
        else
        {
            IO0CLR=LED;
        }
        Timer0_Times=0;
    }
    T0IR=1;             //清除定时器0中断
    VICVectAddr=0;
}
int main()
{
    PINSEL0=0; //设置引脚为GPIO
    IO0DIR=LED;//
    IO0SET=LED;
    Timer0_Init();
    while(1);
}