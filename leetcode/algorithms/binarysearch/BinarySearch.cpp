//
// Created by 包傲磊 on 2023/3/7.
//

#include "BinarySearch.h"

int BinarySearch::search(vector<int> &nums, int target) {
    int left =0, right = nums.size() - 1;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}
