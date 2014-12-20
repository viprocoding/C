/*
 * Queue.h
 *
 * Rasmus Östersjö
 * 2014-12-20
 *
 * A generic and dynamic array implementation of a queue.
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

// Constants
#define INIT_CAPACITY 1

#define SUCCESS 0

#define ERR_INVALID_ARGUMENT -1
#define ERR_MALLOC           -2
#define ERR_EMPTY            -3

// Queue data type
typedef struct Queue
{
    int   capacity;
    int   currentSize;
    int   front;
    int   elemSize;
    void* elems;
    
    void (*freeFnk)(void* elem);
} queue_t;

/** queueInit
 *      Initializes a new queue with capacity INIT_CAPACITY and a current size
 *      of 0.
 *
 *  @param q        A pointer to a queue that is to be initialized.
 *  @param elemSize Size of each element in the queue (bytes).
 *  @param freeFnk  A pointer to a function that knows how to free each element
 *                  in the queue, NULL if elements does not need to be freed.
 *  
 *  @return         ERR_MALLOC  Heap memory could not be allocated.
 *                  SUCCESS
 */
int queueInit(queue_t* q, int elemSize, void (*freeFnk)(void* elem));

/** queueDispose
 *      Disposes a queue.
 *
 *  @param q        A pointer to a queue that is to be disposed.
 */
void queueDispose(queue_t* q);

/** queueEnqueue
 *      Enqueues an elemenet to the specified queue.
 *
 *  @param q        A pointer to a queue.
 *  @param elem     A pointer to an element that is to be enqueued.
 *
 *  @return         ERR_MALLOC  Heap memory could not be allocated during grow-
 *                              proccess.
 *                  SUCCESS
 */
int queueEnqueue(queue_t* q, void* elem);

/** queueDequeue
 *      Dequeues am element from the specified queue.
 *
 *  @param q        A pointer to a queue.
 *  @param elem     Dequeue result is written to this addres.
 *
 *  @return         ERR_EMPTY   Queue was empty (dequeue canceled).
 *                  SUCCESS
 */
int queueDequeue(queue_t* q, void* elem);

/** queueIsFull
 *      Checks if the specified queue is full.
 *
 *  @param q        A pointer to a queue.
 *
 *  @return         Non-zero    Queue is full.
 *                  Zero        Queue is not full.
 */
int queueIsFull(queue_t* q);

/** queueIsEmpty
 *      Checks if the specified queue is empty.
 *
 *  @param q        A pointer to a queue.
 *
 *  @return         Non-zero    Queue is empty.
 *                  Zero        Queue is not empty.
 */
int queueIsEmpty(queue_t* q);

#endif  // __QUEUE_H__
