#ifndef __LED_H
#define __LED_H
#include "sys.h"

void LED_Init(void);

#define LED1 PCout(13)
#define LED2 PAout(8)

#endif
