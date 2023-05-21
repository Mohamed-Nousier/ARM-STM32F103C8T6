#ifndef   UART1_PRIVATE.H
#define   UART1_PRIVATE.H

typedef struct
{
	u32     SR;
	u32     DR;
	u32     BBR;
	u32     CR1;
	u32     CR2;
	u32     CR3;
	u32     GTPR;
}UART_Type;

#define    UART1      ((volatile UART_Type *)(0x40013800))


#endif 
