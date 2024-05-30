//
// Created by SuperUser on 29.05.2024.
//

#include "linked_list.h"
#include <iostream>

LinkedList::LinkedList()
{
    value = 0;
    this->next = nullptr;
}

LinkedList::LinkedList(int value)
{
    this->value = value;
    this->next = nullptr;
}

LinkedList::~LinkedList()
{
    LinkedList* next = this->next;
    this->next = nullptr;
    delete next;
}

LinkedList* LinkedList::GetNext()
{
    return this->next;
}

LinkedList* LinkedList::SetNext(LinkedList* next)
{
    return this->next = next;
}

LinkedList* LinkedList::SetNext(int value)
{
    return this->SetNext(new LinkedList(value));
}

void LinkedList::Print()
{
    LinkedList* current = this;
    do
    {
        std::cout << current->value << "\t";
    } while ((current = current->next) != nullptr);
    std::cout << std::endl;
}

LinkedList* LinkedList::InsertAfter(int value)
{
    LinkedList* previousNext = this->next;
    LinkedList* inserted = new LinkedList(value);
    inserted->next = previousNext;

    return this->next = inserted;
}

LinkedList* LinkedList::InsertBefore(LinkedList* previous, int value)
{
    LinkedList* inserted = new LinkedList(value);
    inserted->next = this;

    return previous->next = inserted;
}

LinkedList* LinkedList::RemoveAfter()
{
    if(this->next == nullptr)
        return this;

    LinkedList* nextAfter = nullptr;
    if(this->next != nullptr)
    {
        nextAfter = this->next->next;
    }
    LinkedList* previousNext = this->next;
    this->next = nextAfter;

    previousNext->next = nullptr;
    delete previousNext;

    return this;
}

LinkedList* LinkedList::RemoveBefore(LinkedList* previous)
{
    if(previous == nullptr)
    {
        LinkedList* current = this->next;
        this->next = nullptr;

        delete this;
        return current;
    }

    previous->next = this->next;
    this->next = nullptr;

    delete this;
    return previous;
}









