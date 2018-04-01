/*
Author: Jan Polzer
File:   MaxMinMinHeap.cpp
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
                        std::cout << " " << number;
                        m_array[m_size+1] = number;
                        m_size++;
                }
                inputFile.close();
                std::cout << "\n";
                for (int i=m_size; 0<i; i--) {
                        if (!isLeaf(i)) {
                                heapify(i);
                        }
                }
        }
}

void MaxMinHeap::heapify(int index) {
        int min = minGrandChild(index);
        if ((m_array[index] != -1) && (m_array[index] < m_array[min])) {
                swap(index, min);
                heapify(min);
        }
}

int MaxMinHeap::minGrandChild(int grandParent) {
        int min = grandParent;
        for (int childPos = M_K; 0<childPos; childPos--) {
                for (int grandChildPos = M_K; 0<grandChildPos; grandChildPos--) {
                        int grandChild = childOf(childOf(grandParent, grandChildPos), childPos);
                        if ((grandChildPos > 0) && (m_array[grandChildPos] != -1) && (m_array[grandChild] > m_array[min])) {
                                min = grandChild;
                        }
                }
        }
        return min;
}

int MaxMinHeap::childOf(int ofIndex, int atPosition) {
        // The jth child of A[i] is at A[2i+j], 1<= j <=2, if it exists.
        return (M_K * ofIndex + atPosition);
}

int MaxMinHeap::parentOf(int index) {
        // The parent of A[i] is at A[floor((i-1)/M_K)], if it exists.
        return (floor((index) / M_K));

}

int MaxMinHeap::grandparentOf(int index) {
        // The grandparent of A[i] is at A[floor(i/4)], if it exists.
        return (floor(index / 4));

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
        // Min node: floor(lg(i)) = odd
        bool min = false;
        if ((int)floor(log2(index)) % 2 == 1) {
                min = true;
        }
        return min;
}

bool MaxMinHeap::isMax(int index) {
        // Min node: floor(lg(i)) = even
        bool max = false;
        if ((int)floor(log2(index)) % 2 == 0) {
                max = true;
        }
        return max;
}

void MaxMinHeap::insert(int key) {
        m_size++;
        m_array[m_size] = key;
        int parent = parentOf(parentOf(m_size));
        heapify(parent);
        while (parent != 0) {
                parent = parentOf(parent);
                heapify(parent);
        }
}

void MaxMinHeap::deletemax() {
        if (m_size >  0) {
                m_array[1] = m_array[m_size];
                m_size--;
                heapify(0);
        }
}

void MaxMinHeap::deletemin() {
        int minIndex = findminindex();
        if (m_size > 0) {
                m_array[minIndex] = m_array[m_size-1];
                m_array[m_size-1] = -1;
                m_size--;
        }
}


int MaxMinHeap::findminindex() {
        int min = m_size-1;
        int i = -1;
        if (m_size >  0) {
                for (i=1+M_K; 1<=i; i--) {
                        if (isLeaf(i)) {
                                if ((m_array[i] != -1) && (m_array[i] < m_array[min])) {
                                        min = i;
                                }
                        } else {
                                break;
                        }
                }
        }
        return min;
}

int MaxMinHeap::findmin() {
        int minVal = -1;
        if (m_size > 0) {
                minVal = m_array[findminindex()];
        } else {
                std::cout << "\nHeap is empty.\n";
        }
        return minVal;
}

int MaxMinHeap::findmax() {
        int maxVal = -1;
        if (m_size > 0) {
                maxVal = m_array[1];
        }
        return maxVal;
}

void MaxMinHeap::levelorder() {
        int levels = 1;
        int newLevel = 0;

        std::cout << "\n";
        for (int i=0; i<m_size; i++) {
                if(m_array[i] != -1) {
                        std::cout << m_array[i] << " ";
                        if ((newLevel == i) && ((i%M_K == 0) || (i == M_K))) {
                                std::cout << "\n";
                                newLevel += pow(M_K, levels);
                                levels++;
                        } else if ((i%M_K == 0) && (m_array[i+1] != -1)) {
                                std::cout << "- ";
                        }
                }
        }
}
