#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "sorts.h"

#define SIZE_ARRAY 100

#define TEST_SUCCESS "Test successful! Array is now sorted."
#define TEST_FAILED "Test failed! Array remains unsorted."

void logger(const char*  message, const char* algo_name, double time_elapsed) {
	time_t now;
	time(&now);
	printf("%.24s (Time elapsed: %.10f) [%s]: %s\n", ctime(&now), time_elapsed, algo_name, message);
}

float random_float() {
	return (float) rand() / (float) RAND_MAX;
}

void assert_sorted(float* arr, const char* algo_name, double time_elapsed) {
	for (int i = 0; i < SIZE_ARRAY-1; i++) {
		if (GT(arr[i], arr[i+1])) {
			logger(TEST_FAILED, algo_name, time_elapsed);
			return;
		}
	}
	logger(TEST_SUCCESS, algo_name, time_elapsed);
}

void test(float* arr, const char* algo_name, void (*callback)(float*, int)) {
	float clone[SIZE_ARRAY];

	memcpy(arr, clone, sizeof(float) * SIZE_ARRAY);

	clock_t start, end;

	start = clock();
	callback(clone, SIZE_ARRAY);
	end = clock();

	assert_sorted(clone, algo_name, (double) (end - start) / CLOCKS_PER_SEC);

}

int main() {
	srand(time(NULL));

	float arr[SIZE_ARRAY];
	for (int i = 0; i < SIZE_ARRAY; i++) {
		arr[i] = random_float();
	}	


	test(arr, "BUBBLESORT", bubble);
	test(arr, "SELECTIONSORT", selection);

	return 0;
}
