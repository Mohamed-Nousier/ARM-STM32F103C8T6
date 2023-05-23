

#include  "SPI1_interface.h"

u8 data = 'A';
u8 *ptr;
int main()
{
	
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 12); // RCC_SPI1
	RCC_voidEnablePerClk(RCC_APB2,  2); // RCC_GPIOA
	RCC_voidEnablePerClk(RCC_APB2,  0); // RCC_AFIO
	RCC_voidEnablePerClk(RCC_APB2, 4); // RCC_GPIOC
	
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_AFPP);// PA5 (SCK) AF output Push Pull
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_AFPP); // PA7 (MOSI) AF output Push Pull
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT); // PA6 (MISO) Input mode (floating)
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_2MHZ_PP); // PA4 used for CS, GPIO Output

	DIO_voidSetPinDirection(PORTC, PIN13, GPIO_OUTPUT_2MHZ_PP);
	
	SPI_init();
	SPI_enable();

	

	while(1)
	{
		SPI1_SS_PIN_EN();
		SPI_TXdata( 'A');
		_delay_ms(100);
		SPI1_SS_PIN_DIS();
		SPI_RXdata ( ptr );

		if(*ptr == 'A')
		{
			DIO_voidSetPinValue(PORTC, PIN13, GPIO_LOW);
			_delay_ms(500);
			DIO_voidSetPinValue(PORTC, PIN13, GPIO_HIGH);
			_delay_ms(500);
		}
	}

	return 0;
}
