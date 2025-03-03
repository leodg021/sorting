/**
 * @file: bubblesort.c
 * @author: Leonardo D. Garcia
 *
 * This file contains a function for the bubblesort algorithm.
*/

#include "sorts.h"


/**
 * Bubblesort algorithm with O(n^2) time complexity.
 * @param [in, out]	arr		Array to sort.
 * @param [in]		size	Size of array to sort.
*/
void bubble(float *arr, int size) {
	int swapped;
	for (int i = size-1; i > 0; i--) {
		swapped = 0;
		for (int j = 0; j < i; j++) {
			if (GE(arr[j], arr[j+1])) {
				SWAP(float, arr[j], arr[j+1]);
				swapped = 1;
			}
		}
		if (!swapped) return;
	}
}
