//
// Created by SuperUser on 29.05.2024.
//

#include "stack.h"

#include <iostream>
#include <stdexcept>

Stack::Stack()
{
    this->array = nullptr;
    this->capacity = 0;
    this->top = -1;
}

Stack::Stack(int capacity)
{
    this->array = new int[capacity];
    this->capacity = capacity;
    this->top = -1;
}

Stack::~Stack()
{
    delete[] this->array;
}


void Stack::Push(int value)
{
    if(this->top >= capacity)
        throw std::runtime_error("Cannot push, full.");

    this->array[++this->top] = value;
}

int Stack::Pop()
{
    if(this->top == 0)
    {
        throw std::runtime_error("Cannot pop, empty.");
    }

    return this->array[this->top--];
}

int Stack::Peek() const
{
    if(this->top < 0)
        throw std::runtime_error("Empty.");

    return this->array[this->top];
}

bool Stack::IsEmpty()
{
    return this->top < 0;
}

void Stack::Print() const
{
    for (int i = this->top; i >= 0; --i)
    {
        std::cout << this->array[i] << "\t";
    }

    std::cout << std::endl;
}




