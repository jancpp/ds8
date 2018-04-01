MinMax and MaxMin Heaps - Lab 08
Jan Polzer

Run in command line using:

make 
./Lab08 minmax
Or 
./Lab08 maxmin











Lab Info
75 Points

Due date:
-11:59pm, Monday 4/2/2018 for Monday lab.

Purpose:
The purpose of this lab is to implement a MinMax heap class and MaxMin heap class in C++.

General Requirements:
In this assignment you will work on an array based implementation of MinMax heap and MaxMin heap. You are to read in the numbers from a data file of integers and insert each number into a MinMax heap (and MaxMin heap).
In MinMax heap(and MaxMin heap):
1-    The root of T is at A[1].
2-    MinMax heap:
Min node: floor(lg(i)) = even
Max node: floor(lg(i)) = odd
3-    The grandparent of A[i] is at A[floor(i/4)], if it exists.
Use the bottom-up method for building the Minmax heap. (If a different approach is used, the results will be different. For the bottom-up approach, first put all of the elements in the given order into a complete binary tree, and then try to heapify starting from the last parent, and continue to heapify towards the root). And build a Maxmin heap by inserting the objects, in the given order, into an initially empty heap. The file of numbers you read from will be data.txt. You may hard code the file name in your program if you wish.
In this lab, you should build the heap using the samples which are in the data.txt. After that, your program should have a simple menu like this:
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
The array should be of size 500. Heaps can have duplicate numbers. The index of the last parent can be found using A[floor(last used index in the array/2)].
MinMax heap
The MinMax heap methods should be implemented as follows:
buildheap() – should build the MinMax heap using bottom up approach.
insert(x) - should insert x into the MinMax heap.
deletemin() - should delete the smallest value from the MinMax heap.
findmin() - should print a minimum value from the MinMax heap.
findmax() - should print a maximum value from the MinMax heap.
deletemax() - should delete the maximum value from the MinMax heap.
levelorder() - should print out all the elements of the MinMax heap using level order traversal.
MaxMin heap
The MaxMin heap methods should be implemented as follows:
buildheap() – should build the MaxMin heap by inserting elements into an initially empty heap.
insert(x) - should insert x into the MaxMin heap.
deletemin() - should delete the smallest value from the MaxMin heap.
findmin() - should print a minimum value from the MaxMin heap.
findmax() - should print a maximum value from the MaxMin heap.
deletemax() - should delete the maximum value from the MaxMin heap.
levelorder() - should print out all the elements of the MaxMin heap using level order traversal.
Expected Results:
data.txt elements: 8 50 74 59 31 73 45 79 24 8 10
To compile the lab, use:
./lab08 minmax
or
./lab08 maxmin
Expected output for MaxMin Heap:
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>6
79
8 45
74 31 – 73 50
59 24 – 8 10
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>3
Min value: 8

……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>4
Max value is: 79
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>2
79
8 45
74 31 – 73 50
59 24 – 10
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>5
74
8 45
59 31 – 73 50
10 24
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>1
Enter a value to be inserted:
>100
100
8 45
59 74 – 73 50
10 24 – 31
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>7
Byebye!
Expected output for MinMax Heap:
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>6
8
79 74
24 8 – 73 45
50 59 – 31 10
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>3
Min value is: 8
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>4
Max value is: 79
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>5
8
59 74
10 8 – 73 45
50 24 – 31
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>2
8
59 74
10 31 – 73 45
50 24
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>1
Enter a value to be inserted:
>100
8
100 74
10 31 – 73 45
50 24 – 59
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-    insert
2-    deleteMin
3-    findMin
4-    findMax
5-    deleteMax
6-    levelOrder
7-    exit
>7
Byebye!
