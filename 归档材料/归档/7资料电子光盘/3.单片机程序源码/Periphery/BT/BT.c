#include "BT.h"

//////////////////////////////////////////////////////////////////
//�������´���,֧��printf����,������Ҫѡ��use MicroLIB	  
#if 0
#pragma import(__use_no_semihosting)             
//��׼����Ҫ��֧�ֺ���                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//����_sys_exit()�Ա���ʹ�ð�����ģʽ    
_sys_exit(int x) 
{ 
	x = x; 
} 
//�ض���fputc���� 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//ѭ������,ֱ���������   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

u8 BT_RX_BUF[BT_REC_LEN];     //���ջ���,���BT_REC_LEN���ֽ�.
//����״̬
//bit15��	������ɱ�־
//bit14��	���յ�0x0d
//bit13~0��	���յ�����Ч�ֽ���Ŀ
u16 BT_RX_STA=0;       //����״̬���	
/**********************************
***********************************
BT��ʼ��   ���ߣ��¿���
***********************************
**********************************/
void BT_Init(u32 BT_BaudRate)
{
  //GPIO�˿�����
  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//ʹ��USART1
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//GPIOBʱ��
	
	USART_DeInit( USART1);
	//USART1_TX
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  //USART1_RX	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  //USART1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2 ;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
  
  //USART ��ʼ������
	USART_InitStructure.USART_BaudRate = BT_BaudRate;//���ڲ�����
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

  USART_Init(USART1, &USART_InitStructure); //��ʼ������2
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
  USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���2
}

/**********************************
***********************************
���ڷ�������  ���ߣ��¿���
***********************************
**********************************/
void BT_Send_Data(u8 Data)
{	
	USART_ClearFlag(USART1,USART_FLAG_TC);
	USART_SendData(USART1,Data);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));	
}
/**********************************
***********************************
���ڷ�������  ���ߣ��¿���
***********************************
**********************************/
void BT_Send_Datas(u8* Data,u32 len)
{	
	u32 i;
	for(i=0; i<len; i++)
	{
		USART_ClearFlag(USART1,USART_FLAG_TC);
		USART_SendData(USART1,Data[i]);
		while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));	
	}
}
/**********************************
***********************************
���ڷ�������  ���ߣ��¿���
***********************************
**********************************/

void BT_Send_Command(const u8 *com)
{
  while(*com!=0)
  {
		USART_ClearFlag(USART1,USART_FLAG_TC);
		USART_SendData(USART1,(*com));
		while(!USART_GetFlagStatus(USART1,USART_FLAG_TC));
		com++;
  }
}


void USART1_IRQHandler(void)                	//����1�жϷ������
{
	u8 Res;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		Res=USART_ReceiveData(USART1);	//��ȡ���յ�������
		
		if((BT_RX_STA&0x8000)==0)//����δ���
		{
			if(BT_RX_STA&0x4000)//���յ���0x0d
			{
				if(Res==0x0a||Res=='n')
					BT_RX_STA|=0x8000;	//���������	
				else
          BT_RX_STA=0;//���մ���,���¿�ʼ				
			}
			else //��û�յ�0X0D
			{	
				if(Res==0x0d||Res=='/')
				{
					BT_RX_STA|=0x4000;
				}
				else
				{
					BT_RX_BUF[BT_RX_STA&0X3FFF]=Res;
					BT_RX_STA++;
					if(BT_RX_STA>(BT_REC_LEN-1))
						BT_RX_STA=0;//�������ݴ���,���¿�ʼ����	  
				}		 
			}
		}   		 
  } 								 
} 
