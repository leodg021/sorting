# Sorting Library for the C Programming Language

## On the sorting algorithms

This _library_ was written as a practice exercise just to warm up some **C** programming skills. Below are presented some basic information on the sorting algorithms implemented here. These explanations are expected to contain errors and incomplete information quick to be noticed by the keen eye. It is my intention to improve upon this in the future, so please be patient as I work on it. Thank you!

In preparation to the (utterly brief) explanations to be detailed next for the sorting algorithms shown, we add here a brief video by Timo Bingmann in which, with the help of the [Sound of Sorting](https://panthema.net/2013/sound-of-sorting/), displays visualization for these and some other sorting algorithms.

[![15 Sorting Algorithms in 6 Minutes.](https://img.youtube.com/vi/kPRA0W1kECg/0.jpg)](https://www.youtube.com/watch?v=kPRA0W1kECg)

### Bubblesort

**Bubblesort** is a popular yet inefficient sorting algorithm characterized by constantly swapping the larger elements from bottom to top in the same sense as a _bubble_ "rising" in an array. 

    bubblesort(arr)
        for i = (arr.length - 1)..0:
            for j = 0..i:
                if arr[j] > arr[j+1]:
                    swap(arr[j], arr[j+1])

To prove that bubblesort works, we note that as we move within the inner loop, the largest element we find is guaranteed to end at the position `i` of the array. As such, we can predict that the subarray `arr[i..arr.length-1]` is to be sorted, as any element `arr[i-1]` is expected to be less or equal to `arr[i]`. With this cycle being repeated across all `i`'s, we arrive at the utmost conclusion that the array will end up being sorted from top to bottom.

In the worst case, bubblesort will perform up to $n$ comparisons and swaps for each element in the array, meaning that one can predict that it execute around $\Theta(n^2)$ operations to sort the array, proving that it will be correct but slow way of organizing ordered data. 

### Selection sort

**Selection sort** works in some way similar to bubblesort, in that it tries to find the largest element in the leftmost subarray. It improves upon bubblesort by _selecting_ the location of the currently largest element in this subarray and swapping it to the last element of the partition, instead of slowing swapping element by element until it reaches its local end. In this way, we could save in the worst case up to $n$ swaps per loop.

    selection_sort(arr)
        for i = (arr.length-1)..0
            largest_index = i
            for j = 0..i:
                if arr[j] > arr[largest_index]:
                    largest_index = j;
            swap(arr[i], arr[largest_index])

Given that in principle it follows a logic similar to bubblesort, and while reduces the total number of swaps to up to $n-1$ in the whole cycle, it still has to traverse through the partial array a total number of $n-1$, meaning that its behavior is still $\Theta(n^2)$.

### Insertion sort

Until now, all previously seen sorting algorithms were quadratic, which meant they were not feasible for applications over large data sets. **Insertion sort** improves upon them by numerous reasons.

First of all, insertion sort works by _inserting_ an element down an already sorted list in its right place. We move the element down the sorted list until it reaches the point where it is greater or equal to all elements below it, and less or equal to all elements above it. This has the increased benefit that the algorithm is not forced to traverse through the entire sorted subarray if it stops before. 

Because of this, two added benefits of insertion sort is that is in **in-place** and **stable**. In-place means that we do not require to generate any other auxiliary array to perform the sorting, which saves a lot in memory for the larger arrays. Stable means that it conserves the initial relative order of any group of elements with the same value.

    insertion_sort(arr)
        for i = 1..arr.length:
            j = i
            while j > 0 and arr[j] < arr[j-1]:
                swap(arr[j], arr[j-1])
                j = j - 1

In the worst case, insertion sort traverses through the array a total number of $1 + 2 + ... + n-1$ times, signaling a $\Theta(n^2)$ time complexity, similar to bubblesort or selection sort. Still, it tends to outperform these two most of the time by significant margins.

### Mergesort

**Mergesort** is a sorting algorithm based on the _divide-and-conquer_ approach to problem solving. It works by proposing a recursive methodology to the sorting problem. In essence, its basis radicates on the fact that given two sorted subarrays, we can _merge_ them in linear time to produce sorted whole new array. This is the reason for the name of the algorithm.

In order to generate the two required already sorted subarrays, we proceed to the divide-and-conquer approach. We divide our entire unsorted array into two halves. We proceed then to recursive divide each subarray into two other subarrays until we reach a point where each atomic subarray consists of only one element. Once this is done, given that the single-element subarrays are technically already sorted, we merge each pair of subarrays from the bottom up, until we get our final sorted _mega_ array.

    mergesort(arr, low_pointer, high_pointer)
        if low_pointer >= high_pointer:
            return
        mid_pointer = (low_pointer + high_pointer) / 2
        mergesort(arr, low_pointer, mid_pointer)
        mergesort(arr, mid_pointer+1, high_pointer)
        merge(arr, low_pointer, mid_pointer, high_pointer)

Typically, to merge the two subarrays we require additional space to temporarily store the values in the subarrays that will end up in the larger array. Because of this, mergesort is not in-place, while it preserves the quality of being a stable sorting algorithm due to the fact that the relative order of the initial elements with equal values is kept intact during the merger.

Mergesort requires that we pass through $n$ elements at the time to perform the merger, but to do so, we had to kept dividing the array a total number of $\log{n}$ times. Thus, in its worst-case, mergesort tends to possess a time complexity in the order of $\Theta(n \log{n})$. This immediately presentes it as the best-performing bunch of the sorting algorithms by a larger margin in comparison with the previously seen quadratic sorters.

### Quicksort

**Quicksort** is another famous divide-and-conquer algorithm that, as its name suggests, tends to perform quickly in practice. It works by partitioning the array into two parts, although not necessarily symmetrical as was the case for mergesort. 

The algorithm selects a _pivot_ to commence the run. This pivot should be characterized by making the left half of the array contain all elements smaller than the pivot, and the right half contain all elements larger than the pivot. In theory, the pivot can be any value from the array, although the obvious recommended choice ought to be the _median_.

To partition properly around the pivot, we tend to swap any elements between left and right subarrays if we see they do not align with respect to the pivot's ordering place. Once this is done, we recursively apply quicksort on each half of the partition until the whole array is sorted.

    quicksort(arr, low_pointer, high_pointer)
        if low_pointer < high_pointer:
                pivot = partition(arr, low_pointer, high_pointer)
                quicksort(arr, low_pointer, pivot-1)
                quicksort(arr, pivot+1, high_pointer)

If we select a good pivot to do the partition, we should be able to expect a total number of $\log{n}$ divisions along all elements in the array, making it $\Theta(n \log{n})$ time complexity in average. Nonetheless, if we select a bad pivot, we may arrive at a situation where the partitioning is totally imbalanced, leading in the worst scenario to a case where one partition contains $n-1$ elements and the other partition (which excludes the pivot) zero elements. 

In consequence, we can see that if we repeat this behavior, we can almost assure that we will end up with a worst-case $\Theta(n^2)$ time complexity, much worse than with mergesort. Even so, this statistically rarely happens in practice, and the average linearithmic time complexity tends to perform even better than other $\Theta(n \log{n})$ algorithms such as mergesort in real life while also being in-place (although not stable), giving validity to the prefix of this sorting algorithm.

### Heapsort

**Heapsort** is another fast sorting algorithm inspired by a popular data structure: the _heap_. The heap is characterized by organizing a data set with respect to a relative order. The most popular heaps are _binary heaps_, characterized by following the same structure as a binary tree, with each node being a _parent_ to at most two _children nodes_, normally called _left_ and _right_. 

For the heap, one typically follows a _priority queue_ scheme, where the parent node of the whole tree has a bigger priority than any of its children. For a heap, this typically means either it is the largest element in the tree, or the smallest one.

In the case we follow a _max-heap_ scheme, with its parent node being larger than its children node, then we can continually sort an array as we keep forming heaps of its subarrays growing smaller one element at the time. We build a max-heap, or _heapify_ the array, by _sinking down_ exponentially each element in the upper half of the array (or heap) by swapping it with the location of its children if it is found to be smaller than the largest of them.

Once we have heapified the array, we just swap its largest element (the first one in the priority queue) with the last one in the subarray. We repeat the whole process with a lightly smaller subarray, where we sink the first element in the subarray to heapify it again and swap it with the last one to preserve the ordering. This last element of the subarray is guaranteed to be smaller than any element in the rightmost subarray, so this iterative process conserves the ordering and thus keeps sorting the array until our heap subarray has only one element.

    heapsort(arr)
        heapify(arr)
        for i = arr.length..0:
            swap(arr[0], arr[i])
            sink(arr, index = 0)

Because we sink the swapped elements of the heap logarithmically and traverse through the array as we do it, we can expect heapsort to have $\Theta(n \log{n})$ time-complexity. It is an in-place algorithm like quicksort, but also not stable (like quicksort). Usually, it performs slightly worse than quicksort, but it is has the many benefits of being a linearithmic sorting algorithm, which means that a good implementation executes decently for large volumes of data.


## Getting started

### Installing locally

To install the library locally, you can either download it straight from the repository page or proceed to cloning it with `git`.

    $ git clone https://github.com/leodg021/sorting.git

### Building

In order to build the programs, please make use of the `Makefile` to generate all object files and the main executable.

The command you'll want to use is: `make`. (The `Makefile` assumes you are using the `clang` compiler, so feel free to edit it if you prefer any other compiler such as `gcc`.) 

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

\[2\] [T. H. Cormen, C. E. Leiserson, R. L. Rivest, and C. Stein, Introduction to algorithms. Cambridge, MA: The Mit Press, 2022.](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)

\[3\] [R. Sedgewick and K. Wayne, Algorithms. Upper Saddle River, NJ: Addison-Wesley, 2011.](https://algs4.cs.princeton.edu/home/)
