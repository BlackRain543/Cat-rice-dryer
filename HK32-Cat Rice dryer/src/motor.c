#include "motor.h"
#include "hk32f030m_gpio.h"

//ֱ�����---GPIO��ʼ��
void M_GPIO_Init(void){
	//�����ṹ��
	GPIO_InitTypeDef GPIO_InitStructure;	
	
	//ʹ��GPIO�ڵĶ�ʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC,ENABLE);		//C��ʱ��
	
	//����Motor--GPIO��
	GPIO_InitStructure.GPIO_Pin	 	= GPIO_Pin_3| GPIO_Pin_4;	//���ź�
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_OUT;					//ģʽ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;			//����,10MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}

//��ת
void M_forward(void){
	GPIO_ResetBits(GPIOC,GPIO_Pin_3);
	GPIO_SetBits(GPIOC,GPIO_Pin_4);
}

//��ת
void M_back(void){
	GPIO_SetBits(GPIOC,GPIO_Pin_3);
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
}

//ֹͣ
void M_stop(void){
	GPIO_ResetBits(GPIOC,GPIO_Pin_3|GPIO_Pin_4);
}
