#ifndef SORT
#define SORT

#define SWAP(T, x, y) do {T temp = x; x = y; y = temp;} while(0)

#define GT(x, y) ((x) > (y))
#define LT(x, y) ((x) < (y))
#define GE(x, y) ((x) >= (y)) 
#define LE(x, y) ((x) <= (y))
#define EQ(x, y) ((x) == (y))

void bubble(float *arr, int size);
void selection(float *arr, int size);
void insertion(float *arr, int size);
void merge(float *arr, int size);
void quick(float *arr, int size);
void heapsort(float *arr, int size);

#endif
