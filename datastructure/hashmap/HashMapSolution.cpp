//
// Created by Acer on 6/28/2021.
//

#include "HashMapSolution.h"
#include <unordered_set>
#include <vector>

using namespace  std;

bool HashMapSolution::containsDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    for (int &i : nums){
        if (set.count(i) > 0){
            return true;
        }else{
            set.insert(i);
        }
    }
    return false;
}

int HashMapSolution::singleNumber(vector<int> &nums) {
    int n = 0;
    for(int &i : nums){
        n ^= i;
    }
    return n;
}

vector<int> HashMapSolution::intersection(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    unordered_set<int> temp;
    unordered_set<int>set;
    set.insert(nums1.begin(), nums1.end());
    for (int &i : nums2){
        if (set.count(i) > 0 && temp.count(i) == 0){
            res.push_back(i);
            temp.insert(i);
        }
    }
    return res;
}

bool HashMapSolution::isHappy(int n) {
    unordered_set<int> memo;
    while (n > 0){
        if (memo.count(n) > 0){
            return false;
        }
        memo.insert(n);
        int res = 0;
        while (n > 0){
            int rem = n % 10;
            res += rem * rem;
            n = n / 10;
        }
        if (res == 1){
            return true;
        }
        n = res;
    }
    return false;
}
