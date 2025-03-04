/**
 * @file	insertion_sort.c
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains a function for the selection sort algorithm.
*/

#include "sorts.h"


/**
 * @brief	Insertion sort algorithm with O(n^2) time complexity.
 *
 * @param	arr		Array to sort.
 * @param	size	Size of array to sort.
*/
void insertion(float* arr, int size) {
	for (int i = 1; i < size; i++) {
		int j = i;
		while (j > 0 && LT(arr[j], arr[j-1])) {
			SWAP(float, arr[j], arr[j-1]);
			j--;
		}
	}
}
