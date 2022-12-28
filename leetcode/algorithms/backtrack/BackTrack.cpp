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
    subsetsHelper(0, nums, curPath, res);
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

vector<vector<int>> BackTrack::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> curPath;
    sort(nums.begin(), nums.end());
    bool *visited = new bool[nums.size()];
    for (int i = 0; i < nums.size(); ++i) {
        visited[i] = false;
    }
    subsetsWithDupHelper(0, nums, visited, curPath, res);
    return res;
}

void BackTrack::subsetsWithDupHelper(int startIndex, vector<int> &nums, bool *visited, vector<int> &curPath,
                                     vector<vector<int>> &res) {
    res.push_back(vector<int>(curPath));
    for (int i = startIndex; i < nums.size(); ++i) {
        if (i > 0 && nums.at(i) == nums.at(i - 1) && !visited[i - 1]) {
            continue;
        }
        curPath.push_back(nums.at(i));
        visited[i] = true;
        subsetsWithDupHelper(i + 1, nums, visited, curPath, res);
        curPath.pop_back();
        visited[i] = false;
    }
}

void BackTrack::combinationSumHelper(int startIndex, vector<int> &candidates, int curSum, int targetSum,
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

vector<vector<int>> BackTrack::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> curPath;
    sort(candidates.begin(), candidates.end());
    combinationSumHelper(0, candidates, 0, target, curPath, res);
    return res;
}

vector<vector<int>> BackTrack::combinationSum2(vector<int> &candidates, int target) {
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

void BackTrack::combinationSum2Helper(int startIndex, bool *visited, vector<int> &candidates, int curSum, int targetSum,
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
