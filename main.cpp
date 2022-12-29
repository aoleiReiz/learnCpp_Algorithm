#include <iostream>
#include <string>
#include "leetcode/daily/Solution.h"
#include "leetcode/algorithms/backtrack/BackTrack.h"

using namespace std;

int main() {
    Solution solution;
    vector<int> nums1({1,1,3,2});
    vector<int> nums2({2,3});
    vector<int> nums3({3});
    vector<int> res = solution.twoOutOfThree(nums1, nums2, nums3);
    for (int num: res) {
        cout << num << " ";
    }
    cout<< endl;
    return 0;
}
