//#ifndef __KEY_H
//#define __KEY_H	 
//#include "sys.h"
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


////#define KEY0 PEin(4)   	//PE4
////#define KEY1 PEin(3)	//PE3 
////#define WK_UP PAin(0)	//PA0  WK_UP

//#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//读取按键0
//#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(WK_UP) 

// 

//#define KEY0_PRES 	1	//KEY0按下
//#define KEY1_PRES	  2	//KEY1按下
//#define WKUP_PRES   3	//KEY_UP按下(即WK_UP/KEY_UP)


//void KEY_Init(void);//IO初始化
//u8 KEY_Scan(u8);  	//按键扫描函数					    
//#endif
#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"

#define KEY1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define KEY2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)
#define KEY3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)
#define KEY4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
#define KEY5 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)
#define KEY6 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)
#define KEY7 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15)
#define KEY8 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_4)
#define KEY9 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13)
#define KEY10 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)

#define KEY11  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)
#define KEY12  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)

 

void EXTIX_Init(void);//外部中断初始化		 		
void KEY_Init(void);//IO3初始化
u8 KEY_Scan(u8 mode);//按键扫描函数

//u8 KEY_Scan(u8);  	//°′?üé¨?èoˉêy					    
#endif
