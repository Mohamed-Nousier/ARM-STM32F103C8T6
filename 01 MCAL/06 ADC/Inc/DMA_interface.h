#ifndef DMA_INTERFACE
#define DMA_INTERFACE




void	DMA1_voidChannelInit();
void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength);

#endif