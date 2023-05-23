/*
 * LCD.c
 *
 * Created: 1/15/2021 5:55:22 PM
 *  Author: 20115
 */ 

#include "LCD.h"



void LCD_Init(void)
{
		DIO_voidSetPinDirection(CONTROL_PORT,RS , GPIO_OUTPUT_2MHZ_PP) ;
		DIO_voidSetPinDirection(CONTROL_PORT,RW , GPIO_OUTPUT_2MHZ_PP) ;
		DIO_voidSetPinDirection(CONTROL_PORT,EN , GPIO_OUTPUT_2MHZ_PP) ;

		DIO_voidSetPinDirection(PORTB ,PIN12 , GPIO_OUTPUT_2MHZ_PP) ;
		DIO_voidSetPinDirection(PORTB ,PIN13 , GPIO_OUTPUT_2MHZ_PP) ;
		DIO_voidSetPinDirection(PORTB ,PIN14 , GPIO_OUTPUT_2MHZ_PP) ;
		DIO_voidSetPinDirection(PORTB ,PIN15 , GPIO_OUTPUT_2MHZ_PP) ;


		_delay_ms(40); // more than 15ms

		LCD_Cmd(0x33);
		_delay_us(150);
		LCD_Cmd(0x32);
		LCD_Cmd(0x28); // function set
		LCD_Cmd(0x0C);// display on / off
		LCD_Cmd(0x01); // clear display
		LCD_Cmd(0x06); // entry point

		_delay_ms(1000); // important to implement
	
}
void LCD_Cmd(u8 cmd)  // we will start with this function
						// because LCD_Init(void) will need some command to work
{
/************************ high nibble*************************/
	//DIO_WriteChannel(RS, STD_LOW);
	DIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_LOW) ;
	DIO_voidSetPinValue(CONTROL_PORT,RW , GPIO_LOW) ;

	DATA_PORT = (DATA_PORT & 0x0F)|(cmd	& 0xF0);


	//DIO_WriteChannel(E, STD_HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
	_delay_us(100);
	//DIO_WriteChannel(E, STD_LOW);
	DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;

	_delay_ms(2);

/************************ low nibble*************************/
	//DIO_WriteChannel(RS, STD_LOW);
	DIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_LOW) ;


	DATA_PORT = (DATA_PORT & 0x0F)|(cmd	<< 4);
	//DIO_WriteChannel(E, STD_HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
	_delay_us(100);
	//DIO_WriteChannel(E, STD_LOW);
	DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;

	_delay_ms(2);


}
void LCD_SendChar(u8 data)
{
/************************ high nibble*************************/

	//DIO_WriteChannel(RS, STD_HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_HIGH) ;
	DIO_voidSetPinValue(CONTROL_PORT,RW , GPIO_LOW) ;

	DATA_PORT = (DATA_PORT & 0x0F)|(data & 0xF0);


	//DIO_WriteChannel(E, STD_HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
	_delay_us(100);
	//DIO_WriteChannel(E, STD_LOW);
	DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;

	_delay_ms(2);

/************************ low nibble*************************/

	//DIO_WriteChannel(RS, STD_HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,RS , GPIO_HIGH) ;


	DATA_PORT = (DATA_PORT & 0x0F)|(data << 4);
	
	

	//DIO_WriteChannel(E, STD_HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,EN , GPIO_HIGH);
	_delay_us(100);
	//DIO_WriteChannel(E, STD_LOW);
	DIO_voidSetPinValue(CONTROL_PORT,EN ,GPIO_LOW) ;

	_delay_ms(2);

}
void LCD_SendString(u8 * string)  // sint8 string[i] = "mina" , char * string
{
	u8 i = 0;
	while(string[i] != '\0')
	{
		LCD_SendChar(string[i]);
		i++;
	}
}

void LCD_SendStringPos(u8 * string, u8 line, u8 pos)
{
	switch(line)
	{
		case 1: 
			LCD_Cmd((0x80 | (pos&0x0f)));
			LCD_SendString(string);
		break;
		
		case 2:
			LCD_Cmd((0xC0 | (pos&0x0f)));
			LCD_SendString(string);
		break;
	}
}

void LCD_CustomChar(u8 loc, s8 * msg) // this function just save not print what we want
{
	u8 i;
	if (loc < 8) // we make this to make sure that we will write inside the right 8 places
	{
		LCD_Cmd(0x40 + (loc*8)); // start the specific place
		for (i=0; i<8; i++) 
		{
			LCD_SendChar(msg[i]);
		}
	}
}

