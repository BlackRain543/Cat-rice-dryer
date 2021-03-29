#include "hk32f030m_gpio.h"
#include "led.h"
#include "delay.h"

//LED---GPIO初始化
void LED_GPIO_Init(void){
	//声明结构体
	GPIO_InitTypeDef GPIO_InitStructure;	
	
	//使能GPIO口的定时器
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD,ENABLE);	//D定时器
	
	//配置LED--GPIO口
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2| GPIO_Pin_3;//引脚号
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;				//模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;	//速率,10MHz
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOD,GPIO_Pin_2 | GPIO_Pin_3);
}

//指示灯闪烁
void LED_Blink(uint8_t time,uint8_t RLEDState,uint8_t OLEDState){
	uint16_t LED_GPIO = 0;
	if(RLEDState != 0) LED_GPIO |= GPIO_Pin_2;
	if(OLEDState != 0) LED_GPIO |= GPIO_Pin_3;

	GPIO_ResetBits(GPIOD,LED_GPIO);
	Delay_ms(time*1000);
	GPIO_SetBits(GPIOD,LED_GPIO);
	Delay_ms(time*1000);
}
