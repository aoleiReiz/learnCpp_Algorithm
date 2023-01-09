//
// Created by 包傲磊 on 2023/1/8.
//

#ifndef LEARNCPP_ALGORITHM_QUICKSORT_H
#define LEARNCPP_ALGORITHM_QUICKSORT_H
#include <vector>
#include <iostream>

using namespace std;

struct PartitionedNode{
    int leftPosition;
    int rightPosition;
    PartitionedNode(int l, int r){
        leftPosition = l;
        rightPosition = r;
    }
};

class QuickSort {
public:
    vector<int> sortArray(vector<int>& nums);

    void _sortArray(vector<int>& nums, int left, int right);

    PartitionedNode partition(vector<int>& nums, int left, int right);

    void swap(vector<int>& nums, int i, int j);

};


#endif //LEARNCPP_ALGORITHM_QUICKSORT_H
