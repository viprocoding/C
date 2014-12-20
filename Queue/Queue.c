/*
 * Queue.c
 *
 * Rasmus Östersjö
 * 2014-12-20
 *
 * A generic and dynamic array implementation of a queue.
 */

// Libraries, headers
#include "Queue.h"
#include <stdlib.h>     // malloc, free
#include <string.h>     // memcpy

/** queueGrow:
 *      Static function which is used to increase the size of a queue.
 *
 *  @param q        Pointer to a queue that should grow.
 *
 *  @return         ERR_MALLOC  Heap memory could not be allocated (grow
 *                              cancelled).
 *                  SUCCESS     Queue grew by a factor of 2.
 */
static int queueGrow(queue_t* q)
{
    void *tmp;

    // Attempt to grow by a factor of 2
    if ((tmp = malloc(q->capacity * 2 * q->elemSize)) == NULL)
        return ERR_MALLOC;
    
    // Copy old queue
    for (int i = 0; i < q->capacity; i++)
        queueDequeue(q, (char*) tmp + i * q->elemSize);

    // Clean up -- compleete growing process
    free(q->elems);
    q->elems       = tmp;
    q->front       = 0;             // front is always @0 after a grow process
    q->currentSize = q->capacity;   // currentSize would be 0 if this is not set
    q->capacity  <<= 1;

    return SUCCESS;
}

int queueInit(queue_t* q, int elemSize, void (*freeFnk)(void*))
{
    if (elemSize < 1)
        return ERR_INVALID_ARGUMENT;
    
    // initialize queue 
    q->capacity    = INIT_CAPACITY;
    q->currentSize = 0;
    q->front       = 0;
    q->elemSize    = elemSize;
    q->elems       = malloc(q->capacity * q->elemSize);
    q->freeFnk     = freeFnk;

    return q->elems ? SUCCESS : ERR_MALLOC;
}

void queueDispose(queue_t* q)
{
    void *tmp = NULL;

    // free elements if there's a free function
    if (q->freeFnk)
        for (int i = 0, n = q->currentSize; i < n; i++) {
            queueDequeue(q, tmp);   // here q is never empty -- dont error check
            q->freeFnk(tmp);
        }

    // clean up
    free(q->elems);
    q->capacity = q->currentSize = q->front = q->elemSize = -1;
    q->elems = NULL;
}

int queueEnqueue(queue_t* q, void* elem)
{
    if (queueIsFull(q))
        if (queueGrow(q) == ERR_REALLOC)
            return ERR_MALLOC;
    
    // enqueue
    int index = (q->front + q->currentSize) % q->capacity;
    memcpy((char*) q->elems + index * q->elemSize, elem, q->elemSize);

    ++q->currentSize;
    return SUCCESS;
}

int queueDequeue(queue_t* q, void* elem)
{
    if (queueIsEmpty(q))
        return ERR_EMPTY;
    
    // dequeue
    memcpy(elem, (char*) q->elems + q->front * q->elemSize, q->elemSize);
    q->front = (q->front + 1) % q->capacity;

    --q->currentSize;
    return SUCCESS;
}

int queueIsFull(queue_t* q)
{
    return q->currentSize == q->capacity;
}

int queueIsEmpty(queue_t* q)
{
    return q->currentSize == 0;
}
