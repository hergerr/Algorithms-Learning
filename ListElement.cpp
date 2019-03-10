using namespace std;

class ListElement {
    int number;
    ListElement *next;
public:
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