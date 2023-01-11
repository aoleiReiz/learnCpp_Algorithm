//
// Created by Acer on 6/15/2021.
//

#include "Solution.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int Solution::peakIndexInMountainArray(vector<int> &arr) {
    int n = arr.size();
    int ans = -1;
    int left = 0, right = n - 2;
    while (left <= right) {
        int mid = (right - left) / 2 + left;
        if (arr[mid] > arr[mid + 1]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

//https://leetcode-cn.com/problems/occurrences-after-bigram/submissions/
vector<string> Solution::findOcurrences(string text, string first, string second) {
    vector<string> res;
    istringstream ss(text);
    string cur = "", firstStr = "", secondStr = "";
    while (ss >> cur) {
        if ((first == firstStr) && (second == secondStr)) {
            res.push_back(cur);
        }
        firstStr = secondStr;
        secondStr = cur;
    }
    return res;
}

int Solution::numTilePossibilities(string tiles) {
    vector<int> characterCount(26, 0);
    for (int i = 0; i < tiles.size(); ++i) {
        characterCount[tiles[i] - 'A']++;
    }

    return dfsCount(characterCount);
}

int Solution::dfsCount(vector<int> characterCount) {
    int count = 0;
    for (int i = 0; i < 26; ++i) {
        if (characterCount[i] == 0) {
            continue;
        }
        ++count;
        characterCount[i]--;
        count += dfsCount(characterCount);
        characterCount[i]++;
    }
    return count;
}

TreeNode *Solution::sufficientSubset(TreeNode *root, int limit) {
    return sufficientSubsetHelper(root, limit, 0);
}

TreeNode *Solution::sufficientSubsetHelper(TreeNode *node, int limit, int cur) {
    if (node == nullptr) {
        return nullptr;
    }
    cur += node->val;
    if (node->left == nullptr && node->right == nullptr) {
        if (cur < limit) {
            delete node;
            return nullptr;
        }
        return node;
    }
    node->left = sufficientSubsetHelper(node->left, limit, cur);
    node->right = sufficientSubsetHelper(node->right, limit, cur);
    if (node->left == nullptr && node->right == nullptr) {
        return nullptr;
    }
    return node;
}

bool compareStringInteger(string s1, string s2) {
    return stoi(s1) < stoi(s2);
}

vector<vector<string>> Solution::displayTable(vector<vector<string>> &orders) {
    unordered_map<string, unordered_map<string, int>> orderCountMap;
    vector<string> tables;
    vector<string> foods;
    unordered_set<string> tableSet;
    unordered_set<string> foodSet;

    for (vector<string> &order: orders) {
        string table = order[1];
        string food = order[2];
        if (tableSet.count(table) <= 0) {
            tables.push_back(table);
            tableSet.insert(table);
        }
        if (foodSet.count(food) <= 0) {
            foods.push_back(food);
            foodSet.insert(food);
        }

        if (orderCountMap.count(table) > 0) {
            if (orderCountMap[table].count(food) > 0) {
                orderCountMap[table][food] += 1;
            } else {
                orderCountMap[table].insert(make_pair(food, 1));
            }
        } else {
            orderCountMap[table] = unordered_map<string, int>();
            orderCountMap[table].insert(make_pair(food, 1));
        }
    }

    sort(tables.begin(), tables.end(), compareStringInteger);
    sort(foods.begin(), foods.end());
    vector<vector<string>> res;
    vector<string> header;
    header.push_back("Table");
    for (string &food: foods) {
        header.push_back(food);
    }
    res.push_back(header);

    for (string &table: tables) {
        vector<string> row;
        row.push_back(table);
        for (string &food: foods) {
            if (orderCountMap[table].count(food) <= 0) {
                row.push_back(to_string(0));
            } else {
                row.push_back(to_string(orderCountMap[table][food]));
            }
        }
        res.push_back(row);
    }
    return res;
}

int Solution::majorityElement(vector<int> &nums) {
    int candidate = -1, count = 0;
    for (int i: nums) {
        if (count == 0) {
            candidate = i;
        }
        if (i == candidate) {
            count += 1;
        } else {
            count -= 1;
        }
    }
    count = 0;
    int length = nums.size();
    for (int i = 0; i < length; ++i) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    return count * 2 > length ? candidate : -1;
}

int Solution::minimumMoves(string s) {
    int count = 0;
    int idx = 0;
    while (idx < s.length()) {
        if (s[idx] == 'X') {
            idx += 3;
            count++;
        } else {
            idx += 1;
        }
    }
    return count;
}

int Solution::minimumLength(string s) {
    int leftIdx = 0;
    int rightIdx = s.length() - 1;
    while (leftIdx < rightIdx && s[leftIdx] == s[rightIdx]) {
        char preLeft = s[leftIdx];
        while (s[leftIdx] == preLeft && leftIdx <= rightIdx) {
            leftIdx += 1;
        }
        while (rightIdx >= leftIdx && s[rightIdx] == preLeft) {
            rightIdx -= 1;
        }
    }
    return rightIdx - leftIdx + 1;
}

vector<int> Solution::twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3) {
    unordered_map<int, int> mp;
    for (auto &i: nums1) {
        mp[i] = 1;
    }
    for (auto &i: nums2) {
        mp[i] |= 2;
    }
    for (auto &i: nums3) {
        mp[i] |= 4;
    }
    vector<int> res;
    for (auto&[k, v]: mp) {
        if (v & (v - 1)) {
            res.push_back(k);
        }
    }
    return res;
}

char Solution::repeatedCharacter(string s) {
    unordered_set<char> set;
    int idx = 0;
    int minIdx = INT_MAX;
    char res = 0;
    for (auto &c: s) {
        if (set.find(c) != set.end()) {
            if (idx < minIdx) {
                minIdx = idx;
                res = c;
            }
        } else {
            set.insert(c);
        }
        idx++;
    }
    return res;
}

bool Solution::areNumbersAscending(string s) {
    int preNumber = INT_MIN;
    string cur = "";
    for (auto &c: s) {
        if (c >= '0' and c <= '9') {
            cur += c;
        } else if (cur.length() > 0) {
            int curNumber = stoi(cur);
            if (curNumber <= preNumber) {
                return false;
            }
            preNumber = curNumber;
            cur = "";
        }
    }
    if (cur.length() > 0) {
        int curNumber = stoi(cur);
        if (curNumber <= preNumber) {
            return false;
        }
    }

    return true;
}

int Solution::countEven(int num) {
    int count = 0;
    for (int i = 1; i <=num ; ++i) {
        int sum = 0, j = i;
        while (j > 0){
            int curDigit = j % 10;
            j /= 10;
            sum += curDigit;
        }
        if(sum % 2 == 0){
            count += 1;
        }
    }
    return count;
}

bool Solution::digitCount(string num) {
    vector<int>count(10, 0);
    for (auto digit: num) {
        count[digit - '0']++;
    }
    for (int i = 0; i < num.size(); ++i) {
        if (count[i] != num[i] - '0'){
            return false;
        }
    }
    return true;
}


