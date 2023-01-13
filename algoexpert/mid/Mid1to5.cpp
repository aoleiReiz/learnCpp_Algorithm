//
// Created by aolei.bao on 1/11/2023.
//

#include "Mid1to5.h"

vector<vector<int>> Mid1to5::threeNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    vector<vector<int>>ans;
    for (int i = 0; i < array.size() - 2; ++i) {
        int t = targetSum - array[i];
        vector<vector<int>> r = twoNumberSum(array, t, i + 1);
        for (auto &vec : r){
            vec.insert(vec.begin(), array[i]);
            ans.push_back(vec);
        }
    }
    return ans;
}

vector<vector<int>> Mid1to5::twoNumberSum(vector<int> &array, int target, int startIndex) {
    vector<vector<int>> res;
    int left = startIndex;
    int right = array.size() - 1;
    while (left < right){
        int sum = array[left] + array[right];
        if (sum == target){
            res.push_back(vector<int>({array[left], array[right]}));
            left ++;
            right --;
        }else if (sum > target){
            right --;
        }else{
            left ++;
        }
    }
    return res;
}
