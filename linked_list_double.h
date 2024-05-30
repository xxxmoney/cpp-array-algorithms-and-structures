//
// Created by SuperUser on 29.05.2024.
//

#ifndef LINKED_LIST_DOUBLE_H
#define LINKED_LIST_DOUBLE_H



class LinkedListDouble {
private:
    int value;
    LinkedListDouble* previous;
    LinkedListDouble* next;
    LinkedListDouble();

public:
    LinkedListDouble(int value);
    ~LinkedListDouble();

    int GetValue();
    LinkedListDouble* GetNext();
    LinkedListDouble* SetNext(LinkedListDouble* next);
    LinkedListDouble* SetNext(int value);
    LinkedListDouble* GetPrevious();
    LinkedListDouble* SetPrevious(LinkedListDouble* previous);
    LinkedListDouble* SetPrevious(int value);

    void Print();

    LinkedListDouble* InsertAfter(int value);
    LinkedListDouble* InsertBefore(int value);

    LinkedListDouble* FindFirst(int value);

    LinkedListDouble* RemoveAfter();
    LinkedListDouble* RemoveBefore();



};



#endif //LINKED_LIST_DOUBLE_H
