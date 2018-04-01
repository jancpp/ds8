/*
 Author: Jan Polzer
 File:   MaxMinHeap.h
 Date:   3/12/2018
 */

#include "MaxMinHeap.h"
#include <iostream>
#include <fstream>
#include <climits>

MaxMinHeap::MaxMinHeap() {
    m_size = 0;
    for (size_t i=0; i<sizeof(m_array); i++) {
        m_array[i] = -1;
    }
}

void MaxMinHeap::buildheap() {
    // Read data from a file into array
    std::ifstream inputFile;
    int number = -1;
    m_size = 0;
    inputFile.open("data.txt");
    if (!inputFile) {
        inputFile.close();
        std::cout << "Error reading the input file.\n";
    } else {
        std::cout << "Data.txt elements:";
        while(inputFile >> number) {
            insert(number);
        }
        inputFile.close();
    }
}

void MaxMinHeap::bubbleUp(int index) {
    int parent = parentOf(index);
    if (isMax(index)) {
        if ((m_array[parent] != -1) && (m_array[parent] > m_array[index])) {
            swap(index, parent);
            bubbleUpMin(parent);
        }
        if (parentOf(parent) != -1) {
            bubbleUpMax(index);
        }
    } else if (isMin(index)) {
        if ((m_array[parent] != -1) && (m_array[parent] < m_array[index])) {
            swap(index, parent);
            bubbleUpMax(parent);
        }
        if (m_array[parentOf(parent)] != -1) {
            bubbleUpMin(index);
        }
    } else {
        std::cout << "\nSomething went wrong during bubble up.";
    }
}

int MaxMinHeap::minUnder(int index) {
    int min = index;
    if (m_array[childOf(index, 1)] != -1) {
        for (int childPos = 1; childPos<=M_K; childPos++) {
            int child = childOf(index, childPos);
            if ((m_array[child] != -1) && (m_array[child] < m_array[min])) {
                min = child;
            }
            for (int grandChildPos = 1; grandChildPos<=M_K; grandChildPos++) {
                int grandChild = childOf(child, grandChildPos);
                if ((m_array[grandChild] != -1) && (m_array[grandChild] < m_array[min])) {
                    min = grandChild;
                }
            }
        }
    }
    return min;
}

int MaxMinHeap::maxUnder(int index) {
    int max = index;
    if (m_array[childOf(index, 1)] != -1) {
        for (int childPos = 1; childPos<=M_K; childPos++) {
            int child = childOf(index, childPos);
            if ((m_array[child] != -1) && (m_array[child] > m_array[max])) {
                max = child;
            }
            for (int grandChildPos = 1; grandChildPos<=M_K; grandChildPos++) {
                int grandChild = childOf(child, grandChildPos);
                if ((m_array[grandChild] != -1) && (m_array[grandChild] > m_array[max])) {
                    max = grandChild;
                }
            }
        }
    }
    return max;
}

int MaxMinHeap::childOf(int ofIndex, int atPosition) {
    // The jth child of A[i] is at A[M_Ki+j], 1<= j <=M_K, if it exists.
    return (M_K * ofIndex + atPosition - 1);
}

int MaxMinHeap::parentOf(int index) {
    // The parent of A[i] is at A[floor((i-1)/M_K)], if it exists.
    return (floor((index) / M_K));
    
}

void MaxMinHeap::swap(int index1, int index2) {
    int temp = m_array[index1];
    m_array[index1] = m_array[index2];
    m_array[index2] = temp;
}

bool MaxMinHeap::isLeaf(int index) {
    // The jth child of A[i] is at A[M_Ki+j], 1<= j <=M_K, if it exists.
    bool leaf = false;
    int firstchild = m_array[M_K*index+1];
    if (firstchild == -1) {
        leaf = true;
    }
    return leaf;
}

bool MaxMinHeap::isMin(int index) {
    // Min node: floor(lg(i)) = even
    bool min = false;
    if ((int)floor(log2(index)) % 2 == 1) {
        min = true;
    }
    return min;
}

bool MaxMinHeap::isMax(int index) {
    // Min node: floor(lg(i)) = odd
    bool max = false;
    if ((int)floor(log2(index)) % 2 == 0) {
        max = true;
    }
    return max;
}

void MaxMinHeap::insert(int key) {
    m_size++;
    m_array[m_size] = key;
    bubbleUp(m_size);
}

void MaxMinHeap::bubbleUpMax(int index) {
    int grandParent = parentOf(parentOf(index));
    if (grandParent > 0) {
        if (m_array[grandParent] < m_array[index]) {
            swap(index, grandParent);
        }
        bubbleUpMax(grandParent);
    }
}

void MaxMinHeap::bubbleUpMin(int index) {
    int grandParent = parentOf(parentOf(index));
    if (grandParent > 0) {
        if (m_array[grandParent] > m_array[index]) {
            
            swap(index, grandParent);
        }
        bubbleUpMin(grandParent);
    }
}

void MaxMinHeap::trickleDown(int index) {
    if (isMax(index)) {
        trickleDownMax(index);
    } else if (isMin(index)) {
        trickleDownMin(index);
    } else {
        std::cout << "\nError in heapify.\n";
    }
}

void MaxMinHeap::trickleDownMin(int index) {
    if (m_array[childOf(index, 1)] != -1) {
        int min = minUnder(index);
        int parent = parentOf(min);
        int grandParent = parentOf(parentOf(min));
        if (index == parent) {
            swap(index, min);
            trickleDown(min);
        } else if (index == grandParent) {
            if (m_array[min] < m_array[index]) {
                swap(index, min);
                if (m_array[parent] < m_array[min]) {
                    swap(parent, min);
                }
                trickleDown(min);
            }
        }
    }
}

void MaxMinHeap::trickleDownMax(int index) {
    if (m_array[childOf(index, 1)] != -1) {
        int max = maxUnder(index);
        int parent = parentOf(max);
        int grandParent = parentOf(parentOf(max));
        if (index == parent) {
            swap(index, max);
            trickleDown(max);
        } else if (index == grandParent) {
            if (m_array[max] > m_array[index]) {
                swap(index, max);
                if (m_array[parent] > m_array[max]) {
                    swap(parent, max);
                }
                trickleDown(max);
            }
        }
    }
}

int MaxMinHeap::minGrandChild(int index) {
    int min = index;
    for (int childPos = M_K; 0<childPos; childPos--) {
        int child = childOf(index, childPos);
        for (int grandChildPos = M_K; 0<grandChildPos; grandChildPos--) {
            int grandChild = childOf(child, grandChildPos);
            if ((grandChild > 0) && (m_array[grandChild] != -1) && (m_array[grandChild] < m_array[min])) {
                min = grandChild;
            }
        }
    }
    return min;
}

int MaxMinHeap::maxGrandChild(int grandParent)  {
    int max = grandParent;
    for (int childPos = 0; childPos<M_K; childPos++) {
        int child = childOf(grandParent, childPos);
        if (m_array[child] == -1) {
            return max;
        }
        for (int grandChildPos = 0; childPos<M_K; grandChildPos++) {
            int grandChild = childOf(child, grandChildPos);
            if (m_array[grandChild] == -1) {
                return max;
            }
            if ((grandChild > 0) && (m_array[grandChild] != -1) && (m_array[grandChild] > m_array[max])) {
                max = grandChild;
            }
        }
    }
    return max;
}

void MaxMinHeap::deletemin() {
    if (m_size >  0) {
        m_array[1] = m_array[m_size];
        m_array[m_size] = -1;
        m_size--;
        trickleDown(1);
    }
}

void MaxMinHeap::deletemax() {
    int max = findminindex();
    if (m_size > 0) {
        m_array[max] = m_array[m_size];
        m_array[m_size] = -1;
        m_size--;
        trickleDown(max);
    }
}


int MaxMinHeap::findminindex() {
    int min = -1;
    if (m_size == 1) {
        min = 1;
    } else if ((m_size > 2) && (m_array[3] < m_array[2])){
        min = 3;
    } else {
        min = 2;
    }
    return min;
}

int MaxMinHeap::findmax() {
//    int maxVal = -1;
//    if (m_size > 0) {
//        maxVal = m_array[findmaxindex()];
//    } else {
//        std::cout << "\nHeap is empty.\n";
//    }
//    return maxVal;
    
    
    int maxVal = -1;
    if (m_size > 0) {
        maxVal = m_array[1];
    }
    return maxVal;
}

int MaxMinHeap::findmin() {
//    int minVal = -1;
//    if (m_size > 0) {
//        minVal = m_array[1];
//    }
//    return minVal;
    
    
        int minVal = -1;
        if (m_size > 0) {
            minVal = m_array[findminindex()];
        } else {
            std::cout << "\nHeap is empty.\n";
        }
        return minVal;
}

void MaxMinHeap::levelorder() {
    int levels = 0;
    int newLevel = 1;
    
    std::cout << "\n";
    for (int i=1; i<=m_size; i++) {
        if(m_array[i] != -1) {
            std::cout << m_array[i] << " ";
            if ((newLevel == i) && ((i%M_K == 1) || (i == M_K))) {
                std::cout << "\n";
                levels++;
                newLevel += pow(M_K, levels);
            } else if (((i+1)%M_K == 0) && (m_array[i+1] != -1)) {
                std::cout << "- ";
            }
        }
    }
}
