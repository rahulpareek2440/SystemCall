#include<stdio.h>
#include<unistd.h>
#include<linux/unistd.h>
#include<linux/time.h>
int main(){

struct timespec tm;
int y;
y=syscall(547,&tm);
printf("syscall return value : %d\n",y);
printf("time from kernel: %d\n",tm.tv_nsec);
return 0;
}

