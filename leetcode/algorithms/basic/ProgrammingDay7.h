//
// Created by 包傲磊 on 2023/1/20.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY7_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY7_H
#include <vector>
#include <istream>

using namespace std;


void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m / 2; ++i) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[m - i - 1][j];
            matrix[m - i - 1][j] = temp;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i != j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    if (mat == target){
        return true;
    }
    int n = mat.size();
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int temp = mat[i][j];
                mat[i][j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = mat[n-1-i][n-1-j];
                mat[n-1-i][n-1-j] = mat[j][n-1-i];
                mat[j][n-1-i] = temp;
            }
        }
        if (mat == target){
            return true;
        }
    }
    return false;
}
#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY7_H
