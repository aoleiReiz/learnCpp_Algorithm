//
// Created by aolei.bao on 1/9/2023.
//

#include "CountSort.h"

vector<int> CountSort::sortArray(vector<int> &nums) {
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    for (auto num : nums) {
        if (num > maxVal){
            maxVal = num;
        }
        if (num < minVal){
            minVal = num;
        }
    }
    vector<int> counting (maxVal - minVal + 1, 0);
    for (auto num :nums){
        counting[num - minVal] += 1;
    }
    int idx = 0;
    int countIdx = 0;
    for (auto count : counting){
        while (count > 0){
            nums[idx++] = countIdx + minVal;
            count --;
        }
        countIdx++;
    }
    return nums;
}

vector<int> CountSort::relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    int minVal1 = INT_MAX;
    int maxVal1 = INT_MIN;

    for (auto num : arr1) {
        if (num > maxVal1){
            maxVal1 = num;
        }
        if (num < minVal1){
            minVal1 = num;
        }
    }
    vector<int> counting1 (maxVal1 - minVal1 + 1, 0);
    for (auto num :arr1){
        counting1[num - minVal1] += 1;
    }

    int idx = 0;
    for (int i = 0; i < arr2.size(); ++i) {
        int count = counting1[arr2[i] - minVal1];
        while (count > 0){
            arr1[idx++] = arr2[i];
            count --;
        }
        counting1[arr2[i] - minVal1] = count;
    }
    int countIdx = 0;
    for (auto count : counting1){
        while (count > 0){
            arr1[idx++] = countIdx + minVal1;
            count --;
        }
        countIdx++;
    }
    return arr1;
}
