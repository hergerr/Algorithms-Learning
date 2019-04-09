#include "Table.h"

Table::Table() {
    numbers = NULL;
    size = 0;
}

void Table::loadFromFile(string fileName) {
    if (numbers != NULL) delete[] numbers;  //jesli tablica jest niepusta to ja usuwamy
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

int Table::isValueInTable(int val) {
    for (int i = 0; i < size; ++i) {    //pzeszukiwanie tablicy
        if (numbers[i] == val) {
            display();
            return i;
        }
    }
    display();
    return -1;  //-1 to nieznalezienie elementu
}

void Table::addValueToTheStart(int val) {
    addValue(0, val);
}

void Table::addValueToTheEnd(int val) {
    addValue(size, val);
}

void Table::addValue(int index, int value) {
    if (index < 0) index = 0;       //zabezpieczenie przed nieprawidlowymi danymi
    if (index >= size) index = size;    //index = size, bo size niedlugo sie zwiekszy

    if (size == 0) {
        numbers = new int[1];
        numbers[0] = value;
    }

    int *newArray = new int[++size];    //nowa, wieksza tablica

    newArray[index] = value;             //przepisywanie do nowej tablicy
    for (int i = 0; i < index; i++) {
        newArray[i] = numbers[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArray[i] = numbers[i - 1];
    }

    delete[] numbers;               //usuniecie starej tablicy
    numbers = newArray;             //przypisanie wskaznika na nowa tablice
    display();
}

void Table::deleteFromTable(int index) {
    if (size == 0) {        //zabezpieczenia przed nieprawidlowymi danymi
        return;
    }
    if (index >= size) {
        deleteLast();
        return;
    }
    if (index < 0) {
        deleteFirst();
        return;
    }

    int *newArray = new int[--size];    //nowa tablica o nowym rozmiarze

    for (int i = 0; i < index; ++i) {   //przepisanie do nowej tablicy z pominieciem usuwanego elementu
        newArray[i] = numbers[i];
    }
    for (int i = index + 1; i <= size; ++i) {
        newArray[i - 1] = numbers[i];
    }

    delete[] numbers;   //usuniecie satarej tablicy

    numbers = newArray; //przypisanie wskaznika na nowa tablice
    display();
}

void Table::deleteFirst() {
    deleteFromTable(0);
}

void Table::deleteLast() {
    deleteFromTable(size - 1);
}

void Table::deleteValue(int value) {
    int value_index = isValueInTable(value);
    if (value_index != -1) {    //-1 jest zwaracane kiedy nie ma takiego elementu
        deleteFromTable(value_index);
    } else return;
}

void Table::display() {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void Table::generateTable(int size) {
    this->size = size;
    srand(42);
    numbers = new int[size];
    for (int i = 0; i < size; ++i) {
        numbers[i] = (rand() % 10) + 1;
    }
    display();
}

void Table::test() {
    srand(time(NULL));
    chrono::duration<double> display_dur, add_beg_dur, add_end_dur, add_rand_dur, rmv_beg_dur, rmv_end_dur, rm_rand_dur, find_dur;

    for (int i = 0; i < 100; ++i) {
        auto start = chrono::high_resolution_clock::now();
        display();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        display_dur += diff;

        start = chrono::high_resolution_clock::now();
        addValue(0, 0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        add_beg_dur += diff;

        start = chrono::high_resolution_clock::now();
        addValue(size - 1, 0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        add_end_dur += diff;

        start = chrono::high_resolution_clock::now();
        addValue(rand() % size, 0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        add_rand_dur += diff;

        start = chrono::high_resolution_clock::now();
        deleteFromTable(0);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        rmv_beg_dur += diff;;


        start = chrono::high_resolution_clock::now();
        deleteFromTable(size - 1);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        rmv_end_dur += diff;

        start = chrono::high_resolution_clock::now();
        deleteFromTable(rand() % (size));
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        rm_rand_dur += diff;

        int rand_val = rand() % 100000;
        start = chrono::high_resolution_clock::now();
        int is_in = isValueInTable(rand_val);
        end = chrono::high_resolution_clock::now();
        diff = end - start;
        find_dur += diff;

    }

    cout << "\nWypisywanie wartosci tablicy: " << (display_dur / 100).count() << endl;
    cout << "Wstawianie nowej wartości na początek: " << (add_beg_dur / 100).count() << endl;
    cout << "Wstawianie nowej wartości na koniec: " << (add_end_dur / 100).count() << endl;
    cout << "Wstawianie nowej wartości w losowe miejsce w tablicy: " << (add_rand_dur / 100).count() << endl;
    cout << "Usuwanie wartości z początku tablicy: " << (rmv_beg_dur / 100).count() << endl;
    cout << "Usuwanie wartości z końca tablicy: " << (rmv_end_dur / 100).count() << endl;
    cout << "Usuwanie wartości z losowego miejsca w tablicy: " << (rm_rand_dur / 100).count() << endl;
    cout << "Wyszukiwanie losowej wartosci z tablicy:" << (find_dur / 100).count() << endl;


}