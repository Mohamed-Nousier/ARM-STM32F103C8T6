/*
 * _7_seg.c
 *
 * Created: 11/14/2020 8:29:20 AM
 *  Author: 20115
 */ 



#include "SSD.h"

int main(void)
{
	RCC_voidSysClkInit();
	RCC_voidEnablePerClk(RCC_APB2, 2); // GPIOA


	seg_vInit();
	u8 i = 0;
    while(1)
    {
        for( i=0; i<10; i++)
        {
        	seg_vDisplay(i);
        	_delay_ms(1000);
        }
    	//seg_vDisplay(5);



    }
}
