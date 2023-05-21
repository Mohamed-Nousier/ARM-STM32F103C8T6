

#include  "SPI1_interface.h"


void SPI_init()
{
	/* CPOL=1, CPHA=1*/
	CLR_BIT(SPI1->CR1,0 );
	CLR_BIT(SPI1->CR1,1 );
	
	/*Master Mode*/
	SET_BIT(SPI1->CR1,2);
	
	/*fPCLK/2, PCLK2 = 8MHz, SPI clk = 4MHz*/
	CLR_BIT(SPI1->CR1,3 );
	CLR_BIT(SPI1->CR1,4 );
	CLR_BIT(SPI1->CR1,5 );
	
	/*MSB_BIT FIRST = 1*/
	CLR_BIT(SPI1->CR1,7);
	
	/*Software Slave Management*/
	SET_BIT(SPI1->CR1,9 );
	SET_BIT(SPI1->CR1,8 );
	
	/*Full duplex (Transmit and receive)*/
	CLR_BIT(SPI1->CR1, 10);
	
	/* 8 bit data*/
	CLR_BIT(SPI1->CR1, 11);
	
}


void SPI_enable()
{
	/*Peripheral enabled*/
	SET_BIT(SPI1->CR1,6);
}

void SPI_disable()
{
	/*Peripheral disable*/
	CLR_BIT(SPI1->CR1,6);
}


//void SPI_TXdata(u8 data)
//{
//	/*wait for TXE bit to set*/
//	while(!(GET_BIT(SPI1->SR, 1)));
//	SPI1->DR = data;
//
//}
//
//
//void SPI_RXdata (u8 *data )
//{
//	/* wait for BSY bit to Reset*/
//	while((GET_BIT(SPI1->SR, 7) == 1));
//	*data = SPI1->DR;
//}

u8  SPI_TX_RX(u8 data )
{
	u8 rx  = 0 ;
	
	SPI1 -> DR  = data ;
	while (GET_BIT(SPI1 -> SR , 7)) ;
	rx = SPI1->DR ;
    return  rx ;
}

void SPI1_SS_PIN_EN()
{
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW);
	
}

void SPI1_SS_PIN_DIS()
{
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_HIGH);
	
}









