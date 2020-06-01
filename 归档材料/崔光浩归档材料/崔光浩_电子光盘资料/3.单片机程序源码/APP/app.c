#include "Header.h"

u8 Target1=0;//�������ʱ��
u8 Target2=0;
u8 Target3=0;
u8 Target4=0;

u8 Times1=0;//������ƴ���
u8 Times2=0;
u8 Times3=0;
u8 Times4=0;

u8 Open_JumpEdge=0;//������Ͱ��λʱ��
u8 WakeUp_Flag=0;//���ѱ�־λ

u8 Send_JumpEdge=0;
u8 SendBuff[50]={'L','J',0};
	
int main(void)
{	
	SystemInit(0X00000);	//����Ϊ�������ƫ�Ƶ�ַ
	delay_init();//��ʼ����ʱ
	MP3_Init();//��ʼ��MP3��������ģ��
	YuYin_Init();//��ʼ������ʶ��ģ��
	SysTick_Init();//��ʼ���๦�ܶ�ʱ��
  PWM_Init();//��ʼ��PWM
	BT_Init(9600);//��ʼ������
	
	SendBuff[10]=50;
	
  while(1)
	{
		if(YuYin_RX_STA == 1)//�յ�����ָ��
		{
			if(MP3_State() == 0)
			{
				if(YuYin_RX_CMD=='a' || YuYin_RX_CMD=='b')//����
				{
					WakeUp_Flag = 1;//���Ѵʱ�־λ��λ
					MP3_Star(5);
					delay_ms(1500);
					delay_ms(1500);					
				}
				else if(WakeUp_Flag == 1)
				{
					WakeUp_Flag=0;
					
					if(YuYin_RX_CMD%4 == 1)//��������
					{
						MP3_Star(1);
						Target1 = 1;
						
						Times1++;
						if(Times1>255)
							Times1=255;
						SendBuff[6]=Times1;						
					}
					else if(YuYin_RX_CMD%4 == 2)//��������
					{
						MP3_Star(2);
						Target2 = 1;
						
						Times2++;
						if(Times2>255)
							Times2=255;
						SendBuff[7]=Times2;						
					}
					else if(YuYin_RX_CMD%4 == 3)//�к�����
					{
						MP3_Star(3);
						Target3 = 1;
						
						Times3++;
						if(Times3>255)
							Times3=255;
						SendBuff[8]=Times3;						
					}
					else//�ɻ�����
					{
						MP3_Star(4);
						Target4 = 1;
						
						Times4++;
						if(Times4>255)
							Times4=255;
						SendBuff[9]=Times4;						
					}
				}
			}
			
			YuYin_RX_CMD=0;
			YuYin_RX_STA = 0;
		}
		
		if(SysTick_JumpEdge(&Open_JumpEdge, &SysTickBit.Time1s))//������Ͱ��λʱ�䵽
		{
		  if(Target1 != 0)//��������Ͱ��
			{
			  Target1++;
				TIM_SetCompare1(TIM4,1200);//��
				SendBuff[2]='1';
				
				if(Target1>6)
				{
					TIM_SetCompare1(TIM4,400);//ʱ�䵽�ر�
				  Target1 = 0;
					SendBuff[2]='0';
				}					
			}
			if(Target2 != 0)//��������Ͱ��
			{
				Target2++;
				TIM_SetCompare2(TIM4,1200);//��
				SendBuff[3]='1';
				
				if(Target2>6)
				{
					TIM_SetCompare2(TIM4,400);//ʱ�䵽�ر�
					Target2 = 0;
					SendBuff[3]='0';
				}	
			}	
			if(Target3 != 0)//�к�����Ͱ��
			{
				Target3++;
				TIM_SetCompare3(TIM4,1200);//��
				SendBuff[4]='1';
				
				if(Target3>6)
				{
					TIM_SetCompare3(TIM4,400);//ʱ�䵽�ر�
					Target3 = 0;
					SendBuff[4]='0';
				}	
			}
			if(Target4 != 0)//�ɻ�����Ͱ��
			{
				Target4++;
				TIM_SetCompare4(TIM4,1200);//��
				SendBuff[5]='1';
				
				if(Target4>6)
				{
					TIM_SetCompare4(TIM4,400);//ʱ�䵽�ر�
					Target4 = 0;
					SendBuff[5]='0';
				}	
			}
		}
		
		if(SysTick_JumpEdge(&Send_JumpEdge, &SysTickBit.Time1s))//������Ͱ��λʱ�䵽
		{
		   BT_Send_Datas(SendBuff,11);
		}
	}
}

