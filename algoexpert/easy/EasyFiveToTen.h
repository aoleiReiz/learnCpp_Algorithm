//
// Created by aolei.bao on 1/5/2023.
//

#ifndef LEARNCPP_ALGORITHM_EASYFIVETOTEN_H
#define LEARNCPP_ALGORITHM_EASYFIVETOTEN_H

#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val);

    BST &insert(int val);
};

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};


class EasyFiveToTen {

private:
    void branchSumsHelper(BinaryTree *root, vector<int> &ans, int curSum);
    int nodeDepthHelper(BinaryTree *root, int depth);
public:
    int findClosestValueInBst(BST *tree, int target);
    vector<int> branchSums(BinaryTree *root);
    int nodeDepths(BinaryTree *root);
    int minimumWaitingTime(vector<int> queries);
};

class Node {
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector<string> depthFirstSearch(vector<string> *array) {
        // Write your code here.
        array->push_back(this->name);
        for (auto &nodePtr : this->children) {
            nodePtr->depthFirstSearch(array);
        }
        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};




#endif //LEARNCPP_ALGORITHM_EASYFIVETOTEN_H
