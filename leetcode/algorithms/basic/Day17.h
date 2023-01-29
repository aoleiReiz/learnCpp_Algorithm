//
// Created by 包傲磊 on 2023/1/30.
//

#ifndef LEARNCPP_ALGORITHM_DAY17_H
#define LEARNCPP_ALGORITHM_DAY17_H

#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *p1 = list1;
    ListNode *p2 = list2;
    int idx1 = 0;
    while (idx1 < a - 1) {
        p1 = p1->next;
        idx1++;
    }
    ListNode *aPrev = p1;
    while (idx1 < b - 1) {
        p1 = p1->next;
        idx1++;
    }
    ListNode *bPrev = p1;
    while (p2->next != nullptr) {
        p2 = p2->next;
    }
    aPrev->next = list2;
    p2->next = bPrev->next;
    return list1;
}

class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> seats;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            seats.push(i);
        }
    }

    int reserve() {
        int ret = seats.top();
        seats.pop();
        return ret;
    }

    void unreserve(int seatNumber) {
        seats.push(seatNumber);
    }
};

bool lemonadeChange(vector<int> &bills) {
    int c5 = 0, c10 = 0;
    for (auto bill: bills) {
        if (bill == 5) {
            c5++;
        } else if (bill == 10) {
            if (c5 == 0) {
                return false;
            }
            c10++;
            c5--;
        } else {
            if (c10 > 0 && c5 > 0) {
                c10--;
                c5--;
            } else if (c5 >= 3) {
                c5 -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (text1[i] == text2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i+1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[m][n];
}

#endif //LEARNCPP_ALGORITHM_DAY17_H
