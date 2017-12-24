#ifndef _GPIO_H_
#define _GPIO_H_

#include "xparameters.h"

//base addr
//#define RioUartBase 0x83c10000
//#define SWBACK_BOARD_MAX_COUNT 500
#define GPIO_CFG_ADDR XPAR_AXI_GPIO_CFG_EN_BASEADDR
#define GPIO_DONE_ADDR XPAR_AXI_GPIO_DONE_BASEADDR
#define GPIO_RESET_ADDR XPAR_AXI_GPIO_RST_B_BASEADDR
#define XGPIO_DATA_OFFSET 0x0
#define XGPIO_TRI_OFFSET 0x4

#define GPIO_GA_ADDR XPAR_AXI_GPIO_GA_BASEADDR
#define GPIO_V_1 XPAR_AXI_GPIO_TO_V7_0_BASEADDR
#define GPIO_V_2 XPAR_AXI_GPIO_TO_V7_1_BASEADDR
#define GPIO_V_3 XPAR_AXI_GPIO_TO_V7_2_BASEADDR
#define GPIO_V_4 XPAR_AXI_GPIO_TO_V7_3_BASEADDR


void SetGpioReg(unsigned int addrBase,unsigned int addrOffset,unsigned int value);
int GetGpioReg(unsigned int addrBase,unsigned int addrOffset);

#endif /* UART_H_ */
