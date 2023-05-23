#ifndef   SPI1_INTERFACE_H
#define   SPI1_INTERFACE_H

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "RCC_Config.h"
#include    "RCC_Interface.h"
#include	"DIO_interface.h"
#include	"DIO_private.h"
//#include	"DIO_config.h"
#include    "SPI1_private.h"





void SPI_init(void);
void SPI_enable(void);
void SPI_disable(void);
void SPI_TXdata(u8 data);
void SPI_RXdata (u8 *data );
void SPI1_SS_PIN_EN(void);
void SPI1_SS_PIN_DIS(void);


#endif 
