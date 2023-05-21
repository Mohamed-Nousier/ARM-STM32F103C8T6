#include "LCD.h"




int main(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 3); // GPIOB
	RCC_voidEnablePerClk(RCC_APB2, 2); // GPIOA
	RCC_voidEnablePerClk(RCC_APB2, 4); //GPIOC


	LCD_Init();

	LCD_SendString("THANKS TO : ");
	LCD_SendString("BOB");
	LCD_SendStringPos("MOHAMED", 2, 5);

	while(1)
	{

	}
	return 0;
}
