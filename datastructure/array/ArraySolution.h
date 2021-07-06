//
// Created by aolei.bao on 7/6/2021.
//

#ifndef LEARNCPP_ALGORITHM_ARRAYSOLUTION_H
#define LEARNCPP_ALGORITHM_ARRAYSOLUTION_H
#include <vector>
#include <unordered_map>
using namespace std;

class ArraySolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    //https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
};


#endif //LEARNCPP_ALGORITHM_ARRAYSOLUTION_H
