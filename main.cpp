#include "Table.h"
#include "List.h"
#include "Heap.h"


using namespace std;


void displayMenu(string info) {
    if (info == "--- TABLICA ---") {
        cout << endl;
        cout << info << endl;
        cout << "1.Wczytaj z pliku" << endl;
        cout << "2.Dodaj na koniec" << endl;
        cout << "3.Dodaj na początek" << endl;
        cout << "4.Dodaj na dowolna pozycje" << endl;
        cout << "5.Usun z konca" << endl;
        cout << "6.Usun z poczatku" << endl;
        cout << "7.Usun z dowolnego miejsca" << endl;
        cout << "8.Usun wartosc" << endl;
        cout << "9.Znajdz element" << endl;
        cout << "10.Generuj tablice" << endl;
        cout << "11.Wyswietl tablice" << endl;
        cout << "12.Test" << endl;
        cout << "0.Powrot do menu" << endl;
        cout << "Podaj opcje:";
    } else if (info == "--- LISTA ---") {
        cout << endl;
        cout << info << endl;
        cout << "1.Wczytaj z pliku" << endl;
        cout << "2.Dodaj na koniec" << endl;
        cout << "3.Dodaj na początek" << endl;
        cout << "4.Dodaj na dowolna pozycje" << endl;
        cout << "5.Usun z konca" << endl;
        cout << "6.Usun z poczatku" << endl;
        cout << "7.Usun z dowolnego miejsca" << endl;
        cout << "8.Usun wartosc" << endl;
        cout << "9.Znajdz element" << endl;
        cout << "10.Generuj liste" << endl;
        cout << "11.Wyswietl liste" << endl;
        cout << "12.Test" << endl;
        cout << "0.Powrot do menu" << endl;
        cout << "Podaj opcje:";
    } else if (info == "--- KOPIEC ---") {
        cout << endl;
        cout << info << endl;
        cout << "1.Wczytaj z pliku" << endl;
        cout << "2.Dodaj" << endl;
        cout << "3.Usun wartosc" << endl;
        cout << "4.Znajdz element" << endl;
        cout << "5.Generuj kopiec" << endl;
        cout << "6.Wyswietl kopiec" << endl;
        cout << "7.Test" << endl;
        cout << "0.Powrot do menu" << endl;
        cout << "Podaj opcje:";
    }
}

void menu_table() {

    int opt;
    string fileName;
    int index, value;
    Table myTab;


    do {
        displayMenu("--- TABLICA ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case 1: //tutaj wczytytwanie  listy z pliku
                cout << "Podaj nazwe pliku: ";
                cin >> fileName;
                myTab.loadFromFile(fileName);
                break;

            case 2: //tutaj dodawanie na koniec listy
                cout << "Podaj wartosc: ";
                cin >> value;
                myTab.addValueToTheEnd(value);
                break;

            case 3: //tutaj dodawanie na poczatek listy
                cout << "Podaj wartosc: ";
                cin >> value;
                myTab.addValueToTheStart(value);
                break;

            case 4: //tutaj dodawanie na dowolna pozycja
                cout << "podaj index: ";
                cin >> index;
                cout << "Podaj wartość: ";
                cin >> value;
                myTab.addValue(index, value);
                break;

            case 5: //tutaj usuwanie elemenu z końca listy
                myTab.deleteLast();
                break;

            case 6: //tutaj usuwanie elemenu z początku listy
                myTab.deleteFirst();
                break;

            case 7: //tutaj usuwanie elemenu z dowolnego miejsca
                cout << "Podaj index: ";
                cin >> index;
                myTab.deleteFromTable(index);
                break;

            case 8: //tutaj usuwanie elemenu o danej wartosci
                cout << "Podaj wartosc: ";
                cin >> value;
                myTab.deleteValue(value);
                break;

            case 9: //tutaj znajdowanie elemetu w liscie
                cout << "podaj wartosc:" << endl;
                cin >> value;
                if (myTab.isValueInTable(value) != -1) cout << "\nPodana wartosc jest w tablicy";
                else cout << "podanej wartosci NIE ma w tablicy";
                break;

            case 10:  //tutaj generowanie  listy
                cout << "Podaj ilosc elementow tablicy:";
                cin >> value;
                myTab.generateTable(value);
                break;

            case 11:  //tutaj wyświetlanie listy
                myTab.display();
                break;

            case 12: //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                myTab.test();
                break;
        }

    } while (opt != 0);
}

void menu_list() {
    int opt;
    string fileName;
    int index, value;
    List myList;


    do {
        displayMenu("--- LISTA ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case 1: //tutaj wczytytwanie  listy z pliku
                cout << "Podaj nazwe pliku: ";
                cin >> fileName;
                myList.loadFromFile(fileName);
                break;

            case 2: //tutaj dodawanie na koniec listy
                cout << "Podaj wartosc: ";
                cin >> value;
                myList.addValueToTheEnd(value);
                break;

            case 3: //tutaj dodawanie na poczatek listy
                cout << "Podaj wartosc: ";
                cin >> value;
                myList.addValueToTheStart(value);
                break;

            case 4: //tutaj dodawanie na dowolna pozycja
                cout << "podaj index: ";
                cin >> index;
                cout << "Podaj wartość: ";
                cin >> value;
                myList.addValueOnPosition(value, index);
                break;

            case 5: //tutaj usuwanie elemenu z końca listy
                myList.deleteLast();
                break;

            case 6: //tutaj usuwanie elemenu z początku listy
                myList.deleteFirst();
                break;

            case 7: //tutaj usuwanie elemenu z dowolnego miejsca
                cout << "Podaj index: ";
                cin >> index;
                myList.deleteValueOnThePosition(index);
                break;

            case 8: //tutaj usuwanie elemenu o danej wartosci
                cout << "Podaj wartosc: ";
                cin >> value;
                myList.deleteValue(value);
                break;

            case 9: //tutaj znajdowanie elemetu w liscie
                cout << "podaj wartosc:" << endl;
                cin >> value;
                if (myList.isValueInList(value)) cout << "podana wartosc jest w liscie";
                else cout << "podanej wartosci NIE ma w liscie";
                break;

            case 10:  //tutaj generowanie  listy
                cout << "Podaj ilosc elementow liscie:";
                cin >> value;
                myList.generateList(value);
                break;

            case 11:  //tutaj wyświetlanie listy
                myList.display();
                break;

            case 12: //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                myList.test();
                break;
        }

    } while (opt != 0);
}

void menu_heap() {
    int opt;
    string fileName;
    int index, value;
    Heap myHeap;


    do {
        displayMenu("--- KOPIEC ---");
        cin >> opt;
        cout << endl;
        switch (opt) {
            case 1: //tutaj wczytytwanie kopca z pliku
                cout << "Podaj nazwe pliku: ";
                cin >> fileName;
                myHeap.loadFromFile(fileName);
                break;

            case 2: //tutaj dodawanie do kopca
                cout << "Podaj wartosc: ";
                cin >> value;
                myHeap.add(value);
                break;

            case 3: //tutaj usuwanie elemenu z kopca
                cout << "podaj wartosc:" << endl;
                cin >> value;
                myHeap.deleteKey(value);
                break;

            case 4: //tutaj znajdowanie elemetu w kopcu
                cout << "podaj wartosc:" << endl;
                cin >> value;
                if (myHeap.isKeyInHeap(value) != -1) cout << "podana wartosc jest w kopcu";
                else cout << "podanej wartosci NIE ma w kopcu";
                break;

            case 5:  //tutaj generowanie  kopca
                cout << "Podaj ilosc elementow w kopcu:";
                cin >> value;
                myHeap.generateHeap(value);
                break;

            case 6:  //tutaj wyświetlanie kopca
                myHeap.printBT(cout ,"","", 0);
                break;

            case 7: //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie będzie testowana przez prowadzącego
                myHeap.test();
                break;
        }

    } while (opt != 0);
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
                menu_list();
                break;

            case '3':
                menu_heap();
                break;
        }

    } while (option != '0');

    return 0;
}
