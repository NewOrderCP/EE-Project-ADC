#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "key.h"
#include "usart2.h"
#include "hc05.h"
#include "OLED_I2C.h"
#include "hc04.h"
#include "entrance.h"

extern float dis1,dis2,dis3,dis4,dis5,dis6,dis7 ;	
u32 hc_send;

extern int p1,p2,p3,p4,p5,p6,p7;
extern int d1,d2,d3,d4;
	
 int main(void)
 { 	 
	u8 t;
	u8 key; 
	float temp;	 
	u8 display1[16];	
	u8 display2[16];
	 
	d1=1;		//����1��ѭ��������0��ѭ��ֻ��ⳬ����
	 
//	 FLASH_Unlock();
//	 FLASH_ReadOutProtection(DISABLE);
	 
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	HC_SR04_Init();	 					//��������ʼ��
	I2C_Configuration();				//I2C��ʼ��
	OLED_Init();						//OLED��ʼ��
	OLED_Fill(0x00);					//OLEDȫ����
	 
	while(HC05_Init())
	{
		sprintf((char*)display2,"BT CONNECTING...");
		OLED_ShowStr(0,2,display2,2);
	}
	OLED_Fill(0x00);					//OLEDȫ����
	 
//	HC05_Set_Cmd("AT+ROLE=1");	
//	HC05_Set_Cmd("AT+NAME=master");
	delay_ms(1000);

	while(1)
	{
//		hc1_running();
//		sprintf((char*)display1,"1:%4.1f",dis1);
//		OLED_ShowStr(0,0,display1,2);//��ʾHC1��ֵ

//		hc2_running();
//		sprintf((char*)display1,"2:%4.1f",dis2);
//		OLED_ShowStr(64,0,display1,2);//��ʾHC2��ֵ
//	
//		hc3_running();
//		sprintf((char*)display1,"3:%4.1f",dis3);
//		OLED_ShowStr(0,2,display1,2);//��ʾHC3��ֵ
//		
//		hc4_running();
//		sprintf((char*)display1,"4:%4.1f",dis4);
//		OLED_ShowStr(64,2,display1,2);//��ʾHC4��ֵ
//		
//		hc5_running();
//		sprintf((char*)display1,"5:%5.2f",dis5);
//		OLED_ShowStr(0,4,display1,2);//��ʾHC5��ֵ

//		hc6_running();
//		sprintf((char*)display1,"6:%5.2f",dis6);
//		OLED_ShowStr(64,4,display1,2);//��ʾHC6��ֵ
//		
//		hc7_running();
//		sprintf((char*)display1,"7:%4.1f",dis7);
//		OLED_ShowStr(0,6,display1,2);//��ʾHC7��ֵ
//		
//		OLED_Fill(0x00);					//OLEDȫ����

		fromOtoD();									//��㵽D
		
		while(1);
//		
//		while(d2)
//		{
//			fromDtoC();									//D�⵽C��
//			delay_ms(10);
//		}
//		
//		while(d3)
//		{
//			fromCtoO();									//D�⵽C��
//			delay_ms(10);
//		}
		
		
//		key=KEY_Scan(0);
//		if(key==KEY0_PRES)						//�л�ģ����������
//		{
//			key=HC05_Get_Role();
//			if(key!=0XFF)
//			{
//				key=!key;  					//״̬ȡ��	   
//				if(key==0)HC05_Set_Cmd("AT+ROLE=0");
//				else HC05_Set_Cmd("AT+ROLE=1");
//				HC05_Set_Cmd("AT+RESET");	//��λATK-HC05ģ��
//			}
//		}
//		else delay_ms(10);	
	}											    
}	
