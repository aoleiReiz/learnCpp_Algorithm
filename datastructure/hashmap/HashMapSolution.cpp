//
// Created by Acer on 6/28/2021.
//

#include "HashMapSolution.h"
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>

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

<<<<<<< HEAD
bool HashMapSolution::containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); ++i) {
        if (set.count(nums[i]) > 0){
            return true;
        }
        set.insert(nums[i]);
        if (set.size() > k){
            set.erase(nums[i-k]);
        }
    }

    return false;
=======
vector<int> HashMapSolution::twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int temp = target - nums[i];
        if (map.count(temp) == 0){
            map.insert(make_pair(nums[i], i));
        }else{
            vector<int>res = {i, map.at(temp)};
            return res;
        }
    }

    return vector<int>();
}

bool HashMapSolution::isIsomorphic(string s, string t) {
    if (s.size() != t.size())
        return false;
    unordered_map<char, char> map;
    unordered_map<char, char> reverseMap;
    int i = 0, j = 0;
    while (i < s.size()){
        if (map.count(s[i]) == 0){
            if (reverseMap.count(t[j]) > 0){
                return false;
            }
            map.insert(make_pair(s[i], t[j]));
            reverseMap.insert(make_pair(t[j], s[i]));
        }else{
            if (map.at(s[i]) != t[j]){
                return false;
            }
        }
        i++;
        j++;
    }
    return true;
}

vector<string> HashMapSolution::findRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string , int> charIndexMap;
    unordered_map<string , int> char2IndexSumMap;
    unordered_map<int, vector<string>> indexSum2CharMap;
    for (int i = 0; i < list1.size(); ++i) {
        charIndexMap.insert(make_pair(list1[i], i));
    }
    int minIndexSum = INT_MAX;
    for (int i = 0; i < list2.size(); ++i) {
        if (charIndexMap.count(list2[i]) > 0){
            int indexSum = i + charIndexMap.at(list2[i]);
            char2IndexSumMap.insert(make_pair(list2[i], indexSum));
            if (indexSum2CharMap.count(indexSum) == 0){
                vector<string> v = {list2[i]};
                indexSum2CharMap.insert(make_pair(indexSum, v));
            }else{
                indexSum2CharMap.at(indexSum).push_back(list2[i]);
            }
            if (indexSum <= minIndexSum){
                minIndexSum = indexSum;
            }
        }
    }
    return indexSum2CharMap.at(minIndexSum);
>>>>>>> origin/ac_local
}
