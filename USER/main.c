#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "adc.h"
#include "key.h"
#include "usart2.h"
#include "hc05.h"


//ALIENTEK Mini STM32开发板范例代码15
//ADC实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
   	
 int main(void)
 { 
	u8 t;
	u8 key;
	 
	u8 sendbuf[20];	  
	u8 reclen=0;
	 
	u16 adcx,send_adcx,num_adcx;
	float temp;
	 
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	KEY_Init();				//初始化按键

 	LCD_Init();
 	Adc_Init();		  		//ADC初始化	
	POINT_COLOR=RED;
	while(HC05_Init())
	{
		LCD_ShowString(20,50,200,24,24,"BT CONNECT ERROR!");
	}
	 
	HC05_Set_Cmd("AT+ROLE=1");	
	 
	POINT_COLOR=BLUE;
		 LCD_ShowString(60,190,200,16,16,"BT:");	
	 
		 LCD_ShowString(60,50,200,16,16,"ADC_CH1:");	
		 LCD_ShowString(60,70,200,16,16,"ADC_CH2:");	
		 LCD_ShowString(60,90,200,16,16,"ADC_CH3:");
		 LCD_ShowString(60,110,200,16,16,"ADC_CH4:");	
		 LCD_ShowString(60,130,200,16,16,"ADC_CH5:");	      
		 LCD_ShowString(60,150,200,16,16,"ADC_CH6:");	   
	POINT_COLOR=RED;	

	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_0,10);
		LCD_ShowxNum(132,50,adcx,4,16,0);//显示ADC1的值
		if(adcx>3000)
		{
			send_adcx=adcx+10000;
			num_adcx++;
		}
				
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		LCD_ShowxNum(132,70,adcx,4,16,0);//显示ADC2的值
		if(adcx>3000)
		{
			send_adcx=adcx+20000;
			num_adcx++;
		}
		
		adcx=Get_Adc_Average(ADC_Channel_4,10);
		LCD_ShowxNum(132,90,adcx,4,16,0);//显示ADC3的值
		if(adcx>3000)
		{
			send_adcx=adcx+30000;
			num_adcx++;
		}
		
		adcx=Get_Adc_Average(ADC_Channel_5,10);
		LCD_ShowxNum(132,110,adcx,4,16,0);//显示ADC4的值
		if(adcx>3000)
		{
			send_adcx=adcx+40000;
			num_adcx++;
		}
		
		adcx=Get_Adc_Average(ADC_Channel_6,10);
		LCD_ShowxNum(132,130,adcx,4,16,0);//显示ADC5的值
		if(adcx>3000)
		{
			send_adcx=adcx+50000;
			num_adcx++;
		}
		
		adcx=Get_Adc_Average(ADC_Channel_7,10);
		LCD_ShowxNum(132,150,adcx,4,16,0);//显示ADC6的值
		if(adcx>3000)
		{
			send_adcx=adcx+60000;
			num_adcx++;
		}
		
		if(num_adcx==0)
			send_adcx=0;
		
		num_adcx=0;
		
		
	
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
		
		if(t==5)
		{
			if(send_adcx)					
			{
				sprintf((char*)sendbuf,"%d",send_adcx);
				LCD_ShowString(92,190,200,16,16,sendbuf);		//显示发送数据	
				u2_printf("%d\r\n",send_adcx);		//发送到蓝牙模块
			}   
			t=0;
		}			
			  															     				   
		t++;	
	}		
		
		
//		temp=(float)adcx*(3.3/4096);
//		adcx=temp;

											    
}	
