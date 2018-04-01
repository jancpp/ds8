/*
 Author: Jan Polzer
 File:   main.cpp
 Date:   3/12/2018
 */

#include "MinMaxHeap.h"
#include "MaxMinHeap.h"
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    // Check for correct terminal input
    std::string heaptype = argv[1];
    if ((argc != 2) && ((heaptype != "minmax") || (heaptype != "maxmin")) ) {
        std::cout << "To run program type:\n ./Lab07 maxmin for minmax heap\nor ./Lab07 maxmin for maxmin heap\n\n";
        return 0;
    }

    MinMaxHeap *minmaxheap = nullptr;
    MaxMinHeap *maxminheap = nullptr;
    if (heaptype == "minmax") {
        minmaxheap = new MinMaxHeap();
        minmaxheap->buildheap();
    } else if (heaptype == "maxmin") {
        maxminheap = new MaxMinHeap();
        maxminheap->buildheap();
    } else {
        std::cout << "Wrong heap type was entered. (min/max)\n";
        return 0;
    }

    // User interacation
    int choice = -1;
    int inputkey = -1;

    while (choice != 7) {
        std::cout << "\n............................................\n\n";
        std::cout << "Please choose one of the following commands:\n\n";
        std::cout << "1- insert\n\n";
        std::cout << "2- delete min\n\n";
        std::cout << "3- find min\n\n";
        std::cout << "4- find max\n\n";
        std::cout << "5- delete max\n\n";
        std::cout << "6- level order\n\n";
        std::cout << "7- exit\n\n";

        std::cout << "> ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a number to be inserted: ";
                std::cin >> inputkey;
                if (heaptype == "minmax") {
                    minmaxheap->insert(inputkey);
                    minmaxheap->levelorder();
                } else if (heaptype == "maxmin") {
                    maxminheap->insert(inputkey);
                    maxminheap->levelorder();
                }
                break;
            case 2:
                if (heaptype == "minmax") {
                    minmaxheap->deletemin();
                    minmaxheap->levelorder();
                } else if (heaptype == "maxmin") {
                    maxminheap->deletemin();
                    maxminheap->levelorder();
                }
                break;
            case 3:
            {
                if (heaptype == "minmax") {
                    int min = minmaxheap->findmin();
                    if (min == -1) {
                        std::cout << "\nHeap is empty.\n";
                    } else {
                        std::cout << "\nMin value: " << min;
                    }
                } else if (heaptype == "maxmin") {
                    int min = maxminheap->findmin();
                    if (min == -1) {
                        std::cout << "\nHeap is empty.\n";
                    } else {
                        std::cout << "\nMin value: " << min;
                    }
                }
            }
                break;
            case 4:
                {
                    if (heaptype == "minmax") {
                        int max = minmaxheap->findmax();
                        if (max == -1) {
                            std::cout << "\nHeap is empty.\n";
                        } else {
                            std::cout << "\nMax value: " << max;
                        }
                    } else if (heaptype == "maxmin") {
                        int max = maxminheap->findmax();
                        if (max == -1) {
                            std::cout << "\nHeap is empty.\n";
                        } else {
                            std::cout << "\nMax value: " << max;
                        }
                    }
                }
                break;
            case 5:
                if (heaptype == "minmax") {
                    minmaxheap->deletemax();
                    minmaxheap->levelorder();
                } else if (heaptype == "maxmin") {
                    maxminheap->deletemax();
                    maxminheap->levelorder();
                }
                break;
            case 6:
                if (heaptype == "minmax") {
                    minmaxheap->levelorder();
                } else if (heaptype == "maxmin") {
                    maxminheap->levelorder();
                }
                break;
            case 7:
                std::cout << "Bye bye!\n";
                return (0);
            default:
                std::cout << "\nError: Wrong input.\n\n";
        }
    }
    return 0;
}
