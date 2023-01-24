//
// Created by 包傲磊 on 2023/1/24.
//

#ifndef LEARNCPP_ALGORITHM_DAY11_H
#define LEARNCPP_ALGORITHM_DAY11_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Day11 {
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] == -1) {
                continue;
            }
            map[manager[i]].push_back(i);
        }
        int totalMinutes = 0;
        queue<vector<int>> q;
        q.push(vector<int>({headID, 0}));
        while (!q.empty()) {
            int size = q.size();
            int maxInfoTime = 0;
            while (size > 0) {
                vector<int> cur = q.front();
                q.pop();
                int curSpreadTime = informTime[cur[0]] + cur[1];
                totalMinutes = max(curSpreadTime, totalMinutes);
                for (auto e: map[cur[0]]) {
                    q.push(vector<int>({e, curSpreadTime}));
                }
                size--;
            }
        }
        return totalMinutes;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (string str: strs) {
            vector<int> characterCount(26, 0);
            for (char c: str) {
                characterCount[c - 'a']++;
            }
            string key = "";
            for (auto c: characterCount) {
                key += to_string(c) + "-";
            }
            map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = map.begin(); it != map.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }

    void letterCombinationsHelper(int index, string &digits, string cur, vector<string> &ans,
                                  unordered_map<char, string> &map) {
        if (index == digits.size() && cur.length() > 0) {
            ans.push_back(cur);
            return;
        }
        for (char c: map[digits[index]]) {
            cur.push_back(c);
            letterCombinationsHelper(index + 1, digits, cur, ans, map);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        vector<string> ans;
        letterCombinationsHelper(0, digits, "", ans, map);
        return ans;
    }

    void generateParenthesisHelper(int left, int right, string cur, vector<string> &ans, int n) {
        if (cur.length() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (left < n) {
            cur.push_back('(');
            generateParenthesisHelper(left + 1, right, cur, ans, n);
            cur.pop_back();
        }
        if (right < left) {
            cur.push_back(')');
            generateParenthesisHelper(left, right + 1, cur, ans, n);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisHelper(0, 0, "", ans, n);
        return ans;
    }


    bool existHelper(int index, int x, int y, vector<vector<char>> &board, string &word, vector<vector<bool>> &seen,
                     vector<vector<int>> &directions) {
        if (index == word.length()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];
            if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size() && !seen[new_x][new_y] &&
                board[new_x][new_y] == word[index]) {
                seen[new_x][new_y] = true;
                if (existHelper(index + 1, new_x, new_y, board, word, seen)) {
                    return true;
                }
                seen[new_x][new_y] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        vector<vector<int>> directions;
        directions.push_back(vector<int>({0, 1}));
        directions.push_back(vector<int>({0, -1}));
        directions.push_back(vector<int>({1, 0}));
        directions.push_back(vector<int>({-1, 01}));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] == board[i][j]) {
                    vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
                    seen[i][j] = true;
                    if (existHelper(1, i, j, board, word, seen, directions)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

#endif //LEARNCPP_ALGORITHM_DAY11_H
