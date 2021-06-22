//
// Created by Acer on 6/15/2021.
//

#include "Solution.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int Solution::peakIndexInMountainArray(vector<int> &arr) {
    int n = arr.size();
    int ans = -1;
    int left = 0, right = n - 2;
    while (left <= right){
        int mid = (right - left) / 2 + left;
        if (arr[mid] > arr [mid + 1] ){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}

//https://leetcode-cn.com/problems/occurrences-after-bigram/submissions/
vector<string> Solution::findOcurrences(string text, string first, string second){
    vector<string> res;
    istringstream ss(text);
    string cur = "", firstStr = "", secondStr = "";
    while (ss >> cur){
        if((first == firstStr) && (second == secondStr)){
            res.push_back(cur);
        }
        firstStr = secondStr;
        secondStr = cur;
    }
    return res;
}

int Solution::numTilePossibilities(string tiles) {
    vector<int>characterCount(26, 0);
    for (int i = 0; i < tiles.size(); ++i) {
        characterCount[tiles[i] - 'A']++;
    }
    
    return dfsCount(characterCount);
}
int Solution::dfsCount(vector<int> characterCount) {
    int count = 0;
    for (int i = 0; i < 26; ++i) {
        if(characterCount[i] == 0){
            continue;
        }
        ++ count;
        characterCount[i] --;
        count += dfsCount(characterCount);
        characterCount[i] ++;
    }
    return count;
}

TreeNode *Solution::sufficientSubset(TreeNode *root, int limit) {
    return sufficientSubsetHelper(root, limit, 0);
}
TreeNode *Solution::sufficientSubsetHelper(TreeNode *node, int limit, int cur) {
    if(node == nullptr){
        return nullptr;
    }
    cur += node->val;
    if(node->left == nullptr && node->right == nullptr){
        if (cur < limit){
            delete node;
            return nullptr;
        }
        return node;
    }
    node->left = sufficientSubsetHelper(node->left, limit, cur);
    node->right = sufficientSubsetHelper(node->right, limit, cur);
    if (node->left == nullptr && node->right == nullptr){
        return nullptr;
    }
    return node;
}
