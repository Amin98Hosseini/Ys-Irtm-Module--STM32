#include "IR_NEC.h"

//Variables
int data1[1];


//Function

void put_str(char *str)
{
  while(*str!=0)
  {
    HAL_UART_Transmit(&huart1,(unsigned char*)str, 1, 10);
    str++;
  }
}


int Receive_Data(void)
{
	if(huart1.RxXferCount==0)
		{
			HAL_UART_Receive_IT(&huart1, (unsigned char*)data1, 1);
    }
	return data1[0];
}

int Decode_Data(int Data)
{
	int val=0;
	if(Data==00)
	{
		val=1;
	}
	if(Data==01)
	{
		val=2;
	}
	if(Data==02)
	{
		val=3;
	}
	if(Data==04)
	{
		val=4;
	}
	if(Data==05)
	{
		val=5;
	}
	if(Data==06)
	{
		val=6;
	}
	if(Data==8)
	{
		val=7;
	}
	if(Data==9)
	{
		val=8;
	}
	if(Data==10)
	{
		val=9;
	}
	if(Data==12)
	{
		val=10;
	}
	if(Data==13)
	{
		val=11;
	}
	if(Data==14)
	{
		val=12;
	}
	if(Data==16)
	{
		val=13;
	}
	if(Data==17)
	{
		val=14;
	}
	if(Data==18)
	{
		val=15;
	}
	if(Data==20)
	{
		val=16;
	}
	if(Data==21)
	{
		val=17;
	}
	if(Data==22)
	{
		val=18;
	}
	if(Data==24)
	{
		val=19;
	}
	if(Data==26)
	{
		val=20;
	}
return val;
}



int Decoder_Value(void)
{
	int Parameter;
	Parameter=Decode_Data(Receive_Data());
	return Parameter;
}
void IR_SendBit(int bit1 ,int bit2 , int bit3)
{
	uint8_t variable [6]={0xA1,0xF1};
	variable[2]=bit1;
	variable[3]=bit2;
	variable[4]=bit3;
	HAL_UART_Transmit(&huart1,variable, 6, 10);
}

void IR_sendStr(uint8_t *STR)
{
	uint8_t variable [6]={0xA1,0xF1};
	variable[2]=STR[0];
	variable[3]=STR[1];
	variable[4]=STR[2];
	HAL_UART_Transmit(&huart1,variable, 6, 10);
}
