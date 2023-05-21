/*
 * LCD.h
 *
 * Created: 1/15/2021 5:55:52 PM
 *  Author: 20115
 */ 


#ifndef LCD_H_
#define LCD_H_

#include	"Bit_Math.h"
#include	"Std_Types.h"
#include	"DIO_private.h"
#include    "DIO_interface.h"
#include    "RCC_Interface.h"
#include    "RCC_Config.h"


#define CONTROL_PORT  PORTC
#define DATA_PORT    *(GPIOB_ODR_u8+1)  // we don't need to put typedef enum {4- channels} because we will use the 4-bit at the same time

#define RS  PIN13
#define RW  PIN14
#define EN   PIN15


void GPIOA_ODR_Init();

void LCD_Init(void);  // this initialization is a bit wrong because we should give the function an option of (4-bit & 8-bit) mode 
void LCD_Cmd(u8 cmd);
void LCD_SendChar(u8 data); // form 0 to 127
void LCD_SendString(u8 * string);  // string likes signed character not unsigned
void LCD_SendStringPos(u8 * string, u8 line, u8 pos);
void LCD_CustomChar(u8 loc, s8 * msg);

#endif /* LCD_H_ */
