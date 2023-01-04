//
// Created by Acer on 6/15/2021.
//

#ifndef LEARNCPP_ALGORITHM_SOLUTION_H
#define LEARNCPP_ALGORITHM_SOLUTION_H

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr);

    vector<string> findOcurrences(string text, string first, string second);

    int numTilePossibilities(string tiles);//https://leetcode-cn.com/problems/letter-tile-possibilities/
    int dfsCount(vector<int> characterCount);

    TreeNode *sufficientSubset(TreeNode *root,
                               int limit);//https://leetcode-cn.com/problems/insufficient-nodes-in-root-to-leaf-paths/
    TreeNode *sufficientSubsetHelper(TreeNode *node, int limit, int cur);

    vector<vector<string>> displayTable(vector<vector<string>> &orders);

    int majorityElement(vector<int> &nums);

    int minimumMoves(string s);

    int minimumLength(string s);

    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3);

    char repeatedCharacter(string s);

    bool areNumbersAscending(string s);
};


#endif //LEARNCPP_ALGORITHM_SOLUTION_H
