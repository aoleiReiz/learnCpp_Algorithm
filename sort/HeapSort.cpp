//
// Created by aolei.bao on 1/6/2023.
//

#include "HeapSort.h"

int HeapSort::leftChild(int parentIdx) {
    return 2 * parentIdx + 1;
}

int HeapSort::rightChild(int parentIdx) {
    return 2 * parentIdx + 2;
}

int HeapSort::parent(int childIdx) {
    return (childIdx - 1) / 2;
}

void HeapSort::swap(vector<int> &array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void HeapSort::siftDown(vector<int> &array, int currentIdx) {
    while (currentIdx < array.size()){
        int leftChildIdx = leftChild(currentIdx);
        if (leftChildIdx + 1 < array.size() && array[leftChildIdx] > array[leftChildIdx + 1]){
            leftChildIdx += 1;
        }
        if (leftChildIdx < array.size() && array[leftChildIdx] < array[currentIdx]){
            swap(array, leftChildIdx, currentIdx);
            currentIdx = leftChildIdx;
        }else{
            break;
        }
    }
}

void HeapSort::siftUp(vector<int> &array, int currentIdx) {
    while (currentIdx > 0){
        int parentIdX = parent(currentIdx);
        if (array[parentIdX] > array[currentIdx]){
            swap(array, currentIdx, parentIdX);
            currentIdx = parentIdX;
        }else{
            break;
        }
    }
}

void HeapSort::heapify(vector<int> &array) {
    int lastParentIdx = parent(array.size() - 1);
    for (int i = lastParentIdx; i >= 0 ; --i) {
        siftDown(array, i);
    }
}

void HeapSort::insert(int val, vector<int> &array) {
    array.push_back(val);
    siftUp(array, array.size() - 1);
}

int HeapSort::findKthLargest(vector<int> &nums, int k) {
    vector<int> kLargest(nums.begin(), nums.begin() + k);
    heapify(kLargest);
    for (int i = k; i < nums.size(); ++i) {
        if (nums[i] > kLargest[0]){
            kLargest[0] = nums[i];
            siftDown(kLargest, 0);
        }
    }
    return kLargest[0];
}

vector<int> HeapSort::getLeastNumbers(vector<int> &arr, int k) {
    heapify(arr);
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        int e = pop(arr);
        res.push_back(e);
    }
    return res;
}

int HeapSort::pop(vector<int> &arr) {
    int valDeleted = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    siftDown(arr, 0);
    return valDeleted;
}
