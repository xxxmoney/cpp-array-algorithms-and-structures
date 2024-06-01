//
// Created by SuperUser on 31.05.2024.
//

#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <vector>


class MergeSort {
private:
    std::vector<int> items;
    MergeSort();
    void Merge(int temp[], int left, int right);
    void Sort(int temp[], int left, int right);

public:
    MergeSort(std::vector<int>& items);
    ~MergeSort();

    std::vector<int>& Sort();

    void Print();
};



#endif //MERGE_SORT_H
