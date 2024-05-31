//
// Created by SuperUser on 30.05.2024.
//

#include "quick_sort.h"

#include <algorithm>
#include <iostream>

QuickSort::QuickSort(std::vector<int>& items)
{
    this->items = items;
}

void QuickSort::Sort(int left, int right)
{
    if(left >= right)
        return;

    int pivotIndex = right;
    int pivotValue = this->items[pivotIndex];
    int swapIndex = left - 1;

    for (int currentIndex = left; currentIndex <= pivotIndex - 1; currentIndex++)
    {
        if (this->items[currentIndex] < pivotValue)
        {
            std::swap(this->items[++swapIndex], this->items[currentIndex]);
        }
    }

    std::swap(this->items[swapIndex + 1], this->items[pivotIndex]);
    pivotIndex = swapIndex + 1;

    this->Sort(left, pivotIndex - 1);
    this->Sort(pivotIndex + 1, right);
}

std::vector<int>& QuickSort::Sort()
{
    this->Sort(0, this->items.size() - 1);
    return this->items;
}

void QuickSort::Print()
{
    for (auto item : this->items)
    {
        std::cout << item << "\t";
    }
    std::cout << std::endl;
}


