#include "Table.cpp"

using namespace std;




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
                if (myTab.isValueInTable(value)) cout << "podana wartosc jest w tablicy";
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
                myTab.test();
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
