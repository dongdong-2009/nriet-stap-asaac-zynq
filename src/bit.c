/*
 * bit.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: Administrator
 */

#include "bit.h"
#include "show_v7.h"
#include <stdio.h>
#include <math.h>

//#include "xadc_core.h"

extern unsigned int g_temp[10];

void Show_bit()
{
	u8 uartData1[32];
	u8 uartData2[32];
	u8 uartData3[32];
	u8 uartData4[32];
	float temp,v_int,v_aux;
	int base_addr;
	int val,i;
	int swNumber=0;
	int Delay=0;

	float Temp[10];

	/*get zynq info*/
	Temp[0] = get_temp(0);
	printf("zynq temp %.2f cent!\r\n",Temp[0]);
	g_temp[0]=(unsigned int)Temp[0]+100;

	Temp[1] = get_temp(1);
	printf("1848 board temp  %.2f cent!\r\n",Temp[1]);
	g_temp[1]=(unsigned int)Temp[1]+100;

	Temp[2] =get_vcc(0);
	printf("zynq vcc_int %.2fV !\r\n",Temp[2]);

	Temp[3] = get_vcc(1);
	printf("zynq vcc_aux %.2fV !\r\n",Temp[3]);

	Temp[4] = get_vcc(2);
	printf("zynq vccP_int %.2fV !\r\n",Temp[4]);

	Temp[5] = get_vcc(3);
	printf("zynq vccP_aux %.2fV !\r\n",Temp[5]);

	Temp[6] =get_vcc(4);;
	printf("zynq vccP_ddr %.2fV !\r\n",Temp[6]);

	g_temp[6]=0;
	g_temp[7]=0;

	//get 1848 link status
	for(i=0;i<8;i++)
	{
		base_addr=0x158+0x20*i;
		val = get_1848_reg(swNumber,base_addr);
		if((val&0x2)==0x2)
		{
			g_temp[7]+=2<<i;
		}
	}


	for(i=8;i<12;i++)
	{
		base_addr=0x158+0x20*i;
		val = get_1848_reg(swNumber,base_addr);
		if((val&0x2)==0x2)
		{
			g_temp[6]+=2<<(i-8);
		}
	}


#if 1
	/*get v7 info*/
	XUartLite_read(FIRST_V7_ARRD,uartData1,0x70);
	temp = (uartData1[7] * 255.0 + uartData1[8])*503.975/4096-273.15;
	printf("v7_1 temp %.2f !\r\n",temp);
	g_temp[2]=(unsigned int)temp+100;

	XUartLite_read(FIRST_V7_ARRD,uartData1,0x71);
	v_aux = (uartData1[5] * 255.0 + uartData1[6])*3/4096;
	v_int = (uartData1[7] * 255.0 + uartData1[8])*3/4096;
	printf("v7_1 v_int %.2f; v_aux %.2f !\r\n",v_int,v_aux);

	XUartLite_read(SECOND_V7_ARRD,uartData2,0x70);
	temp = (uartData2[7] * 255.0 + uartData2[8])*503.975/4096-273.15;
	printf("v7_2 temp %.2f !\r\n",temp);
	g_temp[3]=(unsigned int)temp+100;

	XUartLite_read(SECOND_V7_ARRD,uartData2,0x71);
	v_aux = (uartData2[5] * 255.0 + uartData2[6])*3/4096;
	v_int = (uartData2[7] * 255.0 + uartData2[8])*3/4096;
	printf("v7_2 v_int %.2f; v_aux %.2f !\r\n",v_int,v_aux);

	XUartLite_read(THIRD_V7_ARRD,uartData3,0x70);
	temp = (uartData3[7] * 255.0 + uartData3[8])*503.975/4096-273.15;
	printf("v7_3 temp %.2f !\r\n",temp);
	g_temp[4]=(unsigned int)temp+100;

	XUartLite_read(THIRD_V7_ARRD,uartData3,0x71);
	v_aux = (uartData3[5] * 255.0 + uartData3[6])*3/4096;
	v_int = (uartData3[7] * 255.0 + uartData3[8])*3/4096;
	printf("v7_3 v_int %.2f; v_aux %.2f !\r\n",v_int,v_aux);

	XUartLite_read(FORTH_V7_ARRD,uartData4,0x70);
	temp = (uartData4[7] * 255.0 + uartData4[8])*503.975/4096-273.15;
	printf("v7_4 temp %.2f !\r\n",temp);
	g_temp[5]=(unsigned int)temp+100;

	XUartLite_read(FORTH_V7_ARRD,uartData4,0x71);
	v_aux = (uartData4[5] * 255.0 + uartData4[6])*3/4096;
	v_int = (uartData4[7] * 255.0 + uartData4[8])*3/4096;
	printf("v7_4 v_int %.2f; v_aux %.2f !\r\n",v_int,v_aux);

    for (Delay = 0; Delay < LED_DELAY*30; Delay++);
#endif
	return ;

}


