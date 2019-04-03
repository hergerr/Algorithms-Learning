#include<iostream>
#include<fstream>
#include<chrono>

using namespace std;

class Table {
    int *numbers;
    int size; //ilość elementów w tablicy

public:

    Table() {
        numbers = NULL;
        size = 0;
    }

    void loadFromFile(string fileName) {
        if (numbers !=NULL) delete[] numbers;
        ifstream inFile;
        inFile.open(("../" + fileName));
        if (!inFile) {
            cout << "Nie można otworzyć pliku\n";
            exit(1); // terminate with error
        }

        inFile >> size;
        numbers = new int[size];

        int i = 0;
        while (i++ < size) {
            inFile >> numbers[i - 1];
        }
        display();
    }

    int isValueInTable(int val) {
        for (int i = 0; i < size; ++i) {
            if (numbers[i] == val) {
                return i;
            }
        }
        return -1;
    }

    void addValueToTheStart(int val) {
        addValue(0, val);
    }

    void addValueToTheEnd(int val) {
        addValue(size, val);
    }

    void addValue(int index, int value) {
        if(index < 0) index = 0;
        if(index > size) index = size;

        if(size == 0){
            numbers = new int[1];
            numbers[0] = value;
        }

        int *newArray = new int[++size];

        if (index >= size) {
            //dodawanie na koniec listy
            index = size;

        }
        newArray[index] = value;
        for (int i = 0; i < index; i++) {
            newArray[i] = numbers[i];
        }
        for (int i = index + 1; i < size; i++) {
            newArray[i] = numbers[i - 1];
        }

        delete[] numbers;
        numbers = newArray;
        display();
    }

    void deleteFromTable(int index) {
        if (size == 0){
            return;
        }
        if(index >= size){
            deleteLast();
            return;
        }
        if(index < 0){
            deleteFirst();
            return;
        }

        int *newArray = new int[--size];

        for (int i = 0; i < index; ++i) {
            newArray[i] = numbers[i];
        }
        for (int i = index + 1; i <= size; ++i) {
            newArray[i - 1] = numbers[i];
        }

        delete[] numbers;

        numbers = newArray;
        display();
    }

    void deleteFirst() {
        deleteFromTable(0);
    }

    void deleteLast() {
        deleteFromTable(size - 1);
    }

    void deleteValue(int value){
        int value_index = isValueInTable(value);
        if(value_index != -1){
            deleteFromTable(value_index);
        } else return;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << numbers[i] << ' ';
        }
    }

    void generateTable(int size) {
        this->size = size;
        srand(42);
        numbers = new int[size];
        for (int i = 0; i < size; ++i) {
            numbers[i] = (rand() % 10) + 1;
        }
        display();
    }

    void test() {
        auto start = chrono::high_resolution_clock::now();
        display();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "Wypisywanie wartosci tablicy: " << diff.count() << endl << endl;

        cout << "Wstawianie nowej wartości na początek: ";
        start = chrono::high_resolution_clock::now();
        addValue(0, 0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;


        cout << "Wstawianie nowej wartości na koniec: ";
        start = chrono::high_resolution_clock::now();
        addValue(size - 1, 0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;

        cout << "Wstawianie nowej wartości w losowe miejsce w tablicy: ";
        start = chrono::high_resolution_clock::now();
        addValue(rand() % size - 1, 0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl << endl;

        cout << "Usuwanie wartości z początku tablicy: ";
        start = chrono::high_resolution_clock::now();
        deleteFromTable(0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;


        cout << "Usuwanie wartości z końca tablicy: ";
        start = chrono::high_resolution_clock::now();
        deleteFromTable(size - 1);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl;

        cout << "Usuwanie wartości z losowego miejsca w tablicy: ";
        start = chrono::high_resolution_clock::now();
        deleteFromTable(rand() % (size));
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        cout << diff.count() << endl << endl;

        cout << "Wyszukiwanie losowej wartosci z tablicy:" << endl;
        start = chrono::high_resolution_clock::now();
        int rand_val = rand() % 1000000;
        int is_in = isValueInTable(rand_val);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        if (is_in != -1) cout << "Wartosc" << rand_val << " jest w tablicy " << endl;
        else cout << "Wartosci: " << rand_val << " nie ma w tablicy " << endl;
        cout << "Czas: " << diff.count() << endl << endl;

    }
};