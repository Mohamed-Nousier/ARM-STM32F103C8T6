#ifndef    UART1_CONFIG.H
#define    UART1_CONFIG.H

#define   Fck         8000000
/********
**OPTION:  Fck 72000000
********/

#define   BaudRate    9600
/********
**OPTION:  BaudRate 115200
********/

#define    _1_START_BIT_8_DATA_BITS   1
/********
**OPTION:  _1_START_BIT_9_DATA_BITS
********/ 
#define    WORD_LENGTH               _1_START_BIT_8_DATA_BITS

#define    _1_STOP_BIT      1
/********
**OPTION:  _2_STOP_BIT
********/
#define    STOP_BITS                  _1_STOP_BIT


#endif
