//
// Created by aolei.bao on 1/9/2023.
//

#include "Easy11To15.h"

int Easy11To15::binarySearch(vector<int> array, int target) {
    int left = 0;
    int right = array.size() - 1;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if (array[mid] == target){
            return mid;
        }else if (array[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

vector<int> Easy11To15::findThreeLargestNumbers(vector<int> array) {
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;
    for (auto num : array){
        if (num > first){
            third = second;
            second = first;
            first = num;
        }else if (num > second){
            third = second;
            second = num;
        }else if (num > third){
            third = num;
        }
    }
    return vector<int>({third, second, first});
}

vector<int> Easy11To15::bubbleSort(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        int flag = false;
        for (int j = n - 2; j >= 0 ; --j) {
            if (array[j + 1] < array[j]){
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                flag = true;
            }
        }
        if (!flag){
            break;
        }
    }

    return array;
}

vector<int> Easy11To15::insertionSort(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        int e = array[i];
        int j = i;
        for (; j > 0 && array[j-1] > e ; --j) {
            array[j] = array[j-1];
        }
        array[j] = e;
    }
    return array;
}

vector<int> Easy11To15::selectionSort(vector<int> array) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        int minIdx = i;
        int minEle = array[i];
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < minEle){
                minIdx = j;
                minEle = array[j];
            }
        }
        array[minIdx] = array[i];
        array[i] = minEle;
    }
    return array;
}
