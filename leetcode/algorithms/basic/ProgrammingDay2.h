//
// Created by 包傲磊 on 2023/1/15.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY2_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY2_H
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class ProgrammingDay2 {
public:
    int height(TreeNode *root);
    bool isBalanced(TreeNode *root);
    bool repeatedSubstringPattern(std::string s);
};


#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY2_H
