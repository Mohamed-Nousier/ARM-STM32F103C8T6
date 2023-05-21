#ifndef     	 I2C1_PRIVATE
#define 		 I2C1_PRIVATE


typedef struct
{
	u32     CR1;
	u32     CR2;
	u32		OAR1;
	u32     OAR2;
	u32     DR;
	u32 	SR1;
	u32     SR2;
	u32     CCR;
	u32     TRISE;
	
}I2C_Type;

#define  I2C1     ((volatile I2C_Type *)(0x40005400))


#endif           /*I2C1_PRIVATE*/