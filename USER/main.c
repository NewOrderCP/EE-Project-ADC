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
	 
	delay_init();	    	 //延时函数初始化	  
//	uart_init(9600);	 	//串口初始化为9600
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
//		fromOtoA();									//起点到D

//		fromAtoB();									//D库到C库
//	
//		fromBtoO();									//D库到C库
		
		while(cmd==0)		
		{
			hc_send=111;							//停止指令
			sprintf((char*)display1,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display1,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块
			
			if(USART2_RX_STA&0X8000)
			{
				reclen=USART2_RX_STA&0X7FFF;	//得到数据长度
				USART2_RX_BUF[reclen]=0;	 	//加入结束符
				USART2_RX_STA=0;
				cmd0=1000*(USART2_RX_BUF[0]-48)+100*(USART2_RX_BUF[1]-48)+10*(USART2_RX_BUF[2]-48)+(USART2_RX_BUF[3]-48);	
				if(cmd0==1122||cmd0==1212||cmd0==2112||cmd0==1221||cmd0==2121||cmd0==2211||cmd0==1222||cmd0==2122||cmd0==2221)
				{
					cmd=cmd0;
					sprintf((char*)display1,"Receive: %d",cmd);
					OLED_ShowStr(0,4,display1,2);			//显示发送数据	
				}
			}				
		}	
		
		fromOtoX();
		
		while(1);
			
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
