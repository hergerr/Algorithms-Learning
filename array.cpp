#include<conio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


class Table {
    int *numbers;
    int size; //ilość elementów w tablicy

public:
    Table(){
    }

    ~Table() {
        delete[] numbers;
    }

    void loadFromFile(string fileName) {

        ifstream inFile;
        inFile.open(fileName);
        if (!inFile) {
            cout << "Nie można otworzyć pliku\n";
            exit(1); // terminate with error
        }

        inFile >> size;
        numbers = new int [size];

        int i = 0;
        while(i++ < size){
            inFile >> *(numbers + i - 1);
       //     printf("%d %d\n", element, numbers[i]);
        }

    }

    bool IsValueInTable(int val) {
        for (int i = 0; i < size; ++i) {
            if(numbers[i] == val) return true;
        }
        return false;
    }

    void addValue(int index, int value) {

        int * newArray = new int[++size];

        printf("size = %d\n", size);
        for(int i = 0; i < index; ++i) {
            newArray[i] = numbers[i];
        }
        newArray[index] = value;
        for (int i = index; i < size; ++i) {
            newArray[i + 1] = numbers[i];
        }


        delete[] numbers;
        int elementsOfTab = sizeof(numbers);
        numbers = newArray;

        printf("Rozmar de facto %d\n", elementsOfTab);
    }

    void deleteFromTable(int index) {
        int * newArray = new int [--size];

        for(int i = 0; i < index; ++i) {
            newArray[i] = numbers[i];
        }
        for (int i = index + 1; i <= size; ++i) {
            newArray[i - 1] = numbers[i];
        }

        delete[] numbers;

        numbers = newArray;
    }

    void display() {
        cout << "Zawartosc tablicy:\n";
        for (int i = 0; i < size; i++) {
            cout << *(numbers + i) << '\n';
        }
    }

    void generateTable(int size) {
        this->size = size;
        srand( 42 );
        numbers = new int[size];
        for (int i = 0; i < size; ++i) {
            numbers[i] = (rand() % 10) + 1;
        }
    }
};


void displayMenu(string info) {
    cout << endl;
    cout << info << endl;
    cout << "1.Wczytaj z pliku" << endl;
    cout << "2.Usun" << endl;
    cout << "3.Dodaj" << endl;
    cout << "4.Znajdz" << endl;
    cout << "5.Utworz losowo" << endl;
    cout << "6.Wyswietl" << endl;
    cout << "7.Test (pomiary)" << endl;
    cout << "0.Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void menu_table() {

    char opt;
    string fileName;
    int index, value;
    Table myTab;


    do {
        displayMenu("--- TABLICA ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << "Podaj nazwe pliku:";
                cin >> fileName;
                myTab.loadFromFile(fileName);
                myTab.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << "podaj index:";
                cin >> index;
                myTab.deleteFromTable(index);
                myTab.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << "podaj index:";
                cin >> index;
                cout << "podaj wartosc:";
                cin >> value;

                myTab.addValue(index, value);
                myTab.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << "podaj wartosc:" << endl;
                cin >> value;
                if (myTab.IsValueInTable(value)) cout << "podana wartosc jest w tablicy";
                else  cout << "podanej wartosci NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                myTab.generateTable(value);
                myTab.display();
                break;

            case '6':  //tutaj wyświetlanie tablicy
                myTab.display();
                break;

            case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                // można sobie tu dodać własne case'y
                break;
        }

    } while (opt != '0');
}

void menu_list() {
    //analogicznie jak menu_table()
}

void menu_heap() {
    //analogicznie jak menu_table()
}

int main(int argc, char *argv[]) {

    char option;
    do {
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;

        switch (option) {
            case '1':
                menu_table();
                break;

            case '2':
                break;

            case '3':
                break;
        }

    } while (option != '0');

    return 0;
}
