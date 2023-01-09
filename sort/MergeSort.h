//
// Created by 包傲磊 on 2023/1/8.
//

#ifndef LEARNCPP_ALGORITHM_MERGESORT_H
#define LEARNCPP_ALGORITHM_MERGESORT_H
#include <vector>

using namespace std;

class MergeSort {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n);

    int reversePairs(vector<int>& nums);

    int _mergeSort(vector<int> &nums, int left, int right);

    int _merge(vector<int> &nums, int left, int right, int mid);

};


#endif //LEARNCPP_ALGORITHM_MERGESORT_H
