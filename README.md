# Sorting Library for the C Programming Language

## On the sorting algorithms

This _library_ was written as a practice exercise just to warm up some **C** programming skills. Below are presented some basic information on the sorting algorithms implemented here.

### Bubblesort

TODO: Write some information about bubblesort.

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

All references taken for this project were based on the following textbooks:

\[1\] [T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to algorithms. Cambridge, MA: The Mit Press, 2022.](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)
\[2\] [R. Sedgewick and K. Wayne, Algorithms. Upper Saddle River, NJ: Addison-Wesley, 2011.](https://algs4.cs.princeton.edu/home/)
