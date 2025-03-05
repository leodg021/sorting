# Sorting Library for the C Programming Language

## On the sorting algorithms

TODO: Write information about the sorting algorithms employed.


## Instructions

In order to build the programs, please make use of the Makefile to generate all object files and the main executable.

The command you'll want to use is: `make`.

Once this is done, this is the result that you should expect from the terminal:

    $ make
    ===== Compiling: src/quicksort.c
    ===== Compiling: src/insertion_sort.c
    ===== Compiling: src/mergesort.c
    ===== Compiling: src/main.c
    ===== Compiling: src/bubblesort.c
    ===== Compiling: src/selection_sort.c
    ===== Compiling: src/heapsort.c
    ===== Generating executable: ./bin/mainODO: Write about the different sorting algorithms employed for this library.

To run the program as it is, please execute the generated executable `bin/main`. As an example, this is the output from a test run.

    $ bin/main
    ===== Initializing benchmark testing for sorting algorithms:

    Wed Mar  5 15:10:25 2025 (Time elapsed: 23.67196300s) [BUBBLESORT]: Test successful! Array is now sorted.
    Wed Mar  5 15:10:34 2025 (Time elapsed: 9.04890600s) [SELECTIONSORT]: Test successful! Array is now sorted.
    Wed Mar  5 15:10:42 2025 (Time elapsed: 8.05102300s) [INSERTIONSORT]: Test successful! Array is now sorted.
    Wed Mar  5 15:10:42 2025 (Time elapsed: 0.01439300s) [MERGESORT]: Test successful! Array is now sorted.
    Wed Mar  5 15:10:42 2025 (Time elapsed: 0.01262000s) [QUICKSORT]: Test successful! Array is now sorted.
    Wed Mar  5 15:10:42 2025 (Time elapsed: 0.02135400s) [HEAPSORT]: Test successful! Array is now sorted.

    ===== Finished benchmark testing for sorting algorithms.
