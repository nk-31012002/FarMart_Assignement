Approaches that I considered:-

1. Linear Search (Brute Force) : It will read the entire file line by line and filter logs based on the target date.

Pros: Simple to implement and No preprocessing required.

Cons: Extremely inefficient for large files (1 TB).

Time complexity: O(n) : n == number of lines in the file.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------

2. Binary Search on Sorted File(Better) : Assume the log file is sorted by date. Use binary search to locate the start of the logs for the target date.

Pros: No preprocessing required if the file is already sorted. Efficient querying with O(log n) complexity.

Cons: Requires the file to be sorted by date. Binary search on a large file can be hard to implement due to line-based access.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------

3. External Sorting : Sort the log file by date using external sorting algorithms (e.g., merge sort, quick sort). After sorting, use binary search to locate the logs for the target date.

Pros: Enables efficient querying after sorting.

Cons: Sorting a 1 TB file is computationally expensive. Requires significant disk space for intermediate files.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------

4. Indexing with Preprocessing : It will preprocess the file to create an index that maps dates to their byte offsets in the file. Use the index to directly seek to the relevant part of the file during querying.

Pros: Fast querying after preprocessing. Efficient memory usage during querying.

Cons: Requires preprocessing to build the index. Index file size can be large, but much smaller than the original file.

Time Complexity: Preprocessing: O(n) (one-time cost).

```Best suited for this problem due to its efficiency and scalability.```


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
```The logs for the specified date will be saved in output/output_2024-12-01.txt```

```Thank You```

