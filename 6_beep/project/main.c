
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"

/*
 * @description	: main函数
 * @param 		: 无
 * @return 		: 无
 */
int main(void)
{
	clk_enable();		/* 使能所有的时钟 			*/
	led_init();			/* 初始化led 			*/
	beep_init();		/* 初始化beep	 		*/

	while(1)			
	{	
		/* 打开LED0和蜂鸣器 */
		led_switch(LED0,ON);	
		beep_switch(ON);
		delay(500);

		/* 关闭LED0和蜂鸣器 */
		led_switch(LED0,OFF);	
		beep_switch(OFF);
		delay(500);
	}

	return 0;
}
