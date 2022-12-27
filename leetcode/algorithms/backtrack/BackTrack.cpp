//
// Created by aolei.bao on 12/27/2022.
//

#include "BackTrack.h"


vector<vector<int>> BackTrack::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> curPath;
    combineHelper(1, n, k, curPath, res);
    return res;
}

void BackTrack::combineHelper(int startNumber, int n, int k, vector<int> &curPath, vector<vector<int>> &res) {
    if (curPath.size() == k) {
        res.push_back(vector<int>{curPath});
        return;
    }

    if (curPath.size() + n - startNumber + 1 < k) {
        return;
    }

    for (int i = startNumber; i <= n; ++i) {
        curPath.push_back(i);
        combineHelper(i + 1, n, k, curPath, res);
        curPath.pop_back();
    }
}

vector<vector<int>> BackTrack::subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> curPath;
    subsetsHelper(0,nums, curPath, res);
    return res;
}

void BackTrack::subsetsHelper(int startIndex, vector<int> &nums, vector<int> &curPath, vector<vector<int>> &res) {
    res.push_back(vector<int>(curPath));
    for (int i = startIndex; i < nums.size(); ++i) {
        curPath.push_back(nums.at(i));
        subsetsHelper(i + 1, nums, curPath, res);
        curPath.pop_back();
    }
}
