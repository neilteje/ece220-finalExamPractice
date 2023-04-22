#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 
 
/* allocate memory for a new node */
struct node* NewNode(int data);
 

int main()
{
    int negatives; 
    /* make a tree so that we can test countNegatives */
    struct node *root = NewNode(2);
    root->left = NewNode(-5);
    root->right = NewNode(9);
    
    root->left->left = NewNode(-4);
    root->left->right = NewNode(18);
    
    root->right->left = NewNode(9);
    root->right->right = NewNode(11);
    
    root->right->left->right = NewNode(6);

    /* call the function */
    negatives = countNegatives(root);

     /* print number of negative values*/
    printf("The number of negative values stored in the tree %d.\n", negatives);
   
    return 0;   
}
 
 
/* allocate memory for a new node */
inline struct node* NewNode(int data)
{
    struct node* node;
 
    if ((node = (struct node *)malloc(sizeof(struct node))) != NULL)
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
 
    return node;
} 
