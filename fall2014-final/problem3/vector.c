#include <stdio.h>
#include "vector.h"

/*  vectorInit - initializes a vector structure
*   INPUT: inVector - a pointer to the vector structure to initialize
*   OUTPUT: Sets back to be -1
*   RETURN: None
*/
void vectorInit(vector * inVector)
{
    inVector->back = -1;
}

/* isEmpty - Returns whether a given vector is empty or not
*  INPUT: inVector - a pointer to the vector
*  OUTPUT: None
*  RETURN: 1 if vector is empty, 0 if not empty
*/
int isEmpty(vector * inVector)
{
    return inVector->back < 0;
}

/* isFull - Returns whether a given vector is full or not
*  INPUT: inVector - a pointer to the vector
*  OUTPUT: None
*  RETURN: 1 if vector is full, 0 if not full
*/
int isFull(vector * inVector)
{
    return inVector->back >= (MAXSIZE - 1);
}

/*  pushBack - pushes an element onto the back of the vector
*   INPUT: inVector - pointer to the vector to push onto
*          element  - the element to push onto the vector
*   OUTPUT: None
*   RETURN: None
*/
void pushBack(vector * inVector, int element)
{
    if (isFull(inVector))
    {
        printf("Can't push back: vector is full\n");
        return;
    }
    inVector->contents[++inVector->back] = element;
}

/*  popBack - pops an element off the back of the vector
*   INPUT: inVector - pointer to the vector to pop off of
*   OUTPUT: None
*   RETURN: The element popped off the vector
*/
int popBack(vector * inVector)
{
    if(isEmpty(inVector))
    {
        printf("Can't pop back: vector is empty\n");
        return -1;
    }
    return inVector->contents[inVector->back--];
}
