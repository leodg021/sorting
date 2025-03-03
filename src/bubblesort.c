#include "sorts.h"

void bubble(float *arr, int size) {
	int swapped;
	for (int i = size-1; i > 0; i--) {
		swapped = 0;
		for (int j = 0; j < i; j++) {
			if (GE(arr[j], arr[j+1])) {
				SWAP(float, arr[j], arr[j+1]);
				swapped = 1;
			}
		}
		if (!swapped) return;
	}
}
