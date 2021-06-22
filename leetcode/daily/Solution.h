//
// Created by Acer on 6/15/2021.
//

#ifndef LEARNCPP_ALGORITHM_SOLUTION_H
#define LEARNCPP_ALGORITHM_SOLUTION_H
#include <vector>
using  namespace std;

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
    int peakIndexInMountainArray(vector<int>& arr);
    vector<string> findOcurrences(string text, string first, string second);
    int numTilePossibilities(string tiles);//https://leetcode-cn.com/problems/letter-tile-possibilities/
    int dfsCount(vector<int>characterCount);
    TreeNode* sufficientSubset(TreeNode* root, int limit);//https://leetcode-cn.com/problems/insufficient-nodes-in-root-to-leaf-paths/
    TreeNode* sufficientSubsetHelper(TreeNode* node, int limit, int cur);
};


#endif //LEARNCPP_ALGORITHM_SOLUTION_H
