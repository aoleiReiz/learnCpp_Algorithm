//
// Created by 包傲磊 on 2023/1/28.
//

#ifndef LEARNCPP_ALGORITHM_DAY15_H
#define LEARNCPP_ALGORITHM_DAY15_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int waysToMakeFair(vector<int> &nums) {
    int count = 0;
    vector<int> evenSum;
    vector<int> oddSum;
    int curEvenSum = 0, curOddSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) {
            curEvenSum += nums[i];
            evenSum.push_back(curEvenSum);
        } else {
            curOddSum += nums[i];
            oddSum.push_back(curOddSum);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (i % 2 == 0) {
            int preEvenSum = evenSum[i / 2] - nums[i];
            int preOddSum = i == 0 ? 0 : oddSum[i / 2 - 1];
            if (curEvenSum - evenSum[i / 2] + preOddSum == preEvenSum + curOddSum - preOddSum) {
                count++;
            }
        } else {
            int preEvenSum = evenSum[i / 2];
            int preOddSum = oddSum[i / 2] - nums[i];
            if (curEvenSum - preEvenSum + preOddSum == preEvenSum + curOddSum - preOddSum - nums[i]) {
                count++;
            }
        }
    }
    return count;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode * dummyHead = new ListNode(-1);
    ListNode * p = dummyHead;
    int exceedDigit = 0;
    while (l1 || l2){
        if (l1 == nullptr){
            int digit = (l2->val + exceedDigit) % 10;
            exceedDigit = (l2->val + exceedDigit) / 10;
            p->next = new ListNode(digit);
            l2 = l2->next;
        }else if (l2 == nullptr){
            int digit = (l1->val + exceedDigit) % 10;
            exceedDigit = (l1->val + exceedDigit) / 10;
            p->next = new ListNode(digit);
            l1 = l1->next;
        }else{
            int digit = (l1->val + l2->val +  exceedDigit) % 10;
            exceedDigit = (l1->val + l2->val + exceedDigit) / 10;
            p->next = new ListNode(digit);
            l1 = l1->next;
            l2 = l2->next;
        }
         p = p->next;
    }
    if (exceedDigit > 0){
        p->next = new ListNode(exceedDigit);
    }
    return dummyHead->next;
}

ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2, s;
    while (l1){
        s1.push(l1->val);
        l1 = l1->next;
    }
    while (l2){
        s2.push(l2->val);
        l2 = l2->next;
    }
    ListNode * dummyHead = new ListNode(-1);
    ListNode * p = dummyHead;
    int carry = 0;
    while (!s1.empty() || !s2.empty()){
        if (s1.empty()){
            int digit = (carry + s2.top()) % 10;
            carry = (carry + s2.top()) / 10;
            s2.pop();
            s.push(digit);
        }else if (s2.empty()){
            int digit = (carry + s1.top()) % 10;
            carry = (carry + s1.top()) / 10;
            s1.pop();
            s.push(digit);
        }else{
            int digit = (carry + s1.top() + s2.top()) % 10;
            carry = (carry + s1.top() + s2.top()) / 10;
            s1.pop();
            s2.pop();
            s.push(digit);
        }
    }
    if (carry > 0){
        s.push(carry);
    }
    while (!s.empty()){
        int digit = s.top();
        p->next = new ListNode(digit);
        p = p->next;
        s.pop();
    }
    return dummyHead->next;
}


int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <=n ; ++i) {
        if(s[i - 1] != '0'){
            dp[i] += dp[i - 1];
        }
        if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i-1] - '0') <= 26)){
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}

bool wordBreak(string s, vector<string>& wordDict) {
    auto wordDictSet = unordered_set <string> (wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size() ; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

#endif //LEARNCPP_ALGORITHM_DAY15_H
