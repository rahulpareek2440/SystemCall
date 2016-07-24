#include<linux/init.h>
#include<linux/module.h>
#include<linux/linkage.h>
#include<linux/export.h>
#include<linux/time.h>
#include<asm/uaccess.h>
#include<linux/printk.h>
#include<linux/slab.h>
asmlinkage int sys_myhello(void){
	printk(KERN_ALERT "hello world: myhello\n");
	int a=100,i=0,c=0;
	c=a/i;
	printk(KERN_ALERT "this should not print %d\n",c);
	return 0;	
}
EXPORT_SYMBOL(sys_myhello);
