




void		EXTI_voidInit(u8 port, u8 line_num);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));


#define    EXTI0      0
#define    EXTI1      1
#define    EXTI2      2
#define    EXTI3      3
#define    EXTI4      4
#define    EXTI5      5
#define    EXTI6      6
#define    EXTI7      7
#define    EXTI8      8
#define    EXTI9      9
#define    EXTI10     10
#define    EXTI11     11
#define    EXTI12     12
#define    EXTI13     13
#define    EXTI14     14
#define    EXTI15     15




#define   GPIO_PORTA        1
#define   GPIO_PORTB        2
#define   GPIO_PORTC        3

#define   IOC          0
#define   FALLING_EDGE 1
#define   RISING_EDGE  2


//0000: PA[x] pin
//0001: PB[x] pin
//0010: PC[x] pin
//0011: PD[x] pin
//0100: PE[x] pin
//0101: PF[x] pin
//0110: PG[x] pin

