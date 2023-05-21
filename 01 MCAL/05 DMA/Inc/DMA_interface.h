#ifndef DMA_INTERFACE
#define DMA_INTERFACE

#include	"Std_Types.h"
#include	"Bit_Math.h"

#include    "DMA_private.h"
#include    "DMA_interface.h"



#define     COMPLETE_INT          1

#define     DATA_DIR_READ_PERI    0
#define     DATA_DIR_READ_MEM     1

#define     CIRCULAR_MODE_EN      1
#define     CIRCULAR_MODE_DIS     0

#define     PER_INC_EN            1
#define     PER_INC_DIS           0

#define     MEM_INC_EN            1
#define     MEM_INC_DIS           0

#define     PER_SIZE8             1
#define     PER_SIZE16            2
#define     PER_SIZE32            3

#define     MEM_SIZE8             0
#define     MEM_SIZE16            1
#define     MEM_SIZE32            2

#define     Channel_LOW           0 
#define     Channel_MED           1
#define     Channel_HIGH          2     
#define     Channel_VERY_HIGH     3

#define     MEM2MEM_MODE_EN       1
#define     MEM2MEM_MODE_DIS      0


/*we should create a struct before calling the DMA1_voidChannelInit()*/
typedef struct
{
	u8 interrupt_type;
	u8 data_direction;
	u8 circular_mode;
	u8 peripheral_inc;
	u8 memory_inc;
	u8 peripheral_size;
	u8 memory_size;
	u8 channel_priority;
	u8 mem2mem_mode;
}channel_config;

//channel_config *ptr;

void     	DMA1_voidChannelInit(Channel_Type Id, channel_config *ptr);
void	    DMA1_voidStartChannel(Channel_Type Id, u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);

#endif
