#include "Header.h"

static int swap(int *a, int *b)
{
    int tmp = *a;
    *a      = *b;
    *b      = tmp;

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

///////////////////////////// Merge Sort //////////////////////////////////////

static void merge(int *a, int an, int *b, int bn)
{
    int tmp[an + bn], ai, bi, i, n;

    // merge a and b onto tmp until either a or b runs out of elements
    for (i = ai = bi = 0; ai < an && bi < bn; i++)
        *(tmp + i) = *(a + ai) < *(b + bi) ? *(a + ai++) : *(b + bi++);

    // merge remaining elements in a
    while (ai < an)
        *(tmp + i++) = *(a + ai++);

    // merge remaining elements in b
    while (bi < bn)
        *(tmp + i++) = *(b + bi++);

    // write result back to original array
    for (i = 0, n = an + bn; i < n; i++)
        *(a + i) = *(tmp + i);
}

void mergeSort(int *a, int n)
{
    // base case
    if (n <= 1)
        return;

    mergeSort(a, n/2);              // sort left
    mergeSort(a + n/2, n - n/2);    // sort right
    merge(a, n/2, a + n/2, n- n/2); // merge left and right side
}
