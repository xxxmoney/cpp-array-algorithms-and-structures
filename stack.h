//
// Created by SuperUser on 29.05.2024.
//

#ifndef STACK_H
#define STACK_H



class Stack {
private:
    int* array;
    int capacity;
    int top;
    Stack();

public:
    Stack(int capacity = 20);
    ~Stack();

    void Push(int value);
    int Pop();
    int Peek() const;

    bool IsEmpty();

    void Print() const;

};



#endif //STACK_H
