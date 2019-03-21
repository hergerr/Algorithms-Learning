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
    List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~List() {
    }

    //dodawanie na koniec
    void addValueToTheEnd(int value) {
        ListElement *temp = new ListElement();
        temp->setNumber(value);
        temp->setNext(NULL);        //ostatni element wskazuje na null

        if (tail == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->setNext(temp);    //ustawienie wskaznika na nowy element
            tail = temp;            //przestawienie taila
        }
        ++size;
    }

    void addValueToTheStart(int value) {
        ListElement *temp = new ListElement();
        temp->setNumber(value);
        temp->setNext(head);        //ustawienie wskaznika temp na kolejny element
        head = temp;                //ustawienie head na nowy poczatek
        ++size;
    }

    void addValueOnPosition(int value, int index) {
        if (index >= size) {
            addValueToTheEnd(value);
            return;
        }

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
        ++size;
    }

    void deleteFirst() {
        ListElement *temp = new ListElement;
        temp = head;
        delete temp;
        head = head->getNext();
        --size;
    }


    void deleteLast() {
        ListElement *current = new ListElement;
        ListElement *previous = new ListElement;
        current = head;
        while (current->getNext() != NULL) {
            previous = current;
            current = current->getNext();
        }
        tail = previous;            // przypisanie obecnego taila do przedostatniego elementu
        previous->setNext(NULL);    // przedostatni element wskazuje na null -> staje sie ostatnim elementem
        delete current;
        --size;
    }

    void deleteValueOnThePosition(int index) {
        if (index >= size) {
            deleteLast();
            return;
        }

        ListElement *current = new ListElement;
        ListElement *previous = new ListElement;
        current = head;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->getNext();

        }
        previous->setNext(current->getNext()); // pomieniecie elementu o danym indeksie
        --size;
    }

    void display() {
        ListElement *temp = new ListElement;
        temp = head;
        while (temp != NULL) {
            cout << temp->getNumber() << " ";
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
        ListElement *current = new ListElement;
        current = head;
        while (current->getNext() != NULL) {
            if ((*current).getNumber() == val) return true;
            current = current->getNext();
        }
        return false;
    }


    void generateList(int size) {
        for (int i = 0; i < size; ++i) {
            addValueToTheEnd((rand() % 10) + 1);
        }
    }


    void test() {
        auto start = chrono::high_resolution_clock::now();
        display();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "Wypisywanie wartosci listy: " << diff.count() << endl << endl;

        cout << "Wstawianie nowej wartości na początek: ";
        start = chrono::high_resolution_clock::now();
        addValueToTheStart(0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;


        cout << "Wstawianie nowej wartości na koniec: ";
        start = chrono::high_resolution_clock::now();
        addValueToTheEnd(0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;

        cout << "Wstawianie nowej wartości w losowe miejsce listy: ";
        start = chrono::high_resolution_clock::now();
        addValueOnPosition(0, rand() % 100);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl << endl;

        cout << "Usuwanie wartości z początku listy: ";
        start = chrono::high_resolution_clock::now();
        deleteFirst();
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;


        cout << "Usuwanie wartości z końca listy: ";
        start = chrono::high_resolution_clock::now();
        deleteLast();
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;

        cout << "Usuwanie wartości z losowego miejsca w listy: ";
        start = chrono::high_resolution_clock::now();
        deleteValueOnThePosition(rand() % 1000);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl << endl;

        cout << "Wyszukiwanie losowej wartosci z listy:" << endl;
        start = chrono::high_resolution_clock::now();
        int rand_val = rand() % 1000000;
        bool is_in = isValueInList(rand_val);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        if (is_in) cout << "Wartosc" << rand_val << " jest w listy " << endl;
        else cout << "Wartosci: " << rand_val << " nie ma w listy " << endl;
        cout << "Czas: " << diff.count() << endl << endl;
    }
};