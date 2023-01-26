//
// Created by Administrator on 2023/1/26.
//

#ifndef LEARNCPP_ALGORITHM_DAY13_H
#define LEARNCPP_ALGORITHM_DAY13_H

#include <vector>
#include<iostream>
#include <algorithm>

using namespace std;

class NumMatrix {
private:
    vector<vector<int>> rowCumSum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            int curSum = 0;
            vector<int> row;
            for (int j = 0; j < matrix[0].size(); ++j) {
                curSum += matrix[i][j];
                row.push_back(curSum);
            }
            rowCumSum.push_back(row);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int totalSum = 0;
        if (row1 > row2 || col1 > col2) {
            return NULL;
        }
        for (int i = row1; i <= row2; ++i) {
            int preColSum = col1 == 0 ? 0 : rowCumSum[i][col1 - 1];
            totalSum += rowCumSum[i][col2] - preColSum;
        }
        return totalSum;
    }
};


int smallestRangeII(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans = nums[n - 1] - nums[0];
    for (int i = 0; i < n - 1; ++i) {
        int a = nums[i];
        int b = nums[i + 1];
        int high = max(nums[n - 1] - k, a + k);
        int low = min(nums[0] + k, b - k);
        ans = min(ans, high - low);
    }
    return ans;
}

int jump(vector<int> &nums) {
    int maxRight = 0;
    int steps = 0;
    int end = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        maxRight = i + nums[i] > maxRight ?  i + nums[i] : maxRight;
        if(i == end){
            end = maxRight;
            steps ++;
        }
    }
    return steps;
}


int uniquePaths(int m, int n) {
    vector<int> dp;
    for (int i = 0; i < n; ++i) {
        dp.push_back(1);
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0){
                dp[j] = 1;
            }else{
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }
    return dp[n - 1];
}


string getSmallestString(int n, int k) {
    string ans;
    for (int i = 1; i <= n; i++) {
        int lower = max(1, k - (n - i) * 26);
        k -= lower;
        ans.push_back('a' + lower - 1);
    }
    return ans;
}

#endif //LEARNCPP_ALGORITHM_DAY13_H
