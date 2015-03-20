#include <LPC21xx.H>
#include "uart0.h"
typedef unsigned int uint32;
void delay()
{
    unsigned volatile long i,j;
    for(i=0;i<10000;i++)
    {
        for(j=0;j<50;j++);
    }
}
void ADC_Read()
{
    unsigned int val;
    ADCR|=0x01000000;//��ʼADת��
    do{
        val = ADDR;     //��ȡADת�����ݼĴ���
    }while((val&0x80000000)==0);//�ȴ�ADת������
    ADCR &=~0x01000000;
    val=(val>>6)&0x03ff;
    Put_Str("\n AIN0Result =0x");
    Put_Hex((val>>8)&0x0f);
    Put_Hex((val>>4)&0x0f);
    Put_Hex((val&0x0f));
}
int main()
{
    ADCR=0x002E0401;
    PINSEL0=0x20000005;
    PINSEL1=0x00000001;
    Uart0_Init();
    Put_Char('a');
    while(1)
    {
        ADC_Read();
        delay();
    }
}