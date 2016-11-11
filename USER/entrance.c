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

#define LONG 12
#define WIDE 11

extern float dis1,dis2,dis3,dis4,dis5,dis6,dis7,dis8 ;	
extern u32 hc_send;
extern int cmd;
int num=0;

u8 display3[16];	

void fromOtoA(void)
{
	hc1_running();
	
		while(dis1>20)
		{
			hc_send=180;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
			hc1_running();
			sprintf((char*)display3,"DIS1: %f",dis1);
			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}
		
	hc5_running();
	hc7_running();
		
		while(dis5>40&&dis7>20)
		{
			hc_send=190;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc5_running();
			hc7_running();
//			sprintf((char*)display3,"DIS5: %f",dis5);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}
		
	hc5_running();
	hc6_running();
		
		while(dis5>15||dis6>20)
		{
			hc_send=100;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc5_running();
			hc6_running();
//			sprintf((char*)display3,"DIS5: %f",dis5);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}	
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=555;							//ת����180ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;
		
		hc5_running();
		hc6_running();
		OLED_Fill(0x00);						//OLEDȫ����
		sprintf((char*)display3,"Front: %4.2f cm",35-(dis5+LONG));
		OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
		sprintf((char*)display3,"Behind: %4.2f cm",dis5);
		OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Left: %4.2f cm",25-(dis6+WIDE));
		OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Right: %4.2f cm",dis6);
		OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;
		
		OLED_Fill(0x00);
		
}

void fromAtoB(void)
{
	hc7_running();
	hc5_running();
	
		while(dis7>15||dis5<35)
		{
			hc_send=180;				
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
			hc7_running();
			hc5_running();
//			sprintf((char*)display3,"DIS7: %f",dis7);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}
		
	hc4_running();
				
		while(dis4>45)
		{
			hc_send=270;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc4_running();
//			sprintf((char*)display3,"DIS4: %f",dis4);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}
		
	hc4_running();
	hc6_running();
		
		while(dis4>10||dis6>55)
		{
			hc_send=100;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc4_running();
			hc6_running();
//			sprintf((char*)display3,"DIS4: %f",dis4);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}	
	
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=666;					
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;
		
		hc4_running();
		hc6_running();	
		OLED_Fill(0x00);						//OLEDȫ����
		sprintf((char*)display3,"Front: %4.2f cm",35-(dis6+LONG-25));
		OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
		sprintf((char*)display3,"Behind: %4.2f cm",dis6-25);
		OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Left: %4.2f cm",dis4);
		OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Right: %4.2f cm",25-(dis4+WIDE));
		OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;
			
		OLED_Fill(0x00);

}

void fromBtoO(void)
{
	hc4_running();
	hc7_running();
	
		while(dis4<35||dis7>50)
		{
			hc_send=180;			
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
			hc4_running();
			hc7_running();
//			sprintf((char*)display3,"DIS4: %f",dis4);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������			
		}
		
	hc1_running();
				
		while(dis1>20)
		{
			hc_send=270;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc1_running();
//			sprintf((char*)display3,"DIS1: %f",dis1);
//			OLED_ShowStr(0,0,display3,2);					//��ʾ��������	
		}
		
		while(num<12)
		{
			hc_send=100;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			delay_ms(100);
			num++;
		}	
		num=0;
	
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=555;					
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;	
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
}

void fromOtoX(void)
{
	hc1_running();

	while(dis1>15)
	{
		hc_send=180;									
		sprintf((char*)display3,"BT: %d",hc_send);
		OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
		u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
		hc1_running();
	}
	
	
	
	if((cmd%10)==1)
	{
		hc2_running();
		while(dis2>40)
		{
			hc_send=190;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc2_running();
		}
		
		hc2_running();
		while(dis2>15)
		{
			hc_send=100;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc2_running();
		}
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=555;							//ת����180ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;
		
		hc2_running();

		OLED_Fill(0x00);						//OLEDȫ����
		sprintf((char*)display3,"Front: %4.2f cm",35-(dis2+LONG));
		OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
		sprintf((char*)display3,"Behind: %4.2f cm",dis2);
		OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Left: 5.38 cm");
		OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Right: 7.62 cm");
		OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;	
		OLED_Fill(0x00);
		
		hc2_running();
		while(dis2<35)
		{
			hc_send=180;				
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
			hc2_running();
		}
	}
	
	
	
	
	if((cmd%100)/10==1)
	{
		hc3_running();
		while(dis3>40)
		{
			hc_send=190;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc3_running();
		}
		
		hc3_running();
		while(dis3>7)
		{
			hc_send=100;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc3_running();
		}
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=444;							//ת����90ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;
		
		hc3_running();
		hc6_running();

		OLED_Fill(0x00);						//OLEDȫ����
		sprintf((char*)display3,"Front: %4.2f cm",dis6-60);
		OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
		sprintf((char*)display3,"Behind: %4.2f cm",35-(dis1-60)-LONG);
		OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Left: %4.2f cm",25-dis3-WIDE);
		OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Right: %4.2f cm",dis3);
		OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;	
		OLED_Fill(0x00);
		
		hc3_running();
		while(dis3<35)
		{
			hc_send=180;				
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
			hc3_running();
		}
	}
	
	
	
	if((cmd%1000)/100==1)
	{
		hc4_running();
		while(dis4>40)
		{
			hc_send=190;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc4_running();
		}
		
		hc4_running();
		while(dis4>7)
		{
			hc_send=100;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc4_running();
		}
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=666;							//ת����90ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;
		
		hc4_running();
		hc6_running();	
		OLED_Fill(0x00);						//OLEDȫ����
		sprintf((char*)display3,"Front: %4.2f cm",35-(dis6+LONG-25));
		OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
		sprintf((char*)display3,"Behind: %4.2f cm",dis6-25);
		OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Left: %4.2f cm",dis4);
		OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Right: %4.2f cm",25-(dis4+WIDE));
		OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;	
		OLED_Fill(0x00);
		
		hc4_running();
		hc7_running();
		while(dis4<35||dis7>50)
		{
			hc_send=180;				
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��		
			hc4_running();
			hc7_running();
		}
	}
	
	
	
	
	
	if(cmd/1000==1)
	{
		hc5_running();
		hc7_running();	
		while(dis5>40||dis7>15)
		{
			hc_send=190;								
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc5_running();
			hc7_running();
		}
		
		hc5_running();
		hc6_running();		
		while(dis5>15||dis6>20)
		{
			hc_send=100;									
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);					//��ʾ��������	
			u2_printf("%d\r\n",hc_send);					//���͵�����ģ��
			hc5_running();
			hc6_running();
		}	
		
		while(num<10)
		{
			hc_send=111;							//ָֹͣ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
			delay_ms(5);			
			num++;
		}
		num=0;
		
		while(num<10)
		{
			hc_send=555;							//ת����180ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}
		num=0;
		
		hc5_running();
		hc6_running();
		OLED_Fill(0x00);						//OLEDȫ����
		sprintf((char*)display3,"Front: %4.2f cm",35-(dis5+LONG));
		OLED_ShowStr(0,0,display3,2);								//��ʾǰ���߾���
		sprintf((char*)display3,"Behind: %4.2f cm",dis5);
		OLED_ShowStr(0,2,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Left: %4.2f cm",25-(dis6+WIDE));
		OLED_ShowStr(0,4,display3,2);								//��ʾ����߾���
		sprintf((char*)display3,"Right: %4.2f cm",dis6);
		OLED_ShowStr(0,6,display3,2);								//��ʾ�ұ��߾���
		
		while(num<200)
		{
			hc_send=222;							//����ָ������ָ��
			sprintf((char*)display3,"BT: %d",hc_send);
			OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
			u2_printf("%d\r\n",hc_send);			//���͵�����ģ��	
			delay_ms(5);	
			num++;
		}		
		num=0;
		
		OLED_Fill(0x00);
		
	}
	
	while(1)
	{
		hc_send=111;							//ָֹͣ��
		sprintf((char*)display3,"BT: %d",hc_send);
		OLED_ShowStr(0,6,display3,2);			//��ʾ��������	
		u2_printf("%d\r\n",hc_send);			//���͵�����ģ��
		delay_ms(5);			
		num++;
	}
}