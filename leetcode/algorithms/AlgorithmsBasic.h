//
// Created by aolei.bao on 7/5/2021.
//

#ifndef LEARNCPP_ALGORITHM_ALGORITHMSBASIC_H
#define LEARNCPP_ALGORITHM_ALGORITHMSBASIC_H
#include <vector>

using namespace std;


class AlgorithmsBasic {

private:
    void reverseArray(vector<int> &arr, int left, int right);
public:
    //https://leetcode-cn.com/problems/binary-search/
    int search(vector<int>& nums, int target);
    //https://leetcode-cn.com/problems/search-insert-position/
    int searchInsert(vector<int>& nums, int target);
    //https://leetcode-cn.com/problems/squares-of-a-sorted-array/
    vector<int> sortedSquares(vector<int>& nums);
    //https://leetcode-cn.com/problems/rotate-array/
    void rotate(vector<int>& nums, int k);
    //https://leetcode-cn.com/problems/move-zeroes/
    void moveZeroes(vector<int>& nums);
    //https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
    vector<int> twoSum(vector<int>& numbers, int target);
};


#endif //LEARNCPP_ALGORITHM_ALGORITHMSBASIC_H
