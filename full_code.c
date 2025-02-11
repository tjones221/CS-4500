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

/* Removes the head of the list ll, extracts the string stored in the head 
* (and move the head of ll to the next node in the list), 
* and returns a pointer to this string. also frees the removed head node. */
char* remove_from_list(list* ll){

  // Check if list is empty
  if(ll == NULL || ll->head == NULL) { 
    return NULL; 
  }

  // Save pointer to string
  node* temp=ll->head;
  char *removed_item = temp->item; 
        
  // Move head to next node and free old node
  ll->head=ll->head->next;
  free(temp);

  return removed_item;

} // remove_from_list


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

/* Flushes the entire list and re-initializes the list. The passed pointer
* points to a valid, empty list when function returns.
* Any memory allocated to store nodes in the list should be freed.
*/
void flush_list(list *ll){

  // Check if list is empty
  if(ll==NULL){
    return;
  }

  node *current = ll->head;
  //Iterate through list
  while (current !=NULL){
    node *temp = current;
    current = current -> next;
    
    //free allocated string and node
    free(temp->item); 
    free(temp);
  }

  // reset list to empty
  ll->head=NULL;

}// flush_list

/* De-allocates all data for the list. Ensure all memory allocated for list
* ll is freed, including any allocated strings and list ll itself. */
void free_list(list **ll){

  // Check if list is empty
  if (ll == NULL){
    return;
  }

  // clear all nodes and free the list struct 
  flush_list(*ll);
  free(*ll);
  *ll=NULL;

}// free_list

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

  //remove head of list and print item 
  char *removed_item = remove_from_list(creation_list);
  if (removed_item != NULL){
    printf("\nRemoved item: %s\n", removed_item);
    free(removed_item);
  }

  //Print list after remove_from_list is executed 
  printf("\nList after removing head:\n");
  print_list(creation_list);

  //Flush the list 
  flush_list(creation_list);
  printf("\nList after flushing:\n");
  print_list(creation_list); 

  // Free the list
  free_list(&creation_list);
  if(creation_list == NULL){
    printf("\nList successfully deallocated.\n");
  }
  

  return 0;
} // main
