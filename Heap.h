#ifndef ALGORITHMS_LEARNING_HEAP_H
#define ALGORITHMS_LEARNING_HEAP_H


#include <iostream>
#include<iomanip>
#include<fstream>
#include<chrono>

using namespace std;

class Heap {
    int *array; // wskaznik na tablice w ktorej jest kopiec
    int max_size;
    int size;

public:
    Heap();

    void swap(int *x, int *y);

    void add(int value);

    void heapify(int index);

    void deleteKey(int value);

    void loadFromFile(string fileName);

    int isKeyInHeap(int k);

    void generateHeap(int size);

    void printBT(ostream &output, string sp, string sn, int v);

    void test();
};

#endif //ALGORITHMS_LEARNING_HEAP_H