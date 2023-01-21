//
// Created by 包傲磊 on 2023/1/21.
//

#ifndef LEARNCPP_ALGORITHM_PROGRAMMINGDAY8_H
#define LEARNCPP_ALGORITHM_PROGRAMMINGDAY8_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "../../../sort/HeapSort.h"
using namespace std;


class PDay8 {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int rowStart = 0, rowEnd = m - 1, colStart = 0, colEnd = n - 1;
        int r, c;
        vector<int> ans;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            for (c = colStart; c <= colEnd; c++) {
                ans.push_back(matrix[rowStart][c]);
            }
            rowStart++;
            if (rowStart > rowEnd) {
                break;
            }
            for (r = rowStart; r <= rowEnd; ++r) {
                ans.push_back(matrix[r][colEnd]);
            }
            colEnd--;
            if (colStart > colEnd) {
                break;
            }
            for (c = colEnd; c >= colStart; --c) {
                ans.push_back(matrix[rowEnd][c]);
            }
            rowEnd--;
            for (r = rowEnd; r >= rowStart; --r) {
                ans.push_back(matrix[r][colStart]);
            }
            colStart++;
        }
        return ans;
    }

    int eucDistanceSquare(vector<int> &point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        unordered_map<int, vector<int>> map;
        unordered_set<int> used;
        vector<int> closestDistance;
        vector<vector<int>> ans;
        HeapSort hs;
        int i = 0;
        for (vector<int> & point: points) {
            int eucSquare = eucDistanceSquare(point);
            map[eucSquare].push_back(i);
            i ++ ;
            closestDistance.push_back(eucSquare);
        }
        hs.heapify(closestDistance);
        int curSize = 0;
        for (int j = 0; j < k; ++j) {
            int dist = hs.pop(closestDistance);
            if (used.find(dist) != used.end()){
                continue;
            }
            used.insert(dist);
            for (int idx : map[dist]) {
                ans.push_back(points[idx]);
                curSize ++;
                if (curSize == k){
                    break;
                }
            }
        }
        return ans;
    }
};

#endif //LEARNCPP_ALGORITHM_PROGRAMMINGDAY8_H
