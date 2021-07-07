//
// Created by aolei.bao on 7/7/2021.
//

#ifndef LEARNCPP_ALGORITHM_DPDAY3_H
#define LEARNCPP_ALGORITHM_DPDAY3_H
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class DpDay3 {
    //https://leetcode-cn.com/problems/house-robber/
    int rob(vector<int>& nums);
    //https://leetcode-cn.com/problems/house-robber-ii/
    int rob2(vector<int>& nums);
    //https://leetcode-cn.com/problems/delete-and-earn/
    int rob2Helper(vector<int>& nums, int left, int right);
    //https://leetcode-cn.com/problems/delete-and-earn/submissions/
    int deleteAndEarn(vector<int>& nums);
};


#endif //LEARNCPP_ALGORITHM_DPDAY3_H
