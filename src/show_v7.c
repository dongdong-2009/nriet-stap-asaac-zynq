/*
 * show_v7.c
 *
 *  Created on: 2017年9月19日
 *      Author: Administrator
 */

#include "show_v7.h"
#include "xil_io.h"

void SetUartReg(unsigned int addrBase,unsigned int addrOffset,unsigned int value)
{
	Xil_Out32(addrBase+addrOffset, value);
}

int GetUartReg(unsigned int addrBase,unsigned int addrOffset)
{
	int ans=0;
	ans=Xil_In32(addrBase+addrOffset);
	return ans;
}

unsigned int XUartLite_Send(u32 BaseAddr, u8 *DataBufferPtr, unsigned int NumBytes)
{
	u32 StatusRegister;
	u8 IntrEnableStatus;
	unsigned int SentCount = 0;

	StatusRegister = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,0);

	StatusRegister &= XUL_CR_ENABLE_INTR;
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,StatusRegister);

	StatusRegister = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,0);
	IntrEnableStatus = StatusRegister;

#if 0
	printf("send data 0x%x\n",DataBufferPtr[0]);
	printf("send data 0x%x\n",DataBufferPtr[1]);
	printf("send data 0x%x\n",DataBufferPtr[2]);
	printf("send data 0x%x\n",DataBufferPtr[3]);
	printf("send data 0x%x\n",DataBufferPtr[4]);
	printf("send data 0x%x\n",DataBufferPtr[5]);
	printf("send data 0x%x\n",DataBufferPtr[6]);
	printf("send data 0x%x\n",DataBufferPtr[7]);
	printf("send data 0x%x\n",DataBufferPtr[8]);
	printf("send data 0x%x\n",DataBufferPtr[9]);
#endif

	//write data to fifo
	while (((StatusRegister & XUL_SR_TX_FIFO_FULL) == 0) &&(SentCount < 10))
	{
		SetUartReg(BaseAddr,XUL_TX_FIFO_OFFSET,DataBufferPtr[SentCount]);
		SentCount++;
		StatusRegister = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	}
	IntrEnableStatus &= XUL_CR_ENABLE_INTR;
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,IntrEnableStatus);

	return SentCount;
}

unsigned int XUartLite_Recv(u32 BaseAddr, u8 *DataBufferPtr,unsigned int NumBytes)
{
	u32 StatusRegister;
	u8 StatusRegisterVal;
	unsigned int RecvCount = 0;

	StatusRegister = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,0);

	StatusRegister &= XUL_CR_ENABLE_INTR;
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,StatusRegister);

	StatusRegisterVal = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,0);

	//recv data from fifo
	while (RecvCount < 10)
	{
		StatusRegister = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);

		if (StatusRegister & XUL_SR_RX_FIFO_VALID_DATA)
		{
			DataBufferPtr[RecvCount]=GetUartReg(BaseAddr,XUL_RX_FIFO_OFFSET);
			RecvCount++;
		}
		else
		{
			break;
		}
	}

	StatusRegisterVal &= XUL_CR_ENABLE_INTR;
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,StatusRegisterVal);
	return 0;
}

int XUartLite_read(u32 BaseAddr,u8 *Output_p,u8 addr)
{
	u32 StatusRegister;
	u32 reg=0;
	u8 sendbuf[16];
	int Delay;
	uint sended_bytes;

	sendbuf[0]= 0xAA;///head0
	sendbuf[1]= 0x88;///head1
	sendbuf[2]= 0x00;///id
	sendbuf[3]= addr;///addr
	sendbuf[4]= 0x00;///rd_wr
	sendbuf[5]= 0x00;///data
	sendbuf[6]= 0x08;///data
	sendbuf[7]= 0x80;///data
	sendbuf[8]= 0x88;///data
	sendbuf[9]= 0x55;///tail

	//初始化Uart
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,0);

	//reset FIFO
	reg=GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	reg &= XUL_SR_INTR_ENABLED;
	SetUartReg(BaseAddr,XUL_CONTROL_REG_OFFSET,reg|XUL_CR_FIFO_TX_RESET|XUL_CR_FIFO_RX_RESET);


	StatusRegister = GetUartReg(BaseAddr,XUL_STATUS_REG_OFFSET);
	if (StatusRegister != XUL_SR_TX_FIFO_EMPTY) {
		printf("reset Uartlite failed!\n");
	}

	//send data
	sended_bytes = XUartLite_Send(BaseAddr, sendbuf,10);

	for (Delay = 0; Delay < LED_DELAY/2; Delay++);

	//receive data
	XUartLite_Recv(BaseAddr, Output_p,10);

	return 0;
}


void show_V7_info()
{
	u8 uartData1[32];
	u8 uartData2[32];
	u8 uartData3[32];
	u8 uartData4[32];

	u32 temp;
	u8 i;

	printf("--------------V7_1 INFO:\n");
	for(i=0;i<32;i+=4)
	{
		XUartLite_read(FIRST_V7_ARRD,uartData1,i);
		temp = uartData1[5] * 0x1000000 + uartData1[6] * 0x10000 + uartData1[7] * 0x100 + uartData1[8];
		printf("0x%08x ",temp);

		XUartLite_read(FIRST_V7_ARRD,uartData1,i+1);
		temp = uartData1[5] * 0x1000000 + uartData1[6] * 0x10000 + uartData1[7] * 0x100 + uartData1[8];
		printf("0x%08x ",temp);

		XUartLite_read(FIRST_V7_ARRD,uartData1,i+2);
		temp = uartData1[5] * 0x1000000 + uartData1[6] * 0x10000 + uartData1[7] * 0x100 + uartData1[8];
		printf("0x%08x ",temp);

		XUartLite_read(FIRST_V7_ARRD,uartData1,i+3);
		temp = uartData1[5] * 0x1000000 + uartData1[6] * 0x10000 + uartData1[7] * 0x100 + uartData1[8];
		printf("0x%08x \n",temp);
	}

	printf("--------------V7_2 INFO:\n");
	for(i=0;i<32;i+=4)
	{
		XUartLite_read(SECOND_V7_ARRD,uartData2,i);
		temp = uartData2[5] * 0x1000000 + uartData2[6] * 0x10000 + uartData2[7] * 0x100 + uartData2[8];
		printf("0x%08x ",temp);

		XUartLite_read(SECOND_V7_ARRD,uartData2,i+1);
		temp = uartData2[5] * 0x1000000 + uartData2[6] * 0x10000 + uartData2[7] * 0x100 + uartData2[8];
		printf("0x%08x ",temp);

		XUartLite_read(SECOND_V7_ARRD,uartData2,i+2);
		temp = uartData2[5] * 0x1000000 + uartData2[6] * 0x10000 + uartData2[7] * 0x100 + uartData2[8];
		printf("0x%08x ",temp);

		XUartLite_read(SECOND_V7_ARRD,uartData2,i+3);
		temp = uartData2[5] * 0x1000000 + uartData2[6] * 0x10000 + uartData2[7] * 0x100 + uartData2[8];
		printf("0x%08x \n",temp);
	}

	printf("--------------V7_3 INFO:\n");
	for(i=0;i<32;i+=4)
	{
		XUartLite_read(THIRD_V7_ARRD,uartData3,i);
		temp = uartData3[5] * 0x1000000 + uartData3[6] * 0x10000 + uartData3[7] * 0x100 + uartData3[8];
		printf("0x%08x ",temp);

		XUartLite_read(THIRD_V7_ARRD,uartData3,i+1);
		temp = uartData3[5] * 0x1000000 + uartData3[6] * 0x10000 + uartData3[7] * 0x100 + uartData3[8];
		printf("0x%08x ",temp);

		XUartLite_read(THIRD_V7_ARRD,uartData3,i+2);
		temp = uartData3[5] * 0x1000000 + uartData3[6] * 0x10000 + uartData3[7] * 0x100 + uartData3[8];
		printf("0x%08x ",temp);
		XUartLite_read(THIRD_V7_ARRD,uartData3,i+3);
		temp = uartData3[5] * 0x1000000 + uartData3[6] * 0x10000 + uartData3[7] * 0x100 + uartData3[8];
		printf("0x%08x \n",temp);
	}

	printf("--------------V7_4 INFO:\r\n");
	for(i=0;i<32;i+=4)
	{
		XUartLite_read(FORTH_V7_ARRD,uartData4,i);
		temp = uartData4[5] * 0x1000000 + uartData4[6] * 0x10000 + uartData4[7] * 0x100 + uartData4[8];
		printf("0x%08x ",temp);

		XUartLite_read(FORTH_V7_ARRD,uartData4,i+1);
		temp = uartData4[5] * 0x1000000 + uartData4[6] * 0x10000 + uartData4[7] * 0x100 + uartData4[8];
		printf("0x%08x ",temp);

		XUartLite_read(FORTH_V7_ARRD,uartData4,i+2);
		temp = uartData4[5] * 0x1000000 + uartData4[6] * 0x10000 + uartData4[7] * 0x100 + uartData4[8];
		printf("0x%08x ",temp);

		XUartLite_read(FORTH_V7_ARRD,uartData4,i+3);
		temp = uartData4[5] * 0x1000000 + uartData4[6] * 0x10000 + uartData4[7] * 0x100 + uartData4[8];
		printf("0x%08x \n",temp);
	}
	return ;
}


