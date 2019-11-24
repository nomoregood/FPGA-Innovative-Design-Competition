#ifndef _MY_STRUCT
#define _MY_STRUCT
#include  "sys.h" 

//#define		_RUN_HW 1				//运行红外遥控
//#define		_RUN_KEY 1				//运行按键
//#define		_RUN_ADC 1				//	运行ADC
//#define		_RUN_PID 1				//	运行PID
//#define   _RUN_3PHASE 1			//	运行3相SPWM
//======================

typedef enum
{
	OK,					//	任务完成
	UPDAT,			//	任务状态更新
	BUSY,				//	任务繁忙
}TASK_STATUS;

//typedef struct
//{
//	float Voltage;
//	u8 Frequency;
//	u8 Count[3];
//	u8 PIDFlag;
//	FRE_MODE FreqMode;
//}SysStatus;
//extern SysStatus SYS;


//#define My_CarrierArr 4096
//#define My_TableLen 168
#endif
