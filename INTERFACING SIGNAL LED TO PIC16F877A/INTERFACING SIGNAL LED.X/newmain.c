#include<pic.h>
#define _XTAL_FREQ 20000000  // IF I WANT TO USE DELAY-MS I HAVE TO USE THIS MICRO OTHER WAIS WILL SHOW ERRO

void main ()
{
    TRISB7 = 0;   //RB7 = output
    while(1)
    {
     RB7=1;
     __delay_ms(1000);
     RB7=0;
     __delay_ms(1000);
    }
}