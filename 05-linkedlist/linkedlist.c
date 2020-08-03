#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct node {
  int val;
  struct node* previous;
  struct node* next;
} node_t;

void print_list(node_t* head)
{
  printf("Printing list:\n");
  node_t* current;
  current = head;
  int currindex = 0;
  if(head==NULL)
  {
    return;
  }
  printf("list[%d]: %d\n", currindex, current->val);
  while (head != current->next)
  {
    current = current->next;
    currindex++;
    printf("list[%d]: %d\n", currindex, current->val);
  }
  printf("\n");
}

void append_list(node_t* head, int newval) {
  node_t* newitem = NULL;
  newitem = (node_t*) malloc(sizeof(node_t));
  if(newitem == NULL)
  {
    ferror(stderr);
  }

  newitem->val = newval;

  newitem->previous = head->previous;
  newitem->next = head;

  newitem->previous->next = newitem;
  newitem->next->previous = newitem;

}

void pop_list(node_t* head) {
  node_t* to_remove = head->previous;
  to_remove->previous->next = head;
  head->previous = to_remove->previous;
  free(to_remove);
}

int main()
{
  node_t* head = NULL;
  head = (node_t*) malloc(sizeof(node_t));
  if(head == NULL)
  {
    ferror(stderr);
  }

  head->val = 0;
  head->previous = head;
  head->next = head;
  

  print_list(head);
  append_list(head, 2);
  print_list(head);
  append_list(head, 4);
  append_list(head, 8);
  append_list(head, 16);
  append_list(head, 32);
  print_list(head);
  pop_list(head);
  print_list(head);
  return 0;
}
