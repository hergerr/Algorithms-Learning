#include <iostream>
#include <fstream>
#include<chrono>
#include "ListElement.cpp"

using namespace std;

//todo deleting value
//todo pointer to the back

class List {
    ListElement *head;
    ListElement *tail;
    int size;
public:
    List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~List() {
    }

    //dodawanie na koniec
    void addValueToTheEnd(int value) {
        ListElement *temp = new ListElement();  //nowy element
        temp->setNumber(value);

        if (size == 0) {            //jesli dodajemy pierwszy element
            head = temp;            //wtedy head i temp sa ustawione na ten sam element
            tail = temp;
            ++size;
            display();
            return;
        }

        tail->setNext(temp);        //przestawienie wskaznika ostaniego element na nowy ostatni element
        temp->setNext(NULL);        //nowy ostatni element wskazuje na null
        temp->setPrevious(tail);    //ustawienie poprzedniego na element na ktory wskazuje tail
        tail = temp;                //tail znow wskazuje na koniec
        ++size;
        display();
    }

    void addValueToTheStart(int value) {
        ListElement *temp = new ListElement();  //nowy element
        temp->setNumber(value);

        if (size == 0) {            //podobnie jak powyzej, przypadek dla pierwszego elementu
            head = temp;
            tail = temp;
            ++size;
            display();
            return;
        }

        head->setPrevious(temp);    //ustawienie wskaznika pierwszego elementu na nowy pierwszy element
        temp->setNext(head);        //ustawienie wskaznika nowego pierwszego elementu na
        temp->setPrevious(NULL);    //poprzedni to NULL
        head = temp;                //ustawienie head na nowy poczatek
        ++size;
        display();
    }

    void addValueOnPosition(int value, int index) {
        if (index >= size) {            //przypadek kiedy podany zostal indeks wiekszy niz rozmiar listy
            addValueToTheEnd(value);
            return;
        }

        if (index <= 0) {                //zabezpieczenie przed za malym indeksem
            addValueToTheStart(value);
            return;
        }

        ListElement *current;
        ListElement *temp = new ListElement;
        temp->setNumber(value);     //ustawiewnie wartosci nowego elemnetu
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->getNext(); //dotarcie na zadana pozycje
        }
        temp->setPrevious(current->getPrevious());
        current->getPrevious()->setNext(temp);  //przestawienie wskaznika z poprzedniego elementu na ten ktory jest dodawany
        current->setPrevious(temp);
        temp->setNext(current);                 //ustawienie nastepnika dodawanego elementu
        ++size;
        display();
    }

    void deleteFirst() {
        if (size == 0)      //zabezpieczenie przed usuwaniem nieistniejacego elementu
            return;

        ListElement *temp;
        temp = head;

        if (head->getNext() != NULL) //jesli element na ktory wskazuje head nie wskazuje na null
            head = head->getNext();  //przestaw head

        delete temp;
        head->setPrevious(NULL);
        if (size == 1) { //jesli usuwa sie ostatni element to trzeba head i tail przestawic na null
            head = NULL;
            tail = NULL;
        }
        --size;
        display();
    }

    void deleteLast() {     //analogicznie do powyzszego
        if (size == 0)
            return;

        ListElement *temp;
        temp = tail;
        if (tail->getPrevious() != NULL)
            tail = tail->getPrevious();
        delete temp;
        tail->setNext(NULL);
        if (size == 1) {
            head = NULL;
            tail = NULL;
        }
        --size;
        display();
    }

    void deleteValueOnThePosition(int index) {
        if (index >= size - 1) { //zabezpieczenie przed za duzym indeksem
            deleteLast();
            return;
        }
        if (index <= 0) {   //zabezpieczenie przed za malym indeksem
            deleteFirst();
            return;
        }

        ListElement *current = new ListElement;
        current = head;
        for (int i = 0; i < index; i++) {   //dotarcie do zadanej pozycji
            current = current->getNext();

        }
        current->getPrevious()->setNext(current->getNext()); // pomieniecie elementu o danym indeksie
        current->getNext()->setPrevious(current->getPrevious());
        delete current;   //usuniecie zadanego elementu
        --size;
        display();
    }

    void display() {
        ListElement *temp;
        temp = head;
        while (temp != NULL) {  //dopoki nie dojdziemy do konca wyswietlamy element i idziemy dalej
            cout << temp->getNumber() << " ";
            temp = temp->getNext();
        }
        cout << endl;

        ListElement *temp2;
        temp2 = tail;
        while(temp2 != NULL){
            cout << temp2->getNumber() << " ";
            temp2 = temp2->getPrevious();
        }
        cout << endl;
    }

    void loadFromFile(string fileName) {
        if (head != NULL) { //jesli lista nie jest pusta to usun wszystko co w niej jest
            ListElement *current = head;
            while (current != NULL) {
                ListElement *tmp = current->getNext();
                delete current;
                current = tmp;

            }
            head = NULL;
            tail = NULL;
            this->size = 0;
        }

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
            addValueToTheEnd(number);
        }
    }

    bool isValueInList(int val) {
        ListElement *current;
        current = head;
        display();
        while (current->getNext() != NULL) {    //dopoki nie dotrzemy do konca, szukamy elementu o zadanej wartosci
            if (current->getNumber() == val) return true;
            current = current->getNext();
        }
        return false;
    }

    void deleteValue(int val) {
        ListElement *current;
        current = head;
        int counter = 0;
        while (current != NULL) {
            if (current->getNumber() == val) {  //wyszukiwanie zadanej wartosci
                deleteValueOnThePosition(counter);  //usuniecie wartosci o danym indeksie
                return;
            }
            ++counter;
            current = current->getNext();
        }
        display();
    }

    void generateList(int size) {
        if (head != NULL) { //usuniecie wszystkich elementow jesli lista jest niepusta
            ListElement *current = head;
            while (current != NULL) {
                ListElement *tmp = current->getNext();
                delete current;
                current = tmp;

            }
            head = NULL;
            tail = NULL;
            this->size = 0;
        }
        for (int i = 0; i < size; ++i) {
            addValueToTheStart((rand() % 10) + 1);
        }
    }


    void test() {
        srand(time(NULL));
        chrono::duration<double> display_dur, add_beg_dur, add_end_dur, add_rand_dur, rmv_beg_dur, rmv_end_dur, rm_rand_dur, find_dur;

        for (int i = 0; i < 100; ++i) {
            auto start = chrono::high_resolution_clock::now();
            display();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            display_dur += diff;

            start = chrono::high_resolution_clock::now();
            addValueToTheStart(0);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            add_beg_dur += diff;


            start = chrono::high_resolution_clock::now();
            addValueToTheEnd(0);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            add_end_dur += diff;

            start = chrono::high_resolution_clock::now();
            addValueOnPosition(0, rand() % size);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            add_rand_dur += diff;

            start = chrono::high_resolution_clock::now();
            deleteFirst();
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            rmv_beg_dur += diff;


            start = chrono::high_resolution_clock::now();
            deleteLast();
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            rmv_end_dur += diff;

            start = chrono::high_resolution_clock::now();
            deleteValueOnThePosition(rand() % size);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            rm_rand_dur += diff;

            int rand_val = rand() % 100000;
            start = chrono::high_resolution_clock::now();
            int is_in = isValueInList(rand_val);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            find_dur += diff;
        }

        cout << "\nWypisywanie wartosci listy: " << (display_dur / 100).count() << endl;
        cout << "Wstawianie nowej wartości na początek: " << (add_beg_dur / 100).count() << endl;
        cout << "Wstawianie nowej wartości na koniec: " << (add_end_dur / 100).count() << endl;
        cout << "Wstawianie nowej wartości w losowe miejsce w listy: " << (add_rand_dur / 100).count() << endl;
        cout << "Usuwanie wartości z początku listy: " << (rmv_beg_dur / 100).count() << endl;
        cout << "Usuwanie wartości z końca listy: " << (rmv_end_dur / 100).count() << endl;
        cout << "Usuwanie wartości z losowego miejsca w listy: " << (rm_rand_dur / 100).count() << endl;
        cout << "Wyszukiwanie losowej wartosci z listy: " << (find_dur / 100).count() << endl;


    }

};