
#include  "UART1_interface.h"

/*
in the main:
1- Enable UART(1,2,3) RCC
2- GPIO => Alternate Function A9 (Tx) Direction OUTPUT AF_PP
3- GPIO A10 (Rx) Direction INPUT_FLOAT
*/

void UART_init() 
{
	/*UART ENABLE BIT*/
		SET_BIT(UART1->CR1,13);
	#if (Fck == 8000000)
	{
		#if (BaudRate == 9600)
		{
			UART1->BBR = 0x0341 ;
		}
		#elif (BaudRate == 115200)
		{
			UART1->BRR = 0x45;
		}
		#endif
	}
	#elif (Fck == 72000000)
	{
		#if (BaudRate == 9600)
		{
			UART1->BRR = 0x1D4C;
		}
		#elif (BaudRate == 115200)
		{
			UART1->BRR = 0x271;
		}
		#endif
	}
	#endif
	
	
	#if(WORD_LENGTH == _1_START_BIT_8_DATA_BITS)
	{
		CLR_BIT(UART1->CR1,12);
	}
	#elif(WORD_LENGTH == 1_START_BIT_9_DATA_BITS)
	{
		SET_BIT(UART1->CR1,12);
	}
	#endif
	
	#if(STOP_BITS == _1_STOP_BIT)
	{
		CLR_BIT(UART1->CR2,12);
		CLR_BIT(UART1->CR2,13);
	}
	#elif(STOP_BITS == _2_STOP_BIT)
	{
		CLR_BIT(UART1->CR2,12);
		SET_BIT(UART1->CR2,13);
	}
	#endif
	

}
  
//enable transmitter
void UART_enableTX(void) 
{
	/*transmitter enable*/
	SET_BIT(UART1->CR1,3);	
}
//enable receiver
void UART_enableRX(void) 
{
	/*reciever enable*/
	SET_BIT(UART1->CR1,2);
}
//transmit data
void UART_TXdata(u8 data)
{
//	 while(!get_bit(UCSRA,UCSRA_UDRE)) ;
//	 UDR = data ;
	 while(!(GET_BIT(UART1->SR, 7)));
	 UART1->DR = data;
	 //while(!(GET_BIT(UART1->SR, 6)));
}
//receive data
void UART_RXdata (u8 *data ) {
//	while(!get_bit(UCSRA ,UCSRA_RXC)) ;
//	*data = UDR ;
	
	while(!(GET_BIT(UART1->SR , 5)));
	*data = UART1->DR;
}

void UART1_voidSendString(u8 * const str)
{
	u8 i=0;
	while(str[i] != '\0')
	{
		UART_TXdata(str[i]);
		i++;
	}
}
void UART1_StrReceiveString( u8 *str)
{
	u8 i=0;
	while(str[i] != '\0')
	{
		UART_RXdata (str[i]);
		i++;
	}
}



/*
1- to connect Rx with Tx pin

Sendchar ('a');
u8 Rx = reciveChar();
if(Rx == 'a')
{
	Led on
	Delay();
}
else
{
	Led Off
	Delay();
}
*/
