

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ADC_CONVERSION_MODE              ADC_CONTINUOUS_CONVERSION_MODE

/*OPTIONS:
			 ADC_SINGLE_CONVERSION_MODE
			 ADC_CONTINUOUS_CONVERSION_MODE
			 ADC_SCAN_MODE_SINGLE_CONVERSION_MODE
			 ADC_SCAN_MODE_CONTINUOUS_CONVERSION_MODE
 */
#define ADC_TRIGGER                      ADC_SWSTART

/*OPTIONS:
 	 	 	 ADC_SWSTART
 			 ADC_EXTERNAL_TR
 */
#define ADC_DATA_ALIGNMENT               RIGHT_ALIGNMENT

/*OPTIONS:
			RIGHT_ALIGNMENT
			LEFT_ALIGNMENT
 */
#define ADC_DMA                         DISABLE

/*OPTIONS:
			ENABLE
  			DISABLE
 */

#define ADC_CHANNEL_ID                   CHANNEL1

/*OPTIONS:
			CHANNEL0
			CHANNEL1
			CHANNEL2
			CHANNEL3
			CHANNEL4
			CHANNEL5
			CHANNEL6
			CHANNEL7
			CHANNEL8
			CHANNEL9

 */

#define ADC_CHANNEL_SAMPLE_TIME       CYCLES1

/*OPTIONS:
			CYCLES1             For 1.5   Cycles
			CYCLES2             For 7.5   Cycles
			CYCLES3             For 13.5  Cycles
			CYCLES4             For 28.5  Cycles
			CYCLES5             For 41.5  Cycles
			CYCLES6             For 55.5  Cycles
			CYCLES7             For 71.5  Cycles
			CYCLES8             For 239.5 Cycles
*/

#define	NO_OF_CONVERSIONS           1


#define  INTERNAL_TEMP                      DISABLE

#endif /* ADC_CONFIG_H_ */
