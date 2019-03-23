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
        int i = size++;         //pozycja nowego elementu -> rozmiar kopca + 1
        int j = (i - 1) / 2;    //indeks rodzica wstawianego elementu

        while (i > 0 && array[j] < value) { //dopki nie jestesmy w korzeniu i potencjalny rodzic jest mniejszy
            array[i] = array[j];            //umiesc rodzica na miejscu syna
            i = j;
            j = (i - 1) / 2;                //idziemy 'w gore'
        }
        array[i] = value;       //wstawienie elementu do kopca
    }

    void deleteRoot() {
        if (size == 0) return;

        if (size--) { // zmniejszamy razmiar kopca
            int value = array[size]; //ostatni element kopca

            int i = 0; //obecny indeks przy przeszukiwaniu. Zaczynamy od korzenia
            int j = 1; //pozycja lewego syna

            while (j < size) {
                if (j + 1 < size && array[j + 1] > array[j]) j++;   //szukamy wiekszego syna
                if (value >= array[j]) break;                       //jesli wartosc jest wieksza od lewego syna to jest spelniowy warunek kopca
                array[i] = array[j];                                //kopiowanie wiekszego syna do ojca
                i = j;
                j = 2 * j + 1;                                      //idziemy 'w dol'
            }

            array[i] = value;
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
            add((rand() % 10) + 1);
        }
    }

    //Funkcja do wypisywania drzewa binarnego
    //źródło: https://eduinf.waw.pl/inf/alg/001_search/0113.php
    void printBT(ostream & output, string sp, string sn, int v)
    {
        string s;
        string cr,cl,cp;

        cr = cl = cp = "  ";
        cr[0] = 218; cr[1] = 196;
        cl[0] = 192; cl[1] = 196;
        cp[0] = 179;

        if(v < size)
        {
            s = sp;
            if(sn == cr) s[s.length() - 2] = ' ';
            printBT(output, s + cp, cr, 2 * v + 2);

            s = s.substr(0,sp.length()-2);

            output << s << sn << array[v] << endl;

            s = sp;
            if(sn == cl) s[s.length() - 2] = ' ';
            printBT(output, s + cp, cl, 2 * v + 1);
        }
    }

};
