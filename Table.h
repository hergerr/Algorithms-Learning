#ifndef ALGORITHMS_LEARNING_TABLE_H
#define ALGORITHMS_LEARNING_TABLE_H

#include<iostream>
#include<fstream>
#include<chrono>


using namespace std;

class Table {
    int *numbers;
    int size; //ilość elementów w tablicy

public:
    Table();

    void loadFromFile(string fileName);

    int isValueInTable(int val);

    void addValueToTheStart(int val);

    void addValueToTheEnd(int val);

    void addValue(int index, int value);

    void deleteFromTable(int index);

    void deleteFirst();

    void deleteLast();

    void deleteValue(int value);

    void display();

    void generateTable(int size);

    void test();
};

#endif //ALGORITHMS_LEARNING_TABLE_H
