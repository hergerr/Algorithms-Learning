#include <iostream>
#include "ListElement.cpp"

using namespace std;

class List {
    ListElement *head;
    ListElement *tail;
public:
    List() {
        head = NULL;
        tail = NULL;
    }

    ~List() {
    }

    //dodawanie na koniec
    void addValueToTheEnd(int value) {
        ListElement *temp = new ListElement;
        temp->setNumber(value);
        temp->setNext(NULL);
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        } else {
            tail->setNext(temp);
            tail = temp;
        }
    }

    void deleteFromList(int index) {
    }

    void display() {
        ListElement *temp = new ListElement;
        temp = head;
        while (temp != NULL) {
            cout << temp->getNumber() << endl;
            temp = temp->getNext();
        }
    }

    void loadFromFile(string fileName) {

    }

    bool isValueInList(int val) {

    }


    void generateList(int size) {
    }


    void test() {
    }
};