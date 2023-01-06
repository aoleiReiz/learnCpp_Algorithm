//
// Created by aolei.bao on 1/6/2023.
//

#ifndef LEARNCPP_ALGORITHM_HEAPSORT_H
#define LEARNCPP_ALGORITHM_HEAPSORT_H
#include <vector>

using namespace std;

class HeapSort {
private:
    int leftChild( int parentIdx);
    int rightChild(int parentIdx);
    int parent(int childIdx);
    void swap(vector<int> & array, int i, int j);
    void siftUp(vector<int> & array, int currentIdx);
    void siftDown(vector<int> & array, int currentIdx);
public:
    void heapify(vector<int> & array);
    void insert(int val, vector<int> & array);
    int findKthLargest(vector<int>& nums, int k);
    vector<int> getLeastNumbers(vector<int>& arr, int k);
    int pop(vector<int>& arr);
};


#endif //LEARNCPP_ALGORITHM_HEAPSORT_H
