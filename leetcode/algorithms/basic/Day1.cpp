//
// Created by 包傲磊 on 2023/1/14.
//

#include "Day1.h"

vector<int> Day1::searchRange(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int leftRange = -1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums.at(mid) == target) {
            leftRange = mid;
            right = mid - 1;
        } else if (nums.at(mid) < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = 0, right = nums.size() - 1;
    int rightRange = -1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums.at(mid) == target) {
            rightRange = mid;
            left = mid + 1;
        } else if (nums.at(mid) < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return vector<int>({leftRange, rightRange});
}

int Day1::search(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (nums.at(mid) == target) {
            return mid;
        } else{
            if(nums.at(mid) >= nums[left]){
                if (nums[mid] >= target && nums.at(left) <= target){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }else{
                if (nums.at(mid) < target && nums.at(right) >= target){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
    }
    return -1;
}

bool Day1::searchMatrix(vector<vector<int>> &matrix, int target) {
    int r = matrix.size() - 1;
    int c = 0;
    while (r >= 0 && c < matrix.at(0).size()){
        if (matrix.at(r).at(c) == target){
            return true;
        } else if(matrix.at(r).at(c) > target){
            r --;
        }else{
            c ++;
        }
    }
    return false;
}
