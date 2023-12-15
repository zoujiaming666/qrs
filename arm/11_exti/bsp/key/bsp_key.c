#include "bsp_key.h"
void key_init(void){
    /* 1、初始化IO复用，复用为GPIO1_IO019 */
	IOMUXC_SetPinMux(IOMUXC_UART1_RTS_B_GPIO1_IO19,0);		
	/* 2、、配置GPIO1_IO03的IO属性	
	 *bit 16:0 HYS关闭
	 *bit [15:14]: 00 默认下拉
	 *bit [13]: 0 kepper功能
	 *bit [12]: 1 pull/keeper使能
	 *bit [11]: 0 关闭开路输出
	 *bit [7:6]: 10 速度100Mhz
	 *bit [5:3]: 110 R0/6驱动能力
	 *bit [0]: 0 低转换率
	 */
	IOMUXC_SetPinConfig(IOMUXC_UART1_RTS_B_GPIO1_IO19,0XF080);
	
	/* 3、初始化GPIO,GPIO5_IO19设置为输入 */
	GPIO1->GDIR &= ~(1 << 19);	 
}

	int read_key(void){
            int ret =0;
            ret =((GPIO1->DR)>>19)& 0X1;
            return ret;
        }
    
    int key_getvalue(void){
        int ret =0;
        static unsigned char release=1;/*表示按键释放*/
        if(release==1 && read_key()==0)/*按下*/
        {
            delay(10);
            release=0;
            if(read_key()==0)/*延时10ms以后key还是0则按键有效*/
            {
                ret=KEY0_VALUE;
            }
        }
        else if(read_key()==1)/*未按下*/
        {
            ret =KEY_NONE;
            release =1;
        }
        return ret;
    }
