//
// Created by aolei.bao on 1/10/2023.
//

#include "SortLC.h"

int SortLC::smallestRangeI(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    return (nums[nums.size() - 1] - 2* k - nums[0]);
}
