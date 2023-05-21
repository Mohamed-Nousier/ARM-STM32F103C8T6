/*
 * _7_seg.c
 *
 * Created: 11/14/2020 8:29:20 AM
 *  Author: 20115
 */ 


#include "SSD.h"

u8 seg_arr[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x07f, 0x6f};
	
	
void seg_vInit(void)
{
	//DDRC = 0xff;

		DIO_voidSetPinDirection(PORTA, PIN0, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN1, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN2, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN6, GPIO_OUTPUT_2MHZ_PP);
		DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_PP);
}


void seg_vDisplay(u8 data)
{
	GPIOA_ODR = (seg_arr[data]);

}



