#ifndef  RCC_CONFIG_H
#define  RCC_CONFIG_H

#include "RCC_Private.h"


#define RCC_SYS_CLK    RCC_HSI  //options:  or RCC_HSE , RCC_PLL 
								 
#define PLL_CLK_SRC    HSI_CLK // options: or HSE_CLK
#define HSE_CLK_DIV        0   // options: or 1: it divided by 2
#define PLL_MULL           0   // options: or 1: it will be divided 
#define PLL_MULL_FAC       2   // options: from X2 .... X16


#define BUS_CONTROL        0        //options:  or 1: to unlock the code(configs) below it
#define AHB_PRE        SYSCLK_DIV_2 // options: or   SYSCLK_DIV_4,SYSCLK_DIV_8,SYSCLK_DIV_16,SYSCLK_DIV_64,SYSCLK_DIV_128,SYSCLK_DIV_256,SYSCLK_DIV_512
#define APB_PRE1       HCLK_DIV_2   // options: OR   HCLK_DIV_4 , HCLK_DIV_8 ,HCLK_DIV_16 
#define APB_PRE2       HCLK_DIV_2   // options: OR   HCLK_DIV_4 , HCLK_DIV_8 ,HCLK_DIV_16




#endif









