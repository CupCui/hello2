#ifndef __IO_H
#define	__IO_H

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"


/******************
控制和中断按键
******************/
#define LED1_ON   GPIO_ResetBits(GPIOB,GPIO_Pin_5)
#define LED1_OFF  GPIO_SetBits(GPIOB,GPIO_Pin_5)

#define LED2_ON   GPIO_ResetBits(GPIOB,GPIO_Pin_6)
#define LED2_OFF  GPIO_SetBits(GPIOB,GPIO_Pin_6)

#define LED3_ON   GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define LED3_OFF  GPIO_SetBits(GPIOB,GPIO_Pin_7)

#define LED4_ON   GPIO_ResetBits(GPIOB,GPIO_Pin_8)
#define LED4_OFF  GPIO_SetBits(GPIOB,GPIO_Pin_8)

void GPIO_Config(void);

#endif 

