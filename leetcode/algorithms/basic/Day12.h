//
// Created by 包傲磊 on 2023/1/25.
//

#ifndef LEARNCPP_ALGORITHM_DAY12_H
#define LEARNCPP_ALGORITHM_DAY12_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int robHelper(vector<int> &nums, int startIndex, int endIndex){
    int prev = 0, curr = 0;
    for (int i = startIndex; i <= endIndex ; ++i) {
        int temp = max(prev + nums[i], curr);
        prev = curr;
        curr = temp;
    }
    return curr;
}

int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    else if (n == 2) return max(nums[0], nums[1]);
    return max(robHelper(nums, 0, n-2), robHelper(nums, 1, n-1));
}

bool canJump(vector<int>& nums) {
    int n = nums.size() - 1;
    int rightMost = nums[0];
    for (int i = 1; i < n; ++i) {
        if (i > rightMost){
            return false;
        }
        rightMost = max(nums[i] + i, rightMost);
        if (rightMost >= n - 1){
            return true;
        }
    }
    return true;
}

#endif //LEARNCPP_ALGORITHM_DAY12_H
