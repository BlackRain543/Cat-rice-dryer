#ifndef __BEEP_H
#define __BEEP_H

#include <stdio.h>
#include <stdint.h>

void HKBEEP_Init(void);
void SetPrescaler(uint8_t BEEP_Prescaler);
void Sound(uint16_t  frq);
void play_music(void);
void Beep_1s(void);

void PowerOn(void);
void PowerOff(void);
	
#endif

