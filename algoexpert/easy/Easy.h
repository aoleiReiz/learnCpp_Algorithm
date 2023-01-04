//
// Created by aolei.bao on 12/30/2022.
//

#ifndef LEARNCPP_ALGORITHM_EASY_H
#define LEARNCPP_ALGORITHM_EASY_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include_next <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Easy {
    vector<int> twoNumberSum(vector<int> array, int targetSum);
    bool isValidSubsequence(vector<int> array, vector<int> sequence);
    vector<int> sortedSquaredArray(vector<int> array);
    string tournamentWinner(vector<vector<string>> competitions,
                            vector<int> results);
    int nonConstructibleChange(vector<int> coins);
};


#endif //LEARNCPP_ALGORITHM_EASY_H
