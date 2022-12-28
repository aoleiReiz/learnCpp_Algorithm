#include <iostream>
#include <string>
#include "leetcode/daily/Solution.h"
#include "leetcode/algorithms/backtrack/BackTrack.h"

using namespace std;

int main() {
    BackTrack backTrack;
    vector<int> nums({2,5,2,1,2});
    vector<vector<int>> res = backTrack.combinationSum2(nums, 5);
    for (vector<int> &v: res) {
        for (int i: v) {
            cout << i << " ";
        }
        cout <<endl;
    }
    return 0;
}
