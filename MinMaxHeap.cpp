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

void MinMaxHeap::heapify(int index) {
        int min = minChild(index);
        if ((m_array[index] != -1) && (m_array[index] > m_array[min])) {
                swap(index, min);
                heapify(min);
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

int MinMaxHeap::childOf(int ofIndex, int atPosition) {
        // The jth child of A[i] is at A[M_Ki+j], 1<= j <=M_K, if it exists.
        return (M_K * ofIndex + atPosition);
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
    int parent = parentOf(m_size);
    if (isMax(m_size)) {
        if ((m_array[parent] != -1) && (m_array[parent] > key)) {
            swap(m_size, parent);
            bubbleUpMin(parent);
        }
        if (parentOf(parent) != -1) {
            bubbleUpMax(m_size);
        }
    } else if (isMin(m_size)) {
        if ((m_array[parent] != -1) && (m_array[parent] < key)) {
            swap(m_size, parent);
            bubbleUpMax(parent);
        }
        if (parentOf(parent) != -1) {
            bubbleUpMin(m_size);
        }
    } else {
        std::cout << "\nSomething went wrong during insert in minmax heap";
    }
       levelorder();
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

void MinMaxHeap::deletemin() {
        if (m_size >  0) {
                m_array[1] = m_array[m_size];
                m_size--;
                heapify(0);
        }
}

void MinMaxHeap::deletemax() {
        int maxIndex = findmaxindex();
        if (m_size > 0) {
                m_array[maxIndex] = m_array[m_size-1];
                m_array[m_size-1] = -1;
                m_size--;
        }
}


int MinMaxHeap::findmaxindex() {
        int max = m_size-1;
        int i = -1;
        if (m_size >  0) {
                for (i=m_size-1; 0<i; i--) {
                        if (isLeaf(i)) {
                                if ((m_array[i] != -1) && (m_array[i] > m_array[max])) {
                                        max = i;
                                }
                        } else {
                                break;
                        }
                }
        }
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
