//
// Created by aolei.bao on 7/6/2021.
//

#ifndef LEARNCPP_ALGORITHM_ARRAYSOLUTION_H
#define LEARNCPP_ALGORITHM_ARRAYSOLUTION_H
#include <vector>
#include <unordered_map>
using namespace std;

class ArraySolution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
    //https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    //https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(vector<int>& prices);
    //https://leetcode-cn.com/problems/reshape-the-matrix/
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c);
    //https://leetcode-cn.com/problems/pascals-triangle/
    vector<vector<int>> generate(int numRows);
    //https://leetcode-cn.com/problems/valid-sudoku/
    bool isValidSudoku(vector<vector<char>>& board);
    //https://leetcode-cn.com/problems/set-matrix-zeroes/
    void setZeroes(vector<vector<int>>& matrix);
};


#endif //LEARNCPP_ALGORITHM_ARRAYSOLUTION_H
