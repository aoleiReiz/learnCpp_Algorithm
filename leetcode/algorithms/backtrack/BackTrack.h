//
// Created by aolei.bao on 12/27/2022.
//

#ifndef LEARNCPP_ALGORITHM_BACKTRACK_H
#define LEARNCPP_ALGORITHM_BACKTRACK_H
#include <vector>
#include <unordered_set>

using namespace std;

class BackTrack {
private:
    void combineHelper(int startNumber, int n, int k, vector<int> &curPath, vector<vector<int>> &res);
    void subsetsHelper(int startIndex, vector<int>& nums, vector<int> &curPath, vector<vector<int>> &res);
public:
    vector<vector<int>> combine(int n, int k);
    vector<vector<int>> subsets(vector<int>& nums);
};


#endif //LEARNCPP_ALGORITHM_BACKTRACK_H
