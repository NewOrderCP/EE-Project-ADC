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
	 
	u8 sendbuf[20];	  

	float temp;
	 
	u8 display1[16];	
	u8 display2[16];
	 
//	 FLASH_Unlock();
//	 FLASH_ReadOutProtection(DISABLE);
	 
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	KEY_Init();				//初始化按键
//	Adc_Init();				//ADC初始化	
	HC_SR04_Init();
	 
	I2C_Configuration();
	OLED_Init();						//OLED初始化
	OLED_Fill(0x00);					//OLED全屏灭
	 

//	while(HC05_Init())
//	{
//		sprintf((char*)display2,"BT CONNECTING...");
//		OLED_ShowStr(0,2,display2,2);
//	}
//	OLED_Fill(0x00);					//OLED全屏灭
	 
//	HC05_Set_Cmd("AT+ROLE=1");	
//	HC05_Set_Cmd("AT+NAME=master");
	delay_ms(1000);


	while(1)
	{
		hc1_running();
		if(dis1<200)
		{
			sprintf((char*)display1,"1: %6.3f",dis1);
			OLED_ShowStr(0,0,display1,2);//显示HC1的值
		}
		else dis1=0;

		hc2_running();
		if(dis2<60)
		{
			sprintf((char*)display1,"2: %6.3f",dis2);
			OLED_ShowStr(0,2,display1,2);//显示HC2的值
		}
		else dis2=0;
		
		hc3_running();
		if(dis3<60)
		{
			sprintf((char*)display1,"3: %6.3f",dis3);
			OLED_ShowStr(0,2,display1,2);//显示HC3的值
		}
		else dis3=0;
		
		hc4_running();
		if(dis4<60)
		{
			sprintf((char*)display1,"4: %6.3f",dis4);
			OLED_ShowStr(0,2,display1,2);//显示HC4的值
		}
		else dis4=0;
		
		hc5_running();
		if(dis5<60)
		{
			sprintf((char*)display1,"5: %6.3f",dis5);
			OLED_ShowStr(0,2,display1,2);//显示HC5的值
		}
		else dis5=0;

		hc6_running();
		if(dis6<120)
		{
			sprintf((char*)display1,"6: %6.3f",dis6);
			OLED_ShowStr(0,4,display1,2);//显示HC6的值
		}
		else dis6=0;
		
		hc7_running();
		if(dis7<120)
		{
			sprintf((char*)display1,"7: %6.3f",dis7);
			OLED_ShowStr(0,4,display1,2);//显示HC7的值
		}
		else dis7=0;
		
		
		sprintf((char*)display2,"BT: %d",hc_send);
		OLED_ShowStr(0,6,display2,2);					//显示发送数据	
		u2_printf("%d\r\n",hc_send);					//发送到蓝牙模块
		
		while(d1)
			fromOtoD();									//起点到D库
		
		while(d2)
			fromDtoC();									//D库到C库
		
//		key=KEY_Scan(0);
//		if(key==KEY0_PRES)						//切换模块主从设置
//		{
//			key=HC05_Get_Role();
//			if(key!=0XFF)
//			{
//				key=!key;  					//状态取反	   
//				if(key==0)HC05_Set_Cmd("AT+ROLE=0");
//				else HC05_Set_Cmd("AT+ROLE=1");
//				HC05_Set_Cmd("AT+RESET");	//复位ATK-HC05模块
//			}
//		}
//		else delay_ms(10);	
	}											    
}	
