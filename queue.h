//
// Created by SuperUser on 29.05.2024.
//

#ifndef QUEUE_H
#define QUEUE_H



class Queue {
private:
    int* array;
    int capacity;
    int first;
    int last;
    int length;
    Queue();


public:
    Queue(int capacity);
    ~Queue();

    void Enqueue(int value);
    int Dequeue();
    int Front() const;

    void Print() const;
};



#endif //QUEUE_H
