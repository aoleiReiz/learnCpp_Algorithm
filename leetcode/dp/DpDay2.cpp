//
// Created by aolei.bao on 7/6/2021.
//

#include "DpDay2.h"


int DpDay2::climbStairs(int n) {
    if (n <= 2){
        return n;
    }
    int prev = 1, cur = 2;
    for (int i = 3; i <= n; ++i) {
        int temp = prev + cur;
        prev = cur;
        cur = temp;
    }
    return cur;
}

int DpDay2::minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    int prev =0, curr = 0;
    for (int i = 2; i <= n; ++i) {
        int next = min(curr + cost[i-1], prev + cost[i-2]);
        prev = curr;
        curr = next;
    }
    return curr;
}
