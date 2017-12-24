/*
 * Copyright (c) 2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/kernel.h>
#include <linux/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <stdlib.h>
#include "iic_1848.h"
#include "config_v7.h"
#include "gpio.h"
#include "show_v7.h"
#include "bit.h"
#include "shell.h"

extern int Init_1848();
extern void SlectUartMenu(void);
extern void NetInit();
extern int Config_V7();
extern int Xil_In32(uint64_t phyaddr);
extern void Xil_Out32(uint64_t phyaddr, uint32_t val);
extern void iic_SrioErrorDetect();


unsigned short *file_mem_addr = NULL;
unsigned int g_slotNum = 6;
unsigned int g_temp[10];


//gpio reset operations
void SetGpioReg(unsigned int addrBase,unsigned int addrOffset,unsigned int value)
{
	Xil_Out32(addrBase+addrOffset, value);
}

int GetGpioReg(unsigned int addrBase,unsigned int addrOffset)
{
	int ans=0;
	ans=Xil_In32(addrBase+addrOffset);
	return ans;
}

//get v7 configuration file size
unsigned long get_file_size(const char *path)
{
    unsigned long filesize = -1;
    struct stat statbuff;
    if(stat(path, &statbuff) < 0){
        return filesize;
    }else{
        filesize = statbuff.st_size;
    }
    return filesize;
}


int main()
{
	unsigned short _speed = 0;
	unsigned int _data=0;
	int status=0;
	int result=0;
	int flag=0,i;
	unsigned int file_size=0;
	int reset_addr=0xF20300,j,base_addr,reCFG;
	unsigned int val;
	unsigned int swNumber=0;
	FILE *pFile = NULL;
	FILE *pFile1 = NULL;
	FILE *pFile2 = NULL;
	pid_t fpid;
	printf("\n-----------------Linux STAP_ASSAC app(Version 1.0)-------------------\n");

#if 1
	/****读取槽位号*****/
	SetGpioReg(GPIO_GA_ADDR,0x4,0xFFFFFFFF);
	_data = GetGpioReg(GPIO_GA_ADDR,0x0);
	g_slotNum = ~_data & 0x1f;
	printf("slotNum = %d\r\n",g_slotNum);

	/******配置1848******/
	Init_1848();
	//设置默认速率配置5G
//	iic_SwSpeedBaudSet(1);
#endif

#if 1
	printf("######config 1848 in port speed\n");
	pFile1 = fopen("/home/root/nor_flash/speed_in.txt","r");
	if( pFile1 == NULL )
	{
		printf("打开速度配置文件speed_in.txt失败，设置默认速度为5G.\n");
		_speed = 1;
	}
	else
	{
		fread((void*)&_speed,1,1,pFile1);
		_speed=_speed&0x0000000f;
		fclose( pFile1 );
	}

	if( _speed == 0 )	//3.125G
	{
		iic_SwSpeedBaudSetIN(0);
	}
	else if( _speed == 1 )	//5.0G
	{
		iic_SwSpeedBaudSetIN(1);
	}
	else if( _speed == 2 )	//6.25G
	{
		iic_SwSpeedBaudSetIN(2);
	}
	else
	{
		printf("错误！读取速度模式失败，当前读取速度模式为 speed = 0x%x\n",_speed);
	}

	printf("######config 1848 out port speed\n");
	pFile2 = fopen("/home/root/nor_flash/speed_out.txt","r");
	if( pFile2 == NULL )
	{
		printf("打开速度配置文件speed_out.txt失败，设置默认速度为5G.\n");
		_speed = 1;
	}
	else
	{
		fread((void*)&_speed,1,4,pFile2);
		_speed=_speed&0x0000000f;
		fclose( pFile2 );
	}
	if( _speed == 0 )	//3.125G
	{
		iic_SwSpeedBaudSetOUT(0);
	}
	else if( _speed == 1 )	//5.0G
	{
		iic_SwSpeedBaudSetOUT(1);
	}
	else if( _speed == 2 )	//6.25G
	{
		iic_SwSpeedBaudSetOUT(2);
	}
	else
	{
		printf("错误！读取速度模式失败，当前读取速度模式为 speed = %d\r\n",_speed);
	}
#endif

#if 1
	//设置ttl 3.2ms
   	iic_TTL_csr(0x7d00000);
   	//使能端口统计
   	iic_SwPortCounterEnable();
   	//错误检测
	iic_SrioErrorDetect();
	//修链路状态
	iic_SwPortRepair();
	//清除错误状态
	iic_SwPortClear();
	//设置静态路由
	set_route_table(0);
#endif

#if 1
	/******配置V7******/
	file_mem_addr = (unsigned short *)malloc(29*1024*1024*sizeof(char));
	printf("mem allocated ok!\n");
	file_size=get_file_size("/home/root/config_flash/v7.bin");
	printf("v7 dat file size is %d\n",file_size);

	pFile = fopen("/home/root/config_flash/v7.bin","rb");
	if( pFile == NULL )
	{
		printf("打开V7配置文件失败.\n");
	}
	else
	{
		flag=1;
		printf("copy v7 data to memory\n");
		fread(file_mem_addr,sizeof(unsigned short),file_size,pFile);
		fclose( pFile );
	}
	if(flag==1)
	{
		printf("config v7\n");
		status=Config_V7((unsigned int *)file_mem_addr, file_size);
	}
	if(status==0)
	{
		printf("V7 configure success\n");
	}
	else
	{
		printf("Reconfig the %d v7 again\n",status);
		if((status& 0x1)==1)
		{
			result=Config_V7_single((unsigned int *)file_mem_addr, file_size,1);
			if(result==1)
			{
				printf("no.1 V7 configure fail\n");
			}
		}
		if((status & 0x2)==2)
		{
			result=Config_V7_single((unsigned int *)file_mem_addr, file_size,2);
			if(result==1)
			{
				printf("no.2 V7 configure fail\n");
			}
		}
		if((status & 0x4)==4)
		{
			result=Config_V7_single((unsigned int *)file_mem_addr, file_size,4);
			if(result==1)
			{
				printf("no.3 V7 configure fail\n");
			}
		}
		if((status & 0x8)==8)
		{
			result=Config_V7_single((unsigned int *)file_mem_addr, file_size,8);
			if(result==1)
			{
				printf("no.4 V7 configure fail\n");
			}
		}
	}

#endif

	usleep(1000000);
	SetGpioReg(GPIO_V_1,0x0,0xFFFFFFFF);
	SetGpioReg(GPIO_V_2,0x0,0xFFFFFFFF);
	SetGpioReg(GPIO_V_3,0x0,0xFFFFFFFF);
	SetGpioReg(GPIO_V_4,0x0,0xFFFFFFFF);
	sleep(2);

#if 1
//	sleep(10);
	/*****修链路*****/
	for(i=0;i<2;i++)
	{
		port_fix_1848();
		reCFG = 0;
		base_addr=0x158+0x20*6;
		val = get_1848_reg(swNumber,base_addr);
		printf("PORT 6 reg158: %x\n", val);
		if((val&0x10104)!=0)
		{
			printf("PORT 6 ERROR: %04x\n", val);
			//////////reset link partner
			base_addr=0x140+0x20*6;
			set_1848_reg(swNumber,base_addr,3);
			///////////reset port
			base_addr = 0x00f20300;
			val = 0x80000040;
			set_1848_reg(swNumber,base_addr,val);

			status = Config_V7_single((unsigned int *)file_mem_addr, file_size,4);
			if(status==1)
			{
				printf("no.3 V7 configure error!\n");
			}
			else
			{
				printf("no.3 V7 configure ok!\n");
			}
			SetGpioReg(GPIO_V_3,0x0,0);
			usleep(1000000);
			SetGpioReg(GPIO_V_3,0x0,0xffffffff);
			reCFG = 1;
			set_1848_reg(swNumber,reset_addr,0);
		}

		base_addr=0x158+0x20*7;
		val = get_1848_reg(swNumber,base_addr);
		printf("PORT 7 reg158: %x\n", val);
		if((val&0x10104)!=0)
		{
			printf("PORT 7 ERROR: %04x\n", val);
			//////////reset link partner
			base_addr=0x140+0x20*7;
			set_1848_reg(swNumber,base_addr,3);
			///////////reset port
			base_addr = 0x00f20300;
			val = 0x80000080;
			set_1848_reg(swNumber,base_addr,val);

			status = Config_V7_single((unsigned int *)file_mem_addr, file_size,1);
			if(status)
			{
				printf("no.1 V7 configure error!\n");
			}
			else
			{
				printf("no.1 V7 configure ok!\n");
			}

			SetGpioReg(GPIO_V_1,0x0,0);
			usleep(1000000);
			SetGpioReg(GPIO_V_1,0x0,0xffffffff);
			reCFG = 1;
			set_1848_reg(swNumber,reset_addr,0);
		}

		base_addr=0x158+0x20*10;
		val = get_1848_reg(swNumber,base_addr);
		printf("PORT 10 reg158: %x\n\r", val);
		if((val&0x10104)!=0)
		{
			printf("PORT 10 ERROR: %04x\n\r", val);
			//////////reset link partner
			base_addr=0x140+0x20*10;
			set_1848_reg(swNumber,base_addr,3);
			///////////reset port
			base_addr = 0x00f20300;
			val = 0x80000400;
			set_1848_reg(swNumber,base_addr,val);

			status = Config_V7_single((unsigned int *)file_mem_addr, file_size,2);
			if(status)
			{
				printf("no.2 V7 configure error!\n");
			}
			else
			{
				printf("no.2 V7 Configure ok!\n");
			}
			SetGpioReg(GPIO_V_2,0x0,0);
			usleep(1000000);
			SetGpioReg(GPIO_V_2,0x0,0xffffffff);
			reCFG = 1;
			set_1848_reg(swNumber,reset_addr,0);
		}

		base_addr=0x158+0x20*11;
		val = get_1848_reg(swNumber,base_addr);
		printf("PORT 11 reg158: %x\n", val);
		if((val&0x10104)!=0)
		{
			printf("PORT 11 ERROR: %04x\n", val);
			//////////reset link partner
			base_addr=0x140+0x20*11;
			set_1848_reg(swNumber,base_addr,3);
			///////////reset port
			base_addr = 0x00f20300;
			val = 0x80000800;
			set_1848_reg(swNumber,base_addr,val);

			status = Config_V7_single((unsigned int *)file_mem_addr, file_size,8);
			if(status)
			{
				printf("no.4 V7 configure error!\n");
			}
			else
			{
				printf("no.4 V7 configure ok!\n\r");
			}
			SetGpioReg(GPIO_V_4,0x0,0);
			usleep(1000000);
			SetGpioReg(GPIO_V_4,0x0,0xffffffff);
			reCFG = 1;
			set_1848_reg(swNumber,reset_addr,0);

		}
		sleep(2);
		port_fix_1848();
	}
	free(file_mem_addr);
#endif

#if 1
	/******配置网络******/
	NetInit(g_slotNum);
#endif

	iic_SrioErrorDetect();
#if 1
	fpid = fork();
	if( fpid <0 )
	{
		printf("fork error!\n");
	}
	else if( fpid == 0 )			//子任务
	{
		while(1)
		{
			Show_bit();
			config_can(g_temp);
			sleep(10);
		}
	}
	else
	{
		SlectUartMenu();
	}
#endif
	return 0;
}



