//
// Created by 包傲磊 on 2023/1/14.
//

#ifndef LEARNCPP_ALGORITHM_DAY1_H
#define LEARNCPP_ALGORITHM_DAY1_H
#include <vector>
#include <iostream>

using namespace std;

class Day1 {
public:
    vector<int> searchRange(vector<int>& nums, int target);
    int search(vector<int>& nums, int target);
    bool searchMatrix(vector<vector<int>>& matrix, int target);
};


#endif //LEARNCPP_ALGORITHM_DAY1_H
