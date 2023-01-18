//
// Created by 包傲磊 on 2023/1/18.
//

#ifndef LEARNCPP_ALGORITHM_DAY5_H
#define LEARNCPP_ALGORITHM_DAY5_H
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Day5{
public:
    vector<int> findAnagrams(string s, string p);
    int numSubarrayProductLessThanK(vector<int>& nums, int k);
    int minSubArrayLen(int target, vector<int>& nums);
};

vector<int> Day5::findAnagrams(string s, string p) {
    unordered_map<char, int> need;
    unordered_map<char, int>window;
    vector<int> res;
    for(auto c : p){
        need[c]++;
    }
    int left = 0, right = 0, valid = 0;
    while (right < s.size()){
        char c = s[right];
        if (need.find(c) != need.end()) {
            window[c]++;
            if (window[c] == need[c]) {
                valid++;
            }
        }
        right ++;
        while (right - left >= p.size()){
            if (need.size() == valid){
                res.push_back(left);
            }
            char c = s[left];
            if (need.find(c) != need.end()){
                if (window[c] == need[c]){
                    valid --;
                }
                window[c] --;
            }
        }
    }
    return res;
}

int Day5::numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int left =0, right= 0, cur = 1, count = 0;
    while (right < nums.size()){
        cur *= nums[right];
        while (cur >=k && right >= left && right < nums.size()){
            cur /= nums[left];
            left += 1;
        }
        count += right - left + 1;
        right += 1;
    }
    return count;
}

int Day5::minSubArrayLen(int target, vector<int> &nums) {
    int minLength = INT_MAX;
    int left = 0, right = 0, curSum = 0;
    while (right < nums.size()){
        curSum += nums[right];
        right++;
        while (curSum >= target){
            minLength = min(minLength, right - left + 1);
            curSum -= nums[left];
            left ++;
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}

#endif //LEARNCPP_ALGORITHM_DAY5_H
