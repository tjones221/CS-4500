#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node node;

struct Node {
  char *item; //-->points to a char text (string)
  node *next; //-->points to next node in list
};          

typedef struct List {
  node *head; //--> pointing to the first node @ the beginning
} list;

// allocate space for a new list and set its head to null
// returns the created list if successful, NULL otherwise
list *create_list() {
  // creates space for a list
  list *change_list = (list *)malloc(sizeof(list));

  //checks to see if the list was created
  if (change_list == NULL) {
    printf("Could not create list \n");
    return NULL;
  } // end if
  else {
    change_list->head = NULL;
    printf("Created list successfully. Head is: %p\n",
           (list *)change_list->head);
    return change_list;
  } // end else

}; // end create_list

// Allocates a new node and copies the string from item to this node
//(use malloc, strlen, and strcpy; or try strdup). Adds this new node
// to end of the list ll. Returns 0 if successful, non zero otherwise
int add_to_list(list *ll, char *item) {
  int check = -1;
  // space for node
  // node has *item + *next
  node *newnode = (node *)malloc(sizeof(node));
  if (newnode == NULL) {
    printf("Could not allocate room for node: add_to_list \n");
  } else {
   // printf("Successful Node Space Created \n");
  } // end else

  // make space for node item for the incoming item + copy
  // strdup uses malloc+ includes the null stirng terminator
  newnode->item = strdup(item);
  if (newnode->item == NULL) {
    printf("Could not allocate room for node->item: add_to_list \n");
  } else {
   // printf("Successful Node Space Created \n");
  } // end else

  // means first element in list
  if (ll->head == NULL) {
    ll->head = newnode;
    check = 0;
    return check;
  } // end if

  // Use a current to check for the last element
  node *currentnode = ll->head;

  // go to the last node and add to end newnode to end of list
  while (currentnode->next != NULL) {
    currentnode = currentnode->next;
  } // end while

  // added element
  currentnode->next = newnode;
  check = 0;

  //! Revise check
  if (check == 0) {
   // printf("Succesfully added new element \n");
    check = 0;
  } // end if
  else {
    printf("Could not successfully add new element \n");
    check = -1;
  }
  return check;

}; // add_to_list

//Prints the list
void print_list(list *ll) {

  if (ll == NULL || ll->head == NULL) {
    printf("List is empty \n");
    return;
  }

  // REMEBER: CURRENT_PLC HELPS WITH GOING TO THE NEXT NODE
  node *current_plc = ll->head;

  while (current_plc != NULL) {
    printf("List item: %s \n", current_plc->item);
    current_plc = current_plc->next;
  }

} // print_list;

int main() {
  //creates the list
  list *creation_list = create_list();

  //practice strings to add to linked list
  add_to_list(creation_list, "peace");
  add_to_list(creation_list, "letter");
  add_to_list(creation_list, "pie");
  add_to_list(creation_list, "cake");
  add_to_list(creation_list, "Seaweed");
  add_to_list(creation_list, "BEEHIVE");

  //prints the entire list
  print_list(creation_list);

  return 0;
} // main
