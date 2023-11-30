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
	unsigned int reg=0;
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

	/*设置PLL2的4路PFD*/
	reg=CCM_ANALOG->PFD_528;
	reg &=(0x3F3F3F); 
	reg |=(32<<24); 	/*PLL2 PFD3=297MHZ*/
	reg |=(24<<16);		/*PLL2 PFD3=396MHZ*/
	reg |=(16<<8);		/*PLL2 PFD3=594MHZ*/
	reg |=(27<<0);		/*PLL2 PFD3=352MHZ*/
	CCM_ANALOG->PFD_528=reg;
	/*设置PLL3的4路PFD*/
	reg=CCM_ANALOG->PFD_480;
	reg &=(0x3F3F3F); 
	reg |=(19<<24); 	/*PLL3 PFD3=454.7MHZ*/
	reg |=(17<<16);		/*PLL3 PFD3=508.2MHZ*/
	reg |=(16<<8);		/*PLL3 PFD3=540MHZ*/
	reg |=(12<<0);		/*PLL3 PFD3=720MHZ*/
	CCM_ANALOG->PFD_480=reg;

	/*设置AHB_CLK_ROOT=132MHZ*/
	CCM->CBCMR &=~(3<<18);
	CCM->CBCMR |=1<<18;/*设置pre_periph_clock=PLL2_PFD2=396MHZ*/
	CCM->CBCDR &=~(1<<25);
	while(CCM->CDHIPR &(1<<5));/*等待握手信号*/

	#if 0
	CCM->CBCDR &=~(7<<10);
	CCM->CBCDR |=(2<<10);/*设置三分频   396/3=132*/
	while(CCM->CDHIPR &(1<<1));/*等待握手信号*/
	#endif
	/*IPG_CLK_ROOT=66MHZ*/
	CCM->CBCDR&=~(3<<8);/*清零*/
	CCM->CBCDR|=(1<<8);/*IPG_CLK_ROOT=AHB_CLK_ROOT/2=132/2=66MHZ*/

	/*PER_CLK_ROOT=66MHZ*/
	CCM->CSCMR1&=~(1<<6);/*PER_CLK_ROOT=66MHZ*/
	CCM->CSCMR1|=(0x3f<<0);/*1分频率 PERCLK_CLK_ROOT=66MHZ*/

}
