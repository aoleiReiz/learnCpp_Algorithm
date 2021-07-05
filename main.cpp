#include <iostream>
#include <string>
#include <vector>
#include "leetcode/algorithms/AlgorithmsBasic.h"

using namespace  std;

int main() {
    AlgorithmsBasic algorithmsBasic;

    vector<int> nums = {1,3,5,6};
    int target = 0;

    cout << algorithmsBasic.searchInsert(nums, target)<<endl;

    return 0;
}
