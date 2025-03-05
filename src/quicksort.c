/**
 * @file	quicksort.c
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains a function for the quicksort algorithm.
*/

#include "sorts.h"


/**
 * @brief	Partitions the array into two sorted halves.
 *
 * @param	arr		Array to sort.
 * @param	lo		Lower index of the array.
 * @param	hi		Higher index of the array.
*/
int _partition(float *arr, int lo, int hi) {
	int i = lo - 1;
	int j = hi;

	int pivot = hi;
	while (1) {
		while (i < hi && LT(arr[++i], arr[pivot]));
		while (j > lo && GT(arr[--j], arr[pivot]));
		
		if (i >= j) break;
		
		SWAP(float, arr[i], arr[j]);
	}

	SWAP(float, arr[i], arr[pivot]);

	return i;
}

/**
 * @brief	Recursively sorts each sorted half of the partitioned array.
 *
 * @param	arr		Array to sort.
 * @param	lo		Lower index of the array.
 * @param	hi		Higher index of the array.
*/
void _quicksort(float *arr, int lo, int hi) {
	if (hi <= lo) {
		return;
	}

	int p = _partition(arr, lo, hi);
	_quicksort(arr, lo, p-1);
	_quicksort(arr, p+1, hi);
}

/**
 * @brief	Quicksort algorithm with average O(n logn) time complexity.
 *
 * @param	arr		Array to sort.
 * @param	size	Size of array to sort.
*/
void quick(float *arr, int size) {
	int lo = 0;
	int hi = size - 1;

	_quicksort(arr, lo, hi);
}
