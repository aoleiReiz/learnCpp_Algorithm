//
// Created by aolei.bao on 1/11/2023.
//

#ifndef LEARNCPP_ALGORITHM_MID1TO5_H
#define LEARNCPP_ALGORITHM_MID1TO5_H
#include <vector>
#include <algorithm>

using namespace std;

class Mid1to5 {
public:
    vector<vector<int>> threeNumberSum(vector<int> array, int targetSum);

    vector<vector<int>> twoNumberSum(vector<int>&array, int target, int startIndex);
};


#endif //LEARNCPP_ALGORITHM_MID1TO5_H
