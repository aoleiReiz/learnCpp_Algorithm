//
// Created by aolei.bao on 1/9/2023.
//

#ifndef LEARNCPP_ALGORITHM_COUNTSORT_H
#define LEARNCPP_ALGORITHM_COUNTSORT_H
#include <vector>
#include <iostream>

using namespace std;

class CountSort {
public:

    vector<int> sortArray(vector<int>& nums);
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2);
};


#endif //LEARNCPP_ALGORITHM_COUNTSORT_H
