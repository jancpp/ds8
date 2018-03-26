
Lab08: main.o MinMaxHeap.o MaxMinHeap.o
	g++ -g -std=c++11 -Wall main.o MinMaxHeap.o MaxMinHeap.o -o Lab08

main.o:  MinMaxHeap.h MaxMinHeap.h main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MinHeap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -g -std=c++11 -Wall -c MinMaxHeap.cpp

MaxHeap.o: MaxMinHeap.h MaxMinHeap.cpp
	g++ -g -std=c++11 -Wall -c MaxMinHeap.cpp

clean:
	rm *.o Lab08
