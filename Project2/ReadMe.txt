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
Code Execution Aid:
=============================









=============================
Resources
=============================
