#include <iostream>
#include<iomanip>
#include<fstream>


using namespace std;

class Heap {
    int *array; // wskaznik na tablice w ktorej jest kopiec
    int max_size;
    int size;

public:
    Heap() {
        max_size = 1000000;
        array = new int[max_size];
        size = 0;

    }

    int parent(int i) {
        return (i - 1) / 2;  // zwraca rodzica
    }

    int leftSon(int i) {
        return (2 * i + 1); //zwraca lewego syna
    }

    int rightSon(int i) { //zwraca prawego syna
        return (2 * i + 2);
    }

    int getMin() {  //zwraca korzen, czyli minimum
        return array[0];
    }

    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }


    void insertKey(int key) { // dodaje nowy klucz
        if (max_size == size) {
            cout << "Osiagnieto maksymalny rozmiar" << endl;
            return;
        }

        ++size;
        int i = size - 1;
        array[i] = key;

        while (i != 0 && array[parent(i)] > array[i]) { // jesli syn jest wiekszy od ojca
            swap(&array[i], &array[parent(i)]); // zamiana syna i ojca
            i = parent(i); //idziemy w 'gore' drzewa
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
            insertKey(number);
        }
    }

    bool isKeyInHeap(int k) {
        int i = 0;
        for (int i = 0; i < size; i++) {
            if (k == array[i]) {
                return true;

            }
        }
        return false;
    }

    void generateHeap(int size) {
        srand(42);
        for (int i = 0; i < size; ++i) {
            insertKey((rand() % 10) + 1);
        }
    }


    void print() {

        if (size == 0) {
            cout << "brak elementow do wyswietlenia" << endl;
            return;
        }
        cout << setw(40) << array[0] << endl << endl;
        for (int i = 1; i < 3; i++) {
            if (size > i) {
                cout << setw(27);
                if (array[i] != 0)
                    cout << array[i];
                else
                    cout << 'x';
            }
        }
        cout << endl << endl;
        for (int i = 3; i < 7; i++) {
            if (size > i) {
                cout << setw(16);
                if (array[i] != 0)
                    cout << array[i];
                else
                    cout << 'x';
            }
        }
        cout << endl << endl;
        for (int i = 7; i < 16; i++) {
            if (size > i) {
                cout << setw(9);
                if (array[i] != 0)
                    cout << array[i];
                else
                    cout << 'x';;
            }
        }
        cout << endl << endl;
    }
};
