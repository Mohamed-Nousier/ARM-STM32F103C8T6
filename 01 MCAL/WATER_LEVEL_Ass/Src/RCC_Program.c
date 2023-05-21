#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC_Interface.h"
#include "RCC_Config.h"






void     RCC_voidSysClkInit(void)
{
	#if(RCC_SYS_CLK == RCC_HSI)
		
		SET_BIT(RCC_CR, 0);            //HSION : Internal high-speed clock enable
		while(!(GET_BIT(RCC_CR, 1))); //wait for the ready flag set by hardware
		CLR_BIT(RCC_CFGR, 0); CLR_BIT(RCC_CFGR, 1);//HSI selected as system clock 
		
		 
	#elif(RCC_SYS_CLK == RCC_HSE)
		
		SET_BIT(RCC_CR, 18);//External high-speed clock bypass
		SET_BIT(RCC_CR, 16);//16 HSEON: HSE clock enable
		
		while(!(GET_BIT(RCC_CR, 17)); //wait for the ready flag set by hardware
		SET_BIT(RCC_CR, 19); //Clock security system enable
		SET_BIT(RCC_CFGR, 0); CLR_BIT(RCC_CFGR, 1);//HSE selected as system clock
		while(!(GET_BIT(RCC_CFGR, 2)); //wait for the ready flag set by hardware
		
		
	#elif(RCC_SYS_CLK == RCC_PLL)
		
		#if(PLL_CLK_SRC == HSI_CLK)
				CLR_BIT(RCC_CFGR, 16); // HSI oscillator clock / 2 selected as PLL input clock
		#elif(PLL_CLK_SRC == HSE_CLK)
			SET_BIT(RCC_CFGR, 16);//HSE oscillator clock selected as PLL input clock
			#if(HSE_CLK_DIV)
				SET_BIT(RCC_CFGR, 17);// HSE oscillator clock selected as PLL input clock
			#endif
		#endif
		
		#ifdef(PLL_MULL)
			#if(PLL_MULL_FAC == 2)
				CLR_BIT(RCC_CFGR,18);CLR_BIT(RCC_CFGR,19);CLR_BIT(RCC_CFGR,20);CLR_BIT(RCC_CFGR,21);
			#elif(PLL_MULL_FAC == 3)
				SET_BIT(RCC_CFGR,18);CLR_BIT(RCC_CFGR,19);CLR_BIT(RCC_CFGR,20);CLR_BIT(RCC_CFGR,21);
			#elif(PLL_MULL_FAC == 4)
				CLR_BIT(RCC_CFGR,18);SET_BIT(RCC_CFGR,19);CLR_BIT(RCC_CFGR,20);CLR_BIT(RCC_CFGR,21);
			#elif(PLL_MULL_FAC == 5)
				SET_BIT(RCC_CFGR,18);SET_BIT(RCC_CFGR,19);CLR_BIT(RCC_CFGR,20);CLR_BIT(RCC_CFGR,21);
			#endif
		#endif
		
		SET_BIT(RCC_CR, 24); //PLLON: PLL enable
		while(!(GET_BIT(RCC_CR, 25)); //wait for the ready flag set by hardware
		SET_BIT(RCC_CFGR, 1); CLR_BIT(RCC_CFGR, 0);//PLL selected as system clock
		while(!(GET_BIT(RCC_CFGR, 3)); //wait for the ready flag set by hardware
	#endif
	
	#if BUS_CONTROL
		/***********************************************/
		//AHB prescaler
		#if(AHB_PRE == SYSCLK_DIV_2)
			SET_BIT(RCC_CFGR, 7); // SYSCLK divided by 2
		#elif(AHB_PRE == SYSCLK_DIV_4) 
			SET_BIT(RCC_CFGR, 4); SET_BIT(RCC_CFGR, 7); // SYSCLK divided by 4
		#elif(AHB_PRE == SYSCLK_DIV_8) 
			SET_BIT(RCC_CFGR, 5); SET_BIT(RCC_CFGR, 7);// SYSCLK divided by 8
		#elif(AHB_PRE == SYSCLK_DIV_16) 
			SET_BIT(RCC_CFGR, 4); SET_BIT(RCC_CFGR, 5);SET_BIT(RCC_CFGR, 7);// SYSCLK divided by 16
		#elif(AHB_PRE == SYSCLK_DIV_64) 
			SET_BIT(RCC_CFGR, 6); SET_BIT(RCC_CFGR, 7);// SYSCLK divided by 64
		#endif
		/*************************************************/
			
		/*************************************************/
		//APB low-speed prescaler (APB1)	
		#if(APB_PRE1 == HCLK_DIV_2)
			SET_BIT(RCC_CFGR, 10); //HCLK divided by 2
		#elif(APB_PRE1 ==HCLK_DIV_4)
			SET_BIT(RCC_CFGR, 10);SET_BIT(RCC_CFGR, 8); //HCLK divided by 4
		#elif(APB_PRE1 ==HCLK_DIV_8)
			SET_BIT(RCC_CFGR, 10);SET_BIT(RCC_CFGR, 9); //HCLK divided by 8
		#elif(APB_PRE1 ==HCLK_DIV_16)
			SET_BIT(RCC_CFGR, 10); SET_BIT(RCC_CFGR, 9);SET_BIT(RCC_CFGR, 8);//HCLK divided by 16
		#endif
		/*************************************************/
		
		/*************************************************/
		//APB high-speed prescaler (APB2)
		#if(APB_PRE2 ==HCLK_DIV_2)
			SET_BIT(RCC_CFGR, 13); //HCLK divided by 2
		#elif(APB_PRE2 ==HCLK_DIV_4)
			SET_BIT(RCC_CFGR, 13);SET_BIT(RCC_CFGR, 11); //HCLK divided by 4
		#elif(APB_PRE2 ==HCLK_DIV_8)
			SET_BIT(RCC_CFGR, 13);SET_BIT(RCC_CFGR, 12); //HCLK divided by 8
		#elif(APB_PRE2 ==HCLK_DIV_16)
			SET_BIT(RCC_CFGR, 13); SET_BIT(RCC_CFGR, 12);SET_BIT(RCC_CFGR, 11);//HCLK divided by 16
		#endif
		/*************************************************/
	#endif
		
}


void     RCC_voidEnablePerClk(u8 BusId, u8 PerId)
{
	/*Range check*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR, PerId)  ;  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR, PerId) ;  break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR, PerId) ;  break;
		}
	}
	else{/*return error "out of range"*/}
}


void     RCC_voidDisablePerClk(u8 BusId, u8 PerId)
{
	/*Range check*/
	if(PerId < 32)
	{
		switch(BusId)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR, PerId)  ;  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR, PerId) ;  break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR, PerId) ;  break;
		}
	}
	else{/*return error "out of range"*/}
}
