#ifndef __BT_H
#define	__BT_H

#include "stm32f10x.h"
#include "misc.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "stdio.h"

#define BT_REC_LEN 1024

extern u8  BT_RX_BUF[BT_REC_LEN]; //���ջ���,���BT_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 BT_RX_STA;         		//����״̬���	

void BT_Init(u32 BT_BaudRate);
void BT_Send_Data(u8 Data);
void BT_Send_Datas(u8* Data,u32 len);
void BT_Send_Command(const u8 *com);
u8 BT_GetDate(void);

#endif 
