#include "stm32f10x.h"
#include "led.h"
#include	"sys.h"
#include "delay.h"
#include "iic.h"
#include "oled.h"
#include "key.h"
#include "usart.h"
#include "OLEDout.h"
#include "writer.h"
//**********************************【主函数】
int main(void)
{ 
	u8 key=0;	//用于接收按键值
  
	delay_init();	//延时函数初始化
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	led_init(); // LED初始化，PA2的LED仅供测试使用，与程序无关
//	M_Usart1_Init();
	//uart_init(9600);
	IIC_Init();   		//IIC初始化
	OLED_Init();		//OLED初始化 
	KEY_Init();			// 按键初始化
	uart_init(9600);
	Start_out(); // 启动后，OLED显示启动完�
  //X_axis_add(5);
	
	while(1) //无限扫描按键
	{	
		key=KEY_Scan(0);	//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				case Xu:	
					led_shansuo();
					//PA2口LED闪烁，供测试使用，注释
				  X_axis_add(3);  //X轴正向转动一步�
				  //delay_ms(300);
					Key_Xu(); //OLED显示此时的动作，下面的Key_xx() 函数就是此作用
					break;
				case Xd:	
					led_shansuo();
				  X_axis_add(-3);  //X轴反向转动一步
					//delay_ms(300);
				  Key_Xd();
					break;
				case Yu:	 
					led_shansuo();
				  Y_axis_add(3);   //Y轴正向
					//delay_ms(300);
				  Key_Yu();	
					break;
				case Yd:	
					led_shansuo();
				  Y_axis_add(-3);   //Y轴反向
					//delay_ms(300);
				  Key_Xu();;	
					break;
				case Zu:	
					led_shansuo();
				  Z_axis_add(3);     //Z轴正向
					//delay_ms(300);
				  Key_Zu();	
					break;
				case Zd:	
					led_shansuo();
				  Z_axis_add(-3);      //Z轴反向
				  //delay_ms(300);
					Key_Zd();	
					break;
				case Ci:	
					led_shansuo();
					//delay_ms(30);
				  round_draw(4);      //画出一个四步长为半径的圆
					//delay_ms(300);
				  Key_Ci();
					
					
					break;
			}
		}else delay_ms(10); 
	}
}
 
