#ifndef TREE
#define TREE

/* A node in a tree
*  value - the node's value
*  left - a pointer to the left node
*  right - a pointer to the right node
*/
struct node {
    int value;
    node * left;
    node * right;
};

// Deletes a doubley linked list
void deleteList(node * head);

// Given a file creates a tree from the file contents
node * create_tree(char * fileName);

#endif /*!TREE*/
