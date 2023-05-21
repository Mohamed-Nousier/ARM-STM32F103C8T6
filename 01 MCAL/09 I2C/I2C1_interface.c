
#include  "I2C1_interface.h"

void I2C1_Init() /*MASTER MODE*/
{
	/*Reset the I2C*/
	SET_BIT(I2C1->CR1, 15); // reset the I2C
	CLR_BIT(I2C1->CR1, 15); // Normal operation

	/*Set the I2C clock*/
	// Program the peripheral input clock in I2C_CR2 Register in order to generate correct timings
	I2C1->CR2 |= (PER_CLK<<0);  // PCLK1 FREQUENCY in MHz (8MHz)

	#if(Sm_mode_I2C)
	{
		CLR_BIT(I2C1->CCR, 15);
	}
	#elif(Fm_mode_I2C)
	{
		SET_BIT(I2C1->CCR, 15);
	}
	
	// Configure the clock control registers
	I2C1->CCR = (MY_CCR<<0);

	// Configure the rise time register
	I2C1->TRISE = MY_TRISE;

	/*Enable the I2C*/
	// Program the I2C_CR1 register to enable the peripheral
	SET_BIT(I2C1->CR1,0); // Enable I2C


	/**** STEPS FOLLOWED  ************
	1. Enable the ACK
	2. Send the START condition 
	3. Wait for the SB ( Bit 0 in SR1) to set. This indicates that the start condition is generated
	*/

	SET_BIT(I2C1->CR1,1);  // Enable the ACK_BIT
	SET_BIT(I2C1->CR1,8);  // Generate START condition

	while (!(GET_BIT(I2C1->SR1))); //Wait for the SB ( Bit 0 in SR1)
	
}


void I2C1_Start()
{
	SET_BIT(I2C1->CR1, 10); // enable ACK
	SET_BIT(I2C1->CR1, 8); // generate start 
	while(!(GET_BIT(I2C1->SR1, 0))); // wait for(SB bit) the start condition to be generated
}

void I2C1_Address(u8 Add)
{
	/**** STEPS FOLLOWED  ************
	1. Send the Slave Address to the DR Register
	2. Wait for the ADDR (bit 1 in SR1) to set. This indicates the end of address transmission
	3. clear the ADDR by reading the SR1 and SR2
	*/

	I2C1->DR = Add;  //  send the address
	while (!(GET_BIT(I2C1->SR1, 1)));  // wait for ADDR bit to set
	u8 temp = (I2C1->SR1 | I2C1->SR2);  // read SR1 and SR2 to clear the ADDR bit
}



void I2C1_Write(u8 data)
{
	/**** STEPS FOLLOWED  ************
	1. Wait for the TXE (bit 7 in SR1) to set. This indicates that the DR is empty
	2. Send the DATA to the DR Register
	3. Wait for the BTF (bit 2 in SR1) to set. This indicates the end of LAST DATA transmission
	*/
	while (!(I2C1->SR1 & (1<<7)));  // wait for TXE bit to set
	I2C1->DR = data;
	while (!(I2C1->SR1 & (1<<2)));  // wait for BTF bit to set
}


void I2C1_Read( u8 Address, u8 *data) /*in case of 1-byte*/
{
	
	
	
		/**** STEP 1-a ****/	
		I2C1->DR = Address;  //  send the address
		while (!(I2C1->SR1 & (1<<1)));  // wait for ADDR bit to set
		
		/**** STEP 1-b ****/	
		I2C1->CR1 &= ~(1<<10);  // clear the ACK bit 
		u8 temp = I2C1->SR1 | I2C1->SR2;  // read SR1 and SR2 to clear the ADDR bit.... EV6 condition
		I2C1->CR1 |= (1<<9);  // Stop I2C

		/**** STEP 1-c ****/	
		while (!(I2C1->SR1 & (1<<6)));  // wait for RxNE to set
		
		/**** STEP 1-d ****/	
		*data = I2C1->DR;  // Read the data from the DATA REGISTER
		

}


void I2C1_Stop()
{
	//I2C1->CR1 |= (1<<9);  // Stop I2C
	SET_BIT(I2C1->CR1, 9);// Stop I2C
}





