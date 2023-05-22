#ifndef ACD_INTERFACE_H
#define ACD_INTERFACE_H

#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "ADC_private.h"
#include    "ADC_config.h"
#include    "RCC_Config.h"
#include    "RCC_Interface.h"


void ADC_voidInit (void);
void ADC_voidEnable (void);
void ADC_voidStart(void);
void 	ADC_voidDisable(void);
u16 ADC_GETRead(void);


#endif 
