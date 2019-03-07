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
    Table() {
//        this->size = size;
//        numbers = new int[size];
    }

    ~Table() {
        delete[] numbers;
    }

    void loadFromFile(string fileName) {
        ifstream file(fileName);
        int number;

        int counter = 0;
        while (counter < size) {
            file >> numbers[counter];
            counter++;
        }
        file.close();
    }

    bool IsValueInTable(int val) {
        return 0;

    }

    void addValue(int index, int value) {

    }

    void deleteFromTable(int index) {
        for (int i = index; i < size; ++i) {
            numbers[i] = numbers[i + 1];
        }
    }

    void display() {
        cout << "Zawartosc tablicy:\n";
        for (int i = 0; i < size; i++) {
            cout << numbers[i] << '\n';
        }
    }

    void generateTable(int size) {
        this->size = size;
        srand(381209);
        numbers = new int(size);
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
                cout << "podaj waertość:";
                cin >> value;

                myTab.addValue(index, value);
                myTab.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << "podaj waertość:";
                cin >> value;
                if (myTab.IsValueInTable(value))
                    cout << "poadana wartośc jest w tablicy";
                else
                    cout << "pozadanej wartości NIE ma w tablicy";
                break;

            case '5':  //tutaj generowanie  tablicy
                cout << "Podaj ilość elementów tablicy:";
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
