/*
 * show_v7.h
 *
 *  Created on: 2017Äê9ÔÂ19ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_SHOW_V7_H_
#define SRC_SHOW_V7_H_

#include "xparameters.h"

#define FIRST_V7_ARRD XPAR_AXI_UARTLITE_0_BASEADDR
#define SECOND_V7_ARRD XPAR_AXI_UARTLITE_1_BASEADDR
#define THIRD_V7_ARRD XPAR_AXI_UARTLITE_2_BASEADDR
#define FORTH_V7_ARRD XPAR_AXI_UARTLITE_3_BASEADDR
#define XUL_CONTROL_REG_OFFSET 12
#define XUL_STATUS_REG_OFFSET 8
#define XUL_SR_INTR_ENABLED 0x10
#define XUL_CR_ENABLE_INTR 0x10
#define XUL_CR_FIFO_TX_RESET 0x01
#define XUL_CR_FIFO_RX_RESET 0x02
#define XUL_SR_TX_FIFO_EMPTY 0x04
#define XUL_SR_TX_FIFO_FULL 0x08
#define XUL_TX_FIFO_OFFSET 4
#define XUL_SR_RX_FIFO_VALID_DATA 0x01
#define XUL_RX_FIFO_OFFSET 0x0

#define LED_DELAY 	10000000

typedef unsigned char u8;
typedef unsigned int u32;

void SetUartReg(unsigned int addrBase,unsigned int addrOffset,unsigned int value);
int GetUartReg(unsigned int addrBase,unsigned int addrOffset);
int XUartLite_read(u32 BaseAddr,u8 *Output_p,u8 addr);
void show_V7_info();

#endif /* SRC_SHOW_V7_H_ */
