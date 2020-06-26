# Quicksort-methods

Implementation of 4 different quicksort algorithms, 
***Default quicksort/Iterative quicksort/Pivot selection quicksort/Optimized quicksort***

-Graph

![퀵소트](https://user-images.githubusercontent.com/61370901/85908328-98943b80-b84f-11ea-91e7-232384d691e2.jpg)


-Default quicksort is based on the implementation from the textbook

-Iterative quicksort has 2 things modified.
  1.	Unlike the default quicksort, which calls recursive function at each partition, I stored the first and last index of each partition to a newly created array called store_point. I also created a variable that access to the elements of store_point. If this variable points outside the array, while loop ends. 
  2.	In order to remove the overhead caused by the function call, I implemented partitioning action inside the while loop. 

-Pivot selection quicksort is implemented with choosing median value index between the first, middle, and the last index. 

-Optimized quicksort has 3 optimization methods.
  1.	I used while loop from the iterative version to reduce the function call overhead. 
  2.	I used pivot selection method from the pivot selection version to get proper pivot.
  3.	Quicksort is a divide-and-conquer algorithm. So dividing the problem into smaller size is important. However, the standard of “smaller size” is ambiguous. I thought quicksort that divides until the very last was inefficient. So I used insertion sort when the partition size is smaller than 7. The number 7 came up with my experiment. I tried 5,6,7,8,9,10 as an option and I found out that 7 was the fastest. 
