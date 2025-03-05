/**
 * @file	mergesort.c
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains a function for the mergesort algorithm.
*/

#include "sorts.h"


/**
 * @brief	Merges the two sorted halves of the array.
 *
 * @param	arr		Array to sort.
 * @param	aux		Auxiliary array for the sorting.
 * @param	lo		Lower index of the array.
 * @param	mid		Middle index of the array.
 * @param	hi		Higher index of the array.
*/
void _merge(float *arr, float *aux, int lo, int mid, int hi) {
	for (int k = lo; k <= hi; k++) {
		aux[k] = arr[k];
	}

	int i = lo;
	int j = mid + 1;

	for (int k = lo; k <= hi; k++) {
		if (i > mid) arr[k] = aux[j++];
		else if (j > hi) arr[k] = aux[i++];
		else if (LE(aux[i], aux[j])) arr[k] = aux[i++];
		else arr[k] = aux[j++];
	}
	
}

/**
 * @brief	Partitions the array and sorts each half to then merge them.
 *
 * @param	arr		Array to sort.
 * @param	aux		Auxiliary array for the sorting.
 * @param	lo		Lower index of the array.
 * @param	hi		Higher index of the array.
*/
void _mergesort(float *arr, float *aux, int lo, int hi) {
	if (lo >= hi) return;

	int mid = lo + (hi - lo) / 2;

	_mergesort(arr, aux, lo, mid);
	_mergesort(arr, aux, mid+1, hi);
	_merge(arr, aux, lo, mid, hi);
}

/**
 * @brief	Mergesort algorithm with average O(n logn) time complexity.
 *
 * @param	arr		Array to sort.
 * @param	size	Size of array to sort.
*/
void merge(float *arr, int size) {
	int lo = 0;
	int hi = size - 1;
	
	float aux[size];

	_mergesort(arr, aux, lo, hi);
}



