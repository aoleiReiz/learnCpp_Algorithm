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

int ArraySolution::maxProfit(vector<int> &prices) {
    int curMin = INT_MAX;
    int ret = -1000000;
    for (int i : prices) {
        if (i - curMin > ret){
            ret = i - curMin;
        }
        if (i < curMin){
            curMin = i;
        }
    }

    return ret;
}

vector<vector<int>> ArraySolution::matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size();
    int n = mat[0].size();
    if (m * n != r * c) return mat;

    vector<vector<int>> ans(r, vector<int>(c));
    for (int i = 0; i < m * n; i++) {
        ans[i / c][i % c] = mat[i / n][i % n];
    }
    return ans;
}

vector<vector<int>> ArraySolution::generate(int numRows) {
    vector<vector<int>>res;
    for (int i = 1; i <= numRows; ++i) {
        if (i == 1){
            res.push_back(vector<int>({1}));
        }else{
            vector<int> prevRow = res[i - 2];
            vector<int> row;
            for (int j = 0; j < i; ++j) {
                if (j == 0 || j == i - 1){
                    row.push_back(1);
                }else{
                    row.push_back(prevRow[j] + prevRow[j-1]);
                }
            }
            res.push_back(row);
        }
    }
    return res;
}
