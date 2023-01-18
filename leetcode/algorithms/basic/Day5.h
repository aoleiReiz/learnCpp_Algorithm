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
};

vector<int> Day5::findAnagrams(string s, string p) {
    unordered_map<char, int> need;
    unordered_map<char, int>window;
    vector<int> res;
    for(auto c : need){
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

#endif //LEARNCPP_ALGORITHM_DAY5_H
