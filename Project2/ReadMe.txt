Read.me


Name of Project: Project 2: Kernel Modules and Processes
Members: Kylie Sanchez, Takaiya Jones, Kaylie Aguila
Statement: We have neither given nor received unauthorized assistance on this work.

============================
Virtual Machine (VM) Information:
============================
Name of Virtual Machine (VM): KaiyaUbuntu
Username: kaiya
Password: Poptartyummy@123
Root Password: Poptartyummy@123

The files can be found in the Project2 directory. Each part has a separted directory called part1, part2, and part3.


=============================
Problem Description and Remediation:
=============================

=============================
Part 1:
=============================
When I ran make, I got "redefinition of 'init_module'" and "redefinition of 'cleanup_module'" errors. The kernel headers already define these functions, so when I tried to define them again it caused issues. To fix this, I renamed the functions in hello.c to 'hello_init' and 'hello_exit'.

The timestamps show that "Hello World" was printed at 21:41:56, while "Goodbye World!" was printed at 21:43:50. "Hello World" is printed by the hello_init function when the module is inserted using insmod, which is when the kernel loads the module. "Goodbye World!" is printed by the hello_exit function when the module is removed using rmmod, which is when the kernel unloads the module. 


=============================
Part 2: 
============================= 
1. When you load your module, which process is recognized as current?

Current is the current task or process which is traced back to init. It dereferenecs the task of the current thread for the process currently executing. When I loaded the module, the current process is each line with process information printed, since the module goes through every task. 

2. In newer kernels, what is it called and what do you see from your module’s output?

The process with a pid of 1 is called "systemd". It represents init, or the mother of all processes. From my output, there are two processes with the name "systemd" and both have a state of 1, but different PIDs. 

3. Do you notice something not working again?

The struct called task_struct does not have a member called state, so I had to change it to "__state" to access the process state. In the module output, the module verification also fails.

- From your module’s output, which state(s) are observed?

When I first ran the module, the module verification failed but it displayed states 0 and 1. After changing print_self to print TASK_RUNNING when the state is 0, the module output passed verification, and each process printed a state of 1.

Solutions: 
- I used the links in the instructions to write the print_self function and successfully run the Makefile. Most of the issues I had were with printing process information due to datatypes and confusion in the instructions for step 3.
- I learned about how to write the kernel module for accessing process and task structures, how the macro current works and initializing a module.

=============================
Part 3: 
============================= 



=============================
Part 4: 
============================= 
1. What's the difference between a kernel module and a system call?

Kernel modules are code that can be loaded and unloaded into the kernel without requiring a reboot. They are used to extend the functionality of the kernel. 

A system call is a predefined entry point provided by the kernel that allows user-level processes to request services from the operating system. It acts as a "gate" into the kernel, enabling programs to perform privileged operations. They are implemented using software interrupts, which trigger execution in kernel mode. 

Kernel modules can modify or intercept system calls, allowing them to change how the operating system handles certain requests. 


2. This article is over 20 years old. If you try this example from the article, does it still work? Use your own words to explain why you think this may be a good (or bad) thing. 

The example from the article does not work anymore, because linux has been updated to prevent the malicious modification of system calls, improving security and stability. Modern linux kernels restrict direct modification of system calls, making the system more resistant to attacks like rootkits. This is a good thing because it helps protect against unauthorized modifications to the kernel, reducing the risk of system compromise and ensuring the integrity of the operating system.  

=============================
Code Execution Aid:
=============================

In the correct directory for each part, execute "make clean" then "make" to load the module into the kernel before seeing the output with "sudo dmesg -T | tail".



=============================
Resources
=============================
