//
// Created by aolei.bao on 12/27/2022.
//

#ifndef LEARNCPP_ALGORITHM_BACKTRACK_H
#define LEARNCPP_ALGORITHM_BACKTRACK_H
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class BackTrack {
private:
    void combineHelper(int startNumber, int n, int k, vector<int> &curPath, vector<vector<int>> &res);
    void subsetsHelper(int startIndex, vector<int>& nums, vector<int> &curPath, vector<vector<int>> &res);
    void subsetsWithDupHelper(int startIndex, vector<int>& nums, bool visited[],vector<int> &curPath, vector<vector<int>> &res);
    void combinationSumHelper(int startIndex, vector<int>& candidates, int curSum, int targetSum,vector<int> &curPath, vector<vector<int>> &res);
    void combinationSum2Helper(int startIndex, bool *visited, vector<int>& candidates, int curSum, int targetSum,vector<int> &curPath, vector<vector<int>> &res);
public:
    vector<vector<int>> combine(int n, int k);
    vector<vector<int>> subsets(vector<int>& nums);
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
};


#endif //LEARNCPP_ALGORITHM_BACKTRACK_H
