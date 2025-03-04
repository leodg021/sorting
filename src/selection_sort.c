/**
 * @file	selection_sort.c
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains a function for the selection algorithm.
*/

#include "sorts.h"


/**
 * @brief	Function employed for sorting an array with selection sort algorithm.
 * 
 * @param	arr		Array to be sorted.
 * @param	size	Size of array to sort.
*/
void selection(float *arr, int size) {
	int curr_max;

	for (int i = size-1; i >= 0; i--) {
		curr_max = i;

		for (int j = 0; j < i; j++) {
			if (GE(arr[j], arr[curr_max])) {
				curr_max = j;
			}
		}
		if (NE(i, curr_max)) SWAP(float, arr[i], arr[curr_max]);
	}
}
