/*
 * _7_seg.c
 *
 * Created: 11/14/2020 8:29:20 AM
 *  Author: 20115
 */ 



#include "KeyPad.h"

u8 temp = 0xff;
int main(void)
{

	RCC_voidSysClkInit();

	RCC_voidEnablePerClk(RCC_APB2, 2);
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 4);


	LCD_Init();
	KEYPAD_Init();

    while(1)
    {
    	if(temp == 0xff )
    	{
    		temp = KEYPAD_Getkey();
    		if(temp != 0xff)
    		{
    			LCD_SendChar(temp);
    		}
    	}
    	else
    	{
    		temp = 0xff;
    	}
    }
    return 0;
}
