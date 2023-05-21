#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"


#include "DMA_interface.h"





u32	Processor_Arr1[1000];
u32	Processor_Arr2[1000];

u32	DMA_Arr3[1000];
u32	DMA_Arr4[1000];

channel_config ch = {
		COMPLETE_INT,
		DATA_DIR_READ_PERI,
		CIRCULAR_MODE_DIS,
		PER_INC_EN,
		MEM_INC_EN,
		PER_SIZE32,
		MEM_SIZE32,
		Channel_VERY_HIGH,
		MEM2MEM_MODE_EN
};
channel_config *ptr = & ch;

int main()
{
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr1[i]	=	i;
		DMA_Arr3[i]			=	i;
	}
	
	/*	System init			*/
	RCC_voidSysClkInit();

	DMA1_voidChannelInit(Ch_1, ptr);
	/*	DMA1 Channel Transfere Round	*/
	DMA1_voidStartChannel(Ch_1, DMA_Arr3,DMA_Arr4,1000);
	
	/*	Processor Transfere Round	*/
	for(u16 i = 0 ; i < 1000 ; i++)
	{
		Processor_Arr2[i]	=	Processor_Arr1[i];
	}
	
	

	while(1)
	{

	}

return 0;
}

void	DMA1_Channel1_IRQHandler()
{
	/*		Toggle led		*/
	volatile u8 x;
		x = GET_BIT(PORTB,1);
}
