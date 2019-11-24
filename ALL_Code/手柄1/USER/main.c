#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "LED.h"
#include "adc.h"
#include "24l01.h"
#include "key.h"

u16 t=0;

int main(void)
{
	u8 key;
	
	u8 tmp_buf;
	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();			//初始化OLED      
	Adc_Init();	 //ADC初始化
	KEY_Init();
	NRF24L01_Init();
	while(NRF24L01_Check())
 	{
		LED1=0;LED2=0;
		delay_ms(200);
		LED1=1;LED2=1;
 		delay_ms(200);
	}
	NRF24L01_TX_Mode();

	while(1)
	{
		LED1 = 1;
		LED2 = 1;
		key=KEY_Task();
		if(key==0)
		{

		}
		if(key==1)  //KEY_LD
		{
//			NRF24L01_RX_Mode();		  
//			while(1)
//			{	  		    		    				 
//				if(NRF24L01_RxPacket(tmp_buf)==0)//一旦接收到信息,则显示出来.
//					{
//						LED1=1;LED2=1;
//					}
//				else 
//					{
//						LED1=0;LED2=0;
//					}
//				delay_us(100);	   			    
//			}
				tmp_buf = '1';
				if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
				{
					LED1 = 0;
					LED2 = 0;
					delay_ms(300);
					LED1 = 1;
					LED2 = 1;
					key = 0;
				}
			
		}
		else if(key==2)    //KEY_RD
		{
//			NRF24L01_TX_Mode();
//			mode=' ';//从空格键开始  
			tmp_buf = '2';
			if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
			{
				LED1 = 1;
				LED2 = 0;
				delay_ms(300);
				LED1 = 0;
				LED2 = 1;
				delay_ms(300);
				LED1 = 1;
				key = 0;
			}

		}
		else if(key==3)    //KEY_LU    
		{
			key = 0;	 
			
			tmp_buf = '3';
			if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
			{
				LED1 = 1;
				LED2 = 0;
				delay_ms(300);
				LED1 = 0;
				LED2 = 1;
				delay_ms(300);
				LED1 = 1;
				key = 0;
				
				
			}	
			
		}
		else if(key==4)   //KEY_RU     第一次按，进入摇杆控速
		{ 
			key=0;
			tmp_buf = '4';
			if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
			{
				LED1 = 1;
				LED2 = 0;
				delay_ms(300);
				LED1 = 0;
				LED2 = 1;
				delay_ms(300);
				LED1 = 1;
				key = 0;
				
				while(1)   //右上按键第一次被按下后，进入遥感控速
				{
					key=KEY_Task();
					
							if(key==1)  //KEY_LD    急停
							{
								
								tmp_buf = '1';
								if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
								{
									LED1 = 0;
									LED2 = 0;
									delay_ms(300);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								}
							}
							
							else if(key == 4)    //再次按下右上按键，LED亮0.5s，如果成功则会再亮1s，取消摇杆控制并且急停
							{
									tmp_buf = '1';   //急停指令
									//LED亮0.5s，提示
									LED1 = 0;
									LED2 = 0;
									delay_ms(500);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								
								if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
								{
									LED1 = 0;
									LED2 = 0;
									delay_ms(1000);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								}
									
									break;  //打破while
							}
							else if(key == 0)
							{
								tmp_buf = adc_value_compare(Get_Adc(2));
								if(NRF24L01_TxPacket(&tmp_buf) == TX_OK)
								{
									LED1 = 0;
									LED2 = 0;
									delay_ms(200);
									LED1 = 1;
									LED2 = 1;
									key = 0;
								}
							}
							
				}//遥感控速 while结束
			}		    
		}
	} //主循环结束

//while(1)
//{
//	LED1=1;LED2=0;
//	delay_ms(500);
//	LED1=0;LED2=1;
//	delay_ms(500);
//}
}


