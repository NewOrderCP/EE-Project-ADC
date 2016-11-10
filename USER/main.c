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
	 
	d1=1;		//等于1开循环，等于0关循环只检测超声波
	 
//	 FLASH_Unlock();
//	 FLASH_ReadOutProtection(DISABLE);
	 
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	HC_SR04_Init();	 					//超声波初始化
	I2C_Configuration();				//I2C初始化
	OLED_Init();						//OLED初始化
	OLED_Fill(0x00);					//OLED全屏灭
	 
	while(HC05_Init())
	{
		sprintf((char*)display2,"BT CONNECTING...");
		OLED_ShowStr(0,2,display2,2);
	}
	OLED_Fill(0x00);					//OLED全屏灭
	 
//	HC05_Set_Cmd("AT+ROLE=1");	
//	HC05_Set_Cmd("AT+NAME=master");
	delay_ms(1000);

	while(1)
	{
//		hc1_running();
//		sprintf((char*)display1,"1:%4.1f",dis1);
//		OLED_ShowStr(0,0,display1,2);//显示HC1的值

//		hc2_running();
//		sprintf((char*)display1,"2:%4.1f",dis2);
//		OLED_ShowStr(64,0,display1,2);//显示HC2的值
//	
//		hc3_running();
//		sprintf((char*)display1,"3:%4.1f",dis3);
//		OLED_ShowStr(0,2,display1,2);//显示HC3的值
//		
//		hc4_running();
//		sprintf((char*)display1,"4:%4.1f",dis4);
//		OLED_ShowStr(64,2,display1,2);//显示HC4的值
//		
//		hc5_running();
//		sprintf((char*)display1,"5:%5.2f",dis5);
//		OLED_ShowStr(0,4,display1,2);//显示HC5的值

//		hc6_running();
//		sprintf((char*)display1,"6:%5.2f",dis6);
//		OLED_ShowStr(64,4,display1,2);//显示HC6的值
//		
//		hc7_running();
//		sprintf((char*)display1,"7:%4.1f",dis7);
//		OLED_ShowStr(0,6,display1,2);//显示HC7的值
//		
//		OLED_Fill(0x00);					//OLED全屏灭

		fromOtoD();									//起点到D
		
		while(1);
//		
//		while(d2)
//		{
//			fromDtoC();									//D库到C库
//			delay_ms(10);
//		}
//		
//		while(d3)
//		{
//			fromCtoO();									//D库到C库
//			delay_ms(10);
//		}
		
		
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
