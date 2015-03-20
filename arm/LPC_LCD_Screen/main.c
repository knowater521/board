#include <LPC21XX.H>
#define rs (1<<8)
#define rw (1<<9)
#define en (1<<10)
#define busy (1<<7) //p0.7
typedef unsigned char uint8;
uint8 ledup[]={"The LED Up"};
uint8 leddown[]={"The LED down"};
void delay(void)
{
    unsigned volatile long i,j;
    for(i=0;i<50000;i++)
    for(j=0;j<10;j++);
}
void Wait_LCD()
{
    unsigned char i;
    IO0CLR=0x00;
    IO0DIR=0xf00;
    while(1)
    {
        IO0CLR=rs;
        IO0SET=rw;
        IO0SET=en;
        //for(i=0;i<100;i++);
        if(!(IO0PIN&busy)) break;
        IO0CLR=en;
    }
    IO0DIR=0xfff;
}
void LCD_Op(uint8 dat)//命令
{
    Wait_LCD();
    //IO0CLR=0x000800;
    IO0CLR=rs;
    IO0CLR=rw;
    IO0CLR=0xff;
    IO0SET=dat;
    IO0SET=en;
    IO0CLR=en;
    //IO0CLR=0x000800;
}
void LCD_Data(uint8 dat)//数据
{
    Wait_LCD();
    IO0SET=rs;
    IO0CLR=rw;
    IO0CLR=0xff;
    IO0SET=dat;
    IO0SET=en;
    IO0CLR=en;
}
void LCD_Init(void)//初始化LCD
{
    LCD_Op(0x38);
    LCD_Op(0x38);
    LCD_Op(0x06);
    LCD_Op(0x0e);
    LCD_Op(0x01);
    
    LCD_Op(0x34);
    LCD_Op(0x34);
    LCD_Op(0x06);
    LCD_Op(0x0e);
    LCD_Op(0x01);
}
void LCD_Display(uint8 addr,uint8 *p)
{
    LCD_Op(addr);
    while(*p!=0)
    {
        LCD_Data(*(p++));
    }
}
void LCD_Clear(void)
{
    LCD_Op(0x01);
}

int main()
{
    LCD_Init();
    IO0DIR=0xfff;
    IO0CLR=0xfff;
    while(1)
    {
        IO0CLR=0x000800;//开LED
        LCD_Display(0x80,ledup);
        delay();
        LCD_Clear();
        IO0SET=0x000800;//关LED
        LCD_Display(0x80,leddown);
        delay();
        LCD_Clear();
    }
}
