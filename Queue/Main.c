#include <stdio.h>
#include "Queue.h"
#include <stdlib.h>

void stringFree(void* elem)
{
	free(*(char**) elem);
}

int main(int argc, char *argv[])
{
	queue_t q;
	char *s = "ELITE";
	char *t;

	queueInit(&q, sizeof(char*), stringFree);

	for (int i = 0; i < 10; i++)
		if (queueEnqueue(&q, &s) == ERR_MALLOC) {
			fprintf(stderr, "Error: Could not realloc during grow-procces.\n");
			break;
		}
	
	for (int i = 0; i < 11; i++) {
		if (queueDequeue(&q, &t) == ERR_EMPTY)
			fprintf(stderr, "Error: Empty stack at itteration %d\n", i);
		else
			printf("Dequeue result: %s\n", t);
	}

	queueDispose(&q);

	return 0;
}
