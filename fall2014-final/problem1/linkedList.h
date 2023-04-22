#include <stdio.h>
#include <stdlib.h>

// Both the singly linked list and the linked list with arbit pointer
// use the same node struct. In the singly linked list the arbit pointer is
// set to null and should be ignored.

typedef struct node{
    int value;
    struct node * next; 
    struct node * arbit;
}node;

// Prototype for function to detect loop in singly linked list.
int DetectLoop(node * head);
// Prototype for function to copy linked list with arbit pointer.
node *CopyList(node * head);
