//
// Created by SuperUser on 30.05.2024.
//

#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>


class QuickSort {
private:
    std::vector<int> items;
    QuickSort();
    void Sort(int left, int right);

public:
    QuickSort(std::vector<int>& items);
    ~QuickSort();

    std::vector<int>& Sort();

    void Print();
};



#endif //QUICK_SORT_H
