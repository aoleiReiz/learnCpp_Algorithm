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
    vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime) {
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
        for (auto &[name, list]: timeMap) {
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

    vector<string> removeSubfolders(vector<string> &folder) {
        sort(folder.begin(), folder.end());
        string cur = folder[0];
        vector<string> ans;
        ans.push_back(cur);
        for (int i = 1; i < folder.size(); ++i) {
            if (cur.size() <= 1) {
                cur = folder[i];
                ans.push_back(cur);
            } else {
                if (folder[i].substr(0, cur.size()) == cur && folder[i][cur.size()] == '/') {
                    continue;
                } else {
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
        while (res.size() <= 32 && num != 0) {
            num *= 2;
            int digit = num;
            res.push_back(digit + '0');
            num -= digit;
        }
        return res.size() <= 32 ? res : "ERROR";
    }

    vector<string> getFolderNames(vector<string> &names) {
        unordered_map<string, int> nameCount;
        vector<string> res;
        for (string &name: names) {
            auto it = nameCount.find(name);
            if (it == nameCount.end()) {
                res.push_back(name);
                nameCount[name] = 1;
            } else {
                string newName = name + "(" + to_string(it->second) + ")";
                while (nameCount.find(newName) != nameCount.end()) {
                    it->second++;
                    newName = name + "(" + to_string(it->second) + ")";
                }
                res.push_back(newName);
                it->second++;
            }
        }
        return res;
    }

    int minimumDeletions(string s) {
        vector<pair<int, int>> pairCountForward;
        vector<pair<int, int>> pairCountBackward;
        int curACount = 0, curBCount = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a') {
                curACount++;
            } else {
                curBCount++;
            }
            pairCountForward.emplace_back(curACount, curBCount);
        }
        curACount = 0;
        curBCount = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'a') {
                curACount++;
            } else {
                curBCount++;
            }
            pairCountBackward.emplace_back(curACount, curBCount);
        }
        int ans = INT_MAX;
        for (int i = 0; i < pairCountForward.size(); ++i) {
            int forward = 0;
            if (i > 0) {
                forward = pairCountForward[i - 1].second;
            }
            int backward = 0;
            if (i < pairCountForward.size() - 1) {
                backward = pairCountBackward[pairCountForward.size() - 2 - i].first;
            }
            if (forward + backward < ans) {
                ans = forward + backward;
            }
        }

        return ans;
    }

    int maxValue(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }

    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int trainingHours = 0;

        int n = energy.size();
        int curEnergy = 0;
        int curExperience = initialExperience;

        for(int i = 0; i < n; i++){
            curEnergy += energy[i];
            if(curExperience > experience[i]){
                curExperience += experience[i];
            }else{
                trainingHours +=(experience[i] - curExperience + 1);
                curExperience += ((experience[i] - curExperience + 1)+ experience[i]);
            }
        }

        return max(max(curEnergy - initialEnergy + 1,0) + trainingHours,0);

    }
};

#endif //LEARNCPP_ALGORITHM_SOLUTION2_H
