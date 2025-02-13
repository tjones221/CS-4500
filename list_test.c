//This file should test your list implementation.  Your test file should try various combinations 
//of your create list, add to list, remove from list, flush list, print list, and free listfunctions.
//Note the difference between flush listand free list: after  calling  flush list,  your  
//list  ll still  points  to  a  valid,  empty  list  (like  a  brand  new list  whose  head  points  to  NULL);  

#include "list.h"
#include "list.c"


int main() {
    // Test 1: ----------------------------------------
    // creates the list
    list *creation_list_1 = create_list();
  
    // practice strings to add to linked list
    add_to_list(creation_list_1, "peace");
    add_to_list(creation_list_1, "letter");
    add_to_list(creation_list_1, "pie");
    add_to_list(creation_list_1, "cake");
    add_to_list(creation_list_1, "Seaweed");
    add_to_list(creation_list_1, "BEEHIVE");
  
    // prints the entire list
    printf("\nList 1:\n")
    print_list(creation_list_1);
  
    // remove head of list and print item
    char *removed_item = remove_from_list(creation_list_1);
    if (removed_item != NULL) {
        printf("\nRemoved item: %s\n", removed_item);
        free(removed_item);
    }

    // Print list after remove_from_list is executed 
    printf("\nList after removing head:\n");
    print_list(creation_list_1);
  
    // Flush the list 
    flush_list(creation_list_1);
    printf("\nList after flushing:\n");
    print_list(creation_list_1); 
  
    // Free the list
    free_list(&creation_list_1);
    if(creation_list == NULL) {
        printf("\nList successfully deallocated.\n");
    }


    // Test 2: ----------------------------------------
    // creates the list
    list *creation_list_2 = create_list();

    // practice strings to add to linked list
    add_to_list(creation_list_2, "Paper");

    // prints the entire list
    printf("\nList 2:\n")
    print_list(creation_list_2);

    // remove head of list and print item
    char *removed_item = remove_from_list(creation_list_2);
    if (removed_item != NULL) {
        printf("\nRemoved item: %s\n", removed_item);
        free(removed_item);
    }

    // print list after remove_from_list is executed 
    printf("\nList after removing head:\n");
    print_list(creation_list_2);

    // add more strings to linked list
    add_to_list(creation_list_2, "Water");
    add_to_list(creation_list_2, "clouds");

    // print list after adding more strings
    printf("\nList after adding strings:\n");
    print_list(creation_list_2);

    // remove head of list and print items
    for (i = 0; i < 2; i++) {
        char *removed_item = remove_from_list(creation_list_2);
        if (removed_item != NULL) {
            printf("\nRemoved item: %s\n", removed_item);
            free(removed_item);
        }
    }

    // Print list after remove_from_list is executed 
    printf("\nList after removing head:\n");
    print_list(creation_list_2);
    
    // Flush the list 
    flush_list(creation_list_2);
    printf("\nList after flushing:\n");
    print_list(creation_list_2); 
  
    // Free the list
    free_list(&creation_list_2);
    if(creation_list == NULL) {
        printf("\nList successfully deallocated.\n");
    }
    
    return 0;
  } // main
    