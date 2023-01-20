//
// Created by 包傲磊 on 2023/1/20.
//

#ifndef LEARNCPP_ALGORITHM_DAY7_H
#define LEARNCPP_ALGORITHM_DAY7_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node *connect(Node *root) {
    if (root == nullptr) {
        return nullptr;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        Node *preNode = nullptr;
        while (size > 0) {
            Node *ptr = q.front();
            q.pop();
            if (preNode) {
                preNode->next = ptr;
            }
            preNode = ptr;
            if (ptr->left) {
                q.push(ptr->left);
            }
            if (ptr->right) {
                q.push(ptr->right);
            }
            size--;
        }
    }
    return root;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSubTreeHelper(TreeNode *root, TreeNode *subRoot) {
    if (subRoot == nullptr && root == nullptr) {
        return true;
    } else if (subRoot == nullptr || root == nullptr){
        return false;
    }else{
        return root->val == subRoot->val && isSubTreeHelper(root->left, subRoot->left) && isSubTreeHelper(root->right, subRoot->right);
    }
}

bool isSubtree(TreeNode *root, TreeNode *subRoot) {

    bool rootFlag = isSubTreeHelper(root, subRoot);
    if (rootFlag){
        return true;
    }
    bool leftFlag = false, rightFlag = false;
    if (root){
        leftFlag = isSubtree(root->left, subRoot);
        if (leftFlag){
            return true;
        }
        rightFlag = isSubtree(root->right, subRoot);
        if (rightFlag){
            return true;
        }
    }
    return leftFlag || rightFlag || rootFlag;
}

#endif //LEARNCPP_ALGORITHM_DAY7_H
