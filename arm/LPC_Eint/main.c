#include <LPC21XX.H>
#define LEDCON 0x02000000
typedef unsigned int uint32;
//void IRQ_Eint(void) __attribute__ ((interrupt));
uint32 times=100;
void __irq IRQ_Eint(void)//应该声明成这样！！
{
    times=18;
    while((EXTINT&0x02)!=0)
    {
        EXTINT=0x02;//清除中断标志
    }
    IO0SET=LEDCON;
    VICVectAddr=0;
}
void delay100(void)
{
    unsigned volatile i,j;
    for(i=0;i<10000;i++)
    {
        for(j=0;j<times;j++);
    }
    /*if(times>100)
    {times--;}
    else if(times<100)
    {times++;}
    */
}
int main(void)
{
    IO0DIR=LEDCON;
    PINSEL0=0x20000000;//选中EINT1功能
    PINSEL1=0x00000000;
    //中断部分
    VICIntSelect=0;//全部中断设置为irq，若某位为一时FIQ
    VICIntEnable=0x00008000;//使能EINT，EINT115位
    VICVectCntl1=0x2f;//15号中断
    VICVectAddr1=(int)IRQ_Eint;//设置子程序
    EXTINT=0x07;
    while(1)
    {
        IO0CLR=LEDCON;
        delay100();
        IO0SET=LEDCON;
        delay100();
    }
}
