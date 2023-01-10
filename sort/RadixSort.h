//
// Created by aolei.bao on 1/10/2023.
//

#ifndef LEARNCPP_ALGORITHM_RADIXSORT_H
#define LEARNCPP_ALGORITHM_RADIXSORT_H
#include <vector>
#include <iostream>

using namespace std;

class RadixSort {
public:
    int myPow(int base, int exponent);
    void countingSort(vector<int> &array, int digit);
    vector<int> radixSort(vector<int> array);

    int maximumGap(vector<int>& nums);

    int arrayPairSum(vector<int>& nums);

};


#endif //LEARNCPP_ALGORITHM_RADIXSORT_H
