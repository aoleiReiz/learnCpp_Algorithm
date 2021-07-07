//
// Created by aolei.bao on 7/7/2021.
//

#include "DpDay3.h"

int DpDay3::rob(vector<int> &nums) {
    int prev = 0, curr = 0;
    for (int &i : nums) {
        int temp = max(prev + i, curr);
        prev = curr;
        curr = temp;
    }
    return curr;
}

int DpDay3::rob2(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    else if (n == 2) return max(nums[0], nums[1]);
    return max(rob2Helper(nums, 0, n-2), rob2Helper(nums, 1, n-1));
}

int DpDay3::rob2Helper(vector<int> &nums, int left, int right) {
    int prev = 0, curr = 0;
    for (int i = left; i<= right; i++) {
        int temp = max(prev + nums[i], curr);
        prev = curr;
        curr = temp;
    }
    return curr;
}

int DpDay3::deleteAndEarn(vector<int> &nums) {
    int maxVal = 0;
    for (int val : nums) {
        maxVal = max(maxVal, val);
    }
    vector<int> sum(maxVal + 1);
    for (int val : nums) {
        sum[val] += val;
    }
    return rob(sum);
}
