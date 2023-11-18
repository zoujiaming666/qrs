
.global _start  

_start:
    ldr r0,=0x020c4068 @CCGR0
    ldr r1,=0xffffffff
    str r1,[r0]

    ldr r0,=0x020c406c  @CCGR1
    str r1,[r0]

    ldr r0,=0x020c4070  @CCGR2
    str r1,[r0]
    
    ldr r0,=0x020c4074  @CCGR3
    str r1,[r0]

    ldr r0,=0x020c4078  @CCGR4
    str r1,[r0]

    ldr r0,=0x020c407c  @CCGR5
    str r1,[r0]

    ldr r0,=0x020c4080  @CCGR6
    str r1,[r0]

    /*                */
    ldr r0,=0x020E0068
    ldr r1,=0x5
    str r1,[r0]
    /* */
    ldr r0,=0x020E02F4
    ldr r1,=0x10b0
    str r1,[r0]
    /* */
    
    /*GPIO */
    ldr r0,=0x0209c004
    ldr r1,=0x8
    str r1,[r0]

    ldr r0,=0x0209c000
    ldr r1,=0
    str r1,[r0]

loop:
    b loop



