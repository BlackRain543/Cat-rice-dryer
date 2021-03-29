#include "motor.h"
#include "hk32f030m_gpio.h"

//直流电机---GPIO初始化
void M_GPIO_Init(void){
	//声明结构体
	GPIO_InitTypeDef GPIO_InitStructure;	
	
	//使能GPIO口的定时器
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);		//C定时器
	
	//配置Motor--GPIO口
	GPIO_InitStructure.GPIO_Pin	 	= GPIO_Pin_3| GPIO_Pin_4;	//引脚号
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;					//模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;			//速率,10MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}

//正转
void M_forward(void){
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
}

//反转
void M_back(void){
	GPIO_SetBits(GPIOC,GPIO_Pin_3);
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
}

//停止
void M_stop(void){
	GPIO_ResetBits(GPIOC,GPIO_Pin_3|GPIO_Pin_4);
}
