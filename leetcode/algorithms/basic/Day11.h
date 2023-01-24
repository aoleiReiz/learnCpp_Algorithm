//
// Created by 包傲磊 on 2023/1/24.
//

#ifndef LEARNCPP_ALGORITHM_DAY11_H
#define LEARNCPP_ALGORITHM_DAY11_H
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Day11{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] == -1){
                continue;
            }
            map[manager[manager[i]]].push_back(i);
        }
    }
};
#endif //LEARNCPP_ALGORITHM_DAY11_H
