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
int cmd=0;
	
 int main(void)
 { 	 
	u8 t;
	u8 key; 
	float temp;	 
	u8 display1[16];	
	u8 display2[16];
	u8 reclen=0;
	 
	 int cmd0;
	 
//	 FLASH_Unlock();
//	 FLASH_ReadOutProtection(DISABLE);
	 
	delay_init();	    	 //��ʱ������ʼ��	  
//	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
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
//		fromOtoA();									//��㵽D

//		fromAtoB();									//D�⵽C��
//	
//		fromBtoO();									//D�⵽C��
		
		while(cmd==0)		
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display1,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display1,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			
			if(USART2_RX_STA&0X8000)
			{
				reclen=USART2_RX_STA&0X7FFF;	//�õ����ݳ���
				USART2_RX_BUF[reclen]=0;	 	//���������
				USART2_RX_STA=0;
				cmd0=1000*(USART2_RX_BUF[0]-48)+100*(USART2_RX_BUF[1]-48)+10*(USART2_RX_BUF[2]-48)+(USART2_RX_BUF[3]-48);	
				if(cmd0==1122||cmd0==1212||cmd0==2112||cmd0==1221||cmd0==2121||cmd0==2211||cmd0==1222||cmd0==2122||cmd0==2221)
				{
					cmd=cmd0;
					sprintf((char*)display1,"Receive: %d",cmd);
					OLED_ShowStr(0,4,display1,2);			//��ʾ��������	
				}
			}				
		}	
		
		fromOtoX();
		
		while(1);
			
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
