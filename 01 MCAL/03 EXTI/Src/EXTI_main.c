#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include	"DIO_interface.h"
#include	"NVIC_interface.h"
#include   "EXTI_interface.h"
#include 	"EXTI_private.h"



void EXTI_TASK(void);

int main()
{
		/*	System Clock Init			*/
		RCC_voidSysClkInit();

		/*	Enable RCC for AFIO		*/
		RCC_voidEnablePerClk(RCC_APB2,0);
		RCC_voidEnablePerClk(RCC_APB2,2);
		/*	Enable RCC for GPIOC		*/
		RCC_voidEnablePerClk(RCC_APB2,4);

		/*	A0 Direction 	"Input @  Pull-up"	*/
		DIO_voidSetPinDirection(PORTA,PIN0,GPIO_INPUT_PULL_UP_DOWN);
		DIO_voidSetPinValue(PORTA, PIN0, GPIO_HIGH);
		/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
		DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

		/*	Interrupt Initialization	*/
		NVIC_voidInit();

		/*EXTI Initialization*/
		EXTI_voidInit( GPIO_PORTA ,EXTI0);

		/*EXTI enable but waiting for the flag*/
		EXTI_voidEnableInt(EXTI0);



		/*	NVIC EXTI0 Enable 			*/
		NVIC_voidEnablePerInt(6);

	while(1)
	{
		/*Check the push button */
		if((DIO_u8GetPinValue(PORTA, PIN0))==0)
		{
			EXTI0_voidSetCallBack(EXTI_TASK);

		}
	}
	return 0;
}



void EXTI_TASK(void)
{


	DIO_voidSetPinValue(PORTC,PIN13,GPIO_LOW);
	_delay_ms(1000);
			/*		Led Off		*/
	DIO_voidSetPinValue(PORTC,PIN13,GPIO_HIGH);
	_delay_ms(1000);

	/*	Clear EXTI0 Flag	*/
	SET_BIT(EXTI -> PR, EXTI0);
}


