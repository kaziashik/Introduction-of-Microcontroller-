#include<pic.h>
#define _XTAL_FREQ 20000000

#define RS RD0
#define RW RD1
#define EN RD2

void  lcd_data(unsigned char data)
{
    PORTC =data;
    RS =1;
    RW=0;
    EN=1;
    __delay_ms(5);
    EN=0;
}

void  lcd_command(unsigned char command)
{
    PORTC =command;
    RS =0;
    RW=0;
    EN=1;
    __delay_ms(50);
    EN=0;
}

void lcd_string (const unsigned char *string,unsigned char length)
{
    unsigned char i;
    for(i=0;i<length;i++)
    {
        lcd_data(string[i]);
    }
}


void lcd_initializ()
{
    lcd_command(0x38); //16 col 2 row format
    lcd_command(0x06); // uto increment carsar wen the current position of lcde 
    lcd_command(0x0C); // display on ad carsar off
    lcd_command(0x01); // clear screen
}



void main()
{
    
    
    TRISC= 0x00;
    TRISD=0x00;
     lcd_initializ();
    while(1)
    {
       lcd_command(0x83);
       lcd_string("EMBEDDED",8);
       lcd_command(0xC3);
       lcd_string("SYSTEMS",7);
    }
}



        