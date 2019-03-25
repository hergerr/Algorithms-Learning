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

    int getLeftSon(int i) {
        return (2 * i + 1); //zwraca lewego syna
    }

    int getRightSon(int i) { //zwraca prawego syna
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


    void add(int value) {       // dodaje nowy klucz
        int i = ++size;         //pozycja nowego elementu -> rozmiar kopca + 1
        int j = (i - 1) / 2;    //indeks rodzica wstawianego elementu
        array[i] = value;       //wstawienie elementu do kopca
        if (size == 1) return;

        while (i > 0 && array[j] < value) {
            swap(array + i, array + j);
            i = j;
            j = (j - 1) / 2;
        }

    }

    void heapify(int index) {
        if (index * 2 + 1 >= size) {
            return;
        }
        int left_son = index * 2 + 1;
        int maxIndex = left_son;
        if (index * 2 + 2 < size) {
            int right_son = index * 2 + 2;
            if ( array[left_son] < array[right_son])
                maxIndex = right_son;
        }

        swap(array + maxIndex, array + index);
        heapify(maxIndex);
    }

    void deleteKey(int value) {
        int index = isKeyInHeap(value);
        if (index != -1) {
            array[index] = array[--size];
            int i = index;
            int j = (i - 1) / 2;
            while (i > 0 && array[j] < value) {
                swap(array + i, array + j);
                i = j;
                j = (j - 1) / 2;
            }
            if (i == index) {
                heapify(index);
            }
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
            add(number);
        }
    }

    int isKeyInHeap(int k) {
        int i = 0;
        for (int i = 0; i < size; i++) {
            if (k == array[i]) {
                return i;

            }
        }
        return -1;
    }

    void generateHeap(int size) {
        srand(42);
        for (int i = 0; i < size; ++i) {
            add((rand() % 10) + 1);
        }
    }

    //Funkcja do wypisywania drzewa binarnego
    //źródło: https://eduinf.waw.pl/inf/alg/001_search/0113.php
    void printBT(ostream &output, string sp, string sn, int v) {
        string s;
        string cr, cl, cp;

        cr = cl = cp = "  ";
        cr[0] = 218;
        cr[1] = 196;
        cl[0] = 192;
        cl[1] = 196;
        cp[0] = 179;

        if (v < size) {
            s = sp;
            if (sn == cr) s[s.length() - 2] = ' ';
            printBT(output, s + cp, cr, 2 * v + 2);

            s = s.substr(0, sp.length() - 2);

            output << s << sn << array[v] << endl;

            s = sp;
            if (sn == cl) s[s.length() - 2] = ' ';
            printBT(output, s + cp, cl, 2 * v + 1);
        }
    }

};
