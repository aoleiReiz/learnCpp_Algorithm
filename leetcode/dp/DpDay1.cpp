//
// Created by aolei.bao on 7/5/2021.
//

#include "DpDay1.h"

int DpDay1::fib(int n) {
    if(n <= 1){
        return n;
    }
    int prev = 0, cur = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = prev + cur;
        prev = cur;
        cur = temp;
    }
    return cur;
}

int DpDay1::tribonacci(int n) {
    if(n == 0){
        return 1;
    }
    if(n <= 2){
        return 1;
    }
    int first = 0, second = 1, third = 1;
    for (int i = 3; i <= n; ++i) {
        int temp1 = first + second + third;
        first = second;
        second = third;
        third = temp1;
    }
    return third;
}

int DpDay1::maxSubArray(vector<int> &nums) {
    int maxSum = -100000000;
    int dpPrev = -100000000;
    for (int &i : nums) {
        dpPrev = (dpPrev + i) > i ? dpPrev + i : i;
        if (dpPrev > maxSum){
            maxSum = dpPrev;
        }
    }
    return maxSum;
}
