
#ifndef DMA_PRIVATE.H
#define DMA_PRIVATE.H



typedef		struct
{
	u32		CCR;
	u32		            CNDTR;
	u32		            CPAR;
	u32		            CMAR;
	u32					Reserved;
}DMA_Channel;

typedef		struct
{
	u32				ISR;
	u32				IFCR;
	DMA_Channel		Channel[7]	;
}DMA1_Type;

#define		DMA1		((volatile DMA1_Type*)(0x40020000))



#endif

