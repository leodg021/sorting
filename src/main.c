/**
 * @file	main.c
 * @author	Leonardo D. Garcia
 *
 * @brief	This file contains the benchmark tests for the sorting algorithms.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorts.h"

#define SIZE_ARRAY 100

// Logger tags.
#define TEST_SUCCESS "Test successful! Array is now sorted."
#define TEST_FAILED "Test failed! Array remains unsorted."

/**
* @brief	Generate a random float number between 0.0 and 1.0.
*
* @return	Returns a random float number between 0.0 and 1.0.
*/
float random_float() {
	return (float) rand() / (float) RAND_MAX;
}

/**
* @brief	Generate a random float number between 0.0 and 1.0.
*
* @param	message			Message to display on logger.
* @param	algo_name		Name of the sorting algorithm employed.
* @param	time_elapsed	Time taken to sort by the algorithm.
*/
void logger(const char *message, const char *algo_name, double time_elapsed) {
	time_t now;
	time(&now);
	printf("%.24s (Time elapsed: %.10f) [%s]: %s\n", ctime(&now), time_elapsed, algo_name, message);
}

/**
* @brief	Function to test whether array is sorted.
*
* @param	arr				Array to be sorted.
* @param	algo_name		Name of the sorting algorithm employed.
* @param	time_elapsed	Time taken to sort by the algorithm.
*/
void assert_sorted(float *arr, const char *algo_name, double time_elapsed) {
	for (int i = 0; i < SIZE_ARRAY-1; i++) {
		if (GT(arr[i], arr[i+1])) {
			logger(TEST_FAILED, algo_name, time_elapsed);
			return;
		}
	}
	logger(TEST_SUCCESS, algo_name, time_elapsed);
}

/**
* @brief	Test function to benchmark sorting algorithm.
*
* @param	arr			Array to be sorted.
* @param	algo_name	Name of the sorting algorithm employed.
* @callback callback	Function pointer for the sorting algorithm.
*/
void test(float *arr, const char *algo_name, void (*callback)(float*, int)) {
	float clone[SIZE_ARRAY];

	memcpy(arr, clone, sizeof(float) * SIZE_ARRAY);

	clock_t start, end;

	start = clock();
	callback(clone, SIZE_ARRAY);
	end = clock();

	assert_sorted(clone, algo_name, (double) (end - start) / CLOCKS_PER_SEC);

}

/**
* @brief	Main function to benchmark sorting algorithms.
*
* @return	0.
*/
int main() {
	srand(time(NULL));

	float arr[SIZE_ARRAY];
	for (int i = 0; i < SIZE_ARRAY; i++) {
		arr[i] = random_float();
	}	


	test(arr, "BUBBLESORT", bubble);
	test(arr, "SELECTIONSORT", selection);
	test(arr, "INSERTIONSORT", insertion);

	return 0;
}
