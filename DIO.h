/*
 * DIO.h
 *
 * Created on: Sep 20, 2019
 *      Author: Mina Raouf
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "registers.h"
#include "stdtypes.h"
#include "DIO_cnfg.h"

typedef enum{NOK,OK}Std_Func_t;

#define MAX_NUM_OF_PINS (uint8) 32

Std_Func_t DIO_init (PINS_t input);

Std_Func_t DIO_write (uint8 port,uint8 pin,uint8 val, PINS_t input);

Std_Func_t DIO_read (uint8 port,uint8 pin,uint8 * Pval, PINS_t input);

#endif /* DIO_H_ */
