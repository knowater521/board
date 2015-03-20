#include <LPC21XX.H>
#include "uart0.h"
#define ST_CP 0x00000100
typedef unsigned int uint32;
typedef unsigned char uint8;
char Status[]="Every thing is fine";
uint8 const DISP_TAB[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
uint8 Rev_Data;
void delay(void)
{
    unsigned volatile long i,j;
    for(i=0;i<10000;i++)
    for(j=0;j<20;j++);
}
void SPI_Init(void)
{
    S0SPCCR=0x52; //设置时钟分频
    S0SPCR=0x30; //设置接口模式
}
uint8 SPI_Char(uint8 data)
{
    IO0CLR=ST_CP; //片选
    S0SPDR=data;
    while(0==(S0SPSR&0x80)); //等待SPIF置位
    IO0SET=ST_CP;
    return (S0SPDR);
}
int main(void)
{
    uint8 i;
    PINSEL0=0x00005505;//引脚开串口SPI UART
    IO0DIR=ST_CP;
    Uart0_Init();
    SPI_Init();
    while(1)
    {
        for(i=0;i<16;i++)
        {
            if(i<10) {Put_Char(i+'0');}
            else {Put_Char(i+7+'0');}
            Rev_Data=SPI_Char(DISP_TAB[i]);//发送显示数据
            delay();
        }
        SerialPuts(Status);
    }
}