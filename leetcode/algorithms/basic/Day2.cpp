//
// Created by 包傲磊 on 2023/1/15.
//

#include "Day2.h"

int Day2::findMin(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    int minVal = INT_MAX;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if (nums[mid] >= nums[left]){
            if (minVal > nums[left])
                minVal = nums[left];
            left = mid + 1;
        }else{
            right = mid;
            if (minVal > nums[mid])
                minVal = nums[mid];
        }
    }
    return minVal;
}

int Day2::findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if (nums[mid] > nums[mid + 1]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}
