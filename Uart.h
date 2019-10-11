/*
 * Uart.h
 *
 *  Created on: Feb 22, 2019
 *      Author: Mina
 */

#ifndef UART_H_
#define UART_H_

#include "STDTYPES.h"
#include "util.h"
#include "Registers.h"

void Uart_Init(void);
void Uart_Transmit(u8);
u8 Uart_Receive (void);


#endif /* UART_H_ */
