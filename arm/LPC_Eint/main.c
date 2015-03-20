#include <LPC21XX.H>
#define LEDCON 0x02000000
typedef unsigned int uint32;
//void IRQ_Eint(void) __attribute__ ((interrupt));
uint32 times=100;
void __irq IRQ_Eint(void)//Ӧ����������������
{
    times=18;
    while((EXTINT&0x02)!=0)
    {
        EXTINT=0x02;//����жϱ�־
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
    PINSEL0=0x20000000;//ѡ��EINT1����
    PINSEL1=0x00000000;
    //�жϲ���
    VICIntSelect=0;//ȫ���ж�����Ϊirq����ĳλΪһʱFIQ
    VICIntEnable=0x00008000;//ʹ��EINT��EINT115λ
    VICVectCntl1=0x2f;//15���ж�
    VICVectAddr1=(int)IRQ_Eint;//�����ӳ���
    EXTINT=0x07;
    while(1)
    {
        IO0CLR=LEDCON;
        delay100();
        IO0SET=LEDCON;
        delay100();
    }
}
