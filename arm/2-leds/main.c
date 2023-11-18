#include "main.h"
/*使能外设时钟*/
void clk_enable(void)
{
    CCM_CCGR1=0xFFFFFFFF;
    CCM_CCGR2=0xFFFFFFFF;
    CCM_CCGR3=0xFFFFFFFF;
    CCM_CCGR4=0xFFFFFFFF;
    CCM_CCGR5=0xFFFFFFFF;
    CCM_CCGR6=0xFFFFFFFF;
}
/*初始化LED*/
void led_init(void)
{
    SW_MUX_GPIO1_IO03=0x5;/*复用为GPIO1-IO03*/
    SW_PAD_GPIO1_IO03=0x1080;/*设置GPIO1_IO03电气属性*/

    /*GPIO初始化*/
    GPIO1_GDIR=0x8;/*设置为输出*/
    GPIO1_DR=0x0;/*打开LED灯*/
}
int main(void){
    clk_enable();/*使能外设时钟*/
    led_init();/*初始化LED*/

    /*设置LED灯闪烁*/
    while(1);
    return 0;
}