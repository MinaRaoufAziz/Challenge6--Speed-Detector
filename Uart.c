/*
 * Uart.c
 *
 *  Created on: Feb 22, 2019
 *      Author: Mina
 */

#include "Uart.h"
#include "stdtypes.h"

void Uart_Init(void){
	SET_BIT(REG_DDRD, 1); // To Set PD1 to Output Direction
	CLEAR_BIT(REG_DDRD, 0); // To Set PD0 To Input Direction
	SET_BIT(REG_UCSRB, 4); // To Enable Receiver
	SET_BIT(REG_UCSRB, 3); // To Enable transmitter
	// For 8 Bit Character Size
	//WRITE_REGISTER(REG_UCSRC, 0x80); // To select The Control Register
	CLEAR_BIT(REG_UCSRB, 2);

	SET_BIT(REG_UCSRC, 1);
	SET_BIT(REG_UCSRC, 2);
	// To Disable Parity
	CLEAR_BIT(REG_UCSRC, 4);
	CLEAR_BIT(REG_UCSRC, 5);
	// To Select The Stop Bit
	CLEAR_BIT(REG_UCSRC, 3);
	// To Select Asynchronous Operation
	CLEAR_BIT(REG_UCSRC, 6);


	// To Disable Interrupt, as we working with polling operation
	CLEAR_BIT(REG_UCSRB, 7);
	CLEAR_BIT(REG_UCSRB, 6);
	CLEAR_BIT(REG_UCSRB, 5);
	// To Select Baud Rate Character Size of 9600
	WRITE_REGISTER(REG_UBRRL, 51);
	WRITE_REGISTER(REG_UBRRH, 0);


}
void Uart_Transmit(u8 Frame){
	while ((GET_BIT(REG_UCSRA, 5)) == 0){
		// Keep Stuck Here Till Flag is Empty
	}
	// To write Data In the Trasmitter Buffer
	WRITE_REGISTER(REG_UDR , Frame);
}
u8 Uart_Receive (void){
	u8 Frame;
	while ((GET_BIT(REG_UCSRA, 7)) == 0){
		// Keep Stuck Here Till Flag is Empty
	}
	Frame = GET_REGISTER(REG_UDR);
	return Frame;
}
