//#include "stm32f10x.h"
//#include "key.h"
//#include "sys.h" 
//#include "delay.h"
////////////////////////////////////////////////////////////////////////////////////	 
////本程序只供学习使用，未经作者许可，不得用于其它任何用途
////ALIENTEK精英STM32开发板
////按键驱动代码	   
////正点原子@ALIENTEK
////技术论坛:www.openedv.com
////修改日期:2012/9/3
////版本：V1.0
////版权所有，盗版必究。
////Copyright(C) 广州市星翼电子科技有限公司 2009-2019
////All rights reserved									  
////////////////////////////////////////////////////////////////////////////////////  
//								    
////按键初始化函数
//void KEY_Init(void) //IO初始化
//{ 
// 	GPIO_InitTypeDef GPIO_InitStructure;
// 
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);//使能PORTA,PORTE时钟

//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4|GPIO_Pin_3;//KEY0-KEY1
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
// 	GPIO_Init(GPIOE, &GPIO_InitStructure);//初始化GPIOE4,3

//	//初始化 WK_UP-->GPIOA.0	  下拉输入
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
//	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0

//}
////按键处理函数
////返回按键值
////mode:0,不支持连续按;1,支持连续按;
////0，没有任何按键按下
////1，KEY0按下
////2，KEY1按下
////3，KEY3按下 WK_UP
////注意此函数有响应优先级,KEY0>KEY1>KEY_UP!!
//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;//按键按松开标志
//	if(mode)key_up=1;  //支持连按		  
//	if(key_up&&(KEY0==0||KEY1==0||WK_UP==1))
//	{
//		delay_ms(10);//去抖动 
//		key_up=0;
//		if(KEY0==0)return KEY0_PRES;
//		else if(KEY1==0)return KEY1_PRES;
//		else if(WK_UP==1)return WKUP_PRES;
//	}else if(KEY0==1&&KEY1==1&&WK_UP==0)key_up=1; 	    
// 	return 0;// 无按键按下
//}


#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"
#include "led.h"
#include "usart.h"	
#include "beep.h"
//按键IO初始化函数
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PORTB时钟

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置为上拉输入
	
	//K1---PB12
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_12;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K2---PB14
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_14;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K3---PB8
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K4---PB7
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K5---PB11
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_11;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K6---PB5
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K7---PB15
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K8---PB4
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_4;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	//K9---PB13
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K10---PB6
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K11---PB9
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//K12---PB10
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	

}


////按键中断初始化函数
//void EXTIX_Init(void)
//{
// 
//		EXTI_InitTypeDef EXTI_InitStructure;
//		NVIC_InitTypeDef NVIC_InitStructure;

//    KEY_Init();	 //按键端口初始化

//  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

	
	
////中断线的设置，中断线和IO的映射		
//	  //K11---PD12
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource12);		//???D????12ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line12;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷

//		//K12---PD15
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource15);		//???D????15ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line15;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//	
//		//K13---PA0
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);		//???D????0ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line0;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K14---PA1
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource1);		//???D????0ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line1;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K15---PD14
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource14);		//???D????14ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line14;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K16---PD13
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource13);		//???D????13ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line13;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K17---PD9
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource9);		//???D????9ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line9;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K18---PD10
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource10);		//???D????10ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line10;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K19---PD11
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource11);		//???D????11ó?GPIOD???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line11;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K20---PA3
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource3);		//???D????3ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line3;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K21---PA5
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource5);		//???D????5ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line5;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K22---PA7
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource7);		//???D????7ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line7;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K23---PA4
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource4);		//???D????4ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line4;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//K24---PA2
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource2);		//???D????2ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line2;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//KL---PE8
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource8);		//???D????8ó?GPIOE???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line8;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		
//		//KR---PA6
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource6);		//???D????6ó?GPIOA???úó3é??eà′
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line6;	//?D????±êo?
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	//?D???￡ê?	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;	//???μ??′￥·￠
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;			//ê1?ü?D????
//  	EXTI_Init(&EXTI_InitStructure);	 	//?ù?YEXTI_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèEXTI??′??÷
//		

////?D??ó??è??éè??oíê1?ü?D??

//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?à??ó??è??2￡? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//×óó??è??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?à??ó??è??2￡? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//×óó??è??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?à??ó??è??2￡? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//×óó??è??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//?à??ó??è??2￡? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//×óó??è??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//?à??ó??è??2￡? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//×óó??è??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure); 
//		
//		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//?à??ó??è??2￡? 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//×óó??è??3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure); 

//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//?à??ó??è??2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//×óó??è??1 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ê1?üía2??D??í¨μà
//  	NVIC_Init(&NVIC_InitStructure);  	  //?ù?YNVIC_InitStruct?D???¨μ?2?êy3?ê??ˉíaéèNVIC??′??÷


//}




// 
////ía2??D??0·t??3ìDò
//void EXTI0_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY13==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x13);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line0);  //??3yLINE0é?μ??D??±ê????  
//}

////ía2??D??1·t??3ìDò
//void EXTI1_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY14==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x14);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line1);  //??3yLINE1é?μ??D??±ê????  
//}

////ía2??D??2·t??3ìDò
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY24==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x24);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line2);  //??3yLINE2é?μ??D??±ê????  
//}

////ía2??D??3·t??3ìDò
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY20==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x20);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line3);  //??3yLINE3é?μ??D??±ê????  
//}

////ía2??D??4·t??3ìDò
//void EXTI4_IRQHandler(void)
//{
//	delay_ms(100);//????
//	if(KEY23==0)	  
//	{
//			LED2=!LED2;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x23);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line4);  //??3yLINE4é?μ??D??±ê????  
//}


////ía2??D??5-9·t??3ìDò
//void EXTI9_5_IRQHandler(void)
//{
//	delay_ms(100);//????
//	
//	if(KEY21==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x21);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line5);
//	
//	
//	if(KEYR==0)	  
//	{
////			LED2=!LED2;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x26);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line6);
//	
//	
//	if(KEY22==0)	  
//	{
//			LED3=!LED3;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x22);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line7);
//	
//	
//	if(KEYL==0)	  
//	{
////			LED2=!LED2;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x25);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line8);
//	
//	
//	if(KEY17==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x17);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line9);
//	
//}



////ía2??D??5-9·t??3ìDò
//void EXTI15_10_IRQHandler(void)
//{
//	delay_ms(100);//????
//	
//	if(KEY18==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x18);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line10);
//	
//	
//	if(KEY19==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x19);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line11);
//	
//	
//	if(KEY11==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x11);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line12);
//	
//	
//	if(KEY16==0)	  
//	{
//			LED5=!LED5;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x16);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line13);
//	
//	
//	if(KEY15==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x15);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line14);
//	
//		
//	if(KEY12==0)	  
//	{
//			LED4=!LED4;
//			BEEP=1;
//			delay_ms(100);
//			BEEP=0;
//			USART_SendData(USART1,0x12);
//	}		 
//	EXTI_ClearITPendingBit(EXTI_Line15);
//	
//}






//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;

//0，没有任何按键按下
//1，KEY1按下
//2，KEY2按下
//3，KEY3按下
//...
//注意此函数有相应优先级,KEY1>KEY2>KEY3...!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0||KEY5==0||KEY6==0||KEY7==0||KEY8==0||KEY9==0||KEY10==0||KEY11==0||KEY12==0))
	{
		delay_ms(100);//去抖动 
		key_up=0;
		if(KEY1==0)return 1;
		else if(KEY2==0)return 2;
		else if(KEY3==0)return 3;
		else if(KEY4==0)return 4;
		else if(KEY5==0)return 5;
		else if(KEY6==0)return 6;
		else if(KEY7==0)return 7;
		else if(KEY8==0)return 8;
		else if(KEY9==0)return 9;
		else if(KEY10==0)return 10;
		else if(KEY11==0)return 11;
		else if(KEY12==0)return 12;
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1&&KEY5==1&&KEY6==1&&KEY7==1&&KEY8==1&&KEY9==1&&KEY10==1&&KEY11==1&&KEY12==1)key_up=1; 	    
	
 	return 0;//无按键按下
}

