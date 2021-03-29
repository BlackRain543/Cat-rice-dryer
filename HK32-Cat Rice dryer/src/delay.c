#include "delay.h"
#include "hk32f030m.h" 

volatile static uint32_t TimingDelay;

//��ʱ����
void Delay_ms(volatile uint32_t nms)
{
    //SYSTICK��Ƶ--1ms��ϵͳʱ���ж�
    if (SysTick_Config(SystemCoreClock/1000))
    {
        while (1);
    }
    TimingDelay=nms;//��ȡ��ʱʱ��
    while(TimingDelay);
    SysTick->CTRL=0x00; //�رռ�����
    SysTick->VAL =0X00; //��ռ�����
}


//��ʱ΢��
void Delay_10us(volatile uint32_t nus)
{
 //SYSTICK��Ƶ--1us��ϵͳʱ���ж�
    if (SysTick_Config(SystemCoreClock/100000))
    {
        while (1);
    }
    TimingDelay=nus;//��ȡ��ʱʱ��
    while(TimingDelay);
    SysTick->CTRL=0x00; //�رռ�����
    SysTick->VAL =0X00; //��ռ�����
}

void TimingDelay_Decrement(void){
	if(TimingDelay != 0x00){
		TimingDelay--;
	}
}
