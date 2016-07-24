#include<linux/init.h>
#include<linux/module.h>
#include<linux/linkage.h>
#include<linux/export.h>
#include<linux/time.h>
#include<asm/uaccess.h>
#include<linux/printk.h>
#include<linux/slab.h>
#include<linux/errno.h>
asmlinkage int sys_my_xtime(struct timespec *current_time){
	printk(KERN_ALERT "MY_XTIME\n");
	if(!access_ok(VERIFY_WRITE, current_time, sizeof(struct timespec)))
	{
		return -EFAULT;
	}
	
	struct timespec time =current_kernel_time(); 
	//clock_gettime(CLOCK_REALTIME_COARSE,time);
	//do_gettimeofday(time);
	
	
	printk(KERN_ALERT "The time from kernel %ld from sys_my_xtime\n",time.tv_nsec);
	if(copy_to_user(current_time,&time,sizeof(struct timespec)))
		return -EFAULT;
	return 0;
}
EXPORT_SYMBOL(sys_my_xtime);
