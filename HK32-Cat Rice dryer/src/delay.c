#include "delay.h"
#include "hk32f030m.h" 

volatile static uint32_t TimingDelay;

//延时毫秒
void Delay_ms(volatile uint32_t nms)
{
    //SYSTICK分频--1ms的系统时钟中断
    if (SysTick_Config(SystemCoreClock/1000))
    {
        while (1);
    }
    TimingDelay=nms;//读取定时时间
    while(TimingDelay);
    SysTick->CTRL=0x00; //关闭计数器
    SysTick->VAL =0X00; //清空计数器
}


//延时微妙
void Delay_10us(volatile uint32_t nus)
{
 //SYSTICK分频--1us的系统时钟中断
    if (SysTick_Config(SystemCoreClock/100000))
    {
        while (1);
    }
    TimingDelay=nus;//读取定时时间
    while(TimingDelay);
    SysTick->CTRL=0x00; //关闭计数器
    SysTick->VAL =0X00; //清空计数器
}

void TimingDelay_Decrement(void){
	if(TimingDelay != 0x00){
		TimingDelay--;
	}
}
