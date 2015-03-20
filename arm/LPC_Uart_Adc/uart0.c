#include <LPC21XX.H>
#include "uart0.h"
#define CR 0x0d
int Put_Char(int ch)
{
    if(ch=='\n')
    {
        while(!(U0LSR&0x20));
        U0THR=CR;
    }
    while(!(U0LSR&0x20));
    return (U0THR=ch);
}
void SerialPuts(char *p)//向串口输出字符串
{
    while(0!=*p)
    {
        Put_Char(*p);
        p++;
    }
    Put_Char('\n');
}
void Uart0_Init()
{
    U0LCR=0x83;//8位数据，无验收
    U0DLL=122; //VPB 15MHz的时候波特率为9600
    U0LCR=0x03;//DLAB=0
}
void Put_Hex(int Hex)
{
    if(Hex>9)
        Put_Char('A'+Hex-10);
    else
        Put_Char('0'+Hex);
}
void Put_Str (char *p) 
{ 
  while (*p)
  {
    Put_Char(*p++); 
  }
}
