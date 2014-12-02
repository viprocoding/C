/*
 * fib.c
 * 2014-09-23
 *
 * Implements the fibonacci sequence.
 *
 * Compile	gcc -Wall -Werror -std=c99 -o fib fib.c
 * Run		./fib		or 		./fib n
 */

// Sneaky add

// libraires
#include <stdio.h>		// printf, fgetc
#include <stdlib.h>		// atoi 

// constants
#define SPACE 8				// minimum space between printed numbers
#define DEFAULT_LIMIT 100	// default limit if the user dont provide one

/*
 * greetUser:
 * Greets the user and waits until the user wants to start the program.
 */
void greetUser(void)
{
	printf("Wellcome to fib. series! Press ENTER to continue!\n");
	while (fgetc(stdin) != '\n')
		;
}

/* fib:
 * Prints the fibbonacci sequence in interval [1, n).
 */
void fib(int n)
{
	int curNum, prevNum, prevPrevNum;

	// seed
	for (curNum = 0, prevNum = prevPrevNum = 1; curNum < 2 && n > 1 ; curNum++)
		printf("%-*d", SPACE, 1);

	// continue running with fib. sequence logic
	while (curNum < n) {
		printf("%-*d", SPACE , curNum);
		prevPrevNum = prevNum;
		prevNum = curNum;
		curNum = prevNum + prevPrevNum;
	}
	printf("\n");
}

int main (int argc, char *argv[])
{
	int limit;
	if (argc == 2)
		limit = atoi(argv[1]);
	else
		limit = DEFAULT_LIMIT;

	// run fib. sequence
	fib(limit);	

	return 0;
}
