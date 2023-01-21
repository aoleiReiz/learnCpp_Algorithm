//
// Created by 包傲磊 on 2023/1/22.
//

#ifndef LEARNCPP_ALGORITHM_DAY9_H
#define LEARNCPP_ALGORITHM_DAY9_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void subsetsHelper(int startIndex, vector<int> &nums, vector<int> &curPath, vector<vector<int>> &res) {
    res.push_back(vector<int>(curPath));
    for (int i = startIndex; i < nums.size(); ++i) {
        curPath.push_back(nums.at(i));
        subsetsHelper(i + 1, nums, curPath, res);
        curPath.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> curPath;
    subsetsHelper(0, nums, curPath, res);
    return res;
}

void subsetsWithDupHelper(int startIndex, vector<int> &nums, bool *visited, vector<int> &curPath,
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

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
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


#endif //LEARNCPP_ALGORITHM_DAY9_H
