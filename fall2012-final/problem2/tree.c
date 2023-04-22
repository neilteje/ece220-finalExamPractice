#include <stdlib.h>
#include "tree.h"

/* Counte the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
   /* Implement Me */
   if (root == NULL) {
      return 0;
   }
   int count = 0; 
   if (root->data < 0) {
      count++;
   }
   count += countNegatives(root->left);
   count += countNegatives(root->right);
   return count;
}
