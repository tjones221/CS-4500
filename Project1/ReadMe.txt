Read.me


Name of Project: Project 1: Makefile
Members: Kylie Sanchez, Takaiya Jones, Kaylie Aguila
Statement: We have neither given nor received unauthorized assistance on this work.
============================
Virtual Machine (VM) Information:
============================
Name of Virtual Machine (VM): KaiyaUbuntu
Username: kaiya
Password:Poptartyummy@123
Root Password: Poptartyummy@123


=============================
Problem Description and Remediation:
=============================


Part 0: Set Up
* Description: Each classmate is reserved one VM, that we can share with teammates or use individually.
* Problem: A random individual had already placed their locked VM in my account. This made it impossible for me to access VM
* Solution: I had to rename the VM to delete me and restart the setup processes again.




=============================
Part 1: Linked List
=============================
Function create_list()
* Description: This function creates the list that will be used throughout the project.
* Problem: A random individual had already placed their locked VM in my account. This made it impossible for me to access VM
* Solution: I had to rename the VM to delete me and restart the setup processes again.
Function add_to_list()-EDIT 
* Description: This function is responsible for adding elements to the list.
* Problem:  Problem Areas include understanding linked lists, the function of structs, and connecting the list to the node.
* Solution: The “item” variable, “next” variable, and “head” variable are elements needed for moving through the linked list. Unfortunately, each variable is held in different structs. Creating a current_variable from node that points to the head of the list allows the pointer to move to the next item. The current pointer is key to tracking where the last element is located so that new elements can be added to the end of the list.


Function print_list():
* Description: This function is responsible for printing the lists created throughout our coding project.
* Problem: It was difficult to keep track of the pointer elements that were inside the linked list. 
* Solution: The solution to understanding and tracking the elements was to understand the relationship between the linked list and the node.Tracking the elements in a list becomes easier, if a current pointer is made from the node pointer. The current pointer will help move through the list, so each element is able to be printed.


Linked List Testing - list_test.c:
* Description: This file includes main() which tests the implementation for the linked list. 
* Problem: The contents of the linked list needed to be viewed each time it was updated to see changes that were made, and that each of the functions were working properly. This includes creating linked lists, adding nodes, and deallocating their memory.
* Solution: We provided two tests then ran through different variations of linked lists:
   * List 1: This list initially had 6 strings added to the list. This test demonstrated that removing the head of the list would still print out the rest of the list afterwards. It also checked that the list could be successfully flushed and freed afterwards with the remaining 5 strings.
   * List 2: The second list has one string example added to the linked list. This shows that once the only item in the list is removed, the list prints out that it is empty without causing an error. Afterwards, more strings can still be added and removed. When the list has no nodes, it is still able to be successfully flushed and deallocated at the end of the test.
=============================
Part 2: Writing a Makefile
============================= 
* Description: The makefile is helpful, because of its ability to simplify code execution.
* Problem: The code for creating a makefile is complicated.
* Solution: The most helpful tool for understanding the code was ChatGPT. I referred to the class tutorial and used ChatGPT to explain the different components of the tutorial Makefile. This helped break down the structure and explained the functionality of each section.


=============================
Code Execution Aid:
=============================
-open the terminal 
-type “pwd” —> the result should be “/home/kaiya”
-type “make”
-type “./list_test”
-type “make clean” -> this will remove all of the .o files




























Resources
 https://youtu.be/N6dOwBde7-M?si=jFkmXt5EVssos4oo : Helpful in understanding the basic structure of a linked list in simple terms. No unnecessary jargon is littered throughout the text.
 https://youtu.be/DneLxrPmmsw?si=0cyet3hR8BwIJiGM : Another source that is helpful in understanding linked list dynamics.