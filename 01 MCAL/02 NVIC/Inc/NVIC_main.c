#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"
void	EXTI0_IRQHandler(void);

int main(void)
{
	/*	System Clock Init			*/
	RCC_voidSysClkInit();
	
	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	
	/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);
	
	/*	Interrupt Initialization	*/
	NVIC_voidInit();
	
	/*	Set pending Flag EXTI0		*/
	NVIC_voidSetPendingFlag(6);
	
	/*	NVIC EXTI0 Enable 			*/
	NVIC_voidEnablePerInt(6);
	while(1)
	{
		
	}
	return 0;
}
//void 	__vector_1(void)
void	EXTI0_IRQHandler(void)
{
		/*		Led On		*/
		DIO_voidSetPinValue(PORTC3,PIN13,GPIO_LOW);
		_delay_ms(1000);
		/*		Led Off		*/
		DIO_voidSetPinValue(PORTC3,PIN13,GPIO_HIGH);
		_delay_ms(1000);
	/*	Clear EXTI0 Flag	*/
}


