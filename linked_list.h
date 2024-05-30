//
// Created by SuperUser on 29.05.2024.
//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


class LinkedList {
int value;
private:
LinkedList* next;
LinkedList();

public:
    LinkedList(int value);
    ~LinkedList();

    LinkedList* GetNext();
    LinkedList* SetNext(LinkedList* next);
    LinkedList* SetNext(int value);

    void Print();

    LinkedList* InsertAfter(int value);
    LinkedList* InsertBefore(LinkedList* previous, int value);
    LinkedList* RemoveAfter();
    LinkedList* RemoveBefore(LinkedList* previous);

};



#endif //LINKED_LIST_H
