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
#include <queue>

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

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        string cur = folder[0];
        vector<string> ans;
        ans.push_back(cur);
        for (int i = 1; i < folder.size(); ++i) {
            if (cur.size()<= 1){
                cur = folder[i];
                ans.push_back(cur);
            }else{
                if (folder[i].substr(0, cur.size()) == cur && folder[i][cur.size()] == '/'){
                    continue;
                }else{
                    cur = folder[i];
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }

    string alphabetBoardPath(string target) {
        int cx = 0, cy = 0;
        string res;
        for (char c: target) {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            if (nx < cx) {
                res.append(cx - nx, 'U');
            }
            if (ny < cy) {
                res.append(cy - ny, 'L');
            }
            if (nx > cx) {
                res.append(nx - cx, 'D');
            }
            if (ny > cy) {
                res.append(ny - cy, 'R');
            }
            res.push_back('!');
            cx = nx;
            cy = ny;
        }
        return res;
    }
    string printBin(double num) {
        string res = "0.";
        while (res.size() <= 32 && num!= 0){
            num *= 2;
            int digit = num;
            res.push_back(digit + '0');
            num -= digit;
        }
        return res.size() <= 32 ? res : "ERROR";
    }

    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
               dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j -1];
            }
        }
        return dp[m][n];
    }
};
#endif //LEARNCPP_ALGORITHM_SOLUTION2_H
