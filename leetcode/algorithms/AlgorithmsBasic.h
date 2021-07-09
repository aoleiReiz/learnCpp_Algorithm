//
// Created by aolei.bao on 7/5/2021.
//

#ifndef LEARNCPP_ALGORITHM_ALGORITHMSBASIC_H
#define LEARNCPP_ALGORITHM_ALGORITHMSBASIC_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class AlgorithmsBasic {

private:
    void reverseArray(vector<int> &arr, int left, int right);
public:
    //https://leetcode-cn.com/problems/binary-search/
    int search(vector<int>& nums, int target);
    //https://leetcode-cn.com/problems/search-insert-position/
    int searchInsert(vector<int>& nums, int target);
    //https://leetcode-cn.com/problems/squares-of-a-sorted-array/
    vector<int> sortedSquares(vector<int>& nums);
    //https://leetcode-cn.com/problems/rotate-array/
    void rotate(vector<int>& nums, int k);
    //https://leetcode-cn.com/problems/move-zeroes/
    void moveZeroes(vector<int>& nums);
    //https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
    vector<int> twoSum(vector<int>& numbers, int target);
    //https://leetcode-cn.com/problems/reverse-string/
    void reverseString(vector<char>& s);
    //https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
    string reverseWords(string s);
    //https://leetcode-cn.com/problems/middle-of-the-linked-list/
    ListNode* middleNode(ListNode* head);
    //https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
    ListNode* removeNthFromEnd(ListNode* head, int n);
};


#endif //LEARNCPP_ALGORITHM_ALGORITHMSBASIC_H
