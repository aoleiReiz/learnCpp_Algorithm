//
// Created by 包傲磊 on 2023/1/17.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY4_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY4_H
#include <string>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class PSSolution {
public:
    bool isSubPathHelper(ListNode* head, TreeNode* root){
        if (head == nullptr){
            return true;
        }
        if (root == nullptr || head->val != root->val){
            return false;
        }
        bool left = isSubPathHelper(head->next,root->left);
        bool right = isSubPathHelper(head->next, root->right);
        return left || right;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr){
            return isSubPathHelper(head, root);
        }
        bool rootPath = isSubPathHelper(head, root);
        if (rootPath){
            return true;
        }
        bool leftPath = isSubPath(head, root->left);
        if (leftPath){
            return true;
        }
        bool rightPath = isSubPath(head, root->right);
        if (rightPath){
            return true;
        }
        return false;
    }

    vector<int> addVector(vector<int> &nums1, vector<int> &nums2){
        vector<int> ret;
        int exceedDigit = 0;
        int idx1 = 0, idx2 = 0;
        while (idx1 < nums1.size() || idx2 < nums2.size()){
            if (idx1 >= nums1.size()){
                int addResult = exceedDigit + nums2[idx2];
                exceedDigit = addResult / 10;
                ret.push_back(addResult - exceedDigit * 10);
                idx2 ++;
            }else if (idx2 >= nums2.size()){
                int addResult = exceedDigit + nums1[idx1];
                exceedDigit = addResult / 10;
                ret.push_back(addResult - exceedDigit * 10);
                idx1 ++;
            }else {
                int addResult = nums1[idx1] + nums2[idx2] + exceedDigit;
                ret.push_back(addResult % 10);
                exceedDigit = addResult / 10;
                idx1 ++;
                idx2 ++;
            }
        }
        if (exceedDigit > 0){
            ret.push_back(exceedDigit);
        }
        return ret;
    }

    string multiply(string num1, string num2) {
        if (num2 == "0" || num1 == "0"){
            return "0";
        }
        vector<int> prev;
        string ans;
        int digitColumn = 0;
        for (int i = num1.size() - 1; i>= 0 ; --i) {
            int exceedDigit = 0;
            vector<int> curRow;
            for (int j = 0; j < digitColumn; ++j) {
                curRow.push_back(0);
            }
            for (int j = num2.size() - 1; j >= 0 ; --j) {
                int digitMultiplyResult = (num1[i] - '0') * (num2[j] - '0') + exceedDigit;
                exceedDigit = digitMultiplyResult / 10;
                curRow.push_back(digitMultiplyResult - exceedDigit * 10);
            }
            if (exceedDigit > 0){
                curRow.push_back(exceedDigit);
            }
            digitColumn ++;
            prev = addVector(prev, curRow);
        }
        for (int i = prev.size() - 1; i >= 0 ; --i) {
            ans += to_string(prev[i]);
        }
        return ans;
    }
};

#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY4_H
