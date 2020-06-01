#include "Header.h"

u8 Target1=0;//舵机控制时间
u8 Target2=0;
u8 Target3=0;
u8 Target4=0;

u8 Times1=0;//舵机控制次数
u8 Times2=0;
u8 Times3=0;
u8 Times4=0;

u8 Open_JumpEdge=0;//开垃圾桶单位时间
u8 WakeUp_Flag=0;//唤醒标志位

u8 Send_JumpEdge=0;
u8 SendBuff[50]={'L','J',0};
	
int main(void)
{	
	SystemInit(0X00000);	//参数为向量表的偏移地址
	delay_init();//初始化延时
	MP3_Init();//初始化MP3语音播报模块
	YuYin_Init();//初始化语音识别模块
	SysTick_Init();//初始化多功能定时器
  PWM_Init();//初始化PWM
	BT_Init(9600);//初始化蓝牙
	
	SendBuff[10]=50;
	
  while(1)
	{
		if(YuYin_RX_STA == 1)//收到语音指令
		{
			if(MP3_State() == 0)
			{
				if(YuYin_RX_CMD=='a' || YuYin_RX_CMD=='b')//唤醒
				{
					WakeUp_Flag = 1;//唤醒词标志位置位
					MP3_Star(5);
					delay_ms(1500);
					delay_ms(1500);					
				}
				else if(WakeUp_Flag == 1)
				{
					WakeUp_Flag=0;
					
					if(YuYin_RX_CMD%4 == 1)//厨余垃圾
					{
						MP3_Star(1);
						Target1 = 1;
						
						Times1++;
						if(Times1>255)
							Times1=255;
						SendBuff[6]=Times1;						
					}
					else if(YuYin_RX_CMD%4 == 2)//其他垃圾
					{
						MP3_Star(2);
						Target2 = 1;
						
						Times2++;
						if(Times2>255)
							Times2=255;
						SendBuff[7]=Times2;						
					}
					else if(YuYin_RX_CMD%4 == 3)//有害垃圾
					{
						MP3_Star(3);
						Target3 = 1;
						
						Times3++;
						if(Times3>255)
							Times3=255;
						SendBuff[8]=Times3;						
					}
					else//可回收物
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
		
		if(SysTick_JumpEdge(&Open_JumpEdge, &SysTickBit.Time1s))//开垃圾桶单位时间到
		{
		  if(Target1 != 0)//厨余垃圾桶打开
			{
			  Target1++;
				TIM_SetCompare1(TIM4,1200);//打开
				SendBuff[2]='1';
				
				if(Target1>6)
				{
					TIM_SetCompare1(TIM4,400);//时间到关闭
				  Target1 = 0;
					SendBuff[2]='0';
				}					
			}
			if(Target2 != 0)//其他垃圾桶打开
			{
				Target2++;
				TIM_SetCompare2(TIM4,1200);//打开
				SendBuff[3]='1';
				
				if(Target2>6)
				{
					TIM_SetCompare2(TIM4,400);//时间到关闭
					Target2 = 0;
					SendBuff[3]='0';
				}	
			}	
			if(Target3 != 0)//有害垃圾桶打开
			{
				Target3++;
				TIM_SetCompare3(TIM4,1200);//打开
				SendBuff[4]='1';
				
				if(Target3>6)
				{
					TIM_SetCompare3(TIM4,400);//时间到关闭
					Target3 = 0;
					SendBuff[4]='0';
				}	
			}
			if(Target4 != 0)//可回收物桶打开
			{
				Target4++;
				TIM_SetCompare4(TIM4,1200);//打开
				SendBuff[5]='1';
				
				if(Target4>6)
				{
					TIM_SetCompare4(TIM4,400);//时间到关闭
					Target4 = 0;
					SendBuff[5]='0';
				}	
			}
		}
		
		if(SysTick_JumpEdge(&Send_JumpEdge, &SysTickBit.Time1s))//开垃圾桶单位时间到
		{
		   BT_Send_Datas(SendBuff,11);
		}
	}
}

