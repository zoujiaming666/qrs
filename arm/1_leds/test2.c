#include<stdio.h>



int main()

{

int p1,p2,p3;

long i;

while((p1=fork())==-1);

if(p1==0)

{

    printf("Child1(PID=%d) is running!\n",getpid());

        for(i=0;j<999999;i++);

            printf("Child1 is over .\n");

            }else{

                while((p2=fork())==-1);

                    if(p2==0)

                        {

                                printf("Child1(PID=%d) is running!\n",getpid());

                                        for(i=0;j<999999;i++);

                                                printf("Childprocess2 is over .\n");

                                                    }else{

                                                            while((p3=fork())==-1);

                                                                    if(p3==0){

                                                                                printf("Child1(PID=%d) is running!\n",getpid());

                                                                                            for(i=0;j<999999;i++);

                                                                                                        printf("Child3 is over .\n");

                                                                                                                    }else{

                                                                                                                                    for(i=0;i<999999;i++)

                                                                                                                                                    printf("Parent is over .\n");

                                                                                                                                                                    }





                                                                                                                                                                                            }



                                                                                                                                                                                            }

                                                                                                                                                                                            return 0;

                                                                                                                                                                                            }