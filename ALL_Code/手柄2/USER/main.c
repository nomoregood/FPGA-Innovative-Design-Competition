#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
//#include "lcd.h"
#include "usart.h"
#include "adc.h"
#include "beep.h"
#include "oled.h"

/************************************************
 ALIENTEK精英STM32开发板实验17
 ADC 实验
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司
 作者：正点原子 @ALIENTEK
************************************************/


int main(void)
{
    u16 key;
    delay_init();	    	 //延时函数初始化
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
    uart_init(9600);	 	//串口初始化为115200
  //  LED_Init();			     //LED端口初始化

  //  BEEP_Init();
//	LCD_Init();
// 	Adc_Init();		  		//ADC初始化
    KEY_Init();
 //   OLED_Init();			//初始化OLED
    while(1)
    {
		delay_ms(100);
		//USART_SendData(USART1, '1');
        key=KEY_Scan(0);	//得到键值
        if(key)
        {
            switch(key)
            {
            case 1: USART_SendData(USART1, '1');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0001);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
////                OLED_ShowString(0,0,"KEY1",12);
////                OLED_Refresh_Gram();
                break;
            case 2:
				USART_SendData(USART1, '2');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0002);
//						delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
////                OLED_ShowString(0,0,"KEY2",12);
////                OLED_Refresh_Gram();
                break;
            case 3: USART_SendData(USART1, '3');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0003);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
////                OLED_ShowString(0,0,"KEY3",12);
////                OLED_Refresh_Gram();
                break;
            case 4: USART_SendData(USART1, '4');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0004);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY4",12);
//                OLED_Refresh_Gram();
                break;
            case 5: USART_SendData(USART1, '5');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0005);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY5",12);
//                OLED_Refresh_Gram();
                break;
            case 6: USART_SendData(USART1, '6');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0006);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY6",12);
//                OLED_Refresh_Gram();
                break;
            case 7: USART_SendData(USART1, '7');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0007);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY7",12);
//                OLED_Refresh_Gram();
                break;
            case 8: USART_SendData(USART1, '8');
//                BEEP =1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0008);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY8",12);
//                OLED_Refresh_Gram();
                break;
            case 9: USART_SendData(USART1, '9');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0009);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY9",12);
//                OLED_Refresh_Gram();
                break;
            case 10: USART_SendData(USART1, 'A');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0010);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY10",12);
//                OLED_Refresh_Gram();
                break;
            case 11: USART_SendData(USART1, 'B');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0011);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY11",12);
//                OLED_Refresh_Gram();
                break;
            case 12: USART_SendData(USART1, 'C');
//                BEEP=1;
//                delay_ms(100);
//                BEEP=0;
//                USART_SendData(USART1, 0x0012);
//                delay_ms(10);
//						    USART_SendData(USART1, 0x000d);
//						    delay_ms(10);
//						    USART_SendData(USART1, 0x000a);
//                OLED_ShowString(0,0,"KEY12",12);
//                OLED_Refresh_Gram();
                break;
            }
        } else delay_ms(100);
    }



}

