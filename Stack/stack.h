#ifndef __STACK_H__
#define __STACK_H__

// Libraires
#include <stdlib.h>     // malloc, free, realloc
#include <string.h>     // memcpy
#include <stdbool.h>    // boolean expressions

// Signals
#define SUCCESS        1
#define ERR_ELEM_SIZE -1
#define ERR_MALLOC    -2
#define ERR_NULL      -3
#define ERR_REALLOC   -4
#define ERR_EMPTY     -5

// Stack data type
typedef struct {
    void *elems;                    // Ptr to block of elements
    unsigned elemSize;              // Size of each element
    unsigned logLength;             // Current ammount of elements in stack
    unsigned allocLength;           // Max amt of elems in current allocation
    void (*elemDispose)(void *);    // Ptr to function that can free an element
} Stack;

/*
 * stackNew:
 * Initializes a stack, initially of size zero and allocoated length 1.
 *
 *  -- Parameters:
 *      Pointer to a stack, the size of each element in the stack and a pointer
 *      to a function that knows how to free the element (NULL if the element
 *      does not need to be freed).
 *
 *  -- Return:
 *      SUCCESS if stack was successfully initialized; ERR_ELEM_SIZE if an
 *      invalid element size was passed, ERR_MALLOC if malloc failed to allocate
 *      heap memory for the elements.
 */
int stackNew(Stack *s, unsigned elemSize, void (*freeFunction)(void *));

/*
 * stackDispose:
 * Disposes a stack, i.e. freeing all heap memory owned by the stack.
 *
 *  -- Parameters:
 *      A pointer to a stack.
 *
 *  -- Return:
 *      SUCCESS if stack was freed successfully; ERR_NULL if either the stack
 *      or the stacks element pointer was set to NULL.
 */
int stackDispose(Stack *s);

/*
 * stackPush:
 * Pushes a new element onto the stack.
 *
 *  -- Parameters:
 *      A pointer to a stack and a pointer to an element that is to be pushed.
 *
 *  -- Return:
 *      SUCCESS if element was pushed successfully; ERR_REALLOC if stack was
 *      full and new memory could not be allocated on the heap. 
 */
int stackPush(Stack *s, const void *newElement);

/*
 * stackPop:
 * Pops an element from the stack.
 *
 *  -- Paramters:
 *      A pointer to a stack, and a pointer to an element that the popped value
 *      should be written to.
 *
 *  -- Return:
 *      SUCCESS if element was popped successfully; ERR_EMPTY if there were no
 *      element to pop.
 */
int stackPop(Stack *s, void *elem);

#endif // __STACK_H__
