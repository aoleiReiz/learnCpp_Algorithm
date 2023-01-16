//
// Created by 包傲磊 on 2023/1/14.
//

#include "ProgrammingDay1.h"

bool ProgrammingDay1::isMonotonic(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2){
        return true;
    }
    bool flag = nums[n - 1] > nums[0];
    for (int i = 0; i < n - 1; ++i) {
        if (nums[i] == nums[i + 1]){
            continue;
        }
        if ((nums[i + 1] > nums[i]) != flag){
            return false;
        }
    }
    return true;
}

int ProgrammingDay1::strStr(string haystack, string needle) {
    int m = haystack.size();
    int n = needle.size();
    for (int i = 0; i + n <= m; ++i) {
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            if (haystack[i + j] != needle[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            return i;
        }
    }
    return -1;
}
