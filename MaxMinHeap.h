/*
Author: Jan Polzer
File:   MaxMinHeap.h
Date:   3/12/2018
*/

#ifndef MAXMIN_HEAP
#define MAXMIN_HEAP

#include <iostream>
#include <queue>
#include <math.h>

class MaxMinHeap {

public:
        MaxMinHeap();

        // @pre:    File with numbers
        // @Post:   MaxMin  heap
        // @Return: None
        void buildheap();

        // @pre:     MaxMin heap
        // @Post:   Inserted a new element
        // @Return: None
        void insert(int key);

        // @pre:     MaxMin heap
        // @post:   Deleted min key
        // @return: None
        void deletemin();

        // @pre:     MaxMin heap
        // @post:   Deleted MaxMin key
        // @return: None
        void deletemax();

        // @pre:     MaxMin heap
        // @post:   Found the smallest element in the  MaxMin heap
        // @return: A value of the smallest element.
        int findmin();

        // @pre:     MaxMin heap
        // @post:   Found the largest element in the  MaxMin heap
        // @return: A value the largest element in MaxMin heap.
        int findmax();

        // @pre:     MaxMin heap
        // @post:   Printed out all the elements of the MaxMin heap by level using levelorder traversal.
        // @return: None
        void levelorder();

        // @pre:    MaxMin heap
        // @post:   None
        // @return: True if element is a min node, false otherwise
        bool isMin(int index);

        // @pre:    MaxMin heap
        // @post:   None
        // @return: True if element is a max node, false otherwise
        bool isMax(int index);

        // @pre:     MaxMin heap
        // @post:   None
        // @return: True if element is a leaf, false otherwise
        bool isLeaf(int index);

        // @pre:    Two indexes from heap
        // @post:   Swapped valued based on indexes
        // @return: None
        void swap(int index1, int index2);

        // @pre:     heap
        // @post:   Element is moved to position where belongs preserving a heap structure
        // @return: None
        void heapify(int index);

        // @pre:    An index of element
        // @post:   None
        // @return: An index of its child
        int childOf(int index, int atPosition);

        // @pre:    An index of parent in heap
        // @post:   None
        // @return: An index of the parents largest child
        int minChild(int parent);

        // @pre:    An index of a child in a heap
        // @post:   None
        // @return: An index of grand parent of the child
        int grandparentOf(int index);

        // @pre:    An index of a child in a heap
        // @post:   None
        // @return: An index of parent of the child
        int parentOf(int index);

private:
        int m_array[500];
        int m_size;
        static const int M_K = 2; // for K-ary heap (binary-heap)

        // @pre:     MaxMin heap
        // @post:   Found the largest index of element in the  MaxMin heap
        // @return: The index of the largest element
        int findminindex();
};

#endif
