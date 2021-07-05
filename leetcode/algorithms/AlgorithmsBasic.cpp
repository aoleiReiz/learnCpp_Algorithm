//
// Created by aolei.bao on 7/5/2021.
//

#include "AlgorithmsBasic.h"
#include <vector>
using namespace std;


int AlgorithmsBasic::search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size();
    while (left <= right){
        int mid = (right - left)/ 2 + left;
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int AlgorithmsBasic::searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right){
        int mid = (right - left)/ 2 + left;
        if (nums[mid] == target){
            return mid;
        }else if (nums[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return left;
}
