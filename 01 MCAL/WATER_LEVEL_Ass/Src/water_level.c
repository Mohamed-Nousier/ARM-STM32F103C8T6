#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"DIO_interface.h"
#include    "RCC_Config.h"
#include    "RCC_Interface.h"


int main(void)
{
 	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 2); // RCC_GPIOA
	RCC_voidEnablePerClk(RCC_APB2, 3); // RCC_GPIOB
	RCC_voidEnablePerClk(RCC_APB2, 4); // RCC_GPIOC

	/*inputs from water level*/
	DIO_voidSetPinDirection(PORTB, PIN5, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_INPUT_PULL_UP_DOWN);
	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_INPUT_PULL_UP_DOWN);

	/*output indicates water level on leds*/
	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_OUTPUT_2MHZ_PP); // 25%
	DIO_voidSetPinDirection(PORTA, PIN11, GPIO_OUTPUT_2MHZ_PP); // 50%
	DIO_voidSetPinDirection(PORTA, PIN12, GPIO_OUTPUT_2MHZ_PP); // 100%

    /* Loop forever */
	for(;;)
	{
		if (DIO_u8GetPinValue(PORTB, PIN5) == GPIO_HIGH )
		{
			DIO_voidSetPinValue(PORTA, PIN10, GPIO_HIGH);
			_delay_ms(500);
		}
		else{DIO_voidSetPinValue(PORTA, PIN10, GPIO_LOW);}
		if(DIO_u8GetPinValue(PORTB, PIN6) == GPIO_HIGH)
		{
			DIO_voidSetPinValue(PORTA, PIN10, GPIO_HIGH);
			_delay_ms(500);
			DIO_voidSetPinValue(PORTA, PIN11, GPIO_HIGH);
			_delay_ms(500);
		}
		else{DIO_voidSetPinValue(PORTA, PIN10, GPIO_LOW); DIO_voidSetPinValue(PORTA, PIN11, GPIO_LOW);}
		if(DIO_u8GetPinValue(PORTB, PIN6) == GPIO_HIGH)
		{
			DIO_voidSetPinValue(PORTA, PIN10, GPIO_HIGH);
			_delay_ms(500);
			DIO_voidSetPinValue(PORTA, PIN11, GPIO_HIGH);
			_delay_ms(500);
			DIO_voidSetPinValue(PORTA, PIN12, GPIO_HIGH);
			_delay_ms(500);
		}
		else{DIO_voidSetPinValue(PORTA, PIN10, GPIO_LOW); DIO_voidSetPinValue(PORTA, PIN11, GPIO_LOW);DIO_voidSetPinValue(PORTA, PIN12, GPIO_LOW);}

	}

	return 0;
}
