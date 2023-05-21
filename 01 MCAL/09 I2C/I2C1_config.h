#ifndef   I2C1_CONFIG
#define   I2C1_CONFIG


#define   APB1_CLK    8  /* clock of APB1 */
#define   PER_CLK     APB1_CLK

#define   T_pclk      (1/PER_CLK)
#define   MY_CCR      ((1000+4000)/T_pclk)

#define   Sm_mode_I2C   1
#define   Fm_mode_I2C   0

#define   MY_TRISE       ((1000/T_pclk)+1)
#endif  /*I2C1_CONFIG*/