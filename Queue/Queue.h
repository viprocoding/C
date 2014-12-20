/*
 * Queue.h
 *
 * Rasmus Östersjö
 * 2014-12-XX
 *
 * A generic and dynamic array implementation of a queue.
 *
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

// Libraries

// Constants

// Queue data type
typedef struct Queue
{
	int   capacity;
	int   currentSize;
	int   elemSize;
	void* elems;
	// free fnk
} queue_t;

int queueInit(queue_t* q, int elemSize /*, freeFnk... */);
int queueDispose(queue_t* q);
int queueEnqueue(queue_t* q, void* elem);
int queueDequeue(queue_t* q, void* elem);
int queueIsFull(queue_t* q);
int queueIsEmpty(queue_t* q);


#endif
