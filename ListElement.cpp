#include <iostream>

class ListElement {
    int number;
    ListElement *next;
    ListElement *previous;
public:
    ListElement(){
        this->next = NULL;
        this->previous = NULL;
    }

    ListElement *getPrevious() const {
        return previous;
    }

    void setPrevious(ListElement *previous) {
        ListElement::previous = previous;
    }

    int getNumber() const {
        return number;
    }

    void setNumber(int number) {
        ListElement::number = number;
    }

    ListElement *getNext() const {
        return next;
    }

    void setNext(ListElement *next) {
        ListElement::next = next;
    }
};