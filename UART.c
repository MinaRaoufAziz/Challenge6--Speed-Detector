/*
 * UART.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Rafaat
 */
#include "UART.h"

void UART_Init()
{
UCSRB |=1<<RXEN|1<<TXEN;
UCSRC |=1<<UCSZ1|1<<UCSZ0|1<<URSEL;
UBRRL = 0x33 ;
}
