#include "linkedList.h"


int DetectLoop(node *head)
{
  //Write code here.
  if (head == NULL) {
    return 0;
  }
  node* slow = head;
  node* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return 1;
    }
  }
  return 0;
}

node *CopyList(node *head)
{
  //Insert Code here. You can change the return statement given.
  node* current = head;
  node* newList = NULL;
  node* tail = NULL;
 
  while (current != NULL)
  {
    if (newList == NULL)
    {
      newList = (struct Node*)malloc(sizeof(node));
      newList->value = current->value;
      newList->next = NULL;
      tail = newList;
    } else {
      tail->next = (struct Node*)malloc(sizeof(node));
      tail = tail->next;
      tail->value = current->value;
      tail->next = NULL;
    }
    current = current->next;
  }
  return newList;
}
