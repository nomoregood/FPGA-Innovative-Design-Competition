#include "key.h"

KEY_STRUCT KEY = { {0},{0},OK };
//按键初始化函数
void KEY_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO , ENABLE);//使能GPIOA时钟
	RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM2 , ENABLE);  //使能TIM2时钟
	  //=================GPIO初始化==================
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15; //KKEY1 KEY2 KEY3 KEY4对应引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//普通输入模式
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50M
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIO
	  //=================TIM2初始化==================
	TIM_TimeBaseInitStructure.TIM_Period = 2000 - 1; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 1000 - 1;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);//初始化TIM2
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE); //允许定时器2更新中断
	TIM_Cmd(TIM2, ENABLE); //使能定时器2
		//=================TIM2 中断初始化==================
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn; //定时器2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x03; //抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
} 
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) //溢出中断
	{
		if (KEY.KEY_STATUS == OK)
		{
			(!KEY1) ? (KEY.NEW[0] = 1) : (KEY.NEW[0] = 0);//根据引脚读取值给状态变量赋值
			(!KEY2) ? (KEY.NEW[1] = 1) : (KEY.NEW[1] = 0);
			(!KEY3) ? (KEY.NEW[2] = 1) : (KEY.NEW[2] = 0);
			(!KEY4) ? (KEY.NEW[3] = 1) : (KEY.NEW[3] = 0);
			KEY.KEY_STATUS = UPDAT;
		}
	}
	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);  //清除中断标志位
} 
u8 KEY_Task(void)
{
	if (KEY.KEY_STATUS == UPDAT)
	{
		KEY.KEY_STATUS = BUSY;
		/****************************key1*****************************/
		if (KEY.NEW[0] && (!KEY.OLD[0]))
		{
			/***********************更新按键****************************/
			for (u8 i = 0; i < 4; i++)//更新状态
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 1;
		}
		/****************************key2*****************************/
		if (KEY.NEW[1] && (!KEY.OLD[1]))
		{
			for (u8 i = 0; i < 4; i++)//更新状态
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 2;
		}
		/****************************key3*****************************/
		if (KEY.NEW[2] && (!KEY.OLD[2]))
		{
			for (u8 i = 0; i < 4; i++)//更新状态
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 3;
		}
		/****************************WK_UP 自加函数*****************************/
		if (KEY.NEW[3] && (!KEY.OLD[3]))
		{
			for (u8 i = 0; i < 4; i++)//更新状态
			KEY.OLD[i] = KEY.NEW[i];
			KEY.KEY_STATUS = OK;
			return 4;
		}
	}
for (u8 i = 0; i < 4; i++)//更新状态
KEY.OLD[i] = KEY.NEW[i];
KEY.KEY_STATUS = OK;
return 0;	
}








