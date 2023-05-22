#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


typedef		struct
{
	u32		SR;
	u32		CR1;
	u32		CR2;
	u32		SMPR1;
	u32		SMPR2;	
	u32     JOFR1;
	u32     JOFR2;
	u32		JOFR3;
	u32 	JOFR4;
	u32     HTR;
	u32		LTR;
	u32     SQR1;
	u32     SQR2;
	u32     SQR3;
	u32     JSQR;
	u32     JDR1;
	u32     JDR2;
	u32		JDR3;
	u32     JDR4;
	u32		DR;

}ADC_Type;

#define ADC1   ((volatile ADC_Type*)(0x40012400))


#define ADC_SINGLE_CONVERSION_MODE                  0
#define ADC_CONTINUOUS_CONVERSION_MODE              1
#define ADC_SCAN_MODE_SINGLE_CONVERSION_MODE        2
#define ADC_SCAN_MODE_CONTINUOUS_CONVERSION_MODE    3


#define 	RIGHT_ALIGNMENT                         0
#define 	LEFT_ALIGNMENT                          1

#define 	ADC_SWSTART                             0
#define 	ADC_EXTERNAL_TR                         1

#define 	ENABLE                                  0
#define 	DISABLE                                 1


#define 	CYCLES1                                 0b000
#define 	CYCLES2                                 0b001
#define 	CYCLES3                                 0b010
#define 	CYCLES4                                 0b011
#define 	CYCLES5                                 0b100
#define 	CYCLES6                                 0b101
#define 	CYCLES7                                 0b110
#define 	CYCLES8                                 0b111


#define 	CHANNEL0                                0
#define 	CHANNEL1                                1
#define 	CHANNEL2                                2
#define 	CHANNEL3                                3
#define 	CHANNEL4                                4
#define 	CHANNEL5                                5
#define 	CHANNEL6                                6
#define 	CHANNEL7                                7
#define 	CHANNEL8                                8
#define 	CHANNEL9                                9

#define SEQ1                                        0
#define SEQ2                                        5
#define SEQ3                                        10
#define SEQ4                                        15
#define SEQ5                                        20
#define SEQ6                                        25

#endif
