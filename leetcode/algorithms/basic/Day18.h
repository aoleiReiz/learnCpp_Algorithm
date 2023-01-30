//
// Created by aolei.bao on 1/31/2023.
//

#ifndef LEARNCPP_ALGORITHM_DAY18_H
#define LEARNCPP_ALGORITHM_DAY18_H

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

bool checkXMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                if (grid[i][j] == 0) {
                    return false;
                }
            } else {
                if (grid[i][j] != 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

class MinStack {
private:
    stack<int> minStack;
    stack<int> dataStack;
public:
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int val) {
        dataStack.push(val);
        int curMin = minStack.top();
        minStack.push(min(curMin, val));
    }

    void pop() {
        minStack.pop();
        dataStack.pop();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.emplace(nestedList.begin(), nestedList.end());
    }

    int next() {
        return stk.top().first++->getInteger();
    }

    bool hasNext() {
        while (!stk.empty()){
            auto &p = stk.top();
            if (p.first == p.second){
                stk.pop();
                continue;
            }
            if (p.first -> isInteger()){
                return true;
            }
            auto &l = p.first++ -> getList();
            stk.emplace(l.begin(), l.end());
        }
        return false;
    }
};

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>>dp(m, vector<int>(n,0));
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <=n ; ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= m ; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i-1][j - 1] + 1);
            }
        }
    }
    return dp[m][n];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 0; i <= amount; ++i) {
        for (auto coin : coins){
            if ( i - coin < 0){
                continue;
            }
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int max3(int a, int b, int c){
    int temp = max(a, b);
    return max(temp, c);
}

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] = max3(dp[i], j * i - j, j * dp[i - j]);
        }
    }
    return dp[n];
}


#endif //LEARNCPP_ALGORITHM_DAY18_H
