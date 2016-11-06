#ifndef __HCSR04_H_
#define __HCSR04_H_	 
#include "stm32f10x.h"

void HC_SR04_Init(void);
void Tim2_Init(u16 arr,u16 psc);
void hc1_running(void);
void hc2_running(void);
void hc3_running(void);
void hc4_running(void);
void hc5_running(void);
void hc6_running(void);
void hc7_running(void);

#endif