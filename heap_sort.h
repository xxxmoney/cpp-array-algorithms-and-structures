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
    void BuildMaxHeap();
    void Heapify(int parentIndex, int heapSize);

public:
    HeapSort(std::vector<int>& items);
    ~HeapSort();

    std::vector<int>& Sort();

    void Print();

};



#endif //HEAP_SORT_H
