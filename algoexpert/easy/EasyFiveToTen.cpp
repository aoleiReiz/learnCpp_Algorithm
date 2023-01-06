//
// Created by aolei.bao on 1/5/2023.
//

#include "EasyFiveToTen.h"


int EasyFiveToTen::findClosestValueInBst(BST *tree, int target) {
    if(tree == nullptr){
        return INT_MAX;
    }
    int diff = abs(tree->value - target);
    int closest_value = tree->value;
    if(tree->value > target){
        int left_closest_value = findClosestValueInBst(tree->left, target);
        if (left_closest_value != INT_MAX && diff > abs(left_closest_value - target)){
            diff = abs(left_closest_value - target);
            closest_value = left_closest_value;
        }
    }else if(tree->value < target){
        int right_closest_value = findClosestValueInBst(tree->right, target);
        if (right_closest_value != INT_MAX && diff > abs(right_closest_value - target)){
            diff = abs(right_closest_value - target);
            closest_value = right_closest_value;
        }
    }
    return closest_value;
}

vector<int> EasyFiveToTen::branchSums(BinaryTree *root) {
    vector<int>ans;
    branchSumsHelper(root, ans, 0);
    return ans;
}

void EasyFiveToTen::branchSumsHelper(BinaryTree *root, vector<int> &ans, int curSum) {
    if (root == nullptr){
        return;
    }

    curSum += root->value;

    if (root->left == nullptr && root->right == nullptr){
        ans.push_back(curSum);
        return;
    }
    branchSumsHelper(root->left, ans, curSum);
    branchSumsHelper(root->right, ans, curSum);
}

int EasyFiveToTen::nodeDepths(BinaryTree *root) {
    return nodeDepthHelper(root, 0);
}

int EasyFiveToTen::nodeDepthHelper(BinaryTree *root, int depth) {
    if (root == nullptr){
        return 0;
    }
    return nodeDepthHelper(root->left, depth + 1) + nodeDepthHelper(root->right, depth + 1) + depth;
}

int EasyFiveToTen::minimumWaitingTime(vector<int> queries) {
    sort(queries.begin(), queries.end());
    int curWaitingTime = 0;
    int totalWaitingTime = 0;
    for (auto query: queries){
        totalWaitingTime += curWaitingTime;
        curWaitingTime += query;
    }
    return totalWaitingTime;
}
