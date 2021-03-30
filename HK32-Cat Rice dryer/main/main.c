#include "main.h"
#include <stdio.h>
#include "hk32f030m.h"

//�Զ����
#include "beep.h"
#include "usart.h"
#include "led.h"
#include "motor.h"
#include "delay.h"

//Tuya SDK
#include "wifi.h"
#include "mcu_api.h"

uint8_t QuickFeed_State = 1;						//����ιʳ״̬
uint8_t ManualFeed_State = 1;						//�ֶ�ιʳ״̬

int main(void)
{	 
	LED_GPIO_Init();											// LED���ų�ʼ��
	M_GPIO_Init();												// ����������ų�ʼ��
	HKBEEP_Init();												// ��������ʼ��
	Usart_Init();													// ���ڳ�ʼ��
	wifi_protocol_init();									// wifi��ʼ��

	while(1)
	{
		//TuyaSDK
		wifi_uart_service();
		Uart_Receive();
	}
}
