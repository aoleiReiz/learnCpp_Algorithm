//
// Created by Acer on 6/28/2021.
//

#ifndef LEARNCPP_ALGORITHM_HASHMAPSOLUTION_H
#define LEARNCPP_ALGORITHM_HASHMAPSOLUTION_H

#include <vector>

using namespace std;

class HashMapSolution {

public:
    bool containsDuplicate(vector<int>& nums);
    int singleNumber(vector<int>& nums) ;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    bool isHappy(int n);

    vector<int> twoSum(vector<int>& nums, int target);

    bool isIsomorphic(string s, string t);

    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
};


#endif //LEARNCPP_ALGORITHM_HASHMAPSOLUTION_H
