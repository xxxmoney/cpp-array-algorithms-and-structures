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

public:
    QuickSort(std::vector<int>& items);
    void Sort(int left, int right);

    std::vector<int>& Sort();

    void Print();
};



#endif //QUICK_SORT_H
