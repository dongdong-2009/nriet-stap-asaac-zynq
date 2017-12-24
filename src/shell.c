/*
 * shell.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: Administrator
 */


#include "shell.h"

#include <stdio.h>
#include <string.h>

#if 0
void config_system()
{
	char cmdline[100];
	sprintf(cmdline,"sh /mnt/init.sh");
	system(cmdline);
}
#endif

void config_ip(unsigned int *ipaddr)
{
	char cmdline[100];
	int ip1,ip2,ip3,ip4;
	ip1=ipaddr[0];
	ip2=ipaddr[1];
	ip3=ipaddr[2];
	ip4=ipaddr[3];
	sprintf(cmdline,"sh /usr/bin/ipaddr.sh %d %d %d %d",ip1,ip2,ip3,ip4);
	system(cmdline);
}


void config_can(unsigned int *temp)
{

	char cmdline[100];
	unsigned int zynq_temp,temp_1848,v7_1_temp,v7_2_temp,v7_3_temp,v7_4_temp;
	unsigned int status1=0,status2=0;
	zynq_temp=temp[0];
	temp_1848=temp[1];
	v7_1_temp=temp[2];
	v7_2_temp=temp[3];
	v7_3_temp=temp[4];
	v7_4_temp=temp[5];
	status1=temp[6];
	status2=temp[7];
	sprintf(cmdline,"sh /usr/bin/can.sh %d %d %d %d %d %d %d %d",zynq_temp,temp_1848,v7_1_temp,v7_2_temp,v7_3_temp,v7_4_temp,status1,status2);
	system(cmdline);
}


