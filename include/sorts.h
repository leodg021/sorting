/**
 * @file	sorts.h
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains the header functions for the sorting algorithm.
*/

#ifndef SORTS_H
#define SORTS_H

#define SWAP(T, x, y) do {T temp = x; x = y; y = temp;} while(0)	// Macro for swapping.

#define GT(x, y) ((x) > (y))	// Macro for 'greater than' comparison.
#define LT(x, y) ((x) < (y))	// Macro for 'less than' comparison.
#define GE(x, y) ((x) >= (y)) 	// Macro for 'greater or equal to' comparison.
#define LE(x, y) ((x) <= (y))	// Macro for 'less or equal to' comparison.
#define EQ(x, y) ((x) == (y))	// Macro for 'equal to' comparison.
#define NE(x, y) ((x) != (y))	// Macro for 'not equal to' comparison.


void bubble(float *arr, int size);		// Bubblesort
void selection(float *arr, int size);	// Selection sort
void insertion(float *arr, int size);	// Insertion sort
void merge(float *arr, int size);		// Mergesort
void quick(float *arr, int size);		// Quicksort
void heapsort(float *arr, int size);	// Heapsort

#endif
