#ifndef  RCC_INTERFACE_H
#define  RCC_INTERFACE_H

#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2

void     RCC_voidSysClkInit(void);
void     RCC_voidEnablePerClk(u8 BusId, u8 PerId);
void     RCC_voidDisablePerClk(u8 BusId, u8 PerId);


/*******************************************************************/
//RCC_CR
/*
#define HSION      0
#define HSI_RDY    1
#define HSE_RDY    17
#define HSE_ON     16
#define HSE_BYP    18
#define CSS_ON     19
#define PLL_ON     24
#define PLL_RDY    25
*/
/*****************************************************************/

/****************************************************************/
//ٌRCC_CGGR
/*
#define SW1            0
#define SW2            1
#define SWS1           2
#define SWS2           3
#define HPRE           4
#define HPRE           5
#define HPRE           6
#define HPRE           7
#define PPRE1          8
#define PPRE1          9
#define PPRE1          10
#define PPRE2          11
#define PPRE2          12
#define PPRE2          13
#define PLL_SRC        16
#define PLL_XTPRE      17
#define PLL_MULL       18
#define PLL_MULL       19
#define PLL_MULL       20
#define PLL_MULL       21
*/
/***************************************************************/

#endif
