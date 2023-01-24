//
// Created by 包傲磊 on 2023/1/23.
//

#ifndef LEARNCPP_ALGORITHM_DAY10_H
#define LEARNCPP_ALGORITHM_DAY10_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> nextGreaterElements(vector<int> &nums) {
    int size = nums.size();
    stack<int> s;
    vector<int> ans(size, -1);
    s.push(0);
    for (int i = 0; i < 2 * size; ++i) {
        int idx = i % size;
        while (!s.empty() && nums[idx] > nums[s.top()]) {
            int top = s.top();
            s.pop();
            ans[top] = nums[idx];
        }
        s.push(idx);
    }
    return ans;
}

int nextGreaterElement(int n) {
    auto nums = to_string(n);
    int i = (int) nums.length() - 2;
    while (i >= 0 && nums[i] >= nums[i+1]){
        i --;
    }
    if (i < 0){
        return -1;
    }
    int j = nums.size() - 1;
    while (j >= 0 && nums[i] >= nums[j]){
        j--;
    }
    swap(nums[i], nums[j]);
    reverse(nums.begin()+ i + 1, nums.end());
    long ans = stol(nums);
    return ans > INT_MAX ? -1 : ans;
}


void permuteUniqueHelper(vector<int> &nums, vector<bool> &seen, vector<int> &curPath, vector<vector<int>> &ans) {
    if (curPath.size() == nums.size()) {
        ans.push_back(vector<int>(curPath.begin(), curPath.end()));
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (seen[i]) {
            continue;
        }
        if (i > 0 && nums[i] == nums[i - 1] && !seen[i - 1]) {
            continue;
        }
        seen[i] = true;
        curPath.push_back(nums[i]);
        permuteUniqueHelper(nums, seen, curPath, ans);
        seen[i] = false;
        curPath.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<bool> seen(nums.size(), false);
    vector<int> curPath;
    permuteUniqueHelper(nums, seen, curPath, ans);
    return ans;
}

void combinationSumHelper(int startIndex, vector<int> &candidates, int curSum, int targetSum,
                          vector<int> &curPath,
                          vector<vector<int>> &res) {
    if (curSum == targetSum) {
        res.push_back(vector<int>(curPath));
        return;
    }
    for (int i = startIndex; i < candidates.size(); ++i) {
        if (curSum + candidates[i] > targetSum) {
            continue;
        }
        curPath.push_back(candidates[i]);
        combinationSumHelper(i, candidates, curSum + candidates[i], targetSum, curPath, res);
        curPath.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> curPath;
    sort(candidates.begin(), candidates.end());
    combinationSumHelper(0, candidates, 0, target, curPath, res);
    return res;
}

void combinationSum2Helper(int startIndex, bool *visited, vector<int> &candidates, int curSum, int targetSum,
                           vector<int> &curPath, vector<vector<int>> &res);

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> curPath;
    bool *visited = new bool[candidates.size()];
    for (int i = 0; i < candidates.size(); ++i) {
        visited[i] = false;
    }
    sort(candidates.begin(), candidates.end());
    combinationSum2Helper(0, visited, candidates, 0, target, curPath, res);
    return res;
}

void combinationSum2Helper(int startIndex, bool *visited, vector<int> &candidates, int curSum, int targetSum,
                           vector<int> &curPath, vector<vector<int>> &res) {
    if (curSum == targetSum) {
        res.push_back(vector<int>(curPath));
        return;
    }
    for (int i = startIndex; i < candidates.size(); ++i) {
        if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
            continue;
        }
        if (curSum + candidates[i] > targetSum) {
            continue;
        }
        visited[i] = true;
        curPath.push_back(candidates[i]);
        combinationSum2Helper(i + 1, visited, candidates, curSum + candidates[i], targetSum, curPath, res);
        curPath.pop_back();
        visited[i] = false;
    }
}

#endif //LEARNCPP_ALGORITHM_DAY10_H
