#include <reg51.h>
#include <intrins.h>
#include "ZH.h"
#define uchar unsigned char
#define uint unsigned int
uchar num;
sbit RS=P2^2;//Rs为0命令，1数据
sbit RW=P2^1;//RW为1写 0读
sbit EN=P2^0;//使能端
sbit CS1=P2^4;//片选1低电平有效
sbit CS2=P2^3;//片选2低电平有效
void SelectScreen(uchar screen);
void delay(uint i)
{
	unsigned char k;
	while(--i)
	{
		for(k=0;k<250;k++);
	}
}
void Read_Busy()
{
	P3=0x00;
	RS=0;
	RW=1;
	EN=1;
	while(P0&0x80)
	EN=0;
}
void Write_Lcd_Command(uchar value)
{
	Read_Busy();
	RS=0;
	RW=0;
	P3=value;
	EN=1;
	_nop_();
	_nop_();
	EN=0;
}
void Write_Lcd_Data(uchar value)
{
	Read_Busy();
	RS=1;
	RW=0;
	P3=value;
	EN=1;
	_nop_();
	_nop_();
	EN=0;
}
void Set_Page(uchar page)
{
	page=0xb8|page;
	Write_Lcd_Command(page);
}
void Set_Line(uchar startline)
{
	startline=0xc0|startline;
	Write_Lcd_Command(startline);
}
void Set_Column(uchar column)
{
	column=column&0x3f;
	column=column|0x40;
	Write_Lcd_Command(column);
}
void SetOnOff(uchar on_off)
{
	on_off=0x3e|on_off;//3e关3f开
	Write_Lcd_Command(on_off);
}
void SelectScreen(uchar screen)
{
	switch(screen)
	{
		case 0:CS1=0;CS2=0;break;//全屏
		case 1:CS1=0;CS2=1;break;
		case 2:CS1=1;CS2=0;break;
		default: break;
	}
}
void ClearScreen(uchar screen)
{
	uchar i,j;
	SelectScreen(screen);
	for(i=0;i<8;i++)
	{
		Set_Page(i);
		Set_Column(0);
		for(j=0;j<64;j++)
		{
			Write_Lcd_Data(0xf1);
		}
	}
}
void Init_Lcd()
{
	Read_Busy();
	delay(500);
	SelectScreen(0);
	delay(500);
	SetOnOff(0);
	delay(500);
	SelectScreen(0);
	delay(500);
	SetOnOff(1);
	SelectScreen(0);
	delay(500);
	ClearScreen(0);
	delay(500);
	Set_Line(0);
	delay(500);
}
void Display(uchar ss,uchar page,uchar column,uchar *p)
{
	uchar i;
	SelectScreen(ss);
	Set_Page(page);
	Set_Column(column);
	for(i=0;i<16;i++)
	{
		Write_Lcd_Data(p[i]);
	}
	Set_Page(page+1);
	Set_Column(column);
	for(i=0;i<16;i++)
	{
		Write_Lcd_Data(p[i+16]);
	}
}
void main()
{
	Init_Lcd();
	while(1)
	{
	delay(200);
	ClearScreen(1);
	delay(200);
	//while(1);
	//delay(3000);
	Set_Line(0);
	Display(1,0,2*16,zhao);
	}
}