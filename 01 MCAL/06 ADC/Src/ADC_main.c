#include	"ADC_interface.h"
#include	"DIO_interface.h"
#include	"NVIC_interface.h"





volatile u32 tempertaure = 0;
volatile u16 ADC_value;
int main()
{
	

	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 9); // ADC _RCC
	RCC_voidEnablePerClk(RCC_APB2, 2); // GPIOA_RCC

	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_INPUT_ANALOG);

	ADC_voidInit();
	ADC_voidEnable();
	ADC_voidStart();
	

	 ADC_value = ADC_GETRead();

	while(1)
	{

		//tempertaure = ((1.43 - ((u32)(3.3*(u16)ADC_value/(float)4095))) / 0.0043) + 25;
		//_delay_ms(500);
		 //tempertaure = 357.558 - 0.187364*ADC_value;
		ADC_value = ADC_GETRead();
		_delay_ms(500);
	}

return 0;
}

