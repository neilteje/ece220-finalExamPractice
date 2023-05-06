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
  node* curr = head;
  node* copiedlist = NULL;
  node* tail = NULL;
 
  while (curr != NULL)
  {
    if (copiedlist == NULL)
    {
      copiedlist = (struct Node*)malloc(sizeof(node));
      copiedlist->value = curr->value;
      copiedlist->next = NULL;
      tail = copiedlist;
    } else {
      tail->next = (struct Node*)malloc(sizeof(node));
      tail = tail->next;
      tail->value = curr->value;
      tail->next = NULL;
    }
    curr = curr->next;
  }
  return copiedlist;
}
