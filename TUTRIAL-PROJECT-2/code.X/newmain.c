#define _XTAL_FREQ 8000000

#define RS RB2
#define EN RB3
#define D4 RB4
#define D5 RB5
#define D6 RB6
#define D7 RB7

#include <xc.h>;
#include "lcd.h";

// BEGIN CONFIG
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG

int main()
{
    TRISB = 0x00;
    
    TRISD0 = 0;
    TRISD1 = 0;
    TRISD2 = 0;
    TRISD3 = 0;
    TRISD4 = 0;
    TRISD5 = 0;
    TRISD6 = 0;
    TRISD7 = 0;
    
    TRISC0 = 1;
    TRISC1 = 1;
    TRISC2 = 1;
    
    RD0 = 0;
    RD1 = 0;
    RD2 = 0;
    RD3 = 0;
    RD4 = 0;
    RD5 = 0;
    RD6 = 0;
    RD7 = 0;
    
    int a = 1;
    
    Lcd_Init();
    Lcd_Clear();
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String("Welcome");
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String("PRESS SW1");
        
    while(1) {
    if(RC0 == 1) {
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("PRESS SW2");
            __delay_ms(100);
            RD0 = 1;
            RD1 = 1;
            RD2 = 1;
            RD3 = 1;
            RD4 = 1;
            RD5 = 1;
            RD6 = 1;
            RD7 = 1;
            
        
        } else if(RC1 == 1) {
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("PRESS SW3");
            RD0 = 0;
            RD1 = 1;
            RD2 = 0;
            RD3 = 1;
            RD4 = 0;
            RD5 = 1;
            RD6 = 0;
            RD7 = 1;
        
        } else if(RC2 == 1) {
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("Press STOP");
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("THANK YOU SALAM...");
            RD0 = 1;
            RD1 = 0;
            RD2 = 1;
            RD3 = 0;
            RD4 = 1;
            RD5 = 0;
            RD6 = 1;
            RD7 = 0;
        }
    }
         
        

    return 0;
}