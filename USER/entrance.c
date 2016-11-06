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
int p1=1,p2,p3,p4,p5,p6,p7;
int d1=1,d2=0,d3=0,d4=0;
extern u32 hc_send;

u8 display3[16];	

void fromOtoD(void)
{
	hc1_running();
	hc2_running();
	hc6_running();
	hc7_running();
	
		hc_send=0;						//����0��ֱ��		
		
		if(dis1<15||p1==1)
		{
			hc_send=270;				//����270����ת90
			p1=0;
			p2=1;
		}
		
		if(dis1>80||dis1<105||dis2<55||p2==1)
		{
			hc_send=0;					//����0����ת90
			p2=0;
			p3=1;
		}
		
		if(dis7>95||dis7<120||p3==1)
		{
			while(dis7>120)
			{
				hc7_running();
			}
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��		
			delay_ms(200);
			
			hc_send=222;							//ԭ����ת180��ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			
			hc_send=555;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			
			delay_ms(1000);
			
			hc2_running();
			hc6_running();
			
			OLED_Fill(0x00);					//OLEDȫ����
			sprintf((char*)display3,"Front: %6.3f cm",35-(dis2+LONG));
			OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
			sprintf((char*)display3,"Behind: %6.3f cm",dis2);
			OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
			sprintf((char*)display3,"Left: %6.3f cm",25-(dis6+WIDE-95));
			OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
			sprintf((char*)display3,"Right: %6.3f cm",dis6-95);
			OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
			
			delay_ms(3000);
			
			p3=0;
			p4=1;
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
	
		hc_send=0;							//����0��ֱ��		
		
		if(dis1>80||dis1<105||dis2<55||p4==1)
		{
			hc_send=270;					//����270����ת90
			p4=0;
			p5=1;
		}
		
		if(dis1>105||dis1<140||dis3<55||p5==1)
		{
			hc_send=0;						//����0����ת90
			p5=0;
			p6=1;
		}
		
		if(dis7>60||p6==1)
		{
			while(dis7>95)
			{
				hc7_running();
			}
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��		
			delay_ms(200);
			
			hc_send=333;							//ԭ����ת90��ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			
			hc_send=555;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			
			delay_ms(1000);
			
			hc3_running();
			hc6_running();
			
			OLED_Fill(0x00);					//OLEDȫ����
			sprintf((char*)display3,"Front: %6.3f cm",dis6-60);
			OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
			sprintf((char*)display3,"Behind: %6.3f cm",35-(dis6-60+LONG));
			OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
			sprintf((char*)display3,"Left: %6.3f cm",25-(dis3+WIDE));
			OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
			sprintf((char*)display3,"Right: %6.3f cm",dis3);
			OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
			
			delay_ms(3000);
			
			p6=0;
			p7=1;
			d2=0;
			d3=1;	
		}
}