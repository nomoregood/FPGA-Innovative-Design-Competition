#include "LED.h"



void LED_Init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO,ENABLE);//使能PORTC、复用功能时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;//HW
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC13
	
	GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PB.5 输出高
	GPIO_SetBits(GPIOC,GPIO_Pin_13);						 //PB.5 输出高
}

