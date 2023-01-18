//
// Created by 包傲磊 on 2023/1/19.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY6_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY6_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int lengthOfLastWord(string s) {
    int right = s.length() - 1;
    while (right >= 0 && isspace(s[right])) {
        right--;
    }
    int left = right;
    while (left >= 0 && !isspace(s[left])) {
        left--;
    }
    return right - left;
}

vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    vector<int> stack;
    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && temperatures[stack[stack.size() - 1]] < temperatures[i]) {
            int pop_idx = stack[stack.size() - 1];
            stack.pop_back();
            ans[pop_idx] = i - pop_idx;
        }
        stack.push_back(i);
    }
    return ans;
}

#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY6_H
