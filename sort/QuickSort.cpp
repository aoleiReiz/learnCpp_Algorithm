//
// Created by 包傲磊 on 2023/1/8.
//

#include "QuickSort.h"

vector<int> QuickSort::sortArray(vector<int> &nums) {
    _sortArray(nums, 0, nums.size() - 1);
    return nums;
}

void QuickSort::_sortArray(vector<int> &nums, int left, int right) {
    if (left >= right){
        return;
    }
    PartitionedNode partitionedNode = partition(nums, left, right);
    _sortArray(nums, left, partitionedNode.leftPosition - 1);
    _sortArray(nums, partitionedNode.rightPosition + 1, right);
}

PartitionedNode QuickSort::partition(vector<int> &nums, int left, int right) {
    int pivot_index = rand() % (right - left + 1) + left;
    swap(nums, pivot_index, left);
    int e = nums[left];
    int k = left - 1, i = left, j = right;
    while (i <= j){
        if (nums[i] < e){
            k ++;
            swap(nums, i, k);
            i ++;
        }else if (nums[i] == e){
            i ++;
        }else{
            swap(nums, i, j);
            j--;
        }
    }
    return PartitionedNode(k + 1, j);
}

void QuickSort::swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
