//
// Created by 包傲磊 on 2023/1/22.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY9_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY9_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans;
    for (int i = 0; i < l.size(); ++i) {
        int left = l[i];
        int right = r[i];
        vector<int> subArray(nums.begin() + left, nums.begin() + right+1);
        sort(subArray.begin(), subArray.end());
        if (right - left <= 1){
            ans.push_back(true);
        }else{
            bool flag = true;
            int diff = subArray[1] - subArray[0];
            for (int j = 2; j < subArray.size(); ++j) {
                if (subArray[j] - subArray[j -1] != diff){
                    flag  = false;
                    break;
                }
            }
            ans.push_back(flag);
        }
    }
    return ans;
}

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    queue<Node*> q;
    if (root){
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> row;
            while (size > 0){
                Node * nodePtr = q.front();
                q.pop();
                row.push_back(nodePtr->val);
                for (Node * ptr: nodePtr->children) {
                    if (ptr){
                        q.push(ptr);
                    }
                }
                size --;
            }
            ans.push_back(row);
        }
    }
    return ans;
}

#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY9_H
