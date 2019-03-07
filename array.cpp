#include<iostream>
using namespace std;

int main()
{

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1.Tablica" << endl;
        cout << "2.Lista" << endl;
        cout << "3.Kopiec" << endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getchar();
        cout << endl;

        switch (option){
            case '1':
                break;

            case '2':
                break;

            case '3':
                break;
        }

    } while (option != '0');


    return 0;
}