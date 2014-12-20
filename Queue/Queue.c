#include "Queue.h"
#include <stdlib.h>		// malloc

static int queueGrow(queue_t* q)
{
	// todo
	return 0;
}

int queueInit(queue_t* q, int elemSize /*, freeFnk ... */)
{
	if (elemSize < 1)
		return ERR_INVALID_ARGUMENT;
	
	// Initialize queue	
	q->capacity = INIT_CAPACITY;
	q->currentSize = 0;
	q->elemSize = elemSize;
	q->elems = malloc(q->capacity * q->elemSize);

	return q->elems ? SUCCESS : ERR_MALLOC;
}

int queueDispose(queue_t* q)
{
	// todo
	return 0;
}

int queueEnqueue(queue_t* q, void* elem)
{
	// todo
	return 0;
}

int queueDequeue(queue_t* q, void* elem)
{
	// todo
	return 0;
}

int queueIsFull(queue_t* q)
{
	return q->capacity == q->currentSize;
}

int queueIsEmpty(queue_t* q)
{
	return !q->currentSize;
}
