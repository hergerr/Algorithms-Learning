#include<conio.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


class Table {
    int *tab;
    int cnt; //ilość elementów w tablicy
    vector<int> numbers;

public:

    void loadFromFile(string fileName) {
        ifstream in(fileName, ios::in);
        int number;

        //Read number using the extraction (>>) operator
        while (in >> number) {
            numbers.push_back(number);
        }
        in.close();
    }

    bool IsValueInTable(int val) {
        return 0;

    }

    void addValue(int index, int value) {

    }

    void deleteFromTable(int index) {

    }

    void display() {
        cout << "Zawartosc pliku:\n";
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << '\n';
        }
    }

    void generateTable(int size) {

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

Table myTab;

void menu_table() {
    char opt;
    string fileName;
    int index, value;


    do {
        displayMenu("--- TABLICA ---");
        opt = getche();
        cout << endl;
        switch (opt) {
            case '1': //tutaj wczytytwanie  tablicy z pliku
                cout << " Podaj nazwe pliku:";
                cin >> fileName;
                myTab.loadFromFile(fileName);
                myTab.display();
                break;

            case '2': //tutaj usuwanie elemenu z tablicy
                cout << " podaj index:";
                cin >> index;
                myTab.deleteFromTable(index);
                myTab.display();
                break;

            case '3': //tutaj dodawanie elemetu do tablicy
                cout << " podaj index:";
                cin >> index;
                cout << " podaj waertość:";
                cin >> value;

                myTab.addValue(index, value);
                myTab.display();
                break;

            case '4': //tutaj znajdowanie elemetu w tablicy
                cout << " podaj waertość:";
                cin >> value;
                if (myTab.IsValueInTable(value))
                    cout << "poadana wartośc jest w tablicy";
                else
                    cout << "poadanej wartości NIE ma w tablicy";
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
        option = getche();
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
