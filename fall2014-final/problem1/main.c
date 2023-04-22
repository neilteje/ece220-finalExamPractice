#include "linkedList.h"
int CheckCopyList(node *head, node *copyHead)
{
    node *curr=head;
    node *copycurr=copyHead;
    if(curr==NULL && copycurr==NULL)
        return 1;
    if((curr==NULL && copycurr!=NULL) || (curr!=NULL && copycurr==NULL))
    {
        printf("CopyList Check: Head pointers are not both null or non-null\n");
        return 0;
    }
    // checking the value of each node.
    while(curr!=NULL)
    {
        if(curr->value==copycurr->value)
        {
            
            curr=curr->next;
            copycurr=copycurr->next;
        }
        else
        {
            printf("CopyList Check: Node values do not match. Could be a problem with the order of nodes\n");
            return 0;
        }  
    }
    //checking arbit pointers.
    curr=head;
    copycurr=copyHead;
    while(curr!=NULL)
    {
       if((curr->arbit==NULL&& copycurr->arbit==NULL)|| ((curr->arbit && copycurr->arbit) && (curr->arbit->value==copycurr->arbit->value)))
       {
           curr=curr->next;
           copycurr=copycurr->next;
       }
       else
       {
           printf("CopyList Check: Arbit pointers do not point to the same nodes\n");
           return 0;
       }

    }   
    return 1; 
}
int main()
{

  // code to setup singly linked list. Change this code to test with different linked lists.
  // The values in the nodes may not be unique.
  node *head, *curr;
  int i;
  head=NULL;
  
  for(i=1;i<=10;i++)
  {
     curr=(node*)malloc(sizeof(node));
     curr->value=i;
     curr->next=head;
     curr->arbit=NULL;
     head=curr;
  }
  curr=head;
  // adding loop
  while(curr->next!=NULL)
      curr=curr->next;
  node *tail=curr;
  tail->next=head->next->next->next;
  int loop=DetectLoop(head);
  if(loop)
      printf("loop detected\n");
  else
      printf("loop not detected\n");
  // modifying singly linked list to add arbit pointers.

  curr=head;
  // removing loop. You will need to remove this line in case you change the test case above to not have a loop.
  // The singly linked list with arbit pointer will not have a loop if traversed using the next pointers.
  // No such restriction on the arbit pointers.
  tail->next=NULL; 
  curr->arbit=curr->next->next;
  curr->next->next->arbit=head;
  curr->next->arbit=curr->next;
  node *copyHead=CopyList(head);
  int result=CheckCopyList(head,copyHead);
  result?printf("Copy List passed\n"):printf("Copy List failed\n"); 
  return 0;
}
