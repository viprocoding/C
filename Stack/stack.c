#include <stdio.h>
#include "stack.h"

int stackNew(Stack *s, unsigned elemSize, void (*freeFunction)(void *))
{
    if (elemSize <= 0)
        return ERR_ELEM_SIZE;
    
    // Initialize stack
    s->logLength   = 0;
    s->allocLength = 1;
    s->elemSize    = elemSize;
    s->elems       = malloc(s->allocLength * s->elemSize);
    s->elemDispose = freeFunction;

    return s->elems == NULL ? ERR_MALLOC : SUCCESS;
}

int stackDispose(Stack *s)
{
    if (s == NULL || s->elems == NULL)
        return ERR_NULL;
    
    // Clean up elements (if neccecary)
    if (s->elemDispose) {
        for (int i = 0; i < s->logLength; i++)
            s->elemDispose((char *)s->elems + i * s->elemSize);
    }
    
    // Clean up stack
    free(s->elems);

    return SUCCESS;
}

static int stackGrow(Stack *s)
{
    // Double size
    s->allocLength <<= 1;

    // Realloc
    void *tmp = realloc(s->elems, s->elemSize * s->allocLength);

    // Request failed
    if (tmp == NULL)
        return ERR_REALLOC;
    
    s->elems = tmp;
    return SUCCESS;
}

static bool isFullStack(Stack *s)
{
    return s->logLength == s->allocLength ? true : false;
}

int stackPush(Stack *s, const void *newElem)
{
    // Full stack
    if (isFullStack(s))
        if (stackGrow(s) == ERR_REALLOC)
            return ERR_REALLOC;
    
    // Push element
    memcpy((char *)s->elems + s->logLength * s->elemSize, newElem, s->elemSize);
    s->logLength++;

    return SUCCESS;
}

static bool isEmptyStack(Stack *s)
{
    return s->logLength == 0 ? true : false;
}

int stackPop(Stack *s, void *elem)
{
    if (isEmptyStack(s))
        return ERR_EMPTY;
    
    // Pop
    s->logLength--;
    memcpy(elem, (char *)s->elems + s->logLength * s->elemSize, s->elemSize);

    return SUCCESS;
}
