//
// Created by aolei.bao on 7/8/2021.
//

#include "DpDay4.h"

bool DpDay4::canJump(vector<int> &nums) {
    int maxRight = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > maxRight){
            return false;
        }
        maxRight = i + nums[i] > maxRight ?  i + nums[i] : maxRight;
        if (maxRight>= nums.size() - 1){
            return true;
        }
    }
    return false;
}

int DpDay4::jump(vector<int> &nums) {
    int maxRight = 0;
    int steps = 0;
    int end = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        maxRight = i + nums[i] > maxRight ?  i + nums[i] : maxRight;
        if(i == end){
            end = maxRight;
            steps ++;
        }
    }
    return steps;
}
