Read.me


Name of Project: Project 2: Kernel Modules and Processes
Members: Kylie Sanchez, Takaiya Jones, Kaylie Aguila
Statement: We have neither given nor received unauthorized assistance on this work.

============================
Virtual Machine (VM) Information:
============================
Name of Virtual Machine (VM): KaiyaUbuntu
Username: kaiya
Password:Poptartyummy@123
Root Password: Poptartyummy@123

The files can be found in the Project2 directory. 


=============================
Problem Description and Remediation:
=============================

Part 0:
* Description: 
* Problem: 
* Solution: 


=============================
Part 1:
=============================
When I ran make, I got "redefinition of 'init_module'" and "redefinition of 'cleanup_module'" errors. The kernel headers already define these functions, so when I tried to define them again it caused issues. To fix this, I renamed the functions in hello.c to 'hello_init' and 'hello_exit'.

The timestamps show that "Hello World" was printed at 21:41:56, while "Goodbye World!" was printed at 21:43:50. "Hello World" is printed by the hello_init function when the module is inserted using insmod, which is when the kernel loads the module. "Goodbye World!" is printed by the hello_exit function when the module is removed using rmmod, which is when the kernel unloads the module. 

=============================
Part 2: 
============================= 
* Description: 
* Problem: 
* Solution:

=============================
Part 3: 
============================= 

*Descritpion: The purpose of my function was to take an incoming PID value print the information attached to this number and transverse through the kernel to reach the parent. While transversing the kernel, there should be three descriptors printed with each PID value: PID value, State, and Name.

*Problem: It is difficult understanding how to transverse the tree and what terminal variables could aid me throughout the process. I learned through reading some of the class material that the kernel information that I am searching for is inside of a circular linked list. I have workied with linked list, but never this variation of lists.

*Solution:I got alot of help from Chatgpt breaking information into childlike pieces for me to understand and the readings that were scattered throughout the assignment. This site "https://linuxgazette.net/133/saha.html" had an incredible example on how to transverse the tree starting from the current node. I used chatgpt to break down the variables used throughout the text and then proceeded to brainstorm ways for me to transform this solution into something that fit my situation. Additionally, chapter 4.5 in the "linux programming guide" book helped me understand how to pass the PID value into my function as well. By incoporating the physical books and Chatgpt, I was able to understand how to fix my function and what the components I needed to gracefully transverse the circular tree.

*How to run: make - pgrep bash (you should recieve a number) - sudo insmod print_other.ko pid= (insert number from previous command) - sudo lsmod (remove) - sudo rmmod print_other - sudo dmesg -T | tail - make clean

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









=============================
Resources
=============================
