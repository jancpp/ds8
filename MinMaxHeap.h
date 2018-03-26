/*
Author: Jan Polzer
File:   MinMaxHeap.h
Date:   3/12/2018
*/

#ifndef MINMAX_HEAP_H
#define MINMAX_HEAP_H

#include <iostream>
#include <queue>
#include <math.h>

class MinMaxHeap{ // //}: public Heap {

public:
        MinMaxHeap();

        // @pre:    File with numbers
        // @Post:   MinMax heap
        // @Return: None
        void buildheap();

        // @pre:    MinMax heap
        // @Post:   Inserted a new element
        // @Return: None
        void insert(int key);

        // @pre:    Min heap
        // @post:   deleted min key
        // @return: None
        void deletemin();

        // @pre:    MinMax heap
        // @post:   deleted max key
        // @return: None
        void deletemax();

        // @pre:    MinMa heap
        // @post:   Found the smallest element in the MinMax heap
        // @return: A value of the smallest element.
        int findmin();

        // @pre:    MinMax heap
        // @post:   Found the largest element in the min heap
        // @return: A value the largest element in min heap.
        int findmax();

        // @pre:    min heap
        // @post:   Printed out all the elements of the MinMax heap by level using levelorder traversal.
        // @return: None
        void levelorder();

        // @pre:    MinMax heap
        // @post:   None
        // @return: True if element is a leaf, false otherwise
        bool isLeaf(int index);

        // @pre:    MinMax heap
        // @post:   None
        // @return: True if element is a min node, false otherwise
        bool isMin(int index);

        // @pre:    MinMax heap
        // @post:   None
        // @return: True if element is a max node, false otherwise
        bool isMax(int index);

        // @pre:    Two indexes from heap
        // @post:   Swapped valued based on indexes
        // @return: None
        void swap(int index1, int index2);

        // @pre:    heap
        // @post:   Element is moved to position where belongs preserving a heap structure
        // @return: None
        void heapify(int index);

        // @pre:    An index of element
        // @post:   None
        // @return: An index of its child
        int childOf(int index, int atPosition);

        // @pre:    An index of parent in heap
        // @post:   None
        // @return: An index of the parents samllest child
        int minChild(int parent);

        // @pre:    An index of a child in a heap
        // @post:   None
        // @return: An index of parent of the child
        int parentOf(int index);

private:
        int m_array[500];
        int m_size;
        static const int M_K = 2; // for K-ary heap (binary-heap)

        // @pre:    MinMax heap
        // @post:   Found the largest index of element in the MinMax heap
        // @return: The index of the largest element
        int findmaxindex();

};

#endif
