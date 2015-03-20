#include <LPC21XX.H>
#define LED 0x000001
typedef unsigned int uint32;
typedef unsigned char uint8;
uint8 Timer0_Times=0;
void __irq Timer0_ISR();
void Timer0_Init()
{
    T0MR0=119999; //ƥ��Ĵ��� 120000 00 Ϊһ��
    T0MCR=3;//�����жϳ�ֵTC
    T0TCR=1;//ʹ�ܶ�ʱ��0
    VICVectAddr0=(unsigned long)Timer0_ISR;
    VICVectCntl0=0x20|4;//��ʱ��Ϊ4���ж�
    VICIntEnable=0x00000010;//����ʱ��0�ж�
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
    T0IR=1;             //�����ʱ��0�ж�
    VICVectAddr=0;
}
int main()
{
    PINSEL0=0; //��������ΪGPIO
    IO0DIR=LED;//
    IO0SET=LED;
    Timer0_Init();
    while(1);
}