//
// Created by SuperUser on 01.06.2024.
//

#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <vector>


class HeapSort {
private:
    std::vector<int> items;
    HeapSort();
    // Builds max heap so that the largest element is at the top
    void BuildMaxHeap();
    // Builds only the heap of given size for the given parent index
    // Elements aftet the current end are ordered
    void Heapify(int parentIndex, int heapSize);

public:
    HeapSort(std::vector<int>& items);
    ~HeapSort();

    std::vector<int>& Sort();

    void Print();

};



#endif //HEAP_SORT_H
