//
// Created by aolei.bao on 7/6/2021.
//

#include "ArraySolution.h"

void ArraySolution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> aux;
    int i = 0, j = 0;
    while (i < m && j < n){
        if (nums1[i] <= nums2[j]){
            aux.push_back(nums1[i]);
            i ++;
        }else{
            aux.push_back(nums2[j]);
            j ++;
        }
    }
    while (i < m){
        aux.push_back(nums1[i]);
        i ++;
    }
    while (j < n){
        aux.push_back(nums2[j]);
        j ++;
    }
    for (int k = 0; k < m+n; ++k) {
        nums1[k] = aux[k];
    }
}

vector<int> ArraySolution::intersect(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> counter;
    for(int &i : nums1){
        if (counter.count(i) > 0){
            counter[i] ++;
        }else{
            counter[i] = 1;
        }
    }
    vector<int>res;
    for(int &i : nums2){
        if (counter.count(i) > 0){
            if (counter[i] > 0){
                res.push_back(i);
                counter[i] --;
            }
        }
    }

    return res;
}
