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

int BinarySearch::searchInsert(vector<int> &nums, int target) {
    int left = 0, right = nums.size();
    while (left < right){
        int mid = (right - left) / 2 + left;
        if(nums[mid] >= target){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

vector<int> BinarySearch::searchRange(vector<int> &nums, int target) {
    int leftPos = searchFirstPosition(nums, target);
    if(leftPos == -1){
        return vector<int>({-1, -1});
    }
    int rightPos = searchLastPosition(nums, target);
    return vector<int>({leftPos, rightPos});
}

int BinarySearch::searchFirstPosition(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int pos = -1;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if(nums[mid] >= target){
            if(nums[mid] == target){
                pos = mid;
            }
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return pos;
}

int BinarySearch::searchLastPosition(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    int pos = -1;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if(nums[mid] <= target){
            if(nums[mid] == target){
                pos = mid;
            }
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return pos;
}
