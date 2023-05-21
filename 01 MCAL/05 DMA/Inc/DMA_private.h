
typedef		struct
{
	u32         		CCR;
	u32					CNDTR;
	u32					CPAR;
	u32					CMAR;
	u32					Reserved;
}DMA_Channel;

typedef		struct
{
	u32				ISR;
	u32				IFCR;
	DMA_Channel		Channel[7]	;
}DMA1_Type;

/*SECOND MODIFICATION*/

typedef     enum
{
	    Ch_1 = 0,
		Ch_2,
		Ch_3,
		Ch_4,
		Ch_5,
		Ch_6,
		Ch_7
}Channel_Type;


#define		DMA1		((volatile DMA1_Type*)(0x40020000))





