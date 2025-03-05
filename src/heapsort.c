/**
 * @file	heapsort.c
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains a function for the heapsort algorithm.
*/

#include "sorts.h"


/**
 * @brief	Element sinks down in the binary heap.
 *
 * @param	arr		Array to heapify.
 * @param	index	Index of heap element that might sink.
 * @param	size	Size of array to heapify.
*/
void _sink(float *arr, int index, int size) {
	int left, right;
	int largest = index;

	while (2*index < size) {
		left = 2*index + 1;
		right = 2*index + 2;

		if (left < size && GT(arr[left], arr[largest])) {
			largest = left;
		}

		if (right < size && GT(arr[right], arr[largest])) {
			largest = right;
		}

		if (largest == index) return;

		SWAP(float, arr[largest], arr[index]);
		index = largest;
	}
}

/**
 * @brief	Transform array into a binary heap.
 *
 * @param	arr		Array to heapify.
 * @param	size	Size of array to heapify.
*/
void _heapify(float *arr, int size) {
	for (int i = size/2-1; i >= 0; i--) {
		_sink(arr, i, size);
	}
}

/**
 * @brief	Heapsort algorithm with average O(n logn) time complexity.
 *
 * @param	arr		Array to sort.
 * @param	size	Size of array to sort.
*/
void heapsort(float *arr, int size) {
	_heapify(arr, size);

	for (int index = size-1; index > 0; index--) {
		SWAP(float, arr[0], arr[index]);
		_sink(arr, 0, index);
	}
}
