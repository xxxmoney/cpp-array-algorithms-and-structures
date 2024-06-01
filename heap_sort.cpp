//
// Created by SuperUser on 01.06.2024.
//

#include "heap_sort.h"

#include <iostream>

HeapSort::HeapSort(std::vector<int>& items)
{
    this->items = items;
}

HeapSort::~HeapSort()
{
    this->items.clear();
}

void HeapSort::Heapify(int parentIndex, int heapSize)
{
    int leftChildIndex = parentIndex * 2 + 1;
    int rightChildIndex = leftChildIndex + 1;

    int smallestIndex = parentIndex;

    if(leftChildIndex < heapSize && this->items[leftChildIndex] < this->items[smallestIndex])
        smallestIndex = leftChildIndex;

    if(rightChildIndex < heapSize && this->items[rightChildIndex] < this->items[smallestIndex])
        smallestIndex = rightChildIndex;

    if(smallestIndex == parentIndex)
        return;

    std::swap(this->items[smallestIndex], this->items[parentIndex]);
    this->Heapify(smallestIndex, heapSize);
}

void HeapSort::BuildMaxHeap()
{
    for (int parentIndex = this->items.size() / 2; parentIndex >= 0; --parentIndex)
        this->Heapify(parentIndex, this->items.size());
}

std::vector<int>& HeapSort::Sort()
{
    this->BuildMaxHeap();
    int topIndex = 0;
    for (int heapSize = this->items.size() - 1; heapSize >= 0; --heapSize)
    {
        // Swap top with current last
        std::swap(this->items[topIndex], this->items[heapSize]);

        this->Heapify(topIndex, heapSize);
    }

    return this->items;
}

void HeapSort::Print()
{
    for (auto item : this->items)
    {
        std::cout << item << "\t";
    }
    std::cout << std::endl;
}



