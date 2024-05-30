//
// Created by SuperUser on 29.05.2024.
//

#include "queue.h"
#include <cstdlib>
#include <iostream>

Queue::Queue()
{
    this->array = nullptr;
    this->capacity = 0;
    this->first = -1;
    this->last = -1;
    this->length = 0;
}

Queue::Queue(int capacity)
{
    this->array = new int[capacity];
    this->capacity = capacity;
    this->first = -1;
    this->last = -1;
    this->length = 0;
}

Queue::~Queue()
{
    delete[] this->array;
}

void Queue::Enqueue(int value)
{
    this->last = (this->last + 1) % this->capacity;
    this->array[this->last] = value;

    if(this->length++ == 0)
    {
        this->first = 0;
    }
}

int Queue::Dequeue()
{
    int current = this->first;
    this->first = (this->first + 1) % this->capacity;

    if(--this->length == 0)
    {
        this->first = 0;
        this->last = 0;
    }

    return this->array[current];
}

int Queue::Front() const
{
    return this->array[this->first];
}

void Queue::Print() const
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << this->array[(this->first + i) % this->capacity] << "\t";
    }

    std::cout << std::endl;
}


