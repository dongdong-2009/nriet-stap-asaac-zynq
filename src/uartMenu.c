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

	printf ("\r\n------------STAP-ASSACģ��˵�������Ӧ���鿴��Ϣ--------------\n");
	usleep(_usec);
	printf("Keyboard-(1)	�鿴1848��·״̬�ṹ.\n");
	usleep(_usec);
	printf("Keyboard-(2)	�鿴1848�ڲ��˿ڼ���ͳ��.\n");
	usleep(_usec);
	printf("Keyboard-(3)	�鿴1848�˿�״̬.\n");
	usleep(_usec);
	printf("Keyboard-(4)	�鿴V7״̬\n");
	usleep(_usec);
	printf("Keyboard-(5)	�鿴RapidIO��·״̬\n");
	usleep(_usec);
	printf("Keyboard-(q)	�˳��˵�ģʽ.\n");
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
			printf("*******��·״̬���*******\n");
			iic_SrioErrorDetect();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '2')
		{
			printf("*******�˿�״̬���*******\n");
			IIC_SrioPortStaticShow();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '3')
		{
			printf("*******1848�˿�״̬*******\n");
			show_1848_status();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '4')
		{
			printf("*******V7״̬���*******\n");
			show_V7_info();
			sleep(1);
			printf("->");
		}
		else if (_recvData == '5')
		{
			printf("*******RapidIO��·״̬���*******\n");
			iic_SwPLLLaneShow();
			sleep(1);
			printf("->");
		}
		else if (_recvData == 'q')
		{
			printf("*******���棡�˳��˵�*******\n");
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




