#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"
#include "DIO_interface.h"

void _delay_ms(u32 ticks)
{
	for(u32 i =0; i<(1000000); i++)
			{
				asm("NOP");
			}
}


/*C13 ===> built in led */
int main(void)
{
	/***********************************/
	// system clock Init
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 4); // GPIOC
	RCC_voidEnablePerClk(RCC_APB2, 2); // GPIOA

	/***********************************/

	/**********************************/
	// C13 Direction "output @2MHZ push-pull"
	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);
	//A0....3Direction "output @2MHZ push-pull"
	DIO_voidSetPinDirection(PORTA, PIN0,GPIO_OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection(PORTA, PIN1,GPIO_OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection(PORTA, PIN2,GPIO_OUTPUT_2MHZ_PP );
	DIO_voidSetPinDirection(PORTA, PIN3,GPIO_OUTPUT_2MHZ_PP );
	/**********************************/
	while(1)
	{
		/*LED OFF*/
		DIO_voidSetPinValue(PORTC,PIN13, GPIO_LOW );
		_delay_ms(1000);

		/*A0....3*/
		/*
		DIO_voidSetPinValue(PORTA,PIN0, GPIO_HIGH );
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA,PIN1, GPIO_HIGH );
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA,PIN2, GPIO_HIGH );
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA,PIN3, GPIO_HIGH );
		_delay_ms(1000);
		*/
		/*Delay OFF*/



		/*LED OFF*/
		DIO_voidSetPinValue(PORTC,PIN13, GPIO_HIGH );
		_delay_ms(1000);
		/*A0....3*/
		/*
		DIO_voidSetPinValue(PORTA,PIN0, GPIO_LOW );
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA,PIN1, GPIO_LOW );
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA,PIN2, GPIO_LOW );
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTA,PIN3, GPIO_LOW );
		_delay_ms(1000);
		*/
		/*Delay OFF*/


		/**********************************************/


	}
	return 0;
}
