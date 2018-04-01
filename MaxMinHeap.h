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
    // @Post:   MaxMin heap
    // @Return: None
    void buildheap();
    
    // @pre:    MaxMin heap
    // @Post:   Inserted a new element
    // @Return: None
    void insert(int key);
    
    // @pre:    MaxMin heap
    // @post:   deleted min key
    // @return: None
    void deletemin();
    
    // @pre:    MaxMin heap
    // @post:   deleted max key
    // @return: None
    void deletemax();
    
    // @pre:    MaxMin heap
    // @post:   Found the smallest element in the MaxMin heap
    // @return: A value of the smallest element.
    int findmin();
    
    // @pre:    MaxMin heap
    // @post:   Found the largest element in the min heap
    // @return: A value the largest element in min heap.
    int findmax();
    
    // @pre:    MaxMin heap
    // @post:   Printed out all the elements of the MaxMin heap by level using levelorder traversal.
    // @return: None
    void levelorder();
    
private:
    int m_array[500];
    int m_size;
    static const int M_K = 2; // for K-ary heap (binary-heap)
    
    // @pre:    MaxMin heap
    // @post:   Found the largest index of element in the MaxMin heap
    // @return: The index of the smallest element
    int findminindex();
    
    // @pre:    MaxMin heap
    // @post:   None
    // @return: True if element is a leaf, false otherwise
    bool isLeaf(int index);
    
    // @pre:    MaxMin heap
    // @post:   None
    // @return: True if element is a min node, false otherwise
    bool isMin(int index);
    
    // @pre:    MaxMin heap
    // @post:   None
    // @return: True if element is a max node, false otherwise
    bool isMax(int index);
    
    // @pre:    Two indexes from heap
    // @post:   Swapped valued based on indexes
    // @return: None
    void swap(int index1, int index2);
    
    // @pre:    MaxMin heap
    // @post:   Element is moved to position downward where belongs preserving a heap structure
    // @return: None
    void trickleDown(int index);
    
    // @pre:    Index is at min level
    // @post:   Element is moved downward while swapping with a grandchild (if grandchil is smaller) preserving a heap structure
    // @return: None
    void trickleDownMin(int index);
    
    // @pre:    Index is at max level
    // @post:   Element is moved downward while swapping with a grandchild (if grandchil is larger) preserving a heap structure
    // @return: None
    void trickleDownMax(int index);
    
    // @pre:    An index of element
    // @post:   None
    // @return: An index of its child
    int childOf(int index, int atPosition);
    
    // @pre:    An index of parent in heap
    // @post:   None
    // @return: An index of the smallest element in heap under the index
    int minUnder(int index);
    
    // @pre:    An index of parent in heap
    // @post:   None
    // @return: An index of the largest element in heap under the index
    int maxUnder(int index);
    
    // @pre:    An index of grand parent in heap
    // @post:   None
    // @return: An index of the largest from index and index's grand children
    int maxGrandChild(int index);
    
    // @pre:    An index of parent in heap
    // @post:   None
    // @return: An index of the parents largest child
    int minGrandChild(int parent);
    
    // @pre:    An index of a child in a heap
    // @post:   None
    // @return: An index of parent of the child
    int parentOf(int index);
    
    // @pre:    Grandparent exists
    // @post:   Keep swapping node with grandparent if grandparent is larger, terminate if not
    // @return: Node
    void bubbleUpMax(int index);
    
    // @pre:    Grandparent exists
    // @post:   Keep swapping node with grandparent if grandparent is smaller, terminate if not
    // @return: Node
    void bubbleUpMin(int index);
    
    // @pre:    Grandparent exists
    // @post:   Keep swapping node with grandparent until the key is in the right place
    // @return: Node
    void bubbleUp(int index);
    
    // @pre:    MaxMin heap
    // @post:   Element is moved to position where belongs preserving a heap structure
    // @return: None
    void heapify(int index);
};

#endif
