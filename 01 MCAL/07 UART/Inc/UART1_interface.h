#ifndef    UART1_INTERFACE.H
#define    UART1_INTERFACE.H

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "RCC_Config.h"
#include    "RCC_Interface.h"
#include	"DIO_interface.h"
#include	"DIO_private.h"
//#include	"DIO_config.h"
#include    "UART1_private.h"
#include    "UART1_config.h"

void UART_init(void);
void UART_enableTX(void);
void UART_enableRX(void);
void UART_TXdata(u8 data);
void UART_RXdata (u8 *data );
void UART1_voidSendString(u8 * const str);
void UART1_StrReceiveString(u8 *ptr);


#endif 
