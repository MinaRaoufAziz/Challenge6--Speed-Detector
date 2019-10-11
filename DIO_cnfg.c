/*
 * DIO_cnfg.c
 *
 * Created on: Sep 20, 2019
 * 		Author: Mina Raouf
 */ 
#include "DIO_cnfg.h"

DIO_cnfg_t DIO_cnfg_arr [NUM_OF_PINS] =
{
	{PORT_B,PIN4,OUTPUT,LOW,NA,INITIALIZED},
	{PORT_A,PIN5,OUTPUT,LOW,NA,INITIALIZED},
	{PORT_D,PIN1,INPUT,NA,PULLUP,INITIALIZED}
};
