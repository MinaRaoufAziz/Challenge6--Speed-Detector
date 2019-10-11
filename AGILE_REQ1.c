


#include "DIO.h"
#include "UART.h"
#include <avr/interrupt.h>

#include "LCD.h"


int main(void)
{
//DDRC &= ~(1<<PIN4);
	LCD_init();
	DIO_init(1);
	UART_Init();
uint8_t x='a';
LCD_displayStrRowCol(0,0,"NEW DATA:");
	while(1)
	{
		if(DIO_read(PORT_C,PIN4))
				{
		while(!(UCSRA&(1<<UDRE)));
		UDR=x;
		_delay_ms(250);
		LCD_gotoRawCol(0,10);


		LCD_displayChar(x++);
				}

	}
}


