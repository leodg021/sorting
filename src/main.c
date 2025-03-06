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

#define SIZE_ARRAY 100000

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
* @brief	Generates the logger info.
*
* @param	algo_name		Name of the sorting algorithm employed.
*/
void logger_info(const char *algo_name) {
	time_t now;
	time(&now);

	char buff[26];
	strftime(buff, 26, "%Y-%m-%d %H:%M:%S", localtime(&now));
	printf("%s [%s]... ", buff, algo_name);
	fflush(stdout);
}

/**
* @brief	Generates logger status.
*
* @param	tag				Message to display on logger.
* @param	time_elapsed	Time taken to sort by the algorithm.
*/
void logger_status(const char *tag, double time_elapsed) {
	printf("(Time elapsed: %2.8fs): %s\n", time_elapsed, tag);
}

/**
* @brief	Function to test whether array is sorted.
*
* @param	arr				Array to be sorted.
* @param	time_elapsed	Time taken to sort by the algorithm.
*/
void assert_sorted(float *arr, double time_elapsed) {
	for (int i = 0; i < SIZE_ARRAY-1; i++) {
		if (GT(arr[i], arr[i+1])) {
			logger_status(TEST_FAILED, time_elapsed);
			return;
		}
	}
	logger_status(TEST_SUCCESS, time_elapsed);
}

/**
* @brief	Test function to benchmark sorting algorithm.
*
* @param	arr			Array to be sorted.
* @param	algo_name	Name of the sorting algorithm employed.
* @param	callback	Function pointer for the sorting algorithm.
*/
void test(float *arr, const char *algo_name, void (*callback)(float*, int)) {
	float clone[SIZE_ARRAY];

	memcpy(clone, arr, sizeof(float) * SIZE_ARRAY);

	clock_t start, end;

	logger_info(algo_name);

	start = clock();
	callback(clone, SIZE_ARRAY);
	end = clock();

	assert_sorted(clone, (double) (end - start) / CLOCKS_PER_SEC);

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

	printf("===== Initializing benchmark testing for sorting algorithms:\n\n");
	test(arr, "BUBBLESORT", bubble);
	test(arr, "SELECTIONSORT", selection);
	test(arr, "INSERTIONSORT", insertion);
	test(arr, "MERGESORT", merge);
	test(arr, "QUICKSORT", quick);
	test(arr, "HEAPSORT", heapsort);
	printf("\n===== Finished benchmark testing for sorting algorithms.\n");

	return 0;
}
