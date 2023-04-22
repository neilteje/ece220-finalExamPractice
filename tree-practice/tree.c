#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* prev_node;
    struct Node* head_node;
};

void bst_to_dll(struct Node* current_node) {

    if (current_node == NULL) {
        return;
    }
    
    bst_to_dll(current_node->left);
    
    if (prev_node != NULL) {
        prev_node->right = current_node;
        current_node->left = prev_node;
    } else {
        head_node = current_node;
    }
    
    prev_node = current_node;
    
    bst_to_dll

/*  delete_list - given the head of a list deletes it, freeing memory
*   INPUT: head - the head of the list
*	OUTPUT: deletes the list
*	RETURN: none
*/
void deleteList(Node * head)
{
    while (head != NULL)
    {
        Node * temp = head;
        head = head->right;
        free(temp);
    }
}

/* create_tree - given a file creates a tree from the file contents
*  INPUT: fileName - name of file containing the tree information
*  OUTPUT: allocates memory and creates a tree
*  RETURN: returns a pointer to the root of the tree
*/
Node * create_tree(char * fileName)
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
    Node * root = (Node *) malloc(sizeof(node));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    queue q;
    initQueue(&q);

    enqueue(&q, root); 

    while (!isEmpty(&q))
    {
        Node * current = dequeue(&q);
        if (fscanf(fp, "%d", &value) != 1)
            break;
        Node * left = (Node *) malloc(sizeof(node));
        left->value = value;
        left->left = NULL;
        left->right = NULL;
        current->left = left;
        enqueue(&q, left);

         if (fscanf(fp, "%d", &value) != 1)
            break;
        Node * right = (node *) malloc(sizeof(node));
        right->value = value;
        right->left = NULL;
        right->right = NULL;
        current->right = right;
        enqueue(&q, right);
    }

    fclose(fp);
	return root;
}

