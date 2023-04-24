#include <stdlib.h>
#include "tree.h"

/* Counte the number of negative values stored in a tree */
int countNegatives(struct node* root)
{
   /* Implement Me */
   if (!root) return 0;
	int curr = 0;
	if (root->data < 0){
		curr = 1;
	}
	return countNegatives(root->left) + countNegatives(root->right)+curr;
}
