#ifndef ALGORITHMS_LEARNING_LIST_H
#define ALGORITHMS_LEARNING_LIST_H

#include <iostream>
#include <fstream>
#include<chrono>
#include "ListElement.cpp"

using namespace std;

//todo deleting value
//todo pointer to the back

class List {
    ListElement *head;
    ListElement *tail;
    int size;
public:
    List();

    ~List();

    void addValueToTheEnd(int value);

    void addValueToTheStart(int value);

    void addValueOnPosition(int value, int index);

    void deleteFirst();

    void deleteLast();

    void deleteValueOnThePosition(int index);

    void display();

    void loadFromFile(string fileName);

    bool isValueInList(int val);

    void deleteValue(int val);

    void generateList(int size);

    void test();
};

#endif //ALGORITHMS_LEARNING_LIST_H
