//
// Created by Acer on 6/15/2021.
//

#include "Solution.h"
#include <utility>
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
    for (int i = 1; i <= num; ++i) {
        int sum = 0, j = i;
        while (j > 0) {
            int curDigit = j % 10;
            j /= 10;
            sum += curDigit;
        }
        if (sum % 2 == 0) {
            count += 1;
        }
    }
    return count;
}

bool Solution::digitCount(string num) {
    vector<int> count(10, 0);
    for (auto digit: num) {
        count[digit - '0']++;
    }
    for (int i = 0; i < num.size(); ++i) {
        if (count[i] != num[i] - '0') {
            return false;
        }
    }
    return true;
}

int Solution::rearrangeCharacters(string s, string target) {
    unordered_map<char, int> map;
    for (auto &c: s) {
        map[c]++;
    }
    int count = 0;
    bool flag = true;
    while (flag) {
        for (char i: target) {
            if (map[i] == 0) {
                flag = false;
                break;
            } else {
                map[i]--;
            }
        }
    }
    return count;
}

int Solution::minMaxGame(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    vector<int> curArray(nums);
    while (n > 1) {
        vector<int> tempNums;
        int k = 0;
        for (int i = 0; i < n - 1; i += 2) {
            if (k % 2 == 0) {
                tempNums.push_back(curArray[i] > curArray[i + 1] ? curArray[i + 1] : curArray[i]);
            } else {
                tempNums.push_back(curArray[i] > curArray[i + 1] ? curArray[i] : curArray[i + 1]);
            }
            k++;
            curArray = tempNums;
        }
        n /= 2;
    }

    return curArray[0];
}

bool Solution::areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> wordsOne = splitWords(std::move(sentence1));
    vector<string> wordsTwo = splitWords(std::move(sentence2));
    int leftOne = 0, rightOne = wordsOne.size() - 1;
    int leftTwo = 0, rightTwo = wordsTwo.size() - 1;
    if (leftOne == rightOne || leftTwo == rightTwo) {
        if (leftOne == rightOne) {
            if (wordsOne[leftOne] == wordsTwo[leftTwo] || wordsOne[leftOne] == wordsTwo[rightTwo]) {
                return true;
            }
            return false;
        } else if (leftTwo == rightTwo) {
            if (wordsOne[leftOne] == wordsTwo[leftTwo] || wordsOne[rightOne] == wordsTwo[rightTwo]) {
                return true;
            }
            return false;
        }
    }
    bool compareLeft = true;
    bool compareRight = true;
    while (leftOne <= rightTwo && leftTwo <= rightOne && (compareLeft || compareRight)) {
        if (wordsOne[leftOne] == wordsTwo[leftTwo]) {
            leftOne++;
            leftTwo++;
        } else {
            compareLeft = false;
        }
        if (wordsOne[rightOne] == wordsTwo[rightTwo]) {
            rightOne--;
            rightTwo--;
        } else {
            compareRight = false;
        }
    }
    return (leftOne > rightOne || leftTwo > rightTwo);
}

vector<string> Solution::splitWords(string sentence) {
    vector<string> words;
    string::size_type idx = 0;
    while (idx < sentence.length()) {
        string::size_type start = idx;
        while (!isspace(sentence[idx]) && idx < sentence.size()) {
            idx++;
        }
        words.push_back(sentence.substr(start, idx - start));
        idx++;
    }
    return words;

}

bool Solution::strongPasswordCheckerII(string password) {
    string specialCharacters = "!@#$%^&*()-+";
    if (password.length() < 8) {
        return false;
    }
    bool lowerCase = false, upperCase = false, digitCase = false, specialCase = false;
    for (int i = 0; i < password.length(); ++i) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowerCase = true;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upperCase = true;
        } else if (password[i] >= '0' && password[i] <= '9') {
            digitCase = true;
        } else if (specialCharacters.find(password[i], 0) != string::npos) {
            specialCase = true;
        }
        if (i < password.length() - 1) {
            if (password[i] == password[i + 1]) {
                return false;
            }
        }
    }
    return lowerCase && upperCase && digitCase && specialCase;
}

vector<int> Solution::findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
    unordered_map<int, unordered_set<int>> actMap;
    vector<int> ans(k, 0);
    for (vector<int> &log: logs) {
        int userId = log.at(0);
        int timeId = log.at(1);
        actMap[userId].insert(timeId);
    }
    auto iter = actMap.begin();
    while (iter != actMap.end()) {
        int activeCount = iter->second.size();
        ans[activeCount - 1]++;
        iter++;
    }
    return ans;
}

double Solution::calculateTax(vector<vector<int>> &brackets, int income) {
    int curIncome = income;
    double tax = 0.0;
    for (int i = 0; i < brackets.size(); ++i) {
        int taxIncome;
        if (i == 0) {
            taxIncome = min(curIncome, brackets[i][0]);
        } else {
            taxIncome = min(curIncome, brackets[i][0] - brackets[i - 1][0]);
        }
        tax += taxIncome * (brackets[i][1] / 100.);
        curIncome -= taxIncome;
        if (curIncome <= 0) {
            break;
        }
    }
    return tax;
}

vector<int> Solution::countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
    vector<int> ans;
    for (vector<int> &query: queries) {
        int count = 0;
        for (vector<int> &point: points) {
            int distance = (query[0] - point[0]) * (query[0] - point[0]) +  (query[1] - point[1]) * (query[1] - point[1]);
            if (distance <= query[2] * query[2]){
                count ++;
            }
        }
        ans.push_back(count);
    }
    return ans;
}


