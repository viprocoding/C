#include "stack.h"
#include <string.h>
#include <stdio.h>

// Constants
#define PUSH_ELEMS 1000000  // Amount of elements to push
#define STR_SIZE   10

/* 
 * freeString:
 * Free function that knows how to free a char * pushed onto the stack.
 */
void freeString(void *str)
{
    free(*(char **)str);
}

int main(void)
{
    char       *tmp;
    const char  str[STR_SIZE] = "123456789";
    Stack       s;

    // Initialize stack
    stackNew(&s, sizeof(char *), freeString);

    // Push lots of elements allocated on the heap to the stack
    for (int i = 0; i < PUSH_ELEMS; i++) {
        tmp = malloc(STR_SIZE);
        strcpy(tmp, str);

        // Need adress of tmp -- this adress is passed to memcpy
        stackPush(&s, &tmp);
    }

    // Pop some elements
    for (int i = 0; i < PUSH_ELEMS / 2; i++) {
        stackPop(&s, &tmp);
        free(tmp);
    }

    // Let the stack return the remaining elements to the heap manager
    stackDispose(&s);

    return 0;
}
