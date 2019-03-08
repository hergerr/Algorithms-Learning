#include<iostream>
#include<fstream>

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
        inFile.open(("../" + fileName));
        if (!inFile) {
            cout << "Nie można otworzyć pliku\n";
            exit(1); // terminate with error
        }

        inFile >> size;
        numbers = new int [size];

        int i = 0;
        while(i++ < size){
            inFile >> *(numbers + i - 1);
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
            cout << numbers[i] << '\n';
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