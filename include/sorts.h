#ifndef SORT
#define SORT

#define SWAP(T, x, y) do {T temp = x; x = y; y = temp;} while(0)

#define GT(x, y) ((x) > (y))
#define LT(x, y) ((x) < (y))
#define GE(x, y) ((x) >= (y)) 
#define LE(x, y) ((x) <= (y))
#define EQ(x, y) ((x) == (y))
#define NE(x, y) ((x) != (y))


void bubble(float *arr, int size);		// Bubblesort
void selection(float *arr, int size);	// Selection sort
void insertion(float *arr, int size);	// Insertion sort
void merge(float *arr, int size);		// Mergesort
void quick(float *arr, int size);		// Quicksort
void heapsort(float *arr, int size);	// Heapsort

#endif
