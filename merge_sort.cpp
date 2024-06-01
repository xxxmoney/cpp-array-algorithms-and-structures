//
// Created by SuperUser on 31.05.2024.
//

#include "merge_sort.h"

#include <iostream>

MergeSort::MergeSort(std::vector<int>& items)
{
    this->items = items;
}

MergeSort::~MergeSort()
{
    this->items.clear();
}

void MergeSort::Merge(int temp[], int left, int right)
{
    int middleIndex = (left + right) / 2;
    int leftIndex = left;
    int rightIndex = middleIndex + 1;
    int tempIndex = left;

    while (leftIndex <= middleIndex && rightIndex <= right)
    {
        if(this->items[leftIndex] <= this->items[rightIndex])
            temp[tempIndex] = this->items[leftIndex++];
        else
            temp[tempIndex] = this->items[rightIndex++];

        tempIndex++;
    }

    while(leftIndex <= middleIndex)
        temp[tempIndex++] = this->items[leftIndex++];

    while(rightIndex <= right)
        temp[tempIndex++] = this->items[rightIndex++];
}

void MergeSort::Sort(int temp[], int left, int right)
{
    if(left == right)
        return;

    int middle = (left + right) / 2;
    this->Sort(temp, left, middle);
    this->Sort(temp, middle + 1, right);

    this->Merge(temp, left, right);
    for (int i = left; i <= right; ++i)
        this->items[i] = temp[i];
}


std::vector<int>& MergeSort::Sort()
{
    int temp[this->items.size()];
    std::fill_n(temp, this->items.size(), 0);

    this->Sort(temp, 0, this->items.size());

    return this->items;
}

void MergeSort::Print()
{
    for (auto item : this->items)
    {
        std::cout << item << "\t";
    }
    std::cout << std::endl;
}

