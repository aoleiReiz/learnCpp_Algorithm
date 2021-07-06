//
// Created by aolei.bao on 7/5/2021.
//

#include "AlgorithmsBasic.h"
#include <vector>
#include <algorithm>
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

vector<int> AlgorithmsBasic::sortedSquares(vector<int> &nums) {
    vector<int>res;
    for(int &i : nums){
        res.push_back( i * i);
    }
    sort(res.begin(), res.end());
    return res;
}

void AlgorithmsBasic::rotate(vector<int> &nums, int k) {
    int n = nums.size();
    if (n <= 1){
        return;
    }
    k = k % n;
    reverseArray(nums, 0, n-1);
    reverseArray(nums, 0, k-1);
    reverseArray(nums, k, n-1);

}

void AlgorithmsBasic::reverseArray(vector<int> &arr, int left, int right) {
    while (left <= right){
        int temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
        left ++;
        right --;
    }
}
