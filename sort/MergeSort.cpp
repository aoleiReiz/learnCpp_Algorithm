//
// Created by 包傲磊 on 2023/1/8.
//

#include "MergeSort.h"

void MergeSort::merge(vector<int> &A, int m, vector<int> &B, int n) {
    int k = m + n - 1;
    int aIdx = m - 1,  bIdx = n - 1;
    while (aIdx >= 0 || bIdx >= 0){
        if (aIdx >= 0  && bIdx >= 0){
            if (A[aIdx] >= B[bIdx]){
                A[k] = A[aIdx];
                aIdx --;
            }else{
                A[k] = B[bIdx];
                bIdx --;
            }
        }else if (aIdx >= 0){
            A[k] = A[aIdx];
            aIdx --;
        }else{
            A[k] = B[bIdx];
            bIdx --;
        }
        k --;
    }
}

int MergeSort::reversePairs(vector<int> &nums) {
    return _mergeSort(nums, 0, nums.size() - 1);
}

int MergeSort::_mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right){
        return 0;
    }
    int mid = (right - left) / 2 + left;
    int leftPairs = _mergeSort(nums, left, mid);
    int rightPairs = _mergeSort(nums, mid + 1, right);
    int curPairs = _merge(nums, left, right, mid);
    return leftPairs + rightPairs + curPairs;
}

int MergeSort::_merge(vector<int> &nums, int left, int right, int mid) {
    vector<int> aux(nums.begin()+ left, nums.begin() + right + 1);
    int i = left, j = mid + 1, count = 0;
    int k = left;
    while (i <= mid || j <= right){
        if (i > mid){
            nums[k++] = aux[j - left];
            j++;
        }else if (j > right){
            nums[k ++] = aux[i - left];
            i++;
        }else if (aux[i-left] <= aux[j - left]){
            nums[k++] = aux[i - left];
            i++;
        }else{
            nums[k++] = aux[j - left];
            count += mid - i + 1;
            j++;
        }
    }
    return count;
}
