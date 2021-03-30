#include "main.h"
#include <stdio.h>
#include "hk32f030m.h"

//自定义库
#include "beep.h"
#include "usart.h"
#include "led.h"
#include "motor.h"
#include "delay.h"

//Tuya SDK
#include "wifi.h"
#include "mcu_api.h"

uint8_t QuickFeed_State = 1;						//快速喂食状态
uint8_t ManualFeed_State = 1;						//手动喂食状态

int main(void)
{	 
	LED_GPIO_Init();											// LED引脚初始化
	M_GPIO_Init();												// 电机控制引脚初始化
	HKBEEP_Init();												// 蜂鸣器初始化
	Usart_Init();													// 串口初始化
	wifi_protocol_init();									// wifi初始化

	while(1)
	{
		//TuyaSDK
		wifi_uart_service();
		Uart_Receive();
	}
}
