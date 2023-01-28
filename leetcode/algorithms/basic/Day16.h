//
// Created by 包傲磊 on 2023/1/29.
//

#ifndef LEARNCPP_ALGORITHM_DAY16_H
#define LEARNCPP_ALGORITHM_DAY16_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int countAsterisks(string s) {
    int count = 0;
    bool startFlag = false;
    for (char c: s) {
        if (!startFlag && c == '*') {
            count++;
        } else if (c == '|' && !startFlag) {
            startFlag = true;
        } else if (c == '|' && startFlag) {
            startFlag = false;
        } else {
            continue;
        }
    }
    return count;
}

int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int ans = 0;
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
                ans = ans > dp[i] ? ans : dp[i];
            }
        }
    }
    return ans;
}

int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size(), maxLen = 0, ans = 0;
    vector<int> dp(n), cnt(n);
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            ans = cnt[i];
        } else if (dp[i] == maxLen) {
            ans += cnt[i];
        }
    }
    return ans;
}

ListNode *rotateRight(ListNode *head, int k) {
    if (k == 0 || head == nullptr) {
        return head;
    }
    ListNode *p = head;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    k = k % len;
    if (k == 0) {
        return head;
    }
    int count = 0;
    p = head;
    while (count < len - k - 1) {
        p = p->next;
        count++;
    }
    ListNode *curr = p->next;
    ListNode *newHead = p->next;
    p->next = nullptr;
    while (curr && curr->next) {
        curr = curr->next;
    }
    if (curr) {
        curr->next = head;
    }
    return newHead;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    TreeNode* curNode;
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode *root) {
        this->curNode = root;
    }

    int next() {
        while (curNode != nullptr){
            s.push(curNode);
            curNode = curNode->left;
        }
        curNode = s.top();
        s.pop();
        int ret = curNode->val;
        curNode = curNode->right;
        return ret;
    }

    bool hasNext() {
        return curNode != nullptr || !s.empty();
    }
};

#endif //LEARNCPP_ALGORITHM_DAY16_H
