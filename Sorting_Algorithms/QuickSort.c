#include "Header.h"

static int swap(int *a, int *b)
{
    // swap a and b without a tmp
    /*
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    */

    int tmp = *a;
    *a = *b;
    *b = tmp;

    return 1;
}

///////////////////////////// Quick sort ///////////////////////////////////////

static int partition(int *a, int l, int r)
{
    int p = l;

    // arrange all elements less or equal to the pivot to the left
    for (int i = l; i < r; i++)
        if (*(a + i) <= *(a + r))
            p += swap(a + i, a + p);

    // place pivot element in the pivot possition
    swap(a + p, a + r);

    return p;
}

void quickSort(int *a, int l, int r)
{
    // base case
    if (l < r) {
        int p = partition(a, l, r); // find pivot
        quickSort(a, l, p - 1);     // sort left side of pivot
        quickSort(a, p + 1, r);     // sort right side of pivot
    }
}
