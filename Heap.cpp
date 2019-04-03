#include <iostream>
#include<iomanip>
#include<fstream>
#include<chrono>


using namespace std;

class Heap {
    int *array; // wskaznik na tablice w ktorej jest kopiec
    int max_size;
    int size;

public:
    Heap() {
        max_size = 1000000; //maksymalny rozmiar kopca
        array = new int[max_size];
        size = 0;

    }

    void swap(int *x, int *y) { //funkcja zamieniajace dane elementy
        int temp = *x;
        *x = *y;
        *y = temp;
    }


    void add(int value) {       // dodaje nowy klucz
        int i = ++size;         //pozycja nowego elementu -> rozmiar kopca + 1
        int j = (i - 1) / 2;    //indeks rodzica wstawianego elementu
        array[i] = value;       //wstawienie elementu do kopca
        if (size == 1) return;

        while (i > 0 && array[j] < value) { //dopoki nie jest spelniony warunek kopca
            swap(array + i, array + j);     //zamieniamy syna z ojcem
            i = j;                          //idziemy w gore. syn zajmuje miejsce ojca
            j = (j - 1) / 2;                //a ojciec idzie poziom wyzej
        }

    }

    void heapify(int index) {               //kopcowanie
        if (index * 2 + 1 >= size) {        //sprawdzanie czy lewy syn istnieje
            return;
        }
        int left_son = index * 2 + 1;
        int maxIndex = left_son;
        if (index * 2 + 2 < size) {         //sprawdzanie czy prawy syn istnieje
            int right_son = index * 2 + 2;
            if (array[left_son] < array[right_son])   //wybranie wiekszego z synow
                maxIndex = right_son;
        }

        swap(array + maxIndex, array + index);  //zamiania syna z ojcem
        heapify(maxIndex);                      //rekurencyjne zejscie w dol kopca
    }

    void deleteKey(int value) {
        int index = isKeyInHeap(value);
        if (index != -1) {                  //funkcja szukajaca zwraca -1 jesli nie ma takiego elementu
            array[index] = array[--size];   //zmniejeszenie rozmiaru tablicy w ktorej jest kopiec i wstawienie w miejsce usunietego elementu ostatniego elementu kopca
            int i = index;                  //syn
            int j = (i - 1) / 2;            //rodzic
            while (i > 0 && array[j] < value) { //warunek kopca
                swap(array + i, array + j); //zamiana syna z ojcem
                i = j;                      //syn staje zajmuje miejsce
                j = (j - 1) / 2;            //ojciec idzie poziom wyzej
            }
            if (i == index) {       //jesli wszystko od usunietego miejsca do gory jest ok
                heapify(index);     //kopcujemy w dol
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

    void test() {
        chrono::duration<double> display_dur, add_dur, rm_dur, find_dur;
        srand(time(NULL));


        for (int i = 0; i < 100; ++i) {

            auto start = chrono::high_resolution_clock::now();
            add(rand() % 100000);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            add_dur += diff;

            start = chrono::high_resolution_clock::now();
            deleteKey(rand() % 100000);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            rm_dur += diff;

            start = chrono::high_resolution_clock::now();
            int rand_val = rand() % 100000;
            int is_in = isKeyInHeap(rand_val);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            find_dur += diff;
        }


        cout << "Wstawianie losowej wartosci: " << (add_dur / 100).count() << endl;
        cout << "Usuwanie losowej wartości: " << (rm_dur / 100).count() << endl;
        cout << "Wyszukiwanie losowej wartosci: " << (find_dur / 100).count() << endl;

    }

};
