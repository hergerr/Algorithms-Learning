#include <iostream>
#include <fstream>
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
        if (head == NULL) { //ustawiamy head na poczatek i on tam bedzie zawsze
            head = temp;
            tail = temp;
            temp = NULL;
        } else { // przestawiamy tail na koniec
            tail->setNext(temp);
            tail = temp; // ?
        }
    }

    void addValueToTheStart(int value) {
        ListElement *temp = new ListElement;
        temp->setNumber(value);
        temp->setNext(head);
        head = temp; // ?
    }

    void addValueOnPosition(int value, int index) {
        ListElement *previous = new ListElement;
        ListElement *current = new ListElement;
        ListElement *temp = new ListElement;
        current = head;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->getNext();
        }
        temp->setNumber(value);
        previous->setNext(temp);
        temp->setNext(current);
    }

    void deleteFirst() {
        ListElement *temp = new ListElement;
        temp = head;
        head = head->getNext();
        delete temp;
    }

    void deleteLast() {
        ListElement *current = new ListElement;
        ListElement *previous = new ListElement;
        current = head;
        while (current->getNext() != NULL) {
            previous = current;
            current = current->getNext();
        }
        tail = previous;
        previous->setNext(NULL);
        delete current;
    }

    void deleteValueOnThePosition(int index) {
        ListElement *current = new ListElement;
        ListElement *previous = new ListElement;
        current = head;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->getNext();
        }
        previous->setNext(current->getNext());
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
        int size;
        ifstream inFile;
        inFile.open(("../" + fileName));
        if (!inFile) {
            cout << "Nie można otworzyć pliku\n";
            exit(1);
        }

        inFile >> size;

        int i = 0;
        while (i++ < size) {
            int number;
            inFile >> number;
            addValueToTheEnd(number);
        }
    }

    bool isValueInList(int val) {

    }


    void generateList(int size) {
    }


    void test() {
    }
};