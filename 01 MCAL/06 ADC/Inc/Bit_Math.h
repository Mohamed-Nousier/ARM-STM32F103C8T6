#ifndef  BIT_MATH_H
#define  BIT_MATH_H

#include "Std_Types.h"


#define  SET_BIT(REG,BIT)     (REG |= (1<<BIT))
#define  CLR_BIT(REG,BIT)     (REG &=~ (1<<BIT))
#define  TOGGLE_BIT(REG,BIT)  (REG ^= (1<<BIT))
#define  GET_BIT(REG,BIT)     ((REG>>BIT)& 0X01)
		 
//#define  BIT_LOW              ((u8)0)
//#define  BIT_HIGH             ((u8)1)


void _delay_ms(u32 ticks);

void _delay_us(u32 ticks);

#endif
