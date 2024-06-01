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

    // Find the largest element between parent and its children
    int swapIndex = parentIndex;

    if(leftChildIndex < heapSize && this->items[leftChildIndex] > this->items[swapIndex])
        swapIndex = leftChildIndex;

    if(rightChildIndex < heapSize && this->items[rightChildIndex] > this->items[swapIndex])
        swapIndex = rightChildIndex;

    // If parent is the largest, then we are done
    if(swapIndex == parentIndex)
        return;

    std::swap(this->items[swapIndex], this->items[parentIndex]);
    this->Heapify(swapIndex, heapSize);
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
    // Start with the heap size - 1, because the last element is already sorted from the BuildMaxHeap
    for (int heapSize = this->items.size() - 1; heapSize >= 0; --heapSize)
    {
        // Set the biggest element at the end, after the current end
        std::swap(this->items[topIndex], this->items[heapSize]);

        // Heapify only the part without the last sorted elements
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



