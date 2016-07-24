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
}
EXPORT_SYMBOL(sys_myhello);
