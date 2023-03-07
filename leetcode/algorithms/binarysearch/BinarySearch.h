//
// Created by 包傲磊 on 2023/3/7.
//

#ifndef LEARNCPP_ALGORITHM_BINARYSEARCH_H
#define LEARNCPP_ALGORITHM_BINARYSEARCH_H

#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
private:
    int searchFirstPosition(vector<int>& nums, int target);
    int searchLastPosition(vector<int>& nums, int target);
public:
    int search(vector<int> &nums, int target);
    int searchInsert(vector<int>& nums, int target);
    vector<int> searchRange(vector<int>& nums, int target);
};


#endif //LEARNCPP_ALGORITHM_BINARYSEARCH_H
