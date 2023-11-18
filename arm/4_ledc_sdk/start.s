
.global _start

_start:
    /*设置处理器进入svr模式 */
    mrs r0,cpsr /*读取cpsr到r0 */
    bic r0,r0,#0x1f  /*清除cpsr的bit4-0 */
    orr r0,r0,#0x13 /*使用svc模式*/
    msr cpsr,r0 /*将r0写入到cpsr */

    /*设置sp指针 */
    ldr sp,=0x00200000 
    b main /*跳转到c语言main函数 */
    