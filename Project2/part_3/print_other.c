#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>
#include <linux/pid.h>

MODULE_LICENSE("GPL"); //<-needed to RUN

//in the Linux kernel mod book
static int pid = 1;  // Default PID -> invalid if 0
module_param(pid, int, 0444);  // Accepts a PID as a module parameter + the 04>
MODULE_PARM_DESC(pid, "The Process ID to look up");


static int __init print_info_mod(void) {
    struct task_struct *task;

    // Find the process by PID
    task = pid_task(find_vpid(pid), PIDTYPE_PID);
    
    // Print error if PID is not found
    if (!task) {
        printk(KERN_ERR "Could not find PID %d\n", pid);
        return -ESRCH;
    }
 // Traverse process tree up to init (PID 1)
    while (task->pid != 1) {
        printk("Process: %s - PID [%d] - State: %d", 
               task->comm, task->pid, task->__state);

        task = task->parent;  // Move to parent process - basically helps w/ m>
    }

    return 0;
}

// Cleanup function when module is removed
static void __exit cleanup_info_mod(void) {
    printk("print_info_mod module removed.\n");
}

module_init(print_info_mod);
module_exit(cleanup_info_mod);
