#include "Queue.h"
#include <stdlib.h>		// malloc
#include <string.h>		// memcpy

static int queueGrow(queue_t* q)
{
	void *tmp;

	// Grow by factory 2
	if ((tmp = malloc(q->capacity * 2 * q->elemSize)) == NULL)
		return ERR_MALLOC;
	
	// Copy old queue
	for (int i = 0; i < q->capacity; i++)
		queueDequeue(q, (char*) tmp + i * q->elemSize);

	// Clean up -- compleete growing process
	free(q->elems);
	q->elems       = tmp;
	q->front       = 0;
	q->currentSize = q->capacity;
	q->capacity  <<= 1;

	return SUCCESS;
}

int queueInit(queue_t* q, int elemSize /*, freeFnk ... */)
{
	if (elemSize < 1)
		return ERR_INVALID_ARGUMENT;
	
	// initialize queue	
	q->capacity    = INIT_CAPACITY;
	q->currentSize = 0;
	q->front       = 0;
	q->elemSize    = elemSize;
	q->elems       = malloc(q->capacity * q->elemSize);

	return q->elems ? SUCCESS : ERR_MALLOC;
}

int queueDispose(queue_t* q)
{
	// todo
	return 0;
}

int queueEnqueue(queue_t* q, void* elem)
{
	if (queueIsFull(q))
		if (queueGrow(q) == ERR_REALLOC)
			return ERR_REALLOC;
	
	// enqueue
	int index = (q->front + q->currentSize) % q->capacity;
	memcpy((char*) q->elems + index * q->elemSize, elem, q->elemSize);

	q->currentSize++;
	return SUCCESS;
}

int queueDequeue(queue_t* q, void* elem)
{
	if (queueIsEmpty(q))
		return ERR_EMPTY;
	
	// dequeue
	memcpy(elem, (char*) q->elems + q->front * q->elemSize, q->elemSize);
	q->front = (q->front + 1) % q->capacity;

	q->currentSize--;
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
