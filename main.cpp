#include <iostream>
#include <string>
#include "leetcode/algorithms/backtrack/BackTrack.h"

using namespace std;

int main() {
    BackTrack backTrack;
    vector<int> nums({1, 2, 3});
    vector<vector<int>> res = backTrack.subsets(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res.at(i).size(); ++j) {
            cout << res.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}
