# Sorting Library for the C Programming Language

## On the sorting algorithms

This _library_ was written as a practice exercise just to warm up some **C** programming skills. Below are presented some basic information on the sorting algorithms implemented here.

In preparation to the (utterly brief) explanations to be detailed next for the sorting algorithms shown, we add here a brief video by Timo Bingmann in which, with the help of the [Sound of Sorting](https://panthema.net/2013/sound-of-sorting/), displays visualization for these and some other sorting algorithms.

[![15 Sorting Algorithms in 6 Minutes.](https://img.youtube.com/vi/kPRA0W1kECg/0.jpg)](https://www.youtube.com/watch?v=kPRA0W1kECg)

### Bubblesort

Bubblesort is a popular yet inefficient sorting algorithm characterized by constantly swapping the larger elements from bottom to top in the same sense as a bubble "rising" in an array. 

    bubblesort(arr)
        for i = (arr.length - 1)..1:
            for j = 0..i:
                if arr[j] > arr[j+1]:
                    swap(arr[j], arr[j+1])

To prove that bubblesort works, we note that as we move within the inner loop, the largest element we find is guaranteed to end at the position `i` of the array. As such, we can predict that the subarray `arr[i..arr.length-1]` is to be sorted, as any element `arr[i-1]` is expected to be less or equal to `arr[i]`. With this cycle being repeated across all `i`'s, we arrive at the utmost conclusion that the array will end up being sorted from top to bottom.

In the worst case, bubblesort will perform up to $n$ comparisons and swaps for each element in the array, meaning that one can predict that it execute around $\Theta(n^2)$ operations to sort the array, proving that it will be correct but slow way of organizing ordered data. 

### Selection sort

TODO: Write some information about selection sort.

### Insertion sort

TODO: Write some information about insertion sort.

### Mergesort

TODO: Write some information about mergesort.

### Quicksort

TODO: Write some information about quicksort.

### Heapsort

TODO: Write some information about heapsort.


## Getting started

### Installing locally

To install the library locally, you can either download it straight from the repository page or proceed to cloning it with `git`.

    $ git clone https://github.com/leodg021/sorting.git

### Building

In order to build the programs, please make use of the `Makefile` to generate all object files and the main executable.

The command you'll want to use is: `make`. (The `Makefile` assumes you are using the `gcc` compiler, so feel free to edit it if you prefer any other compiler such as `clang`.) 

Once this is done, this is the result that you should expect from the terminal:

    $ make
    ===== Compiling: src/quicksort.c
    ===== Compiling: src/insertion_sort.c
    ===== Compiling: src/mergesort.c
    ===== Compiling: src/main.c
    ===== Compiling: src/bubblesort.c
    ===== Compiling: src/selection_sort.c
    ===== Compiling: src/heapsort.c
    ===== Generating executable: ./bin/main

### Running

To run the program as it is, please execute the generated executable `bin/main`. As an example, this is the output from a test run.

    $ bin/main
    ===== Initializing benchmark testing for sorting algorithms:

    2025-03-06 14:27:50 [BUBBLESORT]... (Time elapsed: 25.06595200s): Test successful! Array is now sorted.
    2025-03-06 14:28:15 [SELECTIONSORT]... (Time elapsed: 11.62404500s): Test successful! Array is now sorted.
    2025-03-06 14:28:26 [INSERTIONSORT]... (Time elapsed: 8.21858000s): Test successful! Array is now sorted.
    2025-03-06 14:28:35 [MERGESORT]... (Time elapsed: 0.01623000s): Test successful! Array is now sorted.
    2025-03-06 14:28:35 [QUICKSORT]... (Time elapsed: 0.01234500s): Test successful! Array is now sorted.
    2025-03-06 14:28:35 [HEAPSORT]... (Time elapsed: 0.01759500s): Test successful! Array is now sorted.

    ===== Finished benchmark testing for sorting algorithms.


## References

All references taken for this project were based on the following places:

\[1\] Timo Bingmann. _15 Sorting Algorithms in 6 Minutes._ (May 20, 2013). Accessed: March 18, 2025. \[Online Video\]. Available: [https://www.youtube.com/watch?v=kPRA0W1kECg](https://www.youtube.com/watch?v=kPRA0W1kECg)

\[1\] [T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to algorithms. Cambridge, MA: The Mit Press, 2022.](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)

\[2\] [R. Sedgewick and K. Wayne, Algorithms. Upper Saddle River, NJ: Addison-Wesley, 2011.](https://algs4.cs.princeton.edu/home/)
