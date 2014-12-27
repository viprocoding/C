#include "Header.h"

// Swaps a and b without using a temporary variable.
//  Example: Let a = 0101, b = 1010
//      1. a == 1111
//      2. b == 0101    <-- Previous a
//      3. a == 1010    <-- Previous b
//          -- Swaped successfully --
//
// Function returns 1 to allow reducing expressions such as:
//   swap(..., ...);    | swapped = swap(..., ...);
//   swapped = 1;       |
//
//   swap(..., ...);    | flag += swap(..., ...);
//   flag++;            |
////
static int swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

    return 1;
}

///////////////////////////// Quick sort ///////////////////////////////////////

// Algorithm:
// ----------
//  1. Choose the arrays ending element (indexed by r) to be the pivot element.
//  2. Assume the pivot's correct index is indexed by the first element (l).
//  3. Traverse the array one element at a time (excluding the final index r)
//      -- If there's an element less or equal to the pivot it should be placed
//         to the left of the pivot's index.
//          --> Swap this element with the element indexed by the pivot indexer.
//          --> Increment the pivot indexer by 1.
//  4. All elements less than or equal to the pivot element can be found to the
//     left side of the pivot index, and all elements greater than the pivot can
//     be found to the right side of the pivot index.
//          --> Swap the pivot element (indexed by r) with the element indexed
//              by the pivot indexer. The pivot is now in the correct position.
//  5. Return the pivot index.
////
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
    // Valid array (not in base case)
    if (n <= 1)
        return;

    mergeSort(a, n/2);              // sort left
    mergeSort(a + n/2, n - n/2);    // sort right
    merge(a, n/2, a + n/2, n- n/2); // merge left and right side
}

///////////////////////////// Bubble sort /////////////////////////////////////

// Optimized version
void bubbleSort(int *a, int n)
{
    // Loop at most n - 1 times -- stop early if no swaps occured
    for (int i = 1, swapped = 1; i < n && swapped--; i++)
        // let the current largest element bubble up to the sorted part
        for (int j = 0, jn = n - i; j < jn; j++)
            if (*(a + j) > *(a + j + 1))
                swapped = swap(a + j, a + j + 1);
}

///////////////////////////// Insertion Sort ///////////////////////////////////

void insertionSort(int *a, int size)
{
    for (int i = 0, n = size - 1; i < n; i++)
        for (int j = i; j > 0 && *(a + j) < *(a + j - 1); j--)
                swap(a + j, a + j - 1);
}
