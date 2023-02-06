//
// Created by 包傲磊 on 2023/2/7.
//

#ifndef LEARNCPP_ALGORITHM_SOLUTION2_H
#define LEARNCPP_ALGORITHM_SOLUTION2_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> timeMap;
        int n = keyName.size();
        for (int i = 0; i < n; i++) {
            string name = keyName[i];
            string time = keyTime[i];
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            timeMap[name].emplace_back(hour * 60 + minute);
        }
        vector<string> res;
        for (auto &[name, list] : timeMap) {
            sort(list.begin(), list.end());
            int size = list.size();
            for (int i = 2; i < size; i++) {
                int time1 = list[i - 2], time2 = list[i];
                int difference = time2 - time1;
                if (difference <= 60) {
                    res.emplace_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }

};
#endif //LEARNCPP_ALGORITHM_SOLUTION2_H
