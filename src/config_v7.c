/*
 * config_v7.c
 *
 *  Created on: 2017Äê8ÔÂ17ÈÕ
 *      Author: Administrator
 */

#include "config_v7.h"
#include "gpio.h"
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include "xil_io.h"


#define PAGE_SIZE_FIFO  ((size_t)getpagesize())
#define PAGE_MASK_FIFO ((uint64_t) (long)~(PAGE_SIZE_FIFO - 1))


//config v7 using fifo
int Config_V7(unsigned int *src_addr, int data_size_byte)
{
	int i,j;
	int val=0;
	int timedelay=0;
	struct timeval tBegin,tEnd;
	long deltatime=0;
	u32 tmp_data;


	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0xffffffff);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0xffffffff);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0xffffffff);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0xffffffff);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);

	SetGpioReg(FIFO_ISR_ADDR0,0,0xffffffff);
	SetGpioReg(FIFO_ISR_ADDR1,0,0xffffffff);
	SetGpioReg(FIFO_ISR_ADDR2,0,0xffffffff);
	SetGpioReg(FIFO_ISR_ADDR3,0,0xffffffff);

#if 0
	SetGpioReg(FIFO_IER_ADDR0,0,0x08000000);
	SetGpioReg(FIFO_IER_ADDR1,0,0x08000000);
	SetGpioReg(FIFO_IER_ADDR2,0,0x08000000);
	SetGpioReg(FIFO_IER_ADDR3,0,0x08000000);
#endif

	SetGpioReg(FIFO_TDR_ADDR0,0,0x00000002);
	SetGpioReg(FIFO_TDR_ADDR1,0,0x00000002);
	SetGpioReg(FIFO_TDR_ADDR2,0,0x00000002);
	SetGpioReg(FIFO_TDR_ADDR3,0,0x00000002);

	tmp_data=data_size_byte;
	SetGpioReg(FIFO_TDFD_ADDR0,0,tmp_data);
	SetGpioReg(FIFO_TDFD_ADDR1,0,tmp_data);
	SetGpioReg(FIFO_TDFD_ADDR2,0,tmp_data);
	SetGpioReg(FIFO_TDFD_ADDR3,0,tmp_data);

	SetGpioReg(FIFO_TLR_ADDR0,0,0x00000004);
	SetGpioReg(FIFO_TLR_ADDR1,0,0x00000004);
	SetGpioReg(FIFO_TLR_ADDR2,0,0x00000004);
	SetGpioReg(FIFO_TLR_ADDR3,0,0x00000004);

	printf("******write flash data\n");

	gettimeofday(&tBegin,NULL);

	//mmap address of fifo
	int fd;
	volatile uint8_t *map_base0;
	volatile uint8_t *map_base1;
	volatile uint8_t *map_base2;
	volatile uint8_t *map_base3;

	uint64_t base0 = FIFO_TDFD_ADDR0 & PAGE_MASK_FIFO;
	uint64_t base1 = FIFO_TDFD_ADDR1 & PAGE_MASK_FIFO;
	uint64_t base2 = FIFO_TDFD_ADDR2 & PAGE_MASK_FIFO;
	uint64_t base3 = FIFO_TDFD_ADDR3 & PAGE_MASK_FIFO;

	uint64_t pgoffset0 = FIFO_TDFD_ADDR0 & (~PAGE_MASK_FIFO);
	uint64_t pgoffset1 = FIFO_TDFD_ADDR1 & (~PAGE_MASK_FIFO);
	uint64_t pgoffset2 = FIFO_TDFD_ADDR2 & (~PAGE_MASK_FIFO);
	uint64_t pgoffset3 = FIFO_TDFD_ADDR3 & (~PAGE_MASK_FIFO);

	if((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1)
	{
		perror("open /dev/mem:");
	}

	map_base0 = mmap(NULL, PAGE_SIZE_FIFO, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, base0);
	map_base1 = mmap(NULL, PAGE_SIZE_FIFO, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, base1);
	map_base2 = mmap(NULL, PAGE_SIZE_FIFO, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, base2);
	map_base3 = mmap(NULL, PAGE_SIZE_FIFO, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, base3);

	if(map_base0 == MAP_FAILED || map_base1 == MAP_FAILED ||map_base2 == MAP_FAILED || map_base3 == MAP_FAILED)
	{
		perror("mmap:");
	}

	printf("FIFO 0 mapped addr is:0x%x\n",(unsigned int)(map_base0 + pgoffset0));
	printf("FIFO 1 mapped addr is:0x%x\n",(unsigned int)(map_base1 + pgoffset1));
	printf("FIFO 2 mapped addr is:0x%x\n",(unsigned int)(map_base2 + pgoffset2));
	printf("FIFO 3 mapped addr is:0x%x\n",(unsigned int)(map_base3 + pgoffset3));
	close(fd);

	//write data to fifo unit 1024 bytes
	for(i=0; i<data_size_byte/4-1024; i+=1024)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR0));
		while((val & 0x08000000) == 0)
		{
			val=Xil_In32((unsigned int)(FIFO_ISR_ADDR0));
		}
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR1));
		while((val & 0x08000000) == 0)
		{
			val=Xil_In32((unsigned int)(FIFO_ISR_ADDR1));
		}
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR2));
		while((val & 0x08000000) == 0)
		{
			val=Xil_In32((unsigned int)(FIFO_ISR_ADDR2));
		}
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR3));
		while((val & 0x08000000) == 0)
		{
			val=Xil_In32((unsigned int)(FIFO_ISR_ADDR3));
		}

		SetGpioReg(FIFO_ISR_ADDR0,0,0xffffffff);
		SetGpioReg(FIFO_TDR_ADDR0,0,0x00000002);
		SetGpioReg(FIFO_ISR_ADDR1,0,0xffffffff);
		SetGpioReg(FIFO_TDR_ADDR1,0,0x00000002);
		SetGpioReg(FIFO_ISR_ADDR2,0,0xffffffff);
		SetGpioReg(FIFO_TDR_ADDR2,0,0x00000002);
		SetGpioReg(FIFO_ISR_ADDR3,0,0xffffffff);
		SetGpioReg(FIFO_TDR_ADDR3,0,0x00000002);

		for(j=0;j<1024;j++)
		{
			*(volatile uint32_t *)(map_base0 + pgoffset0)=*((u32*)(src_addr + i +j));
			*(volatile uint32_t *)(map_base1 + pgoffset1)=*((u32*)(src_addr + i +j));
			*(volatile uint32_t *)(map_base2 + pgoffset2)=*((u32*)(src_addr + i +j));
			*(volatile uint32_t *)(map_base3 + pgoffset3)=*((u32*)(src_addr + i +j));
//			SetGpioReg(FIFO_TDFD_ADDR0,0,*((u32*)(src_addr + i +j)));
//			SetGpioReg(FIFO_TDFD_ADDR1,0,*((u32*)(src_addr + i +j)));
//			SetGpioReg(FIFO_TDFD_ADDR2,0,*((u32*)(src_addr + i +j)));
//			SetGpioReg(FIFO_TDFD_ADDR3,0,*((u32*)(src_addr + i +j)));
		}
		SetGpioReg(FIFO_TLR_ADDR0,0,0x00001000);
		SetGpioReg(FIFO_TLR_ADDR1,0,0x00001000);
		SetGpioReg(FIFO_TLR_ADDR2,0,0x00001000);
		SetGpioReg(FIFO_TLR_ADDR3,0,0x00001000);
	}

//	gettimeofday(&tEnd,NULL);
//	deltatime=1000000L*(tEnd.tv_sec-tBegin.tv_sec)+(tEnd.tv_usec-tBegin.tv_usec);
//
//	printf("time spent of each for is: %ldus\n",deltatime);

	//write left bytes to fifo
//	printf("******write left flash data\n");

//	gettimeofday(&tBegin,NULL);

	//FIFO 0 FOR FIRST V7
	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR0));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR0));
	}
	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR1));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR1));
	}
	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR2));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR2));
	}
	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR3));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR3));
	}

	SetGpioReg(FIFO_ISR_ADDR0,0,0xffffffff);
	SetGpioReg(FIFO_TDR_ADDR0,0,0x00000002);
	SetGpioReg(FIFO_ISR_ADDR1,0,0xffffffff);
	SetGpioReg(FIFO_TDR_ADDR1,0,0x00000002);
	SetGpioReg(FIFO_ISR_ADDR2,0,0xffffffff);
	SetGpioReg(FIFO_TDR_ADDR2,0,0x00000002);
	SetGpioReg(FIFO_ISR_ADDR3,0,0xffffffff);
	SetGpioReg(FIFO_TDR_ADDR3,0,0x00000002);

	for(j=i;j<data_size_byte/4;j++)
	{
//		SetGpioReg(FIFO_TDFD_ADDR0,0,*((u32*)(src_addr +j)));
//		SetGpioReg(FIFO_TDFD_ADDR1,0,*((u32*)(src_addr +j)));
//		SetGpioReg(FIFO_TDFD_ADDR2,0,*((u32*)(src_addr +j)));
//		SetGpioReg(FIFO_TDFD_ADDR3,0,*((u32*)(src_addr +j)));

		*(volatile uint32_t *)(map_base0 + pgoffset0)=*((u32*)(src_addr +j));
		*(volatile uint32_t *)(map_base1 + pgoffset1)=*((u32*)(src_addr +j));
		*(volatile uint32_t *)(map_base2 + pgoffset2)=*((u32*)(src_addr +j));
		*(volatile uint32_t *)(map_base3 + pgoffset3)=*((u32*)(src_addr +j));

	}
	SetGpioReg(FIFO_TLR_ADDR0,0,data_size_byte-i*4);
	SetGpioReg(FIFO_TLR_ADDR1,0,data_size_byte-i*4);
	SetGpioReg(FIFO_TLR_ADDR2,0,data_size_byte-i*4);
	SetGpioReg(FIFO_TLR_ADDR3,0,data_size_byte-i*4);


	munmap((void *)map_base0, PAGE_SIZE_FIFO);
	munmap((void *)map_base1, PAGE_SIZE_FIFO);
	munmap((void *)map_base2, PAGE_SIZE_FIFO);
	munmap((void *)map_base3, PAGE_SIZE_FIFO);
	//WAIT FOR FIFO DONE
	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR0));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR0));
	}

	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR1));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR1));
	}

	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR2));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR2));
	}

	val=Xil_In32((unsigned int)(FIFO_ISR_ADDR3));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(FIFO_ISR_ADDR3));
	}

	gettimeofday(&tEnd,NULL);
	deltatime=1000000L*(tEnd.tv_sec-tBegin.tv_sec)+(tEnd.tv_usec-tBegin.tv_usec);

	printf("time spent in writing data to v7 is: %ldus\n",deltatime);

	val=GetGpioReg(GPIO_DONE_ADDR,0);
	while((val& 0xf) != 0xf)
	{
		timedelay += 1;
		val=GetGpioReg(GPIO_DONE_ADDR,0);
		if (timedelay >= 200000000)
		{
			printf("done up timeout! config failed!!!!!\n");
			return val & 0xf;
		}
	}
	return 0;
}

//config single v7 using fifo
int Config_V7_single(unsigned int *src_addr, int data_size_byte,unsigned int v7_select)
{
	int i,j;
	int val=0;
	int timedelay=0;
	struct timeval tBegin,tEnd;
	long deltatime=0;
	u32 tmp_data;
	u32 fifo_isr_addr,fifo_ier_addr,fifo_tdr_addr,fifo_tdfd_addr,fifo_tlr_addr;

	 switch(v7_select)
	 {
	 	 case 1:
	 	 {
			fifo_isr_addr = FIFO_ISR_ADDR0;
			break;
	 	 }
	 	case 2:
	 	{
			fifo_isr_addr = FIFO_ISR_ADDR1;
			break;
	 	}
	 	case 4:
	 	{
	 		fifo_isr_addr = FIFO_ISR_ADDR2;
	 		break;
	 	}
		case 8:
		{
			fifo_isr_addr = FIFO_ISR_ADDR3;
			break;
		}
		default:
			break;

	 }
	fifo_ier_addr = (u32 *)(fifo_isr_addr + 0x1);
	fifo_tdfd_addr = (u32 *)(fifo_isr_addr + 0x4);
	fifo_tlr_addr = (u32 *)(fifo_isr_addr + 0x5);
	fifo_tdr_addr = (u32 *)(fifo_isr_addr + 0xb);

	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET, (0xf & v7_select));
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET, (0xf & v7_select));
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET, (0xf & v7_select));
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET, (0xf & v7_select));
	SetGpioReg(GPIO_CFG_ADDR,XGPIO_DATA_OFFSET,0x00000000);

	SetGpioReg(fifo_isr_addr,0,0xffffffff);

#if 1
	SetGpioReg(fifo_ier_addr,0,0x08000000);
#endif

	SetGpioReg(fifo_tdr_addr,0,0x00000002);

	tmp_data=data_size_byte;
	SetGpioReg(fifo_tdfd_addr,0,tmp_data);

	SetGpioReg(fifo_tlr_addr,0,0x00000004);

	printf("******write flash data\n");

	gettimeofday(&tBegin,NULL);

	//mmap address of fifo
	int fd;
	volatile uint8_t *map_base;

	uint64_t base = fifo_tdfd_addr & PAGE_MASK_FIFO;
	uint64_t pgoffset = fifo_tdfd_addr & (~PAGE_MASK_FIFO);

	if((fd = open("/dev/mem", O_RDWR | O_SYNC)) == -1)
	{
		perror("open /dev/mem:");
	}

	map_base = mmap(NULL, PAGE_SIZE_FIFO, PROT_READ | PROT_WRITE, MAP_SHARED,
			fd, base);

	if(map_base == MAP_FAILED)
	{
		perror("mmap:");
	}

	printf("FIFO  mapped addr is:0x%x\n",(unsigned int)(map_base + pgoffset));
	close(fd);

	//write data to fifo unit 1024 bytes
	for(i=0; i<data_size_byte/4-1024; i+=1024)
	{
		val=Xil_In32((unsigned int)(fifo_isr_addr));
		while((val & 0x08000000) == 0)
		{
			val=Xil_In32((unsigned int)(fifo_isr_addr));
		}
		SetGpioReg(fifo_isr_addr,0,0xffffffff);
		SetGpioReg(fifo_tdr_addr,0,0x00000002);


		for(j=0;j<1024;j++)
		{
			*(volatile uint32_t *)(map_base + pgoffset)=*((u32*)(src_addr + i +j));
		}
		SetGpioReg(fifo_tlr_addr,0,0x00001000);
	}

//	gettimeofday(&tEnd,NULL);
//	deltatime=1000000L*(tEnd.tv_sec-tBegin.tv_sec)+(tEnd.tv_usec-tBegin.tv_usec);
//
//	printf("time spent of each for is: %ldus\n",deltatime);

	//write left bytes to fifo
//	printf("******write left flash data\n");

//	gettimeofday(&tBegin,NULL);

	//FIFO 0 FOR FIRST V7
	val=Xil_In32((unsigned int)(fifo_isr_addr));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(fifo_isr_addr));
	}

	SetGpioReg(fifo_isr_addr,0,0xffffffff);
	SetGpioReg(fifo_tdr_addr,0,0x00000002);

	for(j=i;j<data_size_byte/4;j++)
	{
		*(volatile uint32_t *)(map_base + pgoffset)=*((u32*)(src_addr +j));
	}
	SetGpioReg(fifo_tlr_addr,0,data_size_byte-i*4);

	munmap((void *)map_base, PAGE_SIZE_FIFO);

	//WAIT FOR FIFO DONE
	val=Xil_In32((unsigned int)(fifo_isr_addr));
	while((val & 0x08000000) == 0)
	{
		val=Xil_In32((unsigned int)(fifo_isr_addr));
	}


	gettimeofday(&tEnd,NULL);
	deltatime=1000000L*(tEnd.tv_sec-tBegin.tv_sec)+(tEnd.tv_usec-tBegin.tv_usec);

	printf("time spent in writing data to v7 is: %ldus\n",deltatime);

	val=GetGpioReg(GPIO_DONE_ADDR,0);
	while((val& v7_select) != v7_select)
	{
		timedelay += 1;
		val=GetGpioReg(GPIO_DONE_ADDR,0);
		if (timedelay >= 200000000)
		{
			printf("done up timeout! config failed!!!!!\n");
			return 1;
		}
	}
	return 0;
}
