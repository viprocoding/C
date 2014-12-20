#include <stdio.h>
#include "Queue.h"

int main(int argc, char *argv[])
{
	queue_t q;

	queueInit(&q, sizeof(int));

	for (int i = 0; i < 10; i++)
		if (queueEnqueue(&q, &i) == ERR_REALLOC) {
			fprintf(stderr, "Error: Could not realloc during grow-procces.\n");
			break;
		}
	
	for (int i = 0, j; i < 11; i++) {
		if (queueDequeue(&q, &j) == ERR_EMPTY)
			fprintf(stderr, "Error: Empty stack at itteration %d\n", i);
		else
			printf("Dequeue result: %d\n", j);
	}

	queueDispose(&q);

	return 0;
}
