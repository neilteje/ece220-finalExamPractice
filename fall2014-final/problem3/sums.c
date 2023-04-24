#include <stdio.h>
#include "vector.h"
#include "tree.h"

// FUNCTION DEFINITIONS
void findPathRecursive(node * root, int expectedSum, int currentSum, vector * path);
void findPath(node * root, int expectedSum);


// Don't change the main function
int main(int argc, char * argv[])
{
    if (argc < 1)
    {
        printf("Not enough arguments\n");
        return -1;
    }

    node * root = create_tree(argv[1]);
    int sum;
    printf("Please enter a sum: ");
    scanf("%d", &sum);

    findPath(root, sum);
    delete_tree(root);
}

// Recursive helper function for printing paths within a tree
// that add up to an expected sum
void findPathRecursive(node * root, int expectedSum, int currentSum, vector * path)
{
    // YOUR CODE HERE
    if (currentSum == expectedSum){ //to check if desired path length is reached 
        if (!(root->left) && !(root->right)){ //check if it's a leaf node
            int end = path->back;
            for (int i = 0; i<=end; i++){
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }
    }
    if (!root){
        return;
    }
    if (!isFull(path)){
        currentSum += root->value;
        pushBack(path, root->value);
        findPathRecursive(root->left, expectedSum, currentSum, path);
        findPathRecursive(root->right, expectedSum, currentSum, path);
    }
}

// Finds and prints all paths within a tree that add to an expected sum
void findPath(node * root, int expectedSum)
{
    // YOUR CODE HERE
    vector* myvector = (vector*)malloc(sizeof(vector));
    vectorInit(myvector);
    findPathRecursive(root, expectedSum, 0, myvector);
    return;
}
