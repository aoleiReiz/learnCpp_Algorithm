//
// Created by aolei.bao on 1/10/2023.
//

#include "RadixSort.h"

int RadixSort::myPow(int base, int exponent) {
    int result = 1;
    for (int i = 1; i <= exponent; ++i) {
        result *= base;
    }
    return result;
}

void RadixSort::countingSort(vector<int> &array, int digit) {
    vector<int> sortedArray(array.size(), 0);
    vector<int> countArray(10, 0);

    int digitColumn = myPow(10, digit);
    for (auto num : array){
        int countIndex = (num / digitColumn) % 10;
        countArray[countIndex] ++;
    }

    for (int i = 1; i < 10; ++i) {
        countArray[i] += countArray[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; --i) {
        int countIndex = (array[i] / digitColumn) % 10;
        countArray[countIndex] --;
        int sortedIndex = countArray[countIndex];
        sortedArray[sortedIndex] = array[i];
    }

    for (int i = 0; i < array.size(); ++i) {
        array[i] = sortedArray[i];
    }
}

vector<int> RadixSort::radixSort(vector<int> array) {
    if (array.size() == 0){
        return array;
    }
    int maxNumber = INT_MIN;
    for (auto num : array){
        if (num > maxNumber){
            maxNumber = num;
        }
    }
    int digit = 0;
    while (maxNumber / myPow(10, digit) > 0){
        countingSort(array, digit);
        digit ++;
    }
    return array;
}

int RadixSort::maximumGap(vector<int> &nums) {
    if (nums.size() < 2){
        return 0;
    }
    int maxNumber = INT_MIN;
    for (auto num : nums){
        if (num > maxNumber){
            maxNumber = num;
        }
    }
    int digit = 0;
    while (maxNumber / myPow(10, digit) > 0){
        countingSort(nums, digit);
        digit ++;
    }
    int maxDifference = 0;
    for (int i = 0; i < nums.size() -1; ++i) {
        int diff = nums[i + 1] - nums[i];
        if (diff > maxDifference){
            maxDifference = diff;
        }
    }
    return maxDifference;
}

int RadixSort::arrayPairSum(vector<int> &nums) {
    int maxNumber = INT_MIN;
    for (auto num : nums){
        if (num > maxNumber){
            maxNumber = num;
        }
    }
    int digit = 0;
    while (maxNumber / myPow(10, digit) > 0){
        countingSort(nums, digit);
        digit ++;
    }
    int sum = 0;
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}
