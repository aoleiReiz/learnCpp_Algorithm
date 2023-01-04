//
// Created by 包傲磊 on 2023/1/4.
//

#include "SelectionSort.h"

int SelectionSort::findKthLargest(vector<int> &nums, int k) {
    for (int i = 0; i < k; ++i) {
        int e = nums.at(i);
        int maxIdx = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums.at(j) > nums.at(maxIdx)){
                maxIdx = j;
            }
        }
        nums.at(i) = nums.at(maxIdx);
        nums.at(maxIdx) = e;
    }
    return nums.at(k - 1);
}
