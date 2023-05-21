
#include "UART1_interface.h"

u8 data;
int main()
{
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 0); // RCC_AFIO
	RCC_voidEnablePerClk(RCC_APB2, 2); // RCC_GPIOA
	RCC_voidEnablePerClk(RCC_APB2, 14); // RCC_UART
	RCC_voidEnablePerClk(RCC_APB2, 4); // RCC_GPIOC
	
	DIO_voidSetPinDirection(PORTA, PIN9, GPIO_OUTPUT_2MHZ_AFPP); // TX
	DIO_voidSetPinDirection(PORTA, PIN10, GPIO_INPUT_FLOAT); // RX
	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP); // LED c13


	UART_init();

	UART_enableTX();
	UART_enableRX();



	while(1)
	{
		UART_TXdata('1');
		UART_RXdata(&data);

		if(data == '1')
		{
			DIO_voidSetPinValue(PORTC, PIN13, GPIO_LOW);
			_delay_ms(500);
			DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
			_delay_ms(500);

		}
	}
	return 0;
}

/*
#ifndef			AFIO_EXTICRX
			#define		AFIO_BASE_ADD		     (0x40010000)
			#define     AFIO_MAPR               *((u32 *)(AFIO_BASE_ADD+0x04))
			#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
            #define		AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
            #define		AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
            #define		AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))

		#endif
*/
