
#include "ADC_interface.h"

void ADC_voidInit (void)
{
	/***** Set the Conversion Mode *******/
	#if(ADC_CONVERSION_MODE == ADC_CONTINUOUS_CONVERSION_MODE)
	{
		CLR_BIT(ADC1->CR2,1);
	}
	#elif(ADC_CONVERSION_MODE == ADC_CONTINUOUS_CONVERSION_MODE)
	{
		SET_BIT(ADC1->CR2,1);
	}
	#elif(ADC_CONVERSION_MODE == ADC_SCAN_MODE_SINGLE_CONVERSION_MODE)
	{
		SET_BIT(ADC1->CR1,8);
		CLR_BIT(ADC1->CR2,1);
	}
	#elif(ADC_CONVERSION_MODE == ADC_SCAN_MODE_CONTINUOUS_CONVERSION_MODE)
	{
		SET_BIT(ADC1->CR1,8);
		SET_BIT(ADC1->CR2,1);
	}
	#endif

	/*****************set ADC trigger********************/

	#if(ADC_TRIGGER == ADC_SWSTART)
	{
		SET_BIT(ADC1->CR2,20); // External trigger conversion mode so we can choose ADC_SWSTART

		SET_BIT(ADC1->CR2,17);
		SET_BIT(ADC1->CR2,18);
		SET_BIT(ADC1->CR2,19);
	}
	#elif(ADC_TRIGGER == ADC_EXTERNAL_TR)
	{
		/*we have others resources*/
		/*OPTIONS:
		 	    ADC_TIMER1CC1
				ADC_TIMER1CC2
				ADC_TIMER1CC3
				ADC_TIMER2CC2
				ADC_TIMER3TRGO
				ADC_TIMER4CC4
				ADC_EXTI11

		 */
	}
	#endif

	/********************ADC data alignment*****************************/
	#if(ADC_DATA_ALIGNMENT == RIGHT_ALIGNMENT)
		{
			CLR_BIT(ADC1->CR2,11);
		}
	#elif(ADC_DATA_ALIGNMENT == LEFT_ALIGNMENT)
		{
			SET_BIT(ADC1->CR2,11);
		}
	#endif

	/***********************DMA for ADC***********************/

	#if(ADC_DMA == ENABLE)
		{
			SET_BIT(ADC1->CR2,8);
		}
	#elif(ADC_DMA == DISABLE )
		{
			CLR_BIT(ADC1->CR2,8);
		}
	#endif

	/*************************internal temperature sensor(if enable) ****************************/

	#if(INTERNAL_TEMP == ENABLE)
		{
			/*for temperature sensor */
			ADC1->SMPR1 |= (7<<18);  // Sampling time (71.5 cycles) of 7 us for channel 16.. It should be <17.1 us
			ADC1->CR2 |= (1<<23);//Set the TSVREFE Bit to wake the sensor
			ADC1->SQR3 |= (16<<SEQ1); //SEQ1 for Channel_16
		}
	#endif


	/**********************************set conversion time(sample time) ********************/
	#if(ADC_CHANNEL_ID < 10)
		{
			ADC1->SMPR2 |= ( ADC_CHANNEL_SAMPLE_TIME << (ADC_CHANNEL_ID*3) );
		}
	#endif

	/********************************no of conversion**********************************/
	#if(NO_OF_CONVERSIONS >= 1)
		{
			ADC1->SQR1 |= (NO_OF_CONVERSIONS<<20);   // SQR1_L
		}
	#endif

	/**************************channel sequence********************************/
	#if(ADC_CHANNEL_ID < 10)
		{
			ADC1->SQR3 |= ( ADC_CHANNEL_ID << SEQ2);
		}
	#endif
		/**************************start calibration*************************/
		SET_BIT(ADC1->CR2 , 2);
			_delay_ms(10);
}



void ADC_voidEnable(void)
{
	/************** STEPS TO FOLLOW *****************
		1. Enable the ADC by setting ADON bit in CR2
		2. Wait for ADC to stabilize (approx 10us)
		************************************************/
		ADC1->CR2 |= 1<<0;   // ADON =1 enable ADC1

		u32 delay = 10000;
		while (delay--);
}
void 	ADC_voidDisable(void)
{
	CLR_BIT(ADC1->CR2,0);
	u32 delay = 10000;
	while (delay--);

}
void ADC_voidStart(void)
{
	/************** STEPS TO FOLLOW *****************
		1. Clear the Status register
		2. Start the Conversion by Setting the SWSTART bit in CR2
		*************************************************/
		ADC1->SR = 0;                      // Clear Status register
		#if(ADC_TRIGGER == ADC_EXTERNAL_TR)
		{
			ADC1->CR2 |= (1<<20);              // Conversion on external event enabled
		}
		#endif
		ADC1->CR2 |= 1<<22;                // Start conversion
}
u16 ADC_GETRead(void)
{
	return ADC1->DR;
}






















