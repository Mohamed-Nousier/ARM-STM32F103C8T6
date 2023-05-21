
#include "DMA_interface.h"





void	DMA1_voidChannelInit(Channel_Type Id, channel_config *ptr )
{
	/*
	Memory to Memory
	priority very high
	Size (Source & Destination) u32
	MINC, PINC enabled
	Direction read from Peripheral
	Transfere Complete Interrupt
	Channel Disable
	*/
	//DMA1 ->	Channel[Id].CCR = 0x00007AC2;
	
	SET_BIT(DMA1->Channel[0].CCR, 1);
	if(ptr->interrupt_type == COMPLETE_INT){SET_BIT(DMA1->Channel[0].CCR, 1);}
	
	if(ptr->data_direction == DATA_DIR_READ_PERI){CLR_BIT(DMA1 ->	Channel[Id].CCR, 4);}
	else if(ptr->data_direction == DATA_DIR_READ_MEM){SET_BIT(DMA1 ->	Channel[Id].CCR, 4);}
	
	if(ptr->circular_mode == CIRCULAR_MODE_EN){SET_BIT(DMA1 ->	Channel[Id].CCR, 5);}
	else if(ptr->circular_mode == CIRCULAR_MODE_DIS){CLR_BIT(DMA1 ->	Channel[Id].CCR, 5);}
	
	if(ptr->peripheral_inc == PER_INC_EN){SET_BIT(DMA1 ->	Channel[Id].CCR, 6);}
	else if(ptr->peripheral_inc == PER_INC_DIS){CLR_BIT(DMA1 ->	Channel[Id].CCR, 6);}
	
	if(ptr->memory_inc == MEM_INC_EN){SET_BIT(DMA1 ->	Channel[Id].CCR, 7);}
	else if(ptr->memory_inc == MEM_INC_DIS){CLR_BIT(DMA1 ->	Channel[Id].CCR, 6);}
	
	if(ptr->peripheral_size == PER_SIZE8){CLR_BIT(DMA1 ->	Channel[Id].CCR, 8); CLR_BIT(DMA1 ->	Channel[Id].CCR, 9);}
	else if(ptr->peripheral_size == PER_SIZE16){SET_BIT(DMA1 ->	Channel[Id].CCR, 8); CLR_BIT(DMA1 ->	Channel[Id].CCR, 9);}
	else if(ptr->peripheral_size == PER_SIZE32){CLR_BIT(DMA1 ->	Channel[Id].CCR, 8); SET_BIT(DMA1 ->	Channel[Id].CCR, 9);}
	
	if(ptr->memory_size == MEM_SIZE8){CLR_BIT(DMA1 ->	Channel[Id].CCR, 10); CLR_BIT(DMA1 ->	Channel[Id].CCR, 11);}
	else if(ptr->memory_size == MEM_SIZE16){SET_BIT(DMA1 ->	Channel[Id].CCR, 10); CLR_BIT(DMA1 ->	Channel[Id].CCR, 11);}
	else if(ptr->memory_size == MEM_SIZE32){CLR_BIT(DMA1 ->	Channel[Id].CCR, 10); SET_BIT(DMA1 ->	Channel[Id].CCR, 11);}
	
	if(ptr->channel_priority == Channel_LOW){CLR_BIT(DMA1 ->	Channel[Id].CCR, 12); CLR_BIT(DMA1 ->	Channel[Id].CCR, 13);}
	else if(ptr->channel_priority == Channel_MED){SET_BIT(DMA1 ->	Channel[Id].CCR, 12); CLR_BIT(DMA1 ->	Channel[Id].CCR, 13);}
	else if(ptr->channel_priority == Channel_HIGH){CLR_BIT(DMA1 ->	Channel[Id].CCR, 12); SET_BIT(DMA1 ->	Channel[Id].CCR, 13);}
	else if(ptr->channel_priority == Channel_VERY_HIGH){SET_BIT(DMA1 ->	Channel[Id].CCR, 12); SET_BIT(DMA1 ->	Channel[Id].CCR, 13);}
	
	if(ptr->mem2mem_mode == MEM2MEM_MODE_EN){SET_BIT(DMA1 ->	Channel[Id].CCR, 14);}
	else if(ptr->mem2mem_mode == MEM2MEM_MODE_DIS){CLR_BIT(DMA1 ->	Channel[Id].CCR, 14);}
	
	
}

void	DMA1_voidStartChannel(Channel_Type Id ,u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[Id].CCR,0);

	DMA1 -> Channel[Id].CPAR	=	SrcAdd;
	DMA1 -> Channel[Id].CMAR	=	DestAdd;
	
	/*	Load the Block Length				*/
	DMA1 -> Channel[Id].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  Enabled to strat transfere*/
	SET_BIT(DMA1 -> Channel[Id].CCR,0);
}








