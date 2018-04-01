/*
Author: Jan Polzer
File:   MinMaxHeap.h
Date:   3/12/2018
*/

#include "MinMaxHeap.h"
#include <iostream>
#include <fstream>
#include <climits>

MinMaxHeap::MinMaxHeap() {
        m_size = 0;
        for (size_t i=0; i<sizeof(m_array); i++) {
                m_array[i] = -1;
        }
}

void MinMaxHeap::load() {

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

void MinMaxHeap::bubbleUp(int index) {
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
        std::cout << "\nSomething went wrong during heapify.";
    }
}

int MinMaxHeap::minChild(int parent) {
    int min = parent;
    for (int childPos = M_K; 0<childPos; childPos--) {
        int child = childOf(parent, childPos);
        if ((m_array[child] != -1) && (m_array[child] < m_array[min])) {
            min = child;
        }
    }
    return min;
}

int MinMaxHeap::maxChild(int parent) {
    int max = parent;
    for (int childPos = M_K; 0<childPos; childPos--) {
        int child = childOf(parent, childPos);
        if ((m_array[child] != -1) && (m_array[child] > m_array[max])) {
            max = child;
        }
    }
    return max;
}

int MinMaxHeap::childOf(int ofIndex, int atPosition) {
        // The jth child of A[i] is at A[M_Ki+j], 1<= j <=M_K, if it exists.
        return (M_K * ofIndex + atPosition - 1);
}

int MinMaxHeap::parentOf(int index) {
        // The parent of A[i] is at A[floor((i-1)/M_K)], if it exists.
        return (floor((index) / M_K));

}

void MinMaxHeap::swap(int index1, int index2) {
        int temp = m_array[index1];
        m_array[index1] = m_array[index2];
        m_array[index2] = temp;
}

bool MinMaxHeap::isLeaf(int index) {
        // The jth child of A[i] is at A[M_Ki+j], 1<= j <=M_K, if it exists.
        bool leaf = false;
        int firstchild = m_array[M_K*index+1];
        if (firstchild == -1) {
                leaf = true;
        }
        return leaf;
}

bool MinMaxHeap::isMin(int index) {
        // Min node: floor(lg(i)) = even
        bool min = false;
        if ((int)floor(log2(index)) % 2 == 0) {
                min = true;
        }
        return min;
}

bool MinMaxHeap::isMax(int index) {
        // Min node: floor(lg(i)) = odd
        bool max = false;
        if ((int)floor(log2(index)) % 2 == 1) {
                max = true;
        }
        return max;
}

void MinMaxHeap::insert(int key) {
    m_size++;
    m_array[m_size] = key;
    bubbleUp(m_size);
}

void MinMaxHeap::bubbleUpMax(int index) {
    int grandParent = parentOf(parentOf(index));
    if (grandParent > 0) {
            if (m_array[grandParent] < m_array[index]) {
                    swap(index, grandParent);
            }
        bubbleUpMax(grandParent);
    }
}

void MinMaxHeap::bubbleUpMin(int index) {
    int grandParent = parentOf(parentOf(index));
    if (grandParent > 0) {
        if (m_array[grandParent] > m_array[index]) {

            swap(index, grandParent);
        }
        bubbleUpMin(grandParent);
    }
}

void MinMaxHeap::trickleDown(int index) {
//    if ((m_array[index] != -1) && (m_array[index] > m_array[min])) {
    if (isMax(index)) {
        int max = maxGrandChild(index);
        if (max != index) {
            swap(index, max);
        }
        trickleDownMax(max);
        
    } else if (isMin(index)) {
        int min = minChild(index);
        if (min != index) {
            swap(index, min);
        }
        trickleDownMin(index);
    } else {
        std::cout << "\nError in trickle down.\n";
    }
        
    
}

void MinMaxHeap::trickleDownMin(int index) {
    int min = minGrandChild(index);
    if (min != index) {
        swap(index, min);
        trickleDownMin(min);
    }
}

void MinMaxHeap::trickleDownMax(int index) {
    int max = maxGrandChild(index);
    if (max != index) {
        swap(index, max);
        trickleDownMin(max);
//    } else {
//        trickleDownMax(index);
    }
}

int MinMaxHeap::minGrandChild(int index) {
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

int MinMaxHeap::maxGrandChild(int grandParent)  {
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

void MinMaxHeap::deletemin() {
    if (m_size >  0) {
            m_array[1] = m_array[m_size];
            m_array[m_size] = -1;
            m_size--;
            trickleDown(1);
    }
}

void MinMaxHeap::deletemax() {
        int maxIndex = findmaxindex();
        if (m_size > 0) {
                m_array[maxIndex] = m_array[m_size];
                m_array[m_size] = -1;
                m_size--;
                trickleDown(maxIndex);
        }
}


int MinMaxHeap::findmaxindex() {
    int max = -1;
    if (m_size == 1) {
        max = 1;
    } else if ((m_size > 2) && (m_array[3] > m_array[2])){
        max = 3;
    } else {
        max = 2;
    }
//        int i = -1;
//        if (m_size >  0) {
//                for (i=m_size-1; 0<i; i--) {
//                        if (isLeaf(i)) {
//                                if ((m_array[i] != -1) && (m_array[i] > m_array[max])) {
//                                        max = i;
//                                }
//                        } else {
//                                break;
//                        }
//                }
//        }
        return max;
}

int MinMaxHeap::findmax() {
        int maxVal = -1;
        if (m_size > 0) {
                maxVal = m_array[findmaxindex()];
        } else {
                std::cout << "\nHeap is empty.\n";
        }
        return maxVal;
}

int MinMaxHeap::findmin() {
        int minVal = -1;
        if (m_size > 0) {
                minVal = m_array[1];
        }
        return minVal;
}

void MinMaxHeap::levelorder() {
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
