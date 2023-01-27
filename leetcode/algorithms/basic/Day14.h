//
// Created by 包傲磊 on 2023/1/27.
//

#ifndef LEARNCPP_ALGORITHM_DAY14_H
#define LEARNCPP_ALGORITHM_DAY14_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

string greatestLetter(string s) {
    vector<int> countLower(26, 0);
    vector<int> countUpper(26, 0);
    for (char c: s) {
        if (c >= 'a') {
            countLower[c - 'a']++;
        } else {
            countUpper[c - 'A']++;
        }
    }
    for (int i = 25; i >= 0; --i) {
        if (countLower[i] >= 2 && countUpper[i] >= 2) {
            return string(1, static_cast<char >('A' + i));
        }
    }
    return "";
}


void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr | head->next->next == nullptr) {
        return;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && slow && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *stopNode = slow;
    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    ListNode *dummyHead = new ListNode(-1, head);
    ListNode *p = dummyHead;
    ListNode *p1 = head;
    ListNode *p2 = prev;
    ListNode *tempP1 = nullptr;
    ListNode *tempP2 = nullptr;
    while (p1 != stopNode) {
        p->next = p1;
        tempP1 = p1->next;
        tempP2 = p2->next;
        p1->next = p2;
        p = p2;
        p1 = tempP1;
        p2 = tempP2;
    }
    stopNode->next = nullptr;
}

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*>map;
    Node *p = head;
    Node * dummyHead = new Node(-1);
    Node * curr = dummyHead;
    while (p){
        auto it = map.find(p);
        if (it != map.end()){
            curr->next = it->second;
        }else{
            curr->next = new Node(p->val);
            map[p] = curr->next;
        }
        p = p->next;
        curr = curr->next;
    }
    p = head;
    curr = dummyHead->next;
    while (p){
        if(p->random){
            auto it = map.find(p->random);
            curr->random = it->second;
        }
        p = p->next;
        curr = curr->next;
    }
    return dummyHead->next;
}

string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n , false));
    string res = "";
    for (int i = n - 1 ; i >= 0 ; --i) {
        for (int j = i; j < n; ++j) {
            dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i+1][j - 1]);
            if (dp[i][j] && j - i + 1 > res.size()){
                res = s.substr(i, j - i + 1);
            }
        }
    }
    return res;
}

int numberOfArithmeticSlices(vector<int>& nums) {
    int total = 0;
    int n = nums.size();
    if (n == 1){
        return 0;
    }
    int d = nums[1] - nums[0];
    int t = 0;
    for (int i = 2; i < n; ++i) {
        if (nums[i] - nums[i - 1] == d){
            ++t;
        }else{
            d = nums[i] - nums[i - 1];
            t = 0;
        }
        total += t;
    }
    return total;
}

#endif //LEARNCPP_ALGORITHM_DAY14_H
