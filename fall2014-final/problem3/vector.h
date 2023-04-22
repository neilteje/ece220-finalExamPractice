#ifndef VEC
#define VEC
#define MAXSIZE 100

/* A vector structure
*  contents - the contents of the vector up to MAXSIZE elements
*  back - the current index of the back of the vector
*/
struct vector {
    int contents[MAXSIZE];
    int back;
};

// Initializes a vector structure
void vectorInit(vector * inVector);

// Returns whether a given vector is empty or not
int isEmpty(vector * inVector);

// Returns whether a given vector is full or not
int isFull(vector * inVector);

// Pushes an element onto the back of the vector
void pushBack(vector * inVector, int element);

// Pops an element off the back of the vector
int popBack(vector * inVector);

#endif /*!VEC*/
