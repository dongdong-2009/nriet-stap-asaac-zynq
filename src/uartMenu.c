#include <stdio.h>
#include <unistd.h>
#include "show_v7.h"

//extern int IicSelfTest();
//extern void hlSrioInit();
//extern void hlSrioTopoShow();
//extern void hlSrioLUTShow();
//extern void hlSrioReInit();
extern void IIC_SrioPortStaticShow();

//extern void UartSetSrioDelay(unsigned short bEnum,int delay);

extern void iic_SrioErrorDetect();
extern void show_1848_status();
//extern void iic_SwPortRepair();
//extern void iic_SwPortClear();
//extern void iic_TTL_csr(unsigned int ttl_count);
//extern void iic_SwSpeedBaudSet(unsigned int speedIndex);
extern void iic_SwPLLLaneShow();
//extern void OpenLogFile();
//extern void ReadLogInfo();
//extern void CloseLogFile();
//extern void OpenSysReset();
//extern void CloseSysReset();

extern unsigned int g_slotNum;

void ShowTab()
{
	int _usec =8000;

	printf ("\r\n------------STAP-ASSAC模块菜单，按对应键查看信息--------------\n");
	usleep(_usec);
	printf("Keyboard-(1)	查看1848链路状态结构.\n");
	usleep(_usec);
	printf("Keyboard-(2)	查看1848内部端口计数统计.\n");
	usleep(_usec);
	printf("Keyboard-(3)	查看1848端口状态.\n");
	usleep(_usec);
	printf("Keyboard-(4)	查看V7状态\n");
	usleep(_usec);
	printf("Keyboard-(5)	查看RapidIO链路状态\n");
	usleep(_usec);
	printf("Keyboard-(q)	退出菜单模式.\n");
	usleep(_usec);
	printf("-----------------------------------------------------------------------------------------------\n");
	usleep(_usec);
}



void SlectUartMenu(void)
{
	unsigned char _recvData;
	unsigned int _bRunning;

	_recvData = '0';
//	_flag = 0;
	_bRunning = 1;
	sleep(1);
	ShowTab();

	while(_bRunning)
	{
		_recvData = '0';
		_recvData = getchar();

		if (_recvData == '1')
		{
			printf("*******链路状态监测*******\n");
			iic_SrioErrorDetect();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '2')
		{
			printf("*******端口状态监测*******\n");
			IIC_SrioPortStaticShow();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '3')
		{
			printf("*******1848端口状态*******\n");
			show_1848_status();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '4')
		{
			printf("*******V7状态监测*******\n");
			show_V7_info();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '5')
		{
			printf("*******RapidIO链路状态监测*******\n");
			iic_SwPLLLaneShow();
			sleep(1);
			printf("->");
		}
		else if (_recvData == 'q')
		{
			printf("*******警告！退出菜单*******\n");
			break;
		}
		else if(_recvData == '\n'||_recvData == '\r')
		{
			ShowTab();
			sleep(1);
			printf("->");
		}
	}
}




