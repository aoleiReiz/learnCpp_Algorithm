//
// Created by aolei.bao on 7/5/2021.
//

#ifndef LEARNCPP_ALGORITHM_DPDAY1_H
#define LEARNCPP_ALGORITHM_DPDAY1_H
#include <vector>

using namespace std;

class DpDay1 {
public:
    //https://leetcode-cn.com/problems/fibonacci-number/
    int fib(int n);

    //https://leetcode-cn.com/problems/n-th-tribonacci-number/
    int tribonacci(int n);

    int maxSubArray(vector<int>& nums);
};


#endif //LEARNCPP_ALGORITHM_DPDAY1_H
