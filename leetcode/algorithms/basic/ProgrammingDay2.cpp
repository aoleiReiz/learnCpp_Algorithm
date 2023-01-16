//
// Created by 包傲磊 on 2023/1/15.
//

#include "ProgrammingDay2.h"

using namespace std;


bool ProgrammingDay2::isBalanced(TreeNode *root) {
    return height(root) >= 0;
}

bool ProgrammingDay2::repeatedSubstringPattern(std::string s) {
    return (s + s).find(s, 1) != s.size();
}

int ProgrammingDay2::height(TreeNode *root) {
    if(root == nullptr){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
        return -1;
    }else{
        return max(leftHeight, rightHeight) + 1;
    }
}
