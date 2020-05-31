#include "Header.h"

TP_PIX  tp_pix={-1,-1};	  //��������
STATE State={4,0};

/**********************************
***********************************
������ô�����״̬
***********************************
**********************************/	
void Operatione(void)
{
	unsigned int Beep_Flag=0;
	
	tp_pix.x=-1;	  //��ʼ����������
	tp_pix.y=-1;
		
	if(IRQ==0&&Convert_Pos(&tp_pix))
	{	
		if(tp_pix.x>30&&tp_pix.x<70&&tp_pix.y>56&&tp_pix.y<264)//�趨ʱ��
		{
			State.Operation_Flag=1;
			Beep_Flag=1;
		}	
			
		if(Beep_Flag==1)
		{
			delay_ms(100);
      Beep_Flag=0;			
	  }
	}
}	

u8 Key_Ctrl(void)
{
	unsigned int Beep_Flag=0;
	u8 Key=0;
	
	tp_pix.x=-1;	  //��ʼ����������
	tp_pix.y=-1;
	  	
	if(IRQ==0&&Convert_Pos(&tp_pix))
	{	
		if(tp_pix.x>100&&tp_pix.x<150&&tp_pix.y>20&&tp_pix.y<100)//���ҵ�
		{
			Key=1;
			Beep_Flag=1;
		}
		else if(tp_pix.x>100&&tp_pix.x<150&&tp_pix.y>120&&tp_pix.y<200)//������
		{
			Key=2;
			Beep_Flag=1;
		}
		else if(tp_pix.x>100&&tp_pix.x<150&&tp_pix.y>220&&tp_pix.y<300)//������
		{
			Key=3;
			Beep_Flag=1;
		}
		else if(tp_pix.x>170&&tp_pix.x<220&&tp_pix.y>20&&tp_pix.y<100)//������
		{
			Key=4;
			Beep_Flag=1;
		}		
		else if(tp_pix.x>170&&tp_pix.x<220&&tp_pix.y>120&&tp_pix.y<200)//�յ�
		{
			Key=5;
			Beep_Flag=1;
		}
		else if(tp_pix.x>170&&tp_pix.x<220&&tp_pix.y>220&&tp_pix.y<300)//����
		{
			Key=6;
			Beep_Flag=1;
		}	
	}

	if(Beep_Flag==1)
	{
		delay_ms(100);
		Beep_Flag=0;			
	}
		
	return Key;

}
/**********************************
***********************************
����ʱ�䴥������
***********************************
**********************************/	
u8 Key_Time(void)
{
	unsigned int Beep_Flag=0;
	u8 Key=0;
	
	tp_pix.x=-1;	  //��ʼ����������
	tp_pix.y=-1;
	  	
	if(IRQ==0&&Convert_Pos(&tp_pix))
	{	
		if(tp_pix.x>0&&tp_pix.x<50&&tp_pix.y>0&&tp_pix.y<60)//��
		{
			Key=1;
			Beep_Flag=1;
		}
		else if(tp_pix.x>0&&tp_pix.x<50&&tp_pix.y>130&&tp_pix.y<190)//��
		{
			Key=2;
			Beep_Flag=1;
		}	
		else if(tp_pix.x>0&&tp_pix.x<50&&tp_pix.y>260&&tp_pix.y<320)//ȷ��
		{
			Key=3;
			Beep_Flag=1;
		}		
		if(Beep_Flag==1)
		{
			delay_ms(100);
			Beep_Flag=0;			
		}
	}
	
	return Key;
}
/**********************************
***********************************
����ʱ�����
***********************************
**********************************/	
void Display_Time(void)
{
	u8 Dis_Buff[3]={0,0,0};
  u8 Key=0;

	GetDS1302(&TIME);
	DS1302_Display(TIME,50,56);//��ʾʱ��
	delay_ms(100);
	Operatione();//����ѡ��
	if(State.Operation_Flag==1)//�޸�ʱ�����
	{
		TFT_Fill(0,0,50,320,BLACK);//����		
		TFT_PutString(10,25,0,"��",RED,BLACK);
		TFT_PutString(10,155,0,"��",RED,BLACK);
		TFT_PutString(10,285,0,"ȷ��",RED,BLACK);
		while(1)
		{
			TFT_PutString(50,72,1,"  ",RED,BLACK);
			delay_ms(50);
			Key=Key_Time();
			if(Key==1)
			{
				TIME.YEAR++;
				if(TIME.YEAR>=99)
					TIME.YEAR=99;
				Key=0;
			}
			if(Key==2)
			{
				TIME.YEAR--;
				if(TIME.YEAR<=0)
					TIME.YEAR=0;
				Key=0;
			}
			Dis_Buff[0]=TIME.YEAR/10;
			Dis_Buff[1]=TIME.YEAR%10;
			Dis_Buff[2]='0';
			TFT_PutNum(50,72,Dis_Buff,RED,BLACK);	
			delay_ms(50);
			if(Key==3)
			{
				while(IRQ==0);
				Key=0;
				break;				
			}
		}	
		while(1)
		{
			TFT_PutString(50,104,1,"  ",RED,BLACK);
			delay_ms(50);
			Key=Key_Time();
			if(Key==1)
			{
				TIME.MONTH++;
				if(TIME.MONTH>=12)
					TIME.MONTH=12;
				Key=0;
			}
			if(Key==2)
			{
				TIME.MONTH--;
				if(TIME.MONTH<=0)
					TIME.MONTH=0;
				Key=0;
			}
			Dis_Buff[0]=TIME.MONTH/10;
			Dis_Buff[1]=TIME.MONTH%10;
			Dis_Buff[2]='0';
			TFT_PutNum(50,104,Dis_Buff,RED,BLACK);
			delay_ms(50);
			if(Key==3)
			{
				while(IRQ==0);
				Key=0;
				break;				
			}
		}	
		while(1)
		{
			TFT_PutString(50,136,1,"  ",RED,BLACK);
			delay_ms(50);
			Key=Key_Time();
			if(Key==1)
			{
				TIME.DATE++;
				if(TIME.DATE>=31)
					TIME.DATE=31;
				Key=0;
			}
			if(Key==2)
			{
				TIME.DATE--;
				if(TIME.DATE<=0)
					TIME.DATE=0;
				Key=0;
			}
			Dis_Buff[0]=TIME.DATE/10;
			Dis_Buff[1]=TIME.DATE%10;
			Dis_Buff[2]='0';
			TFT_PutNum(50,136,Dis_Buff,RED,BLACK);
			delay_ms(50);
			if(Key==3)
			{
				while(IRQ==0);
				Key=0;
				break;				
			}
		}	
		while(1)
		{
			TFT_PutString(50,168,1,"  ",RED,BLACK);
			delay_ms(50);
			Key=Key_Time();
			if(Key==1)
			{
				TIME.HR++;
				if(TIME.HR>=24)
					TIME.HR=24;
				Key=0;
			}
			if(Key==2)
			{
				TIME.HR--;
				if(TIME.HR<=0)
					TIME.HR=0;
				Key=0;
			}
			Dis_Buff[0]=TIME.HR/10;
			Dis_Buff[1]=TIME.HR%10;
			Dis_Buff[2]='0';
			TFT_PutNum(50,168,Dis_Buff,RED,BLACK);
			delay_ms(50);
			if(Key==3)
			{
				while(IRQ==0);
				Key=0;
				break;				
			}
		}	
		while(1)
		{
			TFT_PutString(50,200,1,"  ",RED,BLACK);
			delay_ms(50);	
			Key=Key_Time();				
			if(Key==1)
			{
				TIME.MIN++;
				if(TIME.MIN>=59)
					TIME.MIN=59;
				Key=0;
			}
			if(Key==2)
			{
				TIME.MIN--;
				if(TIME.MIN<=0)
					TIME.MIN=0;
				Key=0;
			}	
			Dis_Buff[0]=TIME.MIN/10;
			Dis_Buff[1]=TIME.MIN%10;
			Dis_Buff[2]='0';
			TFT_PutNum(50,200,Dis_Buff,RED,BLACK);
			delay_ms(50);
			if(Key==3)
			{
				while(IRQ==0);
				Key=0;
				break;				
			}		
		}	
		while(1)
		{
			TFT_PutString(50,232,1,"  ",RED,BLACK);
			delay_ms(50);
			Key=Key_Time();
			if(Key==1)
			{
				TIME.SEC++;
				if(TIME.SEC>=59)
					TIME.SEC=59;
				Key=0;
			}
			if(Key==2)
			{
				TIME.SEC--;
				if(TIME.SEC<=0)
					TIME.SEC=0;
				Key=0;
			}
			Dis_Buff[0]=TIME.SEC/10;
			Dis_Buff[1]=TIME.SEC%10;
			Dis_Buff[2]='0';
			TFT_PutNum(50,232,Dis_Buff,RED,BLACK);
			delay_ms(50);
			if(Key==3)
			{
				while(IRQ==0);
				Key=0;
				break;				
			}
		}	
		InitDS1302(TIME);//д����ĺ��ʱ��	
		State.Operation_Flag=0;
		
		TFT_Fill(0,0,50,320,BLACK);
		TFT_PutString(15,20,0,"�¶�:    ��",WHITE,BLACK);	
		TFT_PutString(15,220,0,"ʪ��:    %",WHITE,BLACK);	
		
		TFT_Fill(100,20,150,100,WHITE); TFT_Fill(100,120,150,200,WHITE); TFT_Fill(100,220,150,300,WHITE);
		TFT_Fill(170,20,220,100,WHITE); TFT_Fill(170,120,220,200,WHITE); TFT_Fill(170,220,220,300,WHITE);
		
		TFT_PutString(110,36,0,"���ҵ�",BLACK,WHITE); TFT_PutString(110,136,0,"������",BLACK,WHITE);	 TFT_PutString(110,236,0,"������",BLACK,WHITE);	
		TFT_PutString(130,52,0,"��",BLACK,WHITE);	    TFT_PutString(130,152,0,"��",BLACK,WHITE);	   TFT_PutString(130,252,0,"��",BLACK,WHITE);
		TFT_PutString(180,36,0,"������",BLACK,WHITE); TFT_PutString(180,144,0,"�յ�",BLACK,WHITE);	   TFT_PutString(180,244,0,"����",BLACK,WHITE);	
		TFT_PutString(200,52,0,"��",BLACK,WHITE);	    TFT_PutString(200,152,0,"��",BLACK,WHITE);	   TFT_PutString(200,252,0,"��",BLACK,WHITE);			
	}				
}



