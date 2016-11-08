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

#define LONG 10
#define WIDE 8

extern float dis1,dis2,dis3,dis4,dis5,dis6,dis7 ;	
int n1=1,n2,p1,p2,p3,p4,p5,p6,p7;				//每一步标识位
int d1,d2,d3,d4;								//每次循环标识位
extern u32 hc_send;

u8 display3[16];	

void fromOtoD(void)
{
	hc1_running();
	hc2_running();
	hc6_running();
	hc7_running();
	
		if(dis1>300||n1==1)
		{
			hc_send=100;					//方向0，直行	
			n1=0;	
			p1=1;
		}
		
		if(dis1<15||p1==1)
		{
			hc_send=270;				//方向270，右转90
			p1=0;
			p2=1;
		}
		
		if(dis1>80||dis1<105||dis2<55||p2==1)
		{
			hc_send=180;				//方向180，右转90
			p2=0;
			p3=1;
		}
		sprintf((char*)display3,"BT: %d",hc_send);
		OLED_ShowStr(0,6,display3,2);					//显示发送数据	
		u2_printf("%d\r\n",hc_send);					//发送到蓝牙模块
		
		if(dis7>95||dis7<120||p3==1)
		{
			while(dis7>120)
			{
				hc7_running();
			}
			hc_send=111;							//停止指令
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块		
			delay_ms(500);
			
			hc_send=333;							//转向方向0指令
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块	
			delay_ms(2000);
			
			hc_send=222;							//到达指定车库指令
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块				
			delay_ms(200);
			
			hc2_running();
			hc6_running();
			
			OLED_Fill(0x00);						//OLED全屏灭
			sprintf((char*)display3,"Front: %6.3f cm",35-(dis2+LONG));
			OLED_ShowStr(0,0,display3,2);								//显示前边线距离
			sprintf((char*)display3,"Behind: %6.3f cm",dis2);
			OLED_ShowStr(0,2,display3,2);								//显示后边线距离
			sprintf((char*)display3,"Left: %6.3f cm",25-(dis6+WIDE-95));
			OLED_ShowStr(0,4,display3,2);								//显示左边线距离
			sprintf((char*)display3,"Right: %6.3f cm",dis6-95);
			OLED_ShowStr(0,6,display3,2);								//显示右边线距离
			
			delay_ms(3000);
			
			p3=0;
			n2=1;
			d1=0;	
			d2=1;				
		}
}

void fromDtoC(void)
{
	hc1_running();
	hc2_running();
	hc3_running();
	hc6_running();
	hc7_running();
	
		if(dis1>300||dis2<30||n2==1)
		{
			hc_send=100;						//方向0，直行
			n2=0;
			p4=1;
		}			
		
		if(dis1>80||dis1<105||dis2<55||dis2>35||p4==1)
		{
			hc_send=270;					//方向270，右转90
			p4=0;
			p5=1;
		}
		
		if(dis1>105||dis1<140||dis3<55||p5==1)
		{
			hc_send=180;					//方向180，右转90
			p5=0;
			p6=1;
		}
		sprintf((char*)display3,"BT: %d",hc_send);
		OLED_ShowStr(0,6,display3,2);					//显示发送数据	
		u2_printf("%d\r\n",hc_send);					//发送到蓝牙模块
		
		if(dis7>60||dis7<95||p6==1)
		{
			while(dis7>95)
			{
				hc7_running();
			}
			hc_send=111;							//停止指令
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块		
			delay_ms(500);
			
			hc_send=666;							//转向方向270指令
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块	
			delay_ms(2000);
			
			hc_send=222;							//到达指定车库指令
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//显示发送数据	
			u2_printf("%d\r\n",hc_send);			//发送到蓝牙模块		
			delay_ms(200);
			
			hc3_running();
			hc6_running();
					
			OLED_Fill(0x00);						//OLED全屏灭
			sprintf((char*)display3,"Front: %6.3f cm",dis6-60);
			OLED_ShowStr(0,0,display3,2);								//显示前边线距离
			sprintf((char*)display3,"Behind: %6.3f cm",35-(dis6-60+LONG));
			OLED_ShowStr(0,2,display3,2);								//显示后边线距离
			sprintf((char*)display3,"Left: %6.3f cm",25-(dis3+WIDE));
			OLED_ShowStr(0,4,display3,2);								//显示左边线距离
			sprintf((char*)display3,"Right: %6.3f cm",dis3);
			OLED_ShowStr(0,6,display3,2);								//显示右边线距离
			
			delay_ms(3000);
			
			p6=0;
			p7=1;
			d2=0;
			d3=1;	
		}
}