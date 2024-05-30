//
// Created by SuperUser on 29.05.2024.
//

#include "linked_list_double.h"
#include <iostream>

LinkedListDouble::LinkedListDouble()
{
    this->value = 0;
    this->next = nullptr;
    this->previous = nullptr;
}

LinkedListDouble::LinkedListDouble(int value)
{
    this->value = value;
    this->next = nullptr;
    this->previous = nullptr;
}

LinkedListDouble::~LinkedListDouble()
{
    LinkedListDouble* next = this->next;
    this->next = nullptr;
    delete next;

    LinkedListDouble* previous = this->previous;
    this->previous = nullptr;
    delete previous;
}

int LinkedListDouble::GetValue()
{
    return this->value;
}


LinkedListDouble* LinkedListDouble::GetNext()
{
    return this->next;
}

LinkedListDouble* LinkedListDouble::SetNext(LinkedListDouble* next)
{
    return this->next = next;
}

LinkedListDouble* LinkedListDouble::SetNext(int value)
{
    return this->SetNext(new LinkedListDouble(value));
}

LinkedListDouble* LinkedListDouble::GetPrevious()
{
    return this->previous;
}

LinkedListDouble* LinkedListDouble::SetPrevious(LinkedListDouble* previous)
{
    return this->previous = previous;
}

LinkedListDouble* LinkedListDouble::SetPrevious(int value)
{
    return this->SetPrevious(new LinkedListDouble(value));
}

void LinkedListDouble::Print()
{
    LinkedListDouble* current = this;
    do
    {
        std::cout << current->value << "\t";
    } while ((current = current->next) != nullptr);
    std::cout << std::endl;
}


LinkedListDouble* LinkedListDouble::InsertAfter(int value)
{
    LinkedListDouble* previousNext = this->next;
    LinkedListDouble* inserted = new LinkedListDouble(value);

    inserted->next = previousNext;
    inserted->previous = this;
    if(previousNext != nullptr)
        previousNext->previous = inserted;

    return this->next = inserted;
}

LinkedListDouble* LinkedListDouble::InsertBefore(int value)
{
    LinkedListDouble* previousBefore = this->previous;
    LinkedListDouble* inserted = new LinkedListDouble(value);

    inserted->previous = previousBefore;
    inserted->next = this;
    if(previousBefore != nullptr)
        previousBefore->next = inserted;

    return this->previous = inserted;
}

LinkedListDouble* LinkedListDouble::FindFirst(int value)
{
    LinkedListDouble* currentBack = this->previous;
    LinkedListDouble* currentForward = this->next;

    if(this->value == value)
    {
        return this;
    }

    bool anyHasValue = true;
    while (anyHasValue)
    {
        anyHasValue = false;

        if(currentBack != nullptr)
        {
            if(currentBack->value == value)
                return currentBack;

            currentBack = currentBack->previous;
            anyHasValue = true;
        }
        if(currentForward != nullptr)
        {
            if(currentForward->value == value)
                return currentForward;

            currentForward = currentForward->next;
            anyHasValue = true;
        }
    }

    return nullptr;
}

LinkedListDouble* LinkedListDouble::RemoveAfter()
{
    LinkedListDouble* next = this->next;
    LinkedListDouble* nextAfter = nullptr;
    if(this->next != nullptr)
    {
        nextAfter = this->next->next;
        next->next = nullptr;
        next->previous = nullptr;
    }

    this->next = nextAfter;
    if(nextAfter != nullptr)
        nextAfter->previous = this;

    delete next;
    return this;
}

LinkedListDouble* LinkedListDouble::RemoveBefore()
{
    LinkedListDouble* previous = this->previous;
    LinkedListDouble* beforePrevious = nullptr;
    if(this->previous != nullptr)
    {
        beforePrevious = this->previous->previous;
        previous->next = nullptr;
        previous->previous = nullptr;
    }

    this->previous = beforePrevious;
    if(beforePrevious != nullptr)
        beforePrevious->next = this;

    delete previous;
    return this;
}











