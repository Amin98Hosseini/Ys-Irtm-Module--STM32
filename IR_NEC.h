#include "main.h"
 

extern UART_HandleTypeDef huart1;

void put_str(char *str);
int Receive_Data(void);
int Decode_Data(int Data);
int Decoder_Value(void);
void IR_SendBit(int bit1 ,int bit2 , int bit3);
void IR_sendStr(uint8_t *STR);
