Min and Max 5-heap - Lab 07
Jan Polzer

Run in command line using:

make 
./Lab07 min
Or 
./Lab07 max


Lab Info

75 Points
Due date:
-11:59pm, Monday 03/26/2018 for Monday lab.
-11:59pm, Tuesday 03/27/2018 for Tuesday lab.
-11:59pm, Wednesday 03/28/2018 for Thursday lab.
Purpose:
The purpose of this lab is to implement a Min-5 heap class and Max-5 heap class in C++.

General Requirements:
In this assignment you will work on an array based implementation of Min 5-Heap and Max-5 heap. You are to read in the numbers from a data file of integers and insert each number into a Min 5-heap (and Max-5 heap).
In Min 5-Heap (and Max-5 heap):
1-	The root of T is at A[0].
2-	The parent of A[i] is at A[floor((i-1)/5)], if it exists.
3-	The jth child of A[i] is at A[5i+j], 1<= j <=5, if it exists.
Use the bottom-up method for building the heap. (If a different approach is used, the results will be different. For the bottom-up approach, first put all of the elements in the given order into an array, and then try to heapify starting from the last parent, and continue to heapify towards the root). The file of numbers you read from will be data.txt. You may hard code the file name in your program if you wish.
In this lab, you should build the heap using the samples which are in the data.txt. After that, your program should have a simple menu like this:
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
The array should be of size 500. Heaps can have duplicate numbers. The max element in Min heap (Min element in Max heap) is one of the leaves, and the index of the first leaf can be found using A[floor((last used index in array-1)/5) + 1].
Min 5-Heap
The Min 5-Heap methods should be implemented as follows:
buildheap() – should build the Min heap using bottom up approach.
insert(x) - should insert x into the Min 5-Heap.
deletemin() - should delete the smallest value from the Min 5-Heap.
findmin() - should print a minimum value from the Min 5-Heap.
findmax() - should print a maximum value from the Min 5-Heap.
deletemax() - should delete the maximum value from the Min 5-Heap.
levelorder() - should print out all the elements of the Min 5-Heap using level order traversal.
Max 5-Heap
The Max 5-Heap methods should be implemented as follows:
buildheap() – should build the Max heap using bottom up approach
insert(x) - should insert x into the Max 5-Heap.
deletemin() - should delete the smallest value from the Max 5-Heap.
findmin() - should print a minimum value from the Max 5-Heap.
findmax() - should print a maximum value from the Max 5-Heap.
deletemax() - should delete the maximum value from the Max 5-Heap.
levelorder() - should print out all the elements of the Max 5-Heap using level order traversal.
Expected Results:
data.txt elements: 100 205 150 44 95 117 402 317 82 66 11 17 1 70 87 99

Expected output for Min Heap:
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>6
1
11 17 44 95 117
402 317 82 66 205 - 100 150 70 87 99
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>3
Min value: 1

……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>4
Max value is: 402
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>2
11
66 17 44 95 117
402 317 82 99 205 – 100 150 70 87
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>5
11
66 17 44 95 117
87 317 82 99 205 – 100 150 70
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>1
Enter a value to be inserted:
>9
9
66 11 44 95 117
87 317 82 99 205 – 100 150 70 17
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>7
Byebye!
Expected output for Max Heap:
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>6
402
317 150 44 95 117
205 100 82 66 11 – 17 1 70 87 99
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>3
Min value is: 1
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>4
Max value is: 402
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>5
317
205 150 44 95 117
99 100 82 66 11 – 17 1 70 87
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>2
317
205 150 44 95 117
99 100 82 66 11 – 17 87 70
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>1
Enter a value to be inserted:
>500
500
205 317 44 95 117
99 100 82 66 11 – 17 87 70 150
……………………………………………………………………………………………………………………………….
Please choose one of the following commands:
1-	insert
2-	deleteMin
3-	findMin
4-	findMax
5-	deleteMax
6-	levelOrder
7-	exit
>7
Byebye!


Submission:
Follow the conventions below to facilitate grading:

Source Code
Place all your source files(*.cpp, *.hpp) and input files in a single folder with no subfolders.
Name your folder using the convention Lastname_LabX(e.g. Smith_Lab07)
Include a functioning Makefile inside the folder (The makefile should also include clean command)
Verify that your code runs on Linux
Compressed File
Compress using .zip, .rar, or .tar.gz.
Name your file using the convention Lastname_LabX(e.g. Smith_Lab07.zip)
Email
Name subject of your email Lastname_LabX(e.g. Smith_Lab07.zip)
Send your code to yvanirudh@ku.edu if you are in Tuesday 11:00 AM or Tuesday 2:30 PM lab.
Send you code to l290w868@ku.edu if you are in Monday 9:00 AM or Thursday 11:00 AM lab.
Anytime you have a question about the lab, put the word question in the subject of the email.
Remark:
Your program must be fully documented. A program that does not compile will receive at most 30% points and a program that compiles but generates unintelligent output will receive no more than 50% points.