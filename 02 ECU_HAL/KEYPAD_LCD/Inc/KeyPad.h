/*
 * KeyPad.h
 *
 * Created: 1/17/2021 5:53:00 PM
 *  Author: 20115
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include	"Bit_Math.h"
#include	"Std_Types.h"
#include	"DIO_private.h"
#include    "DIO_interface.h"
#include    "RCC_Interface.h"
#include    "RCC_Config.h"
#include    "LCD.h"


#define KEY_PORT     PORTA
#define NOT_PRESSED 0xFF


void KEYPAD_Init(void );
u8 KEYPAD_Getkey(void);



#endif /* KEYPAD_H_ */
