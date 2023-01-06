//
// Created by aolei.bao on 1/5/2023.
//

#include "ShellSort.h"

vector<int> ShellSort::sortArray(vector<int> &nums) {
    int h = nums.size() / 2;
    while (h >= 1) {
        for (int i = h; i < nums.size(); ++i) {
            int e = nums[i];
            int j = i;
            for (; j - h >= 0 && nums[j - h] > nums[j]; j -= h) {
                nums[j] = nums[j - h];
            }
            nums[j] = e;
        }
        h /= 2;
    }
    return nums;
}

vector<string> ShellSort::findRelativeRanks(vector<int> &score) {
    vector<string> ans(score.size(), "");
    unordered_map<int, int> m;
    int idx = 0;
    for (auto i: score) {
        m[i] = idx;
        idx += 1;
    }
    int h = score.size();
    while (h >= 1) {
        for (int i = h; i < score.size(); ++i) {
            int j = i;
            int e = score[j];
            for (; j - h >= 0 && score[j - h] > e; j -= h) {
                score[j] = score[j - h];
            }
            score[j] = e;
        }
        h /= 2;
    }
    idx = 0;
    for (int i = score.size() -1; i >= 0; --i){
        int sc = score[i];
        auto it = m.find(sc);
        int ansIdx = it->second;
        if (idx == 0){
            ans[ansIdx] = "Gold Medal";
        }else if (idx == 1){
            ans[ansIdx] = "Silver Medal";
        }else if (idx == 2){
            ans[ansIdx] = "Bronze Medal";
        }else{
            ans[ansIdx] = to_string(idx + 1);
        }
        idx += 1;
    }

    return ans;
}
