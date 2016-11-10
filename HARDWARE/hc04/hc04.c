#include "stm32f10x.h"
#include "sys.h"
#include "delay.h"
#include "hc04.h"
#include "math.h"

#define SIDE 3

u16 cnt;    //�����޶�������  ��hcrs04.h�пɼ�
u32 tim;		//��ʱʱ��    ��hcrs04.h�пɼ�
float dis1,dis2,dis3,dis4,dis5,dis6,dis7 ;				        //����
float ave[3],error[3];
int i=0;

void HC_SR04_Init(void)										
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;					
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_14|GPIO_Pin_3|GPIO_Pin_5;		//ECHO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		//��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_15|GPIO_Pin_4|GPIO_Pin_8;		//TRIG	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			//ģ�����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOB, GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_8);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_10|GPIO_Pin_12;		//ECHO
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 		//��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_15;		//TRIG	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			//ģ�����
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOA, GPIO_Pin_8 |GPIO_Pin_9|GPIO_Pin_10 |GPIO_Pin_11|GPIO_Pin_12 |GPIO_Pin_15);
	
	Tim2_Init(10, 71);
}

void hc1_running(void)
{
	for(i=0;i<3;i++)
	{
		PBout(13)=1;
		delay_us(15);
		PBout(13)=0;
		while(PBin(12) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PBin(12) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis1=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis1;
	}		
	dis1=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis1);
	error[1]=fabs(ave[1]-dis1);
	error[2]=fabs(ave[2]-dis1);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis1=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis1=ave[1];
	else dis1=ave[2];
}

void hc2_running(void)
{
	for(i=0;i<3;i++)
	{
		PBout(15)=1;
		delay_us(15);
		PBout(15)=0;
		while(PBin(14) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PBin(14) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis2=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis2;
	}		
	dis2=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis2);
	error[1]=fabs(ave[1]-dis2);
	error[2]=fabs(ave[2]-dis2);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis2=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis2=ave[1];
	else dis2=ave[2];		
}

void hc3_running(void)
{
	for(i=0;i<3;i++)
	{
		PAout(9)=1;
		delay_us(15);
		PAout(9)=0;
		while(PAin(8) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PAin(8) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis3=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis3;
	}		
	dis3=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis3);
	error[1]=fabs(ave[1]-dis3);
	error[2]=fabs(ave[2]-dis3);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis3=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis3=ave[1];
	else dis3=ave[2];		
}

void hc4_running(void)
{
	for(i=0;i<3;i++)
	{
		PAout(11)=1;
		delay_us(15);
		PAout(11)=0;
		while(PAin(10) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PAin(10) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis4=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis4;
	}		
	dis4=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis4);
	error[1]=fabs(ave[1]-dis4);
	error[2]=fabs(ave[2]-dis4);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis4=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis4=ave[1];
	else dis4=ave[2];	
}

void hc5_running(void)
{
	for(i=0;i<3;i++)
	{
		PAout(15)=1;
		delay_us(15);
		PAout(15)=0;
		while(PAin(12) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PAin(12) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis5=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis5;
	}		
	dis5=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis5);
	error[1]=fabs(ave[1]-dis5);
	error[2]=fabs(ave[2]-dis5);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis5=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis5=ave[1];
	else dis5=ave[2];	
	
}

void hc6_running(void)
{
	for(i=0;i<3;i++)
	{
		PBout(4)=1;
		delay_us(15);
		PBout(4)=0;
		while(PBin(3) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PBin(3) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis6=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis6;
	}		
	dis6=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis6);
	error[1]=fabs(ave[1]-dis6);
	error[2]=fabs(ave[2]-dis6);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis6=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis6=ave[1];
	else dis6=ave[2];	
	
}

void hc7_running(void)
{
	for(i=0;i<3;i++)
	{
		PBout(8)=1;
		delay_us(15);
		PBout(8)=0;
		while(PBin(5) == 0);
		TIM_Cmd(TIM2, ENABLE);
		while(PBin(5) == 1);
		TIM_Cmd(TIM2, DISABLE);
		tim= TIM_GetCounter(TIM2);
		tim=tim+cnt*10;
		dis7=tim*0.017-SIDE;
		TIM2->CNT=0;											
		cnt=0; 
		ave[i]=dis7;
	}		
	dis7=(ave[0]+ave[1]+ave[2])/3;
	error[0]=fabs(ave[0]-dis7);
	error[1]=fabs(ave[1]-dis7);
	error[2]=fabs(ave[2]-dis7);
	if(error[0]<=error[1]&&error[0]<=error[2])
		dis7=ave[0];
	else if(error[1]<=error[0]&&error[1]<=error[2])
		dis7=ave[1];
	else dis7=ave[2];	
	
}

void Tim2_Init(u16 arr,u16 psc)	//arr���Զ���װֵ��	 psc��ʱ��Ԥ��Ƶ��
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); //ʱ��ʹ��

	TIM_TimeBaseStructure.TIM_Period = arr; //������5000Ϊ500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc;  //72MHz/7200=10Khz�ļ���Ƶ��  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = TIM_CKD_DIV1
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); 
	//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_ITConfig(TIM2,	TIM_IT_Update, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure); 
}

/*�жϷ�����򣺲�ѯ�жϱ�־λ�ж��Ƿ��ж�ʱ���жϡ�����жϹ���λ*/
void TIM2_IRQHandler(void)   //TIM2�жϷ����ӳ���
{
	/*���ָ����TIM�жϷ������:TIM �ж�Դ(ʵ���ϲ��ж�Ҳ�ǿ��Եģ�*/
	if (TIM_GetITStatus(TIM2, TIM_IT_Update ) != RESET)  
	{
		
		/*���TIMx���жϴ�����λ:TIM �ж�Դ */
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);  
		cnt++;

		if(cnt == 2000)			//�����2000*10*0.00017=3.4m
		{
			cnt=0;
		}
	}
}