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

        if (size == 0) {
            head = temp;
            tail = temp;
            ++size;
            return;
        }

        tail->setNext(temp);
        temp->setNext(NULL);        //ostatni element wskazuje na null
        temp->setPrevious(tail);     //ustawienie poprzedniego na tail, ktory niedlugo przestawimy
        tail = temp;
        ++size;
    }

    void addValueToTheStart(int value) {
        ListElement *temp = new ListElement();
        temp->setNumber(value);

        if (size == 0) {
            head = temp;
            tail = temp;
            ++size;
            return;
        }

        head->setPrevious(temp);
        temp->setNext(head);        //ustawienie wskaznika temp na kolejny element
        temp->setPrevious(NULL);    //w takim razie poprzedni to NULL
        head = temp;                //ustawienie head na nowy poczatek
        ++size;
    }

    void addValueOnPosition(int value, int index) {
        if (index >= size) {
            addValueToTheEnd(value);
            return;
        }

        ListElement *current;
        ListElement *temp = new ListElement;
        temp->setNumber(value);
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->getNext();
        }
        current->getPrevious()->setNext(temp);
        temp->setNext(current);
        ++size;
    }

    void deleteFirst() {
        if (size == 0)
            return;

        ListElement *temp;
        temp = head;

        if (head->getNext() != NULL)
            head = head->getNext();

        delete temp;
        head->setPrevious(NULL);
        --size;
    }

    void deleteLast() {
        if (size == 0)
            return;

        ListElement *temp;
        temp = tail;
        if (tail->getPrevious() != NULL)
            tail = tail->getPrevious();
        delete temp;
        tail->setNext(NULL);
        --size;
    }

    void deleteValueOnThePosition(int index) {
        if (index >= size) {
            deleteLast();
            return;
        }
        if (index <= 0) {
            deleteFirst();
            return;
        }

        ListElement *current = new ListElement;
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->getNext();

        }
        current->getPrevious()->setNext(current->getNext()); // pomieniecie elementu o danym indeksie
        delete current;
        --size;
    }

    void display() {
        ListElement *temp;
        temp = head;
        while (temp != NULL) {
            cout << temp->getNumber() << " ";
            temp = temp->getNext();
        }
    }

    void loadFromFile(string fileName) {
        if (head != NULL) {
            ListElement *current = head;
            while (current != NULL) {
                ListElement* tmp = current->getNext();
                delete current;
                current = tmp;

            }
            head = NULL;
            tail = NULL;
            this->size = 0;
        }

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
            if (current->getNumber() == val) return true;
            current = current->getNext();
        }
        return false;
    }

    void deleteValue(int val) {
        ListElement *current = new ListElement;
        current = head;
        int counter = 0;
        while (current->getNext() != NULL) {
            if (current->getNumber() == val) {
                deleteValueOnThePosition(counter);
                return;
            }
            ++counter;
            current = current->getNext();
        }
    }

    void generateList(int size) {
        if (head != NULL) {
            ListElement *current = head;
            while (current != NULL) {
                ListElement* tmp = current->getNext();
                delete current;
                current = tmp;

            }
            head = NULL;
            tail = NULL;
            this->size = 0;
        }
        for (int i = 0; i < size; ++i) {
            addValueToTheStart((rand() % 10) + 1);
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
        deleteValueOnThePosition(rand() % size);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl << endl;

        cout << "Usuwanie losowej wartości: ";
        start = chrono::high_resolution_clock::now();
        deleteValue(rand() % (size + 1));
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl << endl;

        cout << "Wyszukiwanie losowej wartosci z listy:" << endl;
        start = chrono::high_resolution_clock::now();
        int rand_val = rand() % 1000000;
        bool is_in = isValueInList(rand_val);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        if (is_in) cout << "Wartosc" << rand_val << " jest w liscie " << endl;
        else cout << "Wartosci: " << rand_val << " nie ma w liscie " << endl;
        cout << "Czas: " << diff.count() << endl << endl;
    }

};