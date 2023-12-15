#include "bsp_clk.h"



/*
 * @description	: 使能I.MX6U所有外设时钟
 * @param 		: 无
 * @return 		: 无
 */
void clk_enable(void)
{
	CCM->CCGR0 = 0XFFFFFFFF;
	CCM->CCGR1 = 0XFFFFFFFF;
	CCM->CCGR2 = 0XFFFFFFFF;
	CCM->CCGR3 = 0XFFFFFFFF;
	CCM->CCGR4 = 0XFFFFFFFF;
	CCM->CCGR5 = 0XFFFFFFFF;
	CCM->CCGR6 = 0XFFFFFFFF;
}


void imx6u_clkinit(void)
{
	/*初始化6u主频为528Mhz*/
	if(((CCM->CCSR>>2) & 0x1) == 0)/*当前时钟使用plli_main_clk*/
	{
		CCM->CCSR &=~(1<<8);/*设置step_clk=24M*/
		CCM->CCSR |=(1<<2);/*pll1_main_clk=step_clk=24M*/
	}
	/*设置PLL1=1056MHZ*/
	CCM_ANALOG->PLL_ARM=(1<<13)|((88<<0) & 0x7F);
	CCM->CACRR=1;/*设置2分频*/
	CCM->CCSR &=~(1<<2);/*设置pll1_sw_clk=plli_main_clk=1056*/
	
}
