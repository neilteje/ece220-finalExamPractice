#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

/*  delete_tree - given the root of a tree deletes it, freeing memory
*   INPUT: root - the root of the tree
*	OUTPUT: deletes the tree
*	RETURN: none
*/
void delete_tree(node * root)
{
	if (root == NULL)
		return;
	delete_tree(root->left);
	delete_tree(root->right);
	free(root);
}


/* create_tree - given a file creates a tree from the file contents
*  INPUT: fileName - name of file containing the tree information
*  OUTPUT: allocates memory and creates a tree
*  RETURN: returns a pointer to the root of the tree
*/
node * create_tree(char * fileName)
{
	int value;
    FILE * fp;
    if ((fp = fopen(fileName, "r")) == NULL)
    {
        printf("Error opening file: %s\n", fileName);
        return NULL;
    }

    if (fscanf(fp, "%d", &value) != 1)
    {
        printf("%s is incorrectly formatted\n", fileName);
        return NULL;
    }
    node * root = (node *) malloc(sizeof(node));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    queue q;
    initQueue(&q);

    enqueue(&q, root); 

    while (!isEmpty(&q))
    {
        node * current = dequeue(&q);
        if (fscanf(fp, "%d", &value) != 1)
            break;
        node * left = (node *) malloc(sizeof(node));
        left->value = value;
        left->left = NULL;
        left->right = NULL;
        current->left = left;
        enqueue(&q, left);

         if (fscanf(fp, "%d", &value) != 1)
            break;
        node * right = (node *) malloc(sizeof(node));
        right->value = value;
        right->left = NULL;
        right->right = NULL;
        current->right = right;
        enqueue(&q, right);
    }

    fclose(fp);
	return root;
}

