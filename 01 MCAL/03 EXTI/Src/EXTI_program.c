#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"EXTI_interface.h"
#include	"EXTI_private.h"

void		EXTI0_voidSetCallBack(void (*Fptr)(void));


#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI0_CallBack)	(void)	= NULL;
/****************************
 *
 * static	void	(*EXTI_CallBack[16])	(void)	=
 * {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
 *
 * **************************/

void		EXTI_voidInit( u8 port , u8 line_num)
{
		#ifndef			AFIO_EXTICRX
			#define		AFIO_BASE_ADD		     (0x40010000)
			#define		AFIO_EXTICR1			*((u32 *)(AFIO_BASE_ADD+0x08))
            #define		AFIO_EXTICR2			*((u32 *)(AFIO_BASE_ADD+0x0C))
            #define		AFIO_EXTICR3			*((u32 *)(AFIO_BASE_ADD+0x10))
            #define		AFIO_EXTICR4			*((u32 *)(AFIO_BASE_ADD+0x14))
		#endif
	if(line_num <16 )
		{
			switch(port)
			{
			case GPIO_PORTA :
				if(line_num >= 0 && line_num <= 3){AFIO_EXTICR1 = (0000<<line_num);};
				if(line_num >= 4 && line_num <= 7){AFIO_EXTICR2 = (0000<<line_num);};
				if(line_num >= 8 && line_num <= 11){AFIO_EXTICR3 = (0000<<line_num);};
				if(line_num >= 12 && line_num <= 15){AFIO_EXTICR4 = (0000<<line_num);}break;

			case GPIO_PORTB :
				if(line_num >= 0 && line_num <= 3)
				{
					switch(line_num)
					{
						case 0:
							AFIO_EXTICR1 |= (0b0001 << 0);break;
						case 1:
							AFIO_EXTICR1 |= (0b0001 << 4);break;
						case 2:
							AFIO_EXTICR1 |= (0b0001 << 8);break;
						case 3:
							AFIO_EXTICR1 |= (0b0001 << 12);break;


					}
				}

				if(line_num >= 4 && line_num <= 7)
				{
					switch(line_num)
					{
						case 4:
							AFIO_EXTICR2 |= (0b0001 << 0);break;
						case 5:
							AFIO_EXTICR2 |= (0b0001 << 4);break;
						case 6:
							AFIO_EXTICR2 |= (0b0001 << 8);break;
						case 7:
							AFIO_EXTICR2 |= (0b0001 << 12);break;


					}

				}

				if(line_num >= 8 && line_num <= 11)
				{
					switch(line_num)
					{
						case 8:
							AFIO_EXTICR3 |= (0b0001 << 0);break;
						case 9:
							AFIO_EXTICR3 |= (0b0001 << 4);break;
						case 10:
							AFIO_EXTICR3 |= (0b0001 << 8);break;
						case 11:
							AFIO_EXTICR3 |= (0b0001 << 12);break;


					}

				}
				if(line_num >= 12 && line_num <= 15)
				{
					switch(line_num)
					{
						case 12:
							AFIO_EXTICR4 |= (0b0001 << 0);break;
						case 13:
							AFIO_EXTICR4 |= (0b0001 << 4);break;
						case 14:
							AFIO_EXTICR4 |= (0b0001 << 8);break;
						case 15:
							AFIO_EXTICR4 |= (0b0001 << 12);break;


					}

				}break;

			case GPIO_PORTC :
				if(line_num >= 12 && line_num <= 15)
				{
					switch (line_num)
					{
						case 12:
							AFIO_EXTICR4 |= (0b0010 << 0);break;
						case 13:
							AFIO_EXTICR4 |= (0b0010 << 4);break;
						case 14:
							AFIO_EXTICR4 |= (0b0010 << 8);break;
						case 15:
							AFIO_EXTICR4 |= (0b0010 << 12);break;

					}
				}break;

			}

		/*************************/
		//Sense mode config
		//EXTI_voidChangeSenseMode(line_num,RISING_EDGE );
		/*************************/

		/**************************/
		//disable interrupt & clear pending flag
		CLR_BIT(EXTI -> IMR ,line_num);
		//SET_BIT(EXTI->PR ,line_num);
		/****************************/
	}
}

void		EXTI_voidEnableInt(u8 line_num)
{
	SET_BIT(EXTI -> IMR,line_num);
}


void		EXTI_voidDisableInt(u8 line_num)
{
	CLR_BIT(EXTI -> IMR ,line_num);
}




void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}



void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}



void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL)
	{
		EXTI0_CallBack = Fptr;
		/*EXTI_CallBack[ID_EXTI] = Fptr;*/
	}
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
//	 if(EXTI_CallBack[0]() != NULL)
//	 {
//		 EXTI_CallBack[0]();
//	 }

}

/*
void EXTI1_IRQHandler(void)
{
	//	 if(EXTI_CallBack[1]() != NULL)
	//	 {
	//		 EXTI_CallBack[1]();
	//	 }
}
// we will do that to the end
 */












