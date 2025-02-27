//header file
//This should be where strcut definitions,typedef, and function prototypes should be placed

#ifndef LIST_H
#define LIST_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Declaring all the structs */

typedef struct Node node;

struct Node {
        char *item; 
        node *next;
};

typedef struct List {
        node *head;
} list;

/* Allocate space for a new list and set its head to NULL.
* Returns the created list if successful, NULL otherwise. */
list* create_list();

/* Allocates a new node and copies the string from item to this node
* Adds this new node to end of the list ll.
* Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item);

/* Removes the head of the list ll, extracts the stored string in the head,
* and returns a pointer to this string. Also frees the removed head node. */
char* remove_from_list(list *ll);

/* Prints every string in each node of the list ll, with a new line
* character at the end of each string */
void print_list(list *ll);

/* Flushes the entire list and re-initializes the list. The passed 
* pointer ll should still point to a valid, empty list when this function
* returns. Any memory allocated to store nodes in the list should be freed.
*/
void flush_list(list *ll);

/* De-allocate all data for the list. Ensure all memory allocated for list
* ll is freed, including any allocated strings and list ll itself. */
void free_list(list **ll);

#endif

