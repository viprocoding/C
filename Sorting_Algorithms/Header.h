#ifndef __HEADER_H__
#define __HEADER_H__

/** Sort an array in increasing order using quick sort.
 *
 * @param a     Pointer to an array that is to be sorted.
 * @param l     Index of the left most element.
 * @param r     Index of the last element.
 */
void quickSort(int *a, int l, int r);

/** Sort an array in increasing order using merge sort.
 *
 * @param a     Pointer to an array that is to be sorted.
 * @param n     Size of the array.
 */
void mergeSort(int *a, int n);

/** Sort an array in increasing order using bubble sort.
 *
 * @param a     Pointer to an array that is to be sorted.
 * @param n     Size of the array.
 */
void bubbleSort(int *a, int n);

/** Sort an array in increasing order using insertion sort
 *
 * @param a     Pointer to an array that is to be sorted.
 * @param n     Size of the array.
 */
void insertionSort(int *a, int n);

#endif // __HEADER_H__
