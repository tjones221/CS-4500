#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/module.h>

// print_self: Print the process name, id, state, and parent process informati>

// Prototypes
int print_self_init(void);
void print_self_cleanup(void);


int print_self_init(void) {
        struct task_struct *task;

        // current: macro which points to the current task/process
        for (task = current; task != &init_task; task = task->parent) {
                printk(KERN_INFO "Process name: %s\tPID: [%d]\tState: ", task->

                // Print when state is 0
                if (task->__state == 0) {
                        printk("%s - %d", "TASK_RUNNING", TASK_RUNNING);
                }
                else {
                        printk("%d", task->__state);
                }

                printk("\n");
 }

        return 0;
}

void print_self_cleanup(void) {
        printk(KERN_INFO "Cleaning up 1.\n");
}

module_init(print_self_init);
module_exit(print_self_cleanup);

MODULE_LICENSE("GPL");
