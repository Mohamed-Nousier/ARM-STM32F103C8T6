/*
 * _7_seg.h
 *
 * Created: 11/14/2020 8:30:52 AM
 *  Author: 20115
 */ 


#ifndef SSD_H_
#define SSD_H_

#include	"Bit_Math.h"
#include	"Std_Types.h"
#include	"DIO_private.h"
#include    "DIO_interface.h"
#include    "RCC_Interface.h"
#include    "RCC_Config.h"


void seg_vInit(void);
void seg_vDisplay(u8 data);




#endif /* 7_SEG_H_ */
