#ifndef __MOTOR_H
#define __MOTOR_H

#include <stdio.h>
#include <stdint.h>

void M_GPIO_Init(void);
void M_forward(void);
void M_back(void);
void M_stop(void);

#endif
