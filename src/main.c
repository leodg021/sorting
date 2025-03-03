#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorts.h"

#define SIZE_ARRAY 10

#define TEST_SUCCESS "Test successful! Array is now sorted."
#define TEST_FAILED "Test failed! Array remains unsorted."

void logger(const char *message, const char *algo_name) {
	time_t now;
	time(&now);
	printf("%.24s [%s]: %s\n", ctime(&now), algo_name, message);
}

float random_float() {
	return (float) rand() / (float) RAND_MAX;
}

void assert_ordered(float *arr, const char* algo_name) {
	for (int i = 0; i < SIZE_ARRAY-1; i++) {
		if (GT(arr[i], arr[i+1])) {
			logger(TEST_FAILED, algo_name);
			return;
		}
	}
	logger(TEST_SUCCESS, algo_name);
}

int main() {
	srand(time(NULL));

	float arr[SIZE_ARRAY];
	for (int i = 0; i < SIZE_ARRAY; i++) {
		arr[i] = random_float();
	}	

	bubble(arr, SIZE_ARRAY);
	assert_ordered(arr, "BUBBLESORT");

	return 0;
}
