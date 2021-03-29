#ifndef __LED_H
#define __LED_H

#include <stdio.h>
#include <stdint.h>

void LED_GPIO_Init(void);
void LED_Blink(uint8_t time,uint8_t RLEDState,uint8_t OLEDState);

#endif
