/*
 * xadc_core.c
 *
 *  Created on: 2017Äê9ÔÂ20ÈÕ
 *      Author: Administrator
 */

#include "xadc_core.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <ctype.h>
#include <pthread.h>
#include <assert.h>

//utility functions
float conv_voltage(float input, enum EConvType conv_direction)
{
	float result=0;

	switch(conv_direction)
	{
	case EConvType_Raw_to_Scale:
		result = ((input * 3.0 * mV_mul)/multiplier);
		break;
	case EConvType_Scale_to_Raw:
		result = (input/(3.0 * mV_mul))*multiplier;
		break;
	default:
		printf("Convertion type incorrect... Doing no conversion\n");
		//  intentional no break;
	case EConvType_None:
		result = input;
		break;
	}

	return result;
}

#if 0
float conv_voltage_ext_ch(float input, enum EConvType conv_direction)
{
	float result=0;

	switch(conv_direction)
	{
	case EConvType_Raw_to_Scale:
		result = ((input * mV_mul)/multiplier);
		break;
	case EConvType_Scale_to_Raw:
		result = (input/mV_mul)*multiplier;
		break;
	default:
		printf("Convertion type incorrect... Doing no conversion\n");
		//  intentional no break;
	case EConvType_None:
		result = input;
		break;
	}

	return result;
}
#endif

float conv_temperature(float input, enum EConvType conv_direction)
{
	float result=0;

	switch(conv_direction)
	{
	case EConvType_Raw_to_Scale:
		result = ((input * 503.975)/multiplier) - 273.15;
		break;
	case EConvType_Scale_to_Raw:
		result = (input + 273.15)*multiplier/503.975;
		break;
	default:
		printf("Conversion type incorrect... Doing no conversion\n");
		//  intentional no break;
	case EConvType_None:
		result = input;
		break;
	}

	return result;
}

float get_temp(int num)
{
	int number;
	int fd = -1;
	char upset[20];
	float raw_data=0;
	float true_data=0;
	int offset=0;
	char value=0;
	float max_temp=0;
	number=num;
	if(number==0)
	{
		fd = open(FPGA_TEMP, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=conv_temperature(raw_data, EConvType_Raw_to_Scale);
//		true_data=(conv_voltage(raw_data, EConvType_Raw_to_Scale)*1000/(3*2.2)-273.15)/10000;
		//printf("FPGA temp is %f cent\n",true_data);
		close(fd);
		return true_data;
	}
	else
	{
		fd = open(TEMP1848_1, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=(conv_voltage(raw_data, EConvType_Raw_to_Scale)*1000/(3*2.2)-273.15)/10000;
		max_temp=true_data;
		//printf("1848-1 temp is %f cent\n",true_data);
		close(fd);

		return max_temp;
	}

}

float get_vcc(int num)
{
	int number;
	int fd = -1;
	char upset[20];
	float raw_data=0;
	float true_data=0;
	int offset=0;
	char value=0;
	number=num;
	if(number==0)
	{
		fd = open(VCC_1, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=conv_voltage(raw_data, EConvType_Raw_to_Scale);
		//printf("vcc 1 is %f mv\n",true_data);
		close(fd);
	}
	else if(number==1)
	{
		fd = open(VCC_1V8, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=conv_voltage(raw_data, EConvType_Raw_to_Scale);
		//printf("vcc 1v8 is %f mv\n",true_data);
		close(fd);

	}
	else if(number==2)
	{
		fd = open(VCC_PINT, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=conv_voltage(raw_data, EConvType_Raw_to_Scale);
		//printf("vcc pint is %f mv\n",true_data);
		close(fd);

	}
	else if(number==3)
	{
		fd = open(VCC_PAUX, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=conv_voltage(raw_data, EConvType_Raw_to_Scale);
		//printf("vcc paux is %f mv\n",true_data);
		close(fd);

	}
	else if(number==4)
	{
		fd = open(VCC_PDDR, O_RDWR );
		offset=0;
		while(offset<5)
		{
			lseek(fd,offset,SEEK_SET);
			read(fd,&value,sizeof(char));
			upset[offset]=value;
			offset++;
		}
		upset[offset]='\0';
		raw_data=atoi(upset);
		true_data=conv_voltage(raw_data, EConvType_Raw_to_Scale);
		//printf("vcc pddr is %f mv\n",true_data);
		close(fd);

	}
	return true_data/1000;
}
