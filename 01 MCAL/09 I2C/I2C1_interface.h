#ifndef   I2C1_INTERFACE
#define   I2C1_INTERFACE

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "RCC_Config.h"
#include    "RCC_Interface.h"
#include	"DIO_interface.h"
#include	"DIO_private.h"
#include	"DIO_config.h"
#include    "I2C1_private.h"


void I2C1_Init(void);
void I2C1_Start(void);
void I2C1_Address(u8 Add);
void I2C1_Write(u8 data);
void I2C1_Read(u8 *data);
void I2C1_Stop();

#endif /*I2C1_INTERFACE*/